
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: benchmarkArray benchmarkOrderedArray benchmarkHeap

benchmarkArray: benchmarkPq.c PqArray.c
	$(CC) $(CFLAGS) -o benchmarkArray benchmarkPq.c PqArray.c

benchmarkOrderedArray: benchmarkPq.c PqOrderedArray.c
	$(CC) $(CFLAGS) -o benchmarkOrderedArray benchmarkPq.c PqOrderedArray.c

benchmarkHeap: benchmarkPq.c PqHeap.c
	$(CC) $(CFLAGS) -o benchmarkHeap benchmarkPq.c PqHeap.c

.PHONY: clean
clean:
	rm -f benchmarkArray benchmarkOrderedArray benchmarkHeap

