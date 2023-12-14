
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testSetArray testSetOrderedArray testSetOrderedList

testSetArray: testSet.c SetArray.c
	$(CC) $(CFLAGS) -o testSetArray testSet.c SetArray.c

testSetOrderedArray: testSet.c SetOrderedArray.c
	$(CC) $(CFLAGS) -o testSetOrderedArray testSet.c SetOrderedArray.c

testSetOrderedList: testSet.c SetOrderedList.c
	$(CC) $(CFLAGS) -o testSetOrderedList testSet.c SetOrderedList.c

.PHONY: clean
clean:
	rm -f testSetArray testSetOrderedArray testSetOrderedList

