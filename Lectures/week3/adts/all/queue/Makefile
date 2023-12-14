
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: clean
all: testQueue

testQueue: testQueue.c Queue.c

.PHONY: clean
clean:
	rm -f testQueue
