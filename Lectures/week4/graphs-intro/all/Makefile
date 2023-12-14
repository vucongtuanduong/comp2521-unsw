
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: runGraphAdjList runGraphAdjMatrix runGraphArrayOfEdges

runGraphAdjList: runGraph.c GraphAdjList.c
	$(CC) $(CFLAGS) -o runGraphAdjList runGraph.c GraphAdjList.c

runGraphAdjMatrix: runGraph.c GraphAdjMatrix.c
	$(CC) $(CFLAGS) -o runGraphAdjMatrix runGraph.c GraphAdjMatrix.c

runGraphArrayOfEdges: runGraph.c GraphArrayOfEdges.c
	$(CC) $(CFLAGS) -o runGraphArrayOfEdges runGraph.c GraphArrayOfEdges.c

.PHONY: clean
clean:
	rm -f runGraphAdjList runGraphAdjMatrix runGraphArrayOfEdges

