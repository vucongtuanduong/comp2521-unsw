
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testCounter

testCounter: testCounter.c Counter.c HashTable.c
	$(CC) $(CFLAGS) -o testCounter testCounter.c Counter.c HashTable.c

.PHONY: clean
clean:
	rm -f testCounter

