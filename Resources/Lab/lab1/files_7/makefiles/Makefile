# COMP2521 - Week 1 Lab

# !!! DO NOT MODIFY THIS FILE !!!

CC = clang
CFLAGS = -Wall -Wvla -Werror -g

########################################################################

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

all: listAddStart mostFrequentLetter

listAddStart: listAddStart.c
	$(CC) $(CFLAGS) -o listAddStart listAddStart.c

mostFrequentLetter: mostFrequentLetter.c
	$(CC) $(CFLAGS) -o mostFrequentLetter mostFrequentLetter.c

########################################################################

clean:
	rm -f listAddStart mostFrequentLetter

