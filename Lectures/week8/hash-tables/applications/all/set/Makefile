
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testSetHash benchmarkSetHash benchmarkSetArray

testSetHash: testSet.c SetHash.c HashTable.c
	$(CC) $(CFLAGS) -o testSetHash testSet.c SetHash.c HashTable.c

benchmarkSetHash: benchmarkSet.c SetHash.c HashTable.c
	$(CC) $(CFLAGS) -o benchmarkSetHash benchmarkSet.c SetHash.c HashTable.c

benchmarkSetArray: benchmarkSet.c SetArray.c
	$(CC) $(CFLAGS) -o benchmarkSetArray benchmarkSet.c SetArray.c

.PHONY: clean
clean:
	rm -f testSetHash benchmarkSetHash benchmarkSetArray

