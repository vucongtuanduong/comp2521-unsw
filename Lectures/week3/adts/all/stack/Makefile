
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testStack brackets

testStack: testStack.c Stack.c
brackets: brackets.c Stack.c

.PHONY: clean
clean:
	rm -f testStack brackets
