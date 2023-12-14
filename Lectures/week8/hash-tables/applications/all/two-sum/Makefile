
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testTwoSum benchmarkTwoSum

testTwoSum: testTwoSum.c twoSum.c HashTable.c
	$(CC) $(CFLAGS) -o testTwoSum testTwoSum.c twoSum.c HashTable.c

benchmarkTwoSum: benchmarkTwoSum.c twoSum.c HashTable.c
	$(CC) $(CFLAGS) -o benchmarkTwoSum benchmarkTwoSum.c twoSum.c HashTable.c

.PHONY: clean
clean:
	rm -f testTwoSum benchmarkTwoSum

