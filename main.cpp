/**
 * @file
 * @brief
 * @date 2022/11/05
 * @author SNMac
 */

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <csignal>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "main.h"
#include "Scheduler.h"
#include "Process.h"

using namespace std;

string schedName;
Scheduler sched;
vector<pair<pid_t, int>> children;
int key;
int msgq;
ofstream output;
chrono::steady_clock::time_point programStart;

int main() {
    cout << "Scheduler : FIFO, RR, MLQ, MLFQ, CFS\n";
    cout << "Scheduler? >> ";
    cin >> schedName;
    if (!sched.setScheduler(schedName)) {
        cerr << "Undefined scheduler\n";
        exit(EXIT_SUCCESS);
    }

    programStart = chrono::steady_clock::now();

    /* for output file */
    output.open(sched.getScheduler() + "_schedule_dump.txt");

    /* create children process */
    createChildren(MAIN_CHILD_NUM);

    /* for message queue */
    key = PROCESS_MSG_KEY;
    msgq = msgget(key, IPC_CREAT | 0666);
    struct msgblock msg{};

    /* for signal handling */
    struct sigaction old_sa{};
    struct sigaction new_sa{};
    new_sa.sa_handler = signal_handler;
    if (sigaction(SIGALRM, &new_sa, &old_sa) == -1) {
        perror("sigaction(SIGALRM)");
        exit(EXIT_FAILURE);
    }

    sched.setNowPID();
    sched.setRemain_ts();

    /* for periodic signaling */
    struct itimerval new_itimer{};
    struct itimerval old_itimer{};
    new_itimer.it_interval.tv_sec = 0;
    new_itimer.it_interval.tv_usec = 50000;  // 50ms
    new_itimer.it_value.tv_sec = 0;
    new_itimer.it_value.tv_usec = 50000;  // 50ms
    if (setitimer(ITIMER_REAL, &new_itimer, &old_itimer) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(true) {  // check IPC message queue
        /* child requested IO time */
        if(msgrcv(msgq, &msg, sizeof(struct msgblock) - sizeof(long), 0, IPC_NOWAIT) != -1) {
            /* for output of the program */
            receivedCPUmsg(msg.pid, msg.CPU_burst);
            if (msg.isIOJob) {
                receivedIOmsg(sched.getRemain_ts(), msg.IO_burst);
            } else if (sched.getRemain_ts() == 0) {  // used all time slice
                output << sched.ReadyQtoInactiveQ();
                if (sched.isReadyQEmpty())  // readyQ is empty
                    output << sched.swapQ();  // swap inactiveQ and readyQ
                sched.setNowPID();  // change target child
                sched.setRemain_ts();  // reset time slice to target child
            }
        }
    }
}
void createChildren(int num) {
    pid_t ch_pid;
    for (int i = 0; i < num; i++) {
        /* create child process using fork() */
        if ((ch_pid = fork()) < 0) {  // fork failed
            perror("fork");
        } else if (ch_pid == 0) {  // fork success, child process
            Process child;
            child.DoSomeJob();
            exit(EXIT_SUCCESS);
        } else {  // fork success, parent process
            int priority = randNumGen(MAIN_PRIORITY_MIN, MAIN_PRIORITY_MAX);
            sched.insertReadyQ(ch_pid, priority);
            children.emplace_back(ch_pid, priority);
            cout << "forked) PID : " << ch_pid << ", priority : " << priority << '\n';
            output << "forked) PID : " << ch_pid << ", priority : " << priority << '\n';
        }
    }
    output << "\n\n";
}

void receivedCPUmsg(pid_t msgpid, int msgCPU) {
    /* child send CPU burst for output */
    bool ContextSwitched = false;

    if (sched.getScheduler() == "MLQ") {
        if (msgpid != sched.getNowPID())  // Context switched by priority
            ContextSwitched = true;
    }
    output << "at time : " << sched.getTickCount() << ", current PID : " << msgpid
           << ", remaining CPU burst : " << msgCPU;
    if (sched.getScheduler() != "FIFO") {
        if (ContextSwitched) {
            output << ", remaining time slice : " << 0 << '\n';
        } else {
            output << ", remaining time slice : " << sched.getRemain_ts() << '\n';
        }
    } else {
        output << '\n';
    }

    output << sched.outputDump();

    if (ContextSwitched)
        output << "\n<<< Context switched by priority) Child PID : " << msgpid << " -> " << sched.getNowPID() << " >>>\n\n\n";
}

void receivedIOmsg(int msgRemain_ts, int msgIO) {
    output << sched.ReadyQtoWaitQ(msgRemain_ts, msgIO);
    if (sched.isReadyQEmpty()) {  // readyQ is empty
        if (!sched.isInactiveQEmpty()) {  // inactiveQ has child
            output << sched.swapQ();  // swap inactiveQ and readyQ
            sched.setNowPID();  // change target child
            sched.setRemain_ts();  // reset time slice to target child
        }
    } else {  // readyQ has child
        sched.setNowPID();  // change target child
        sched.setRemain_ts();  // reset time slice to target child
    }
}

void signal_handler(int signo) {
    cout << "SIGALRM(" << signo << ") ~> Parent(" << getpid() << ")\n";
    sched.incTickCount();
    if (sched.getTickCount() > MAIN_OUTPUT_TICK) {  // end of execution
        auto programEnd = chrono::steady_clock::now();
        auto programTime = chrono::duration<double>(programEnd - programStart);
        if (msgctl(msgq, IPC_RMID, nullptr) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
        for (auto it : children)  // kill children
            kill(it.first, SIGTERM);
        cout << fixed;
        cout.precision(4);
        cout << "Execution time : " << programTime.count() << " seconds" << endl;
        output << "\n<<< End Of Execution >>>\n\n\n";
        for (auto it : children)
            output << "PID : " << it.first << ") priority " << it.second << ", CPU time " << sched.pidCPU[it.first] << '\n';
        output << flush;
        exit(EXIT_SUCCESS);
    }
    pid_t ch_pid;
    if (!sched.isReadyQEmpty()) {  // readyQ has process
        ch_pid = sched.getNowPID();
        sched.addCPUtime(ch_pid);
        kill(ch_pid, SIGUSR1);
        if (sched.getScheduler() != "FIFO")  // RR, MLQ, MLFQ, CFS
            sched.decRemain_ts();
    } else {
        sched.IO_bounded = true;
    }

    if (!sched.isWaitQEmpty()) {  // waitQ has process
        sched.IOJob();
        sched.WaitQtoReadyQ();
    }
}