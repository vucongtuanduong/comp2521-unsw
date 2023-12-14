
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: cycle components hamiltonianPath eulerPath

cycle: cycle.c Graph.c
	$(CC) $(CFLAGS) -o cycle cycle.c Graph.c

components: components.c Graph.c
	$(CC) $(CFLAGS) -o components components.c Graph.c

hamiltonianPath: hamiltonianPath.c Graph.c
	$(CC) $(CFLAGS) -o hamiltonianPath hamiltonianPath.c Graph.c

eulerPath: eulerPath.c Graph.c
	$(CC) $(CFLAGS) -o eulerPath eulerPath.c Graph.c

.PHONY: clean
clean:
	rm -f cycle components hamiltonianPath eulerPath

