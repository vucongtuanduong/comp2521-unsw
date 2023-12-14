# COMP2521 Lab Makefile

CC = gcc
CFLAGS = -Wall -Werror -pg

.PHONY: all
all: words mkwords

words: words.o HashTable.o List.o Item.o
	$(CC) $(CFLAGS) -o words words.o HashTable.o List.o Item.o

# doesn't use CFLAGS as we don't want -pg for mkwords
mkwords: mkwords.c
	$(CC) -Wall -Werror -o mkwords mkwords.c

HashTable.o: HashTable.c HashTable.h
List.o: List.c List.h
Item.o: Item.c Item.h

.PHONY: clean
clean:
	rm -f words mkwords *.o core *.dSYM gmon.out

