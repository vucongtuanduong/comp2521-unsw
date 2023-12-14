
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: travel

travel: travel.o Graph.o Queue.o
	$(CC) $(CFLAGS) -o travel travel.o Graph.o Queue.o

travel.o: travel.c Graph.h
Graph.o: Graph.c Graph.h Queue.h
Queue.o: Queue.c Queue.h

.PHONY: clean
clean:
	-rm -f *.o travel

