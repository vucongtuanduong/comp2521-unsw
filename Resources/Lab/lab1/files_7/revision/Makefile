# COMP2521 - Week 1 Lab

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
all: arrayShift listShift arrayInsertOrdered listInsertOrdered

arrayShift: arrayShift.c
listShift: listShift.c
arrayInsertOrdered: arrayInsertOrdered.c
listInsertOrdered: listInsertOrdered.c

########################################################################

.PHONY: clean
clean:
	rm -f arrayShift listShift arrayInsertOrdered listInsertOrdered

