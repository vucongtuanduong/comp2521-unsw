# COMP2521 - Week 9 Lab

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

TARGETS = runHashTable missing winner similar

$(TARGETS): HashTable.o

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	rm -f *.o runHashTable missing winner similar

