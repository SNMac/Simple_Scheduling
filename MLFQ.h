/**
 * @file
 * @brief
 * @date 2022/11/12
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_MLFQ_H
#define INC_2022_OS_PROJ1_MLFQ_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unistd.h>

#define MLFQ_RESET_TIME 900  // priority reset period
#define MLFQ_FIRST_LEVEL_TIME_SLICE 50
#define MLFQ_SECOND_LEVEL_TIME_SLICE 75
#define MLFQ_THIRD_LEVEL_TIME_SLICE 100
#define MLFQ_FIRST_LEVEL 1
#define MLFQ_SECOND_LEVEL 2
#define MLFQ_THIRD_LEVEL 3

class MLFQ {
public:
    /* class variables */
    pid_t now_pid;  // current handling child's pid
    int now_level;  // current handling child's priority level
    int afterResetTime = 0;  // passed time after priority reset
    std::queue<pid_t> readyFirstQ;  // first priority readyQ
    std::queue<pid_t> readySecondQ;  // second priority readyQ
    std::queue<pid_t> readyThirdQ;  // third priority readyQ
    std::vector<std::pair<pid_t, int>> waitFirstQ;  // <pid, IO_burst>, first priority waitQ
    std::vector<std::pair<pid_t, int>> waitSecondQ;  // <pid, IO_burst>, second priority waitQ
    std::vector<std::pair<pid_t, int>> waitThirdQ;  // <pid, IO_burst>, third priority waitQ
    std::unordered_map<pid_t, int> childRemainTs;

    /* class functions specified in here */
    int getTimeSlice() {return childRemainTs[now_pid];}

    /* class functions specified in .cpp */
    void setNowPID();
    void resetPriority();  // move all children to readyFirstQ or waitFirstQ
};

#endif //INC_2022_OS_PROJ1_MLFQ_H
