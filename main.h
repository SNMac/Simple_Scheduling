/**
 * @file
 * @brief
 * @date 2022/11/05
 * @author SNMac
 */

#ifndef INC_2022_OS_PROJ1_MAIN_H
#define INC_2022_OS_PROJ1_MAIN_H

#define MAIN_CHILD_NUM 10

/* User process priority = 0 ~ 19 */
#define MAIN_PRIORITY_MIN 0
#define MAIN_PRIORITY_MAX 19

#define MAIN_OUTPUT_TICK 10000

void createChildren(int num);
void receivedCPUmsg(pid_t msgpid, int msgCPU);
void receivedIOmsg(int msgRemain_ts, int msgIO);
void signal_handler(int signo);

#endif //INC_2022_OS_PROJ1_MAIN_H
