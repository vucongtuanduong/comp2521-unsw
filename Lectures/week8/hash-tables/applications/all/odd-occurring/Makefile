
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testOddOccurring

testOddOccurring: testOddOccurring.c oddOccurring.c HashTable.c
	$(CC) $(CFLAGS) -o testOddOccurring testOddOccurring.c oddOccurring.c HashTable.c

.PHONY: clean
clean:
	rm -f testOddOccurring

