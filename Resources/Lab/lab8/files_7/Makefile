# COMP2521 - Week 8 Lab

# !!! DO NOT MODIFY THIS FILE !!!

CC = clang
CFLAGS = -Wall -Wvla -Werror -g

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

OBJS1 = testGraphMst.o Graph.o Pq.o
OBJS2 = gridPlanner.o Graph.o planner.o Pq.o

.PHONY: all
all: testGraphMst gridPlanner

testGraphMst: $(OBJS1)
	$(CC) $(CFLAGS) -o testGraphMst $(OBJS1)

gridPlanner: $(OBJS2)
	$(CC) $(CFLAGS) -o gridPlanner $(OBJS2) -lm

testGraphMst.o: testGraphMst.c Graph.h
gridPlanner.o: gridPlanner.c place.h planner.h

Graph.o: Graph.c Graph.h Pq.h
planner.o: planner.c planner.h Graph.h place.h Pq.h
Pq.o: Pq.c Pq.h Graph.h

.PHONY: clean
clean:
	rm -f testGraphMst gridPlanner $(OBJS1) $(OBJS2)

