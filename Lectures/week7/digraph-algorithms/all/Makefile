
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: cycle

cycle: cycle.c Graph.c
	$(CC) $(CFLAGS) -o cycle cycle.c Graph.c

.PHONY: clean
clean:
	rm -f cycle

