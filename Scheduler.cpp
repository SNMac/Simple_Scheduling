/**
 * @file
 * @brief
 * @date 2022/11/02
 * @author SNMac
 */

#include <iostream>
#include <string>

#include "Scheduler.h"

Scheduler::~Scheduler() {
    if (sched == "FIFO") {
        delete fifo;
    } else if (sched == "RR") {
        delete rr;
    } else if (sched == "MLQ") {
        delete mlq;
    } else if (sched == "MLFQ") {
        delete mlfq;
    } else if (sched == "CFS") {
        delete cfs;
    }
}

bool Scheduler::setScheduler(const std::string& schedName) {
    sched = schedName;
    if (sched == "FIFO") {
        fifo = new FIFO;
    } else if (sched == "RR") {
        rr = new RR;
    } else if (sched == "MLQ") {
        mlq = new MLQ;
    } else if (sched == "MLFQ") {
        mlfq = new MLFQ;
    } else if (sched == "CFS") {
        cfs = new CFS;
    } else {  // Undefined scheduler
        return false;
    }
    return true;
}

bool Scheduler::isReadyQEmpty() {
    if (sched == "FIFO") {
        return fifo->readyQ.empty();
    } else if (sched == "RR") {
        return rr->readyQ.empty();
    } else if (sched == "MLQ") {
        return mlq->readyFirstQ.empty() & mlq->readySecondQ.empty() & mlq->readyThirdQ.empty();
    } else if (sched == "MLFQ") {
        return mlfq->readyFirstQ.empty() & mlfq->readySecondQ.empty() & mlfq->readyThirdQ.empty();
    } else if (sched == "CFS") {
        return cfs->readyQ.empty();
    }
}

bool Scheduler::isWaitQEmpty() {
    if (sched == "FIFO") {
        return fifo->waitQ.empty();
    } else if (sched == "RR") {
        return rr->waitQ.empty();
    } else if (sched == "MLQ") {
        return mlq->waitFirstQ.empty() & mlq->waitSecondQ.empty() & mlq->waitThirdQ.empty();
    } else if (sched == "MLFQ") {
        return mlfq->waitFirstQ.empty() & mlfq->waitSecondQ.empty() & mlfq->waitThirdQ.empty();
    } else if (sched == "CFS") {
        return cfs->waitQ.empty();
    }
}

bool Scheduler::isInactiveQEmpty() {
    if (sched == "FIFO") {  // doesn't have inactiveQ
        return true;
    } else if (sched == "RR") {
        return rr->inactiveQ.empty();
    } else if (sched == "MLQ") {  // doesn't have inactiveQ
        return true;
    } else if (sched == "MLFQ") {  // doesn't have inactiveQ
        return true;
    } else if (sched == "CFS") {
        return cfs->inactiveQ.empty();
    }
}

void Scheduler::insertReadyQ(pid_t pid, int priority) {
    pidCPU.insert(std::pair<pid_t, int>(pid, 0));
    if (sched == "FIFO") {
        fifo->readyQ.push(pid);
    } else if (sched == "RR") {
        rr->readyQ.push(pid);
    } else if (sched == "MLQ") {
        if (priority <= 5) {  // 0 ~ 5
            mlq->readyFirstQ.push(pid);
        } else if (priority <= 12) {  // 6 ~ 12
            mlq->readySecondQ.push(pid);
        } else {  // 13 ~ 19
            mlq->readyThirdQ.push(pid);
        }
    } else if (sched == "MLFQ") {
        mlfq->readyFirstQ.push(pid);
        mlfq->childRemainTs.insert(std::pair<pid_t, int>(pid, MLFQ_FIRST_LEVEL_TIME_SLICE));
    } else if (sched == "CFS") {
        cfs->pidWeights.insert(std::pair<pid_t, int>(pid, cfs->sched_prio_to_weight[priority]));
        cfs->pidVruntime.insert(std::pair<pid_t, unsigned long long>(pid, 0));
        cfs->readyQ.insert(std::pair<int, pid_t>(0, pid));
    }
}

void Scheduler::setNowPID() {
    if (sched == "FIFO") {
        fifo->setNowPID();
    } else if (sched == "RR") {
        rr->setNowPID();
    } else if (sched == "MLQ") {
        mlq->setNowPID();
    } else if (sched == "MLFQ") {
        mlfq->setNowPID();
    } else if (sched == "CFS") {
        cfs->setNowPID();
    }
}

pid_t Scheduler::getNowPID() {
    if (sched == "FIFO") {
        return fifo->now_pid;
    } else if (sched == "RR") {
        return rr->now_pid;
    } else if (sched == "MLQ") {
        return mlq->now_pid;
    } else if (sched == "MLFQ") {
        return mlfq->now_pid;
    } else if (sched == "CFS") {
        return cfs->now_pid;
    }
}

void Scheduler::IOJob() {
    std::cout << "< IO job on going >\n";
    if (sched == "FIFO") {
        for (auto& it : fifo->waitQ)
            it.second--;

    } else if (sched == "RR") {
        for (auto& it : rr->waitQ)
            it.second--;

    } else if (sched == "MLQ") {
        for (auto& it : mlq->waitFirstQ)
            it.second--;
        for (auto& it : mlq->waitSecondQ)
            it.second--;
        for (auto& it : mlq->waitThirdQ)
            it.second--;

    } else if (sched == "MLFQ") {
        for (auto& it : mlfq->waitFirstQ)
            it.second--;
        for (auto& it : mlfq->waitSecondQ)
            it.second--;
        for (auto& it : mlfq->waitThirdQ)
            it.second--;

    } else if (sched == "CFS") {
        for (auto& it : cfs->waitQ)
            it.second--;

    }
}

void Scheduler::WaitQtoReadyQ() {
    pid_t pid;
    if (sched == "FIFO") {
        for (int i = 0; i < fifo->waitQ.size(); ) {
            if (fifo->waitQ[i].second == 0) {
                pid = fifo->waitQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyQ >>>\n\n";
                fifo->readyQ.push(pid);
                fifo->waitQ.erase(fifo->waitQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    fifo->setNowPID();
                }
            } else {
                i++;
            }
        }

    } else if (sched == "RR") {
        for (int i = 0; i < rr->waitQ.size(); ) {
            if (rr->waitQ[i].second == 0) {
                pid = rr->waitQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyQ >>>\n\n";
                rr->readyQ.push(pid);
                rr->waitQ.erase(rr->waitQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    rr->setNowPID();
                }
            } else {
                i++;
            }
        }

    } else if (sched == "MLQ") {
        bool isContextSwitched = false;
        pid_t from_pid;
        for (int i = 0; i < mlq->waitThirdQ.size(); ) {
            if (mlq->waitThirdQ[i].second == 0) {
                pid = mlq->waitThirdQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyThirdQ >>>\n\n";
                mlq->readyThirdQ.push(pid);
                mlq->waitThirdQ.erase(mlq->waitThirdQ.begin() + i);
            } else {
                i++;
            }
        }
        for (int i = 0; i < mlq->waitSecondQ.size(); ) {
            if (mlq->waitSecondQ[i].second == 0) {
                pid = mlq->waitSecondQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadySecondQ >>>\n\n";
                mlq->readySecondQ.push(pid);
                mlq->waitSecondQ.erase(mlq->waitSecondQ.begin() + i);
                pid_t old_pid = mlq->now_pid;
                mlq->setNowPID();
                if (old_pid != mlq->now_pid) {
                    isContextSwitched = true;
                    from_pid = old_pid;
                    setRemain_ts();
                }
            } else {
                i++;
            }
        }
        for (int i = 0; i < mlq->waitFirstQ.size(); ) {
            if (mlq->waitFirstQ[i].second == 0) {
                pid = mlq->waitFirstQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyFirstQ >>>\n\n";
                mlq->readyFirstQ.push(pid);
                mlq->waitFirstQ.erase(mlq->waitFirstQ.begin() + i);
                pid_t old_pid = mlq->now_pid;
                mlq->setNowPID();
                if (old_pid != mlq->now_pid) {
                    isContextSwitched = true;
                    from_pid = old_pid;
                    setRemain_ts();
                }
            } else {
                i++;
            }
        }
        if (isContextSwitched)
            std::cout << "\n<<< Context switching by priority) Child PID : " << from_pid << " -> " << mlq->now_pid << " >>>\n\n";

    } else if (sched == "MLFQ") {
        for (int i = 0; i < mlfq->waitFirstQ.size(); ) {
            if (mlfq->waitFirstQ[i].second == 0) {
                pid = mlfq->waitFirstQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyFirstQ >>>\n\n";
                mlfq->readyFirstQ.push(pid);
                mlfq->waitFirstQ.erase(mlfq->waitFirstQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    mlfq->setNowPID();
                }
            } else {
                i++;
            }
        }
        for (int i = 0; i < mlfq->waitSecondQ.size(); ) {
            if (mlfq->waitSecondQ[i].second == 0) {
                pid = mlfq->waitSecondQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadySecondQ >>>\n\n";
                mlfq->readySecondQ.push(pid);
                mlfq->waitSecondQ.erase(mlfq->waitSecondQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    mlfq->setNowPID();
                }
            } else {
                i++;
            }
        }
        for (int i = 0; i < mlfq->waitThirdQ.size(); ) {
            if (mlfq->waitThirdQ[i].second == 0) {
                pid = mlfq->waitThirdQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyThirdQ >>>\n\n";
                mlfq->readyThirdQ.push(pid);
                mlfq->waitThirdQ.erase(mlfq->waitThirdQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    mlfq->setNowPID();
                }
            } else {
                i++;
            }
        }

    } else if (sched == "CFS") {
        for (int i = 0; i < cfs->waitQ.size(); ) {
            if (cfs->waitQ[i].second == 0) {
                pid = cfs->waitQ[i].first;
                std::cout << "\n<<< IO burst finished) Child PID : " << pid << " -> ReadyQ >>>\n\n";
                cfs->readyQ.insert(std::pair<unsigned long long, pid_t>(cfs->pidVruntime[pid], pid));
                cfs->waitQ.erase(cfs->waitQ.begin() + i);
                if (IO_bounded) {
                    IO_bounded = false;
                    cfs->setNowPID();
                }
            } else {
                i++;
            }
        }
    }

}

std::string Scheduler::ReadyQtoWaitQ(int msgRemain_ts, int IO_burst) {
    pid_t pid;
    std::string dump;
    if (sched == "FIFO") {
        pid = fifo->now_pid;
        std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitQ for " << IO_burst << " >>>\n\n";
        fifo->readyQ.pop();
        fifo->waitQ.emplace_back(pid, IO_burst);
        dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitQ for " + std::to_string(IO_burst) + " >>>\n\n\n";

    } else if (sched == "RR") {
        pid = rr->now_pid;
        std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitQ for " << IO_burst << " >>>\n\n";
        rr->readyQ.pop();
        rr->waitQ.emplace_back(pid, IO_burst);
        dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitQ for " + std::to_string(IO_burst) + " >>>\n\n\n";

    } else if (sched == "MLQ") {
        pid = mlq->now_pid;
        if (mlq->now_level == MLQ_FIRST_LEVEL) {
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitFirstQ for " << IO_burst << " >>>\n\n";
            mlq->readyFirstQ.pop();
            mlq->waitFirstQ.emplace_back(pid, IO_burst);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitFirstQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
        } else if (mlq->now_level == MLQ_SECOND_LEVEL) {
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitSecondQ for " << IO_burst << " >>>\n\n";
            mlq->readySecondQ.pop();
            mlq->waitSecondQ.emplace_back(pid, IO_burst);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitSecondQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
        } else {  // mlq->now_level == MLQ_THIRD_LEVEL
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitThirdQ for " << IO_burst << " >>>\n\n";
            mlq->readyThirdQ.pop();
            mlq->waitThirdQ.emplace_back(pid, IO_burst);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitThirdQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
        }

    } else if (sched == "MLFQ") {
        pid = mlfq->now_pid;
        if (msgRemain_ts == 0) {  // CPU burst == 0 && remain_ts == 0
            if (mlfq->now_level == MLFQ_FIRST_LEVEL) {  // first -> second
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitSecondQ for " << IO_burst << " >>>\n\n";
                mlfq->readyFirstQ.pop();
                mlfq->waitSecondQ.emplace_back(pid, IO_burst);
                mlfq->childRemainTs[pid] = MLFQ_SECOND_LEVEL_TIME_SLICE;
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitSecondQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            } else if (mlfq->now_level == MLFQ_SECOND_LEVEL) {  // second -> third
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitThirdQ for " << IO_burst << " >>>\n\n";
                mlfq->readySecondQ.pop();
                mlfq->waitThirdQ.emplace_back(pid, IO_burst);
                mlfq->childRemainTs[pid] = MLFQ_THIRD_LEVEL_TIME_SLICE;
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitThirdQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            } else {  // mlfq->now_level == MLFQ_THIRD_LEVEL  // third -> third
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitThirdQ for " << IO_burst << " >>>\n\n";
                mlfq->readyThirdQ.pop();
                mlfq->waitThirdQ.emplace_back(pid, IO_burst);
                mlfq->childRemainTs[pid] = MLFQ_THIRD_LEVEL_TIME_SLICE;
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitThirdQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            }
        } else {
            if (mlfq->now_level == MLFQ_FIRST_LEVEL) {
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitFirstQ for " << IO_burst << " >>>\n\n";
                mlfq->readyFirstQ.pop();
                mlfq->waitFirstQ.emplace_back(pid, IO_burst);
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitFirstQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            } else if (mlfq->now_level == MLFQ_SECOND_LEVEL) {
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitSecondQ for " << IO_burst << " >>>\n\n";
                mlfq->readySecondQ.pop();
                mlfq->waitSecondQ.emplace_back(pid, IO_burst);
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitSecondQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            } else {  // mlfq->now_level == MLFQ_THIRD_LEVEL
                std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitThirdQ for " << IO_burst << " >>>\n\n";
                mlfq->readyThirdQ.pop();
                mlfq->waitThirdQ.emplace_back(pid, IO_burst);
                dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitThirdQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
            }
        }

        if (mlfq->afterResetTime >= MLFQ_RESET_TIME) {
            std::cout << "\n<<< Resetting priority >>>\n\n";
            mlfq->resetPriority();
            mlfq->afterResetTime = 0;
            dump += "\n<<< Resetting priority >>>\n\n\n";
        }

    } else if (sched == "CFS") {
        pid = cfs->now_pid;
        std::cout << "\n<<< Context switching) Child PID : " << pid << " -> WaitQ for " << IO_burst << " >>>\n\n";
        std::multimap<unsigned long long, pid_t>::iterator it;
        for (it = cfs->readyQ.begin(); it != cfs->readyQ.end(); it++) {
            if (it->second == pid) {
                cfs->readyQ.erase(it);
                break;
            }
        }
        cfs->waitQ.emplace_back(pid, IO_burst);
        dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> WaitQ for " + std::to_string(IO_burst) + " >>>\n\n\n";
    }

    return dump;
}

std::string Scheduler::ReadyQtoInactiveQ() {
    pid_t pid;
    std::string dump;
    if (sched == "RR") {
        pid = rr->now_pid;
        std::cout << "\n<<< Context switching) Child PID : " << pid << " -> InactiveQ >>>\n\n";
        rr->readyQ.pop();
        rr->inactiveQ.push(pid);
        dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> InactiveQ >>>\n\n\n";

    } else if (sched == "MLQ") {
        pid = mlq->now_pid;
        if (mlq->now_level == MLQ_FIRST_LEVEL) {
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadyFirstQ >>>\n\n";
            mlq->readyFirstQ.pop();
            mlq->readyFirstQ.push(pid);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadyFirstQ >>>\n\n\n";
        } else if (mlq->now_level == MLQ_SECOND_LEVEL) {
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadySecondQ >>>\n\n";
            mlq->readySecondQ.pop();
            mlq->readySecondQ.push(pid);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadySecondQ >>>\n\n\n";
        } else {  // mlq->now_level == MLQ_THIRD_LEVEL  // third -> third
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadyThirdQ >>>\n\n";
            mlq->readyThirdQ.pop();
            mlq->readyThirdQ.push(pid);
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadyThirdQ >>>\n\n\n";
        }

    } else if (sched == "MLFQ") {  // decreasing current process priority level
        pid = mlfq->now_pid;
        if (mlfq->now_level == MLFQ_FIRST_LEVEL) {  // first -> second
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadySecondQ >>>\n\n";
            mlfq->readyFirstQ.pop();
            mlfq->readySecondQ.push(pid);
            mlfq->childRemainTs[pid] = MLFQ_SECOND_LEVEL_TIME_SLICE;
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadySecondQ >>>\n\n\n";
        } else if (mlfq->now_level == MLFQ_SECOND_LEVEL) {  // second -> third
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadyThirdQ >>>\n\n";
            mlfq->readySecondQ.pop();
            mlfq->readyThirdQ.push(pid);
            mlfq->childRemainTs[pid] = MLFQ_THIRD_LEVEL_TIME_SLICE;
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadyThirdQ >>>\n\n\n";
        } else {  // mlfq->now_level == MLFQ_THIRD_LEVEL  // third -> third
            std::cout << "\n<<< Context switching) Child PID : " << pid << " -> ReadyThirdQ >>>\n\n";
            mlfq->readyThirdQ.pop();
            mlfq->readyThirdQ.push(pid);
            mlfq->childRemainTs[pid] = MLFQ_THIRD_LEVEL_TIME_SLICE;
            dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> ReadyThirdQ >>>\n\n\n";
        }
        if (mlfq->afterResetTime >= MLFQ_RESET_TIME) {
            std::cout << "\n<<< Resetting priority >>>\n\n";
            mlfq->resetPriority();
            mlfq->afterResetTime = 0;
            dump += "\n<<< Resetting priority >>>\n\n\n";
        }

    } else if (sched == "CFS") {
        pid = cfs->now_pid;
        std::cout << "\n<<< Context switching) Child PID : " << pid << " -> InactiveQ >>>\n\n";
        std::multimap<unsigned long long, pid_t>::iterator it;
        for (it = cfs->readyQ.begin(); it != cfs->readyQ.end(); it++) {
            if (it->second == pid) {
                cfs->readyQ.erase(it);
                break;
            }
        }
        cfs->inactiveQ.push(pid);
        dump = "\n<<< Context switching) Child PID : " + std::to_string(pid) + " -> InactiveQ >>>\n\n\n";
    }

    return dump;
}

std::string Scheduler::swapQ() {
    std::string dump;
    if (sched == "RR") {
        rr->swapQ();
        dump = "\n<<< Queue swapping) InactiveQ <-> ReadyQ >>>\n\n\n";
        std::cout << "\n<<< Queue swapping) InactiveQ <-> ReadyQ >>>\n\n";
    } else if (sched == "CFS") {
        cfs->swapQ();
        dump = "\n<<< Queue swapping) InactiveQ <-> ReadyQ >>>\n\n\n";
        std::cout << "\n<<< Queue swapping) InactiveQ <-> ReadyQ >>>\n\n";
    }
    return dump;
}

void Scheduler::decRemain_ts() {
    remain_ts--;
    if (sched == "MLFQ")  // decrease time slice
        mlfq->childRemainTs[mlfq->now_pid]--;
}

void Scheduler::setRemain_ts() {
    if (sched == "FIFO") {
        remain_ts = 10000;
    } else if (sched == "RR") {
        remain_ts = rr->getTimeSlice();
    } else if (sched == "MLQ") {
        remain_ts = mlq->getTimeSlice();
    } else if (sched == "MLFQ") {
        remain_ts = mlfq->getTimeSlice();
    } else if (sched == "CFS") {
        remain_ts = cfs->getTimeSlice();
    }
    std::cout << "TimeSlice : " << remain_ts << '\n';
}

void Scheduler::addCPUtime(pid_t pid) {
    pidCPU[pid]++;
    if (sched == "CFS") {
        cfs->updateVruntime(pidCPU[pid]);
        std::cout << "PID : " << pid << ") update vruntime : " << cfs->pidVruntime[pid] << '\n';
    }
}

void Scheduler::incTickCount() {
    tick_count++;
    if (sched == "MLFQ")
        mlfq->afterResetTime++;
}

std::string Scheduler::outputDump() {
    std::string dump;
    if (sched == "FIFO") {
        dump = "ReadyQ : ";

        /* readyQ dump */
        for (int i = 0; i < fifo->readyQ.size(); i++) {
            pid_t temp = fifo->readyQ.front();
            dump += std::to_string(temp) + " -> ";
            fifo->readyQ.pop();
            fifo->readyQ.push(temp);
        }
        dump += "EndOfQ\nWaitQ : ";

        /* waitQ dump */
        for (auto it : fifo->waitQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\n";

    } else if (sched == "RR") {
        dump = "ReadyQ : ";

        /* readyQ dump */
        for (int i = 0; i < rr->readyQ.size(); i++) {
            pid_t temp = rr->readyQ.front();
            dump += std::to_string(temp) + " -> ";
            rr->readyQ.pop();
            rr->readyQ.push(temp);
        }
        dump += "EndOfQ\nInactiveQ : ";

        /* inactiveQ dump */
        for (int i = 0; i < rr->inactiveQ.size(); i++) {
            pid_t temp = rr->inactiveQ.front();
            dump += std::to_string(temp) + " -> ";
            rr->inactiveQ.pop();
            rr->inactiveQ.push(temp);
        }
        dump += "EndOfQ\nWaitQ : ";

        /* waitQ dump */
        for (auto it : rr->waitQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\n";

    } else if (sched == "MLQ") {
        dump = "ReadyFirstQ : ";

        /* readyQ dump */
        for (int i = 0; i < mlq->readyFirstQ.size(); i++) {
            pid_t temp = mlq->readyFirstQ.front();
            dump += std::to_string(temp) + " -> ";
            mlq->readyFirstQ.pop();
            mlq->readyFirstQ.push(temp);
        }
        dump += "EndOfQ\nReadySecondQ : ";
        for (int i = 0; i < mlq->readySecondQ.size(); i++) {
            pid_t temp = mlq->readySecondQ.front();
            dump += std::to_string(temp) + " -> ";
            mlq->readySecondQ.pop();
            mlq->readySecondQ.push(temp);
        }
        dump += "EndOfQ\nReadyThirdQ : ";
        for (int i = 0; i < mlq->readyThirdQ.size(); i++) {
            pid_t temp = mlq->readyThirdQ.front();
            dump += std::to_string(temp) + " -> ";
            mlq->readyThirdQ.pop();
            mlq->readyThirdQ.push(temp);
        }
        dump += "EndOfQ\nWaitFirstQ : ";

        /* waitQ dump */
        for (auto it : mlq->waitFirstQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\nWaitSecondQ : ";
        for (auto it : mlq->waitSecondQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\nWaitThirdQ : ";
        for (auto it : mlq->waitThirdQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\n";

    } else if (sched == "MLFQ") {
        dump = "ReadyFirstQ : ";

        /* readyQ dump */
        for (int i = 0; i < mlfq->readyFirstQ.size(); i++) {
            pid_t temp = mlfq->readyFirstQ.front();
            dump += std::to_string(temp) + " -> ";
            mlfq->readyFirstQ.pop();
            mlfq->readyFirstQ.push(temp);
        }
        dump += "EndOfQ\nReadySecondQ : ";
        for (int i = 0; i < mlfq->readySecondQ.size(); i++) {
            pid_t temp = mlfq->readySecondQ.front();
            dump += std::to_string(temp) + " -> ";
            mlfq->readySecondQ.pop();
            mlfq->readySecondQ.push(temp);
        }
        dump += "EndOfQ\nReadyThirdQ : ";
        for (int i = 0; i < mlfq->readyThirdQ.size(); i++) {
            pid_t temp = mlfq->readyThirdQ.front();
            dump += std::to_string(temp) + " -> ";
            mlfq->readyThirdQ.pop();
            mlfq->readyThirdQ.push(temp);
        }
        dump += "EndOfQ\nWaitFirstQ : ";

        /* waitQ dump */
        for (auto it : mlfq->waitFirstQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\nWaitSecondQ : ";
        for (auto it : mlfq->waitSecondQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\nWaitThirdQ : ";
        for (auto it : mlfq->waitThirdQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\n";

    } else if (sched == "CFS") {
        dump = "ReadyQ : ";

        /* readyQ dump */
        for (auto it : cfs->readyQ)
            dump += std::to_string(it.second) + " -> ";
        dump += "EndOfQ\nvruntimes : ";

        /* vruntimes hash map dump */
        for (auto it : cfs->pidVruntime)
            dump += "(PID : " + std::to_string(it.first) + ", " + std::to_string(it.second) + ")" + " -> ";
        dump += "EndOfQ\nInactiveQ : ";

        /* inactiveQ dump */
        for (int i = 0; i < cfs->inactiveQ.size(); i++) {
            pid_t temp = cfs->inactiveQ.front();
            dump += std::to_string(temp) + " -> ";
            cfs->inactiveQ.pop();
            cfs->inactiveQ.push(temp);
        }
        dump += "EndOfQ\nWaitQ : ";

        /* waitQ dump */
        for (auto it : cfs->waitQ)
            dump += std::to_string(it.first) + " -> ";
        dump += "EndOfQ\n";

    }
    return dump + '\n';
}