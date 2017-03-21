# MACRO definitions
CC = gcc

#to execute this line invoke make all
all: schedule

# schedule depends on schedule.o, fcfs.o, roundrobin.o and sjf.o
schedule: schedule.o fcfs.o roundrobin.o sjf.o
	$(CC) -o schedule schedule.o fcfs.o roundrobin.o sjf.o

# fcfs.o depends on the fcfs source file and header files
fcfs.o: fcfs.c schedule.h
	$(CC) -c fcfs.c  

# roundrobin.o depends on the roundrobin source file and header files
roundrobin.o: roundrobin.c schedule.h
	$(CC) -c roundrobin.c

# sjf.o depends on the sjf source file and header files
sjf.o: sjf.c schedule.h
	$(CC) -c sjf.c

# schedule.o depends on the schedule source file and header files
schedule.o: schedule.c schedule.h
	$(CC) -c schedule.c  

