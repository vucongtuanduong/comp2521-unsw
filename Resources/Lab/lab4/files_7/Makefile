# COMP2521 - Week 4 Lab

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

.PHONY: all
all: runBst

runBst: runBst.o bst.o Queue.o
	$(CC) $(CFLAGS) -o runBst runBst.o bst.o Queue.o

runBst.o: runBst.c bst.h

bst.o: bst.c bst.h Queue.h
Queue.o: Queue.c Queue.h

.PHONY: clean
clean:
	rm -f *.o runBst

