/**
 * @file
 * @brief
 * @date 2022/11/12
 * @author SNMac
 */

#include "MLFQ.h"

void MLFQ::setNowPID() {
    if (!readyFirstQ.empty()) {
        now_pid = readyFirstQ.front();
        now_level = MLFQ_FIRST_LEVEL;
    } else if (!readySecondQ.empty()) {
        now_pid = readySecondQ.front();
        now_level = MLFQ_SECOND_LEVEL;
    } else {
        now_pid = readyThirdQ.front();
        now_level = MLFQ_THIRD_LEVEL;
    }
}

void MLFQ::resetPriority() {
    /* move all IO child to waitFirstQ */
    for (auto it : waitSecondQ)
        waitFirstQ.emplace_back(it.first, it.second);
    waitSecondQ.clear();

    for (auto it : waitThirdQ)
        waitFirstQ.emplace_back(it.first, it.second);
    waitThirdQ.clear();

    /* move all CPU child to readyFirstQ */
    while(!readySecondQ.empty()) {
        pid_t pid = readySecondQ.front();
        readyFirstQ.push(pid);
        readySecondQ.pop();
    }
    while(!readyThirdQ.empty()) {
        pid_t pid = readyThirdQ.front();
        readyFirstQ.push(pid);
        readyThirdQ.pop();
    }

    for (auto& it : childRemainTs)
        it.second = MLFQ_FIRST_LEVEL_TIME_SLICE;
}