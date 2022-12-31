/**
 * @file
 * @brief
 * @date 2022/11/08
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_CFS_H
#define INC_2022_OS_PROJ1_CFS_H

#include <map>
#include <unordered_map>
#include <queue>
#include <unistd.h>

#define CFS_TARGET_LATENCY 600
#define CFS_NICE_0_LOAD 64

class CFS {
public:
    /* class variables */
    pid_t now_pid;  // current handling child's pid
    const int sched_prio_to_weight[20] = {  // 64 * 1.15^(-priority)
            259, 225, 196, 170, 148,
            129, 112, 97, 85, 74,
            64, 56, 48, 42, 37,
            32, 28, 24, 21, 18
    };
    std::unordered_map<pid_t, int> pidWeights;  // <pid, weight>, hash map
    std::unordered_map<pid_t, unsigned long long> pidVruntime;  // <pid, vruntime>, hash map
    std::multimap<unsigned long long, pid_t> readyQ;  // <vruntime, pid>, red-black tree
    std::queue<pid_t> inactiveQ;
    std::vector<std::pair<pid_t, int>> waitQ;  // <pid, IO_burst>

    /* class functions specified in here */
    void setNowPID() {now_pid = readyQ.begin()->second;}

    /* class functions specified in .cpp */
    void swapQ();
    void updateVruntime(int CPUTime);
    int getTimeSlice();  // calculate actual time slice
};

#endif //INC_2022_OS_PROJ1_CFS_H
