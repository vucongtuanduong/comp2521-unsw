
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testAnagram

testAnagram: testAnagram.c anagram.c HashTable.c
	$(CC) $(CFLAGS) -o testAnagram testAnagram.c anagram.c HashTable.c

.PHONY: clean
clean:
	rm -f testAnagram

