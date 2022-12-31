/**
 * @file
 * @brief
 * @date 2022/11/14
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_RR_H
#define INC_2022_OS_PROJ1_RR_H

#include <queue>
#include <unistd.h>

#define RR_TIME_SLICE 50

class RR {
public:
    /* class variables */
    pid_t now_pid;
    std::queue<pid_t> readyQ;
    std::queue<pid_t> inactiveQ;
    std::vector<std::pair<pid_t, int>> waitQ;

    /* class functions specified in here */
    void setNowPID() {now_pid = readyQ.front();}
    void swapQ() {readyQ.swap(inactiveQ);}
    int getTimeSlice() {return RR_TIME_SLICE;}
};

#endif //INC_2022_OS_PROJ1_RR_H
