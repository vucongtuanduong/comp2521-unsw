# COMP2521 - Week 7 Lab

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
all: solveBfs solveDfs solveDfsBacktrack solveKeepLeft

solveBfs: solver.c solveBfs.c Maze.c Queue.c matrix.c
	$(CC) $(CFLAGS) solver.c solveBfs.c Maze.c Queue.c matrix.c -o solveBfs

solveDfs: solver.c solveDfs.c Maze.c Stack.c matrix.c
	$(CC) $(CFLAGS) solver.c solveDfs.c Maze.c Stack.c matrix.c -o solveDfs

solveDfsBacktrack: solver.c solveDfsBacktrack.c Maze.c matrix.c
	$(CC) $(CFLAGS) solver.c solveDfsBacktrack.c Maze.c matrix.c -o solveDfsBacktrack

solveKeepLeft: solver.c solveKeepLeft.c Maze.c matrix.c
	$(CC) $(CFLAGS) solver.c solveKeepLeft.c Maze.c matrix.c -o solveKeepLeft

.PHONY: clean
clean:
	rm -f solveBfs solveDfs solveDfsBacktrack solveKeepLeft

