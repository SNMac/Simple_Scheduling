/**
 * @file
 * @brief
 * @date 2022/11/08
 * @author SNMac
 */

#include <iostream>

#include "CFS.h"

void CFS::swapQ() {
    while(!inactiveQ.empty()) {
        pid_t pid = inactiveQ.front();
        readyQ.insert(std::pair<unsigned long long, pid_t>(pidVruntime[pid], pid));
        inactiveQ.pop();
    }
}

void CFS::updateVruntime(int CPUTime) {
    pid_t pid = now_pid;
    pidVruntime[pid] += CPUTime * ((double)CFS_NICE_0_LOAD / (double)pidWeights[pid]);
}

int CFS::getTimeSlice() {
    pid_t pid = now_pid;
    int totalWeight = 0;
    for (auto it : pidWeights)
        totalWeight += it.second;
    return CFS_TARGET_LATENCY * ((double)pidWeights[pid] / (double)totalWeight);
}