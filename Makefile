CXX=g++
CXXFLAGS=-std=c++14
OBJS=main.o Process.o Scheduler.o FIFO.o RR.o MLQ.o MLFQ.o CFS.o

ifeq ($(OS), Windows_NT)
	TARGET=2022-os-proj1.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		TARGET=2022-os-proj1.out
	endif
	ifeq ($(UNAME_S), Darwin)
		TARGET=2022-os-proj1
	endif
endif

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS)

main.o : main.h Scheduler.h Process.h main.cpp
Process.o : Process.h Process.cpp
Scheduler.o : Scheduler.h FIFO.h RR.h MLQ.h MLFQ.h CFS.h Scheduler.cpp
FIFO.o : FIFO.h FIFO.cpp
RR.o : RR.h RR.cpp
MLQ.o : MLQ.h MLQ.cpp
MLFQ.o : MLFQ.h MLFQ.cpp
CFS.o : CFS.h CFS.cpp

clean :
	rm -f *.o $(TARGET)