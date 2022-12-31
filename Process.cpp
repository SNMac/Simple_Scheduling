/**
 * @file
 * @brief
 * @date 2022/11/03
 * @author SNMac
 */

#include <iostream>
#include <random>
#include <csignal>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "Process.h"

Process* process;

Process::Process() {
    process = this;
    my_pid = getpid();
    CPU_burst = randNumGen(PROCESS_BURST_MIN, PROCESS_BURST_MAX);
    IO_burst = randNumGen(PROCESS_BURST_MIN, PROCESS_BURST_MAX);

    key = 0x12345;
    msgq = msgget(key, IPC_CREAT | 0666);
    msg.pid = my_pid;
    new_sa.sa_handler = Process::signal_handler;
}

void Process::DoSomeJob() {
    if (sigaction(SIGUSR1, &new_sa, &old_sa) == -1) {
        perror("sigaction(SIGUSR1)");
        exit(EXIT_FAILURE);
    }

    while(true);
}

void Process::sendMsg(bool isIOJob) {
    msg.CPU_burst = CPU_burst;
    msg.IO_burst = IO_burst;
    msg.isIOJob = isIOJob;
    msg.mtype = 1;
    msgsnd(msgq, &msg, sizeof(struct msgblock) - sizeof(long), 0);
}

void Process::signal_handler(int signo) {
    std::cout << "SIGUSR1(" << signo << ") ~> Child(" << process->my_pid << ")\n";
    process->CPU_burst--;
    std::cout << "Child PID : " << process->my_pid << ") remain CPU burst : " << process->CPU_burst << '\n';
    if (process->CPU_burst == 0) {  // switch to IO burst
        process->sendMsg(true);
        process->CPU_burst = randNumGen(PROCESS_BURST_MIN, PROCESS_BURST_MAX);  // reset CPU burst time
        process->IO_burst = randNumGen(PROCESS_BURST_MIN, PROCESS_BURST_MAX);  // reset IO burst time
    } else {
        process->sendMsg(false);
    }
}

int randNumGen(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}