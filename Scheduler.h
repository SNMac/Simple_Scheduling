/**
 * @file
 * @brief
 * @date 2022/11/03
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_SCHEDULER_H
#define INC_2022_OS_PROJ1_SCHEDULER_H

#include <unordered_map>

#include "FIFO.h"
#include "RR.h"
#include "MLQ.h"
#include "MLFQ.h"
#include "CFS.h"

class Scheduler {
    /* class variables */
    std::string sched;  // current scheduler name
    int tick_count;  // total time tick
    int remain_ts;  // remain time slice
    FIFO* fifo;
    RR* rr;
    MLQ* mlq;
    MLFQ* mlfq;
    CFS* cfs;
public:
    std::unordered_map<pid_t, int> pidCPU;  // <pid, CPU time>
    bool IO_bounded = false;  // indicate readyQ is empty or not

    /* class functions specified in here */
    int getTickCount() {return tick_count;}
    int getRemain_ts() {return remain_ts;}
    std::string getScheduler() {return sched;}

    /* class functions specified in .cpp */
    ~Scheduler();  // destructor
    bool setScheduler(const std::string& schedName);
    bool isReadyQEmpty();
    bool isWaitQEmpty();
    bool isInactiveQEmpty();
    void insertReadyQ(pid_t pid, int priority);  // initial push children to readyQ
    void setNowPID();  // set current handling child
    pid_t getNowPID();  // get current handling child
    void IOJob();  // decrease all IO burst in waitQ
    void WaitQtoReadyQ();  // waitQ child used up its IO burst
    std::string ReadyQtoWaitQ(int msgRemain_ts, int IO_burst);  // current handling child used up its CPU burst
    std::string ReadyQtoInactiveQ();  // current handling child used up assigned time slice
    std::string swapQ();  // swap inactiveQ and readyQ
    void decRemain_ts();
    void setRemain_ts();  // get time slice of current handling child
    void addCPUtime(pid_t pid);  // calculate child's total CPU time
    void incTickCount();  // calculate total time tick
    std::string outputDump();
};

#endif //INC_2022_OS_PROJ1_SCHEDULER_H
