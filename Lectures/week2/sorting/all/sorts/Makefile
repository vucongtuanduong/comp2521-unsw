
CC = clang
CFLAGS = -Wall -Werror

all: gen \
     selectionSort bubbleSort insertionSort shellSort mergeSort \
     naiveQuickSort medianOfThreeQuickSort randomisedQuickSort

gen: gen.c
	$(CC) $(CFLAGS) -o gen gen.c

selectionSort: sorter.c
	$(CC) "-DSORT='s'" $(CFLAGS) -o selectionSort sorter.c

bubbleSort: sorter.c
	$(CC) "-DSORT='b'" $(CFLAGS) -o bubbleSort sorter.c

insertionSort: sorter.c
	$(CC) "-DSORT='i'" $(CFLAGS) -o insertionSort sorter.c

shellSort: sorter.c
	$(CC) "-DSORT='h'" $(CFLAGS) -o shellSort sorter.c

mergeSort: sorter.c
	$(CC) "-DSORT='m'" $(CFLAGS) -o mergeSort sorter.c

naiveQuickSort: sorter.c
	$(CC) "-DSORT='N'" $(CFLAGS) -o naiveQuickSort sorter.c

medianOfThreeQuickSort: sorter.c
	$(CC) "-DSORT='M'" $(CFLAGS) -o medianOfThreeQuickSort sorter.c

randomisedQuickSort: sorter.c
	$(CC) "-DSORT='R'" $(CFLAGS) -o randomisedQuickSort sorter.c

clean:
	rm -f gen \
	      selectionSort bubbleSort insertionSort shellSort mergeSort \
	      naiveQuickSort medianOfThreeQuickSort randomisedQuickSort

