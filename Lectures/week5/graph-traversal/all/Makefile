
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testGraph

testGraph: testGraph.c bfs.c dfs.c Graph.c Queue.c
	$(CC) $(CFLAGS) -o testGraph testGraph.c bfs.c dfs.c Graph.c Queue.c

.PHONY: clean
clean:
	rm -f testGraph

