/**
 * @file
 * @brief
 * @date 2022/11/03
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_PROCESS_H
#define INC_2022_OS_PROJ1_PROCESS_H

#include <unistd.h>

#define PROCESS_BURST_MIN 10
#define PROCESS_BURST_MAX 200

#define PROCESS_MSG_KEY 0x12345

struct msgblock {  // message structure
    long mtype;
    int pid;
    int CPU_burst;
    int IO_burst;
    bool isIOJob;
};

class Process {
    /* class variables */
    pid_t my_pid;
    int CPU_burst;
    int IO_burst;
    int key;
    int msgq;
    struct msgblock msg{};
    struct sigaction old_sa{};
    struct sigaction new_sa{};

public:
    /* class functions specified in .cpp */
    Process();
    void DoSomeJob();
    void sendMsg(bool isIOJob);
    static void signal_handler(int signo);
};

int randNumGen(int min, int max);  // random number generator

#endif //INC_2022_OS_PROJ1_PROCESS_H
