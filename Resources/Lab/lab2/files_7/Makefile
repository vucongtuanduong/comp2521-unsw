# COMP2521 - Week 2 Lab

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
all: gcd rabbits listTail listMax listShift listSum listInsertOrdered listInsertNth

gcd: gcd.c
rabbits: rabbits.c
listTail: listTail.c
listMax: listMax.c
listShift: listShift.c
listSum: listSum.c
listInsertOrdered: listInsertOrdered.c
listInsertNth: listInsertNth.c

.PHONY: clean
clean:
	rm -f gcd rabbits listTail listMax listShift listSum listInsertOrdered listInsertNth

