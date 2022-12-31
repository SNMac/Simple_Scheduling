/**
 * @file
 * @brief
 * @date 2022/11/16
 * @author SNMac
 */

#include "MLQ.h"

void MLQ::setNowPID() {
    if (!readyFirstQ.empty()) {
        now_pid = readyFirstQ.front();
        now_level = MLQ_FIRST_LEVEL;
    } else if (!readySecondQ.empty()) {
        now_pid = readySecondQ.front();
        now_level = MLQ_SECOND_LEVEL;
    } else {
        now_pid = readyThirdQ.front();
        now_level = MLQ_THIRD_LEVEL;
    }
}

int MLQ::getTimeSlice() {
    if (now_level == MLQ_FIRST_LEVEL) {
        return MLQ_FIRST_LEVEL_TIME_SLICE;
    } else if (now_level == MLQ_SECOND_LEVEL) {
        return MLQ_SECOND_LEVEL_TIME_SLICE;
    } else {  // now_level == MLQ_THIRD_LEVEL
        return MLQ_THIRD_LEVEL_TIME_SLICE;
    }
}