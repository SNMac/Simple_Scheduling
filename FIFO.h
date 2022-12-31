/**
 * @file
 * @brief
 * @date 2022/11/05
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_FIFO_H
#define INC_2022_OS_PROJ1_FIFO_H

#include <vector>
#include <queue>
#include <unistd.h>

class FIFO {
public:
    /* class variables */
    pid_t now_pid;  // current handling child's pid
    std::queue<pid_t> readyQ;
    std::vector<std::pair<pid_t, int>> waitQ;  // <pid, IO_burst>

    /* class functions specified in here */
    void setNowPID() {now_pid = readyQ.front();}
};

#endif //INC_2022_OS_PROJ1_FIFO_H
