
---

## `Makefile`

```makefile
CC      = gcc
CFLAGS  = -O2 -Wall -Wextra -std=c11
LDFLAGS =

# Sources
COMMON  = robot.c solve.h
REC_SRC = robotrec.c
MEM_SRC = robotmem.c
DP_SRC  = robotdp.c

# Objects
COMMON_O = robot.o
REC_O    = robotrec.o
MEM_O    = robotmem.o
DP_O     = robotdp.o

.PHONY: all clean

all: robotrec robotmem robotdp

robotrec: $(COMMON_O) $(REC_O)
	$(CC) $(LDFLAGS) -o $@ $^

robotmem: $(COMMON_O) $(MEM_O)
	$(CC) $(LDFLAGS) -o $@ $^

robotdp: $(COMMON_O) $(DP_O)
	$(CC) $(LDFLAGS) -o $@ $^

robot.o: robot.c solve.h
	$(CC) $(CFLAGS) -c robot.c

robotrec.o: robotrec.c
	$(CC) $(CFLAGS) -c robotrec.c

robotmem.o: robotmem.c
	$(CC) $(CFLAGS) -c robotmem.c

robotdp.o: robotdp.c
	$(CC) $(CFLAGS) -c robotdp.c

clean:
	rm -f *.o robotrec robotmem robotdp
