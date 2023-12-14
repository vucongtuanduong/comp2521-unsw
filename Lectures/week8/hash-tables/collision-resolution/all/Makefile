
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: runChaining runLinearProbing runDoubleHashing

runChaining: runHashTable.c HashTableChaining.c
	$(CC) $(CFLAGS) -o runChaining runHashTable.c HashTableChaining.c

runLinearProbing: runHashTable.c HashTableLinearProbing.c
	$(CC) $(CFLAGS) -o runLinearProbing runHashTable.c HashTableLinearProbing.c

runDoubleHashing: runHashTable.c HashTableDoubleHashing.c
	$(CC) $(CFLAGS) -o runDoubleHashing runHashTable.c HashTableDoubleHashing.c

.PHONY: clean
clean:
	rm -f runChaining runLinearProbing runDoubleHashing

