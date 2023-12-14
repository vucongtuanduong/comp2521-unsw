
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Item.h"

#define MAX_ITEMS 100000000

////////////////////////////////////////////////////////////////////////

// Sorting algorithms
static void selectionSort(Item items[], int lo, int hi);
static void bubbleSort(Item items[], int lo, int hi);
static void insertionSort(Item items[], int lo, int hi);
static void shellSort(Item items[], int lo, int hi);
static void mergeSort(Item items[], int lo, int hi);
static void naiveQuickSort(Item items[], int lo, int hi);
static void medianOfThreeQuickSort(Item items[], int lo, int hi);
static void randomisedQuickSort(Item items[], int lo, int hi);

// Utilities
static inline void swap(Item items[], int i, int j);
static void display(Item items[], int lo, int hi);

int main(int argc, char *argv[])
{
	Item *items = malloc(MAX_ITEMS * sizeof(Item));
	if (items == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// read input
	int n = 0;
	while (n < MAX_ITEMS && read(items[n]) == 1) {
		n++;
	}

	/*
		SORT is a macro passed in through `clang -D`
		b - bubble sort
		i - insertion sort
		s - selection sort
		h - shell sort
		m - merge sort
		N - naive quick sort
		M - median of three quick sort
		R - randomised quick sort
		o - bogo sort
	*/
	switch (SORT) {
		case 's': selectionSort(items, 0, n - 1);          break;
		case 'b': bubbleSort(items, 0, n - 1);             break;
		case 'i': insertionSort(items, 0, n - 1);          break;
		case 'h': shellSort(items, 0, n - 1);              break;
		case 'm': mergeSort(items, 0, n - 1);              break;
		case 'N': naiveQuickSort(items, 0, n - 1);         break;
		case 'M': medianOfThreeQuickSort(items, 0, n - 1); break;
		case 'R':
			srand(time(NULL));
			randomisedQuickSort(items, 0, n - 1);
			break;

		default:
			fprintf(stderr, "Invalid sorting method\n");
			exit(1);
			break;
	}

	// display results
	display(items, 0, n - 1);
}

////////////////////////////////////////////////////////////////////////
// Sorting Algorithms                                                 //
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// Selection sort

static void selectionSort(Item items[], int lo, int hi)
{
	for (int i = lo; i < hi; i++) {
		int min = i;
		for (int j = i + 1; j <= hi; j++) {
			if (lt(items[j], items[min])) {
				min = j;
			}
		}
		swap(items, i, min);
	}
}

////////////////////////////////////////////////////////////////////////
// Bubble sort

static void bubbleSort(Item items[], int lo, int hi)
{
	for (int i = hi; i > lo; i--) {
		bool swapped = false;
		for (int j = lo; j < i; j++) {
			if (gt(items[j], items[j + 1])) {
				swap(items, j, j + 1);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

////////////////////////////////////////////////////////////////////////
// Insertion sort

static void insertionSort(Item items[], int lo, int hi)
{
	for (int i = lo + 1; i <= hi; i++) {
		Item item = items[i];
		int j = i;
		for (; j > lo && lt(item, items[j - 1]); j--) {
			items[j] = items[j - 1];
		}
		items[j] = item;
	}
}

////////////////////////////////////////////////////////////////////////
// Shell sort

static void shellSort(Item items[], int lo, int hi)
{
	int size = hi - lo + 1;
	int h;
	for (h = 1; h <= (size - 1) / 9; h = (3 * h) + 1);

	for (; h > 0; h /= 3) {
		for (int i = lo + h; i <= hi; i++) {
			Item item = items[i];
			int j = i;
			for (; j >= lo + h && lt(item, items[j - h]); j -= h) {
				items[j] = items[j - h];
			}
			items[j] = item;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Mergesort

static void merge(Item items[], int lo, int mid, int hi);

static void mergeSort(Item items[], int lo, int hi)
{
	if (lo >= hi) return;
	int mid = (lo + hi) / 2;
	mergeSort(items, lo, mid);
	mergeSort(items, mid + 1, hi);
	merge(items, lo, mid, hi);
}

static void merge(Item items[], int lo, int mid, int hi)
{
	Item *tmp = malloc((hi - lo + 1) * sizeof(Item));

	int i = lo;
	int j = mid + 1;
	int k = 0;

	// Scan both segments, copying to `tmp'.
	while (i <= mid && j <= hi) {
		if (le(items[i], items[j])) {
			tmp[k++] = items[i++];
		} else {
			tmp[k++] = items[j++];
		}
	}

	// Copy items from unfinished segment.
	while (i <= mid) tmp[k++] = items[i++];
	while (j <= hi) tmp[k++] = items[j++];

	// Copy `tmp' back to main array.
	for (i = lo, k = 0; i <= hi; i++, k++) {
		items[i] = tmp[k];
	}

	free(tmp);
}

////////////////////////////////////////////////////////////////////////
// Quicksort

static int partition(Item items[], int lo, int hi)
{
	Item pivot = items[lo];

	int l = lo + 1;
	int r = hi;
	while (true) {
		while (l < r && le(items[l], pivot)) l++;
		while (l < r && ge(items[r], pivot)) r--;
		if (l == r) break;
		swap(items, l, r);
	}

	if (lt(pivot, items[l])) l--;
	swap(items, lo, l);
	return l;
}

////////////////////////////////////
// Naive

static void naiveQuickSort(Item items[], int lo, int hi)
{
	if (lo >= hi) return;
	int pivotIndex = partition(items, lo, hi);
	naiveQuickSort(items, lo, pivotIndex - 1);
	naiveQuickSort(items, pivotIndex + 1, hi);
}

////////////////////////////////////
// Median of three

static void medianOfThree(Item a[], int lo, int hi);

static void medianOfThreeQuickSort(Item items[], int lo, int hi)
{
    if (lo >= hi) return;
    medianOfThree(items, lo, hi);
    int pivotIndex = partition(items, lo, hi);
    medianOfThreeQuickSort(items, lo, pivotIndex - 1);
    medianOfThreeQuickSort(items, pivotIndex + 1, hi);
}

static void medianOfThree(Item a[], int lo, int hi)
{
	int mid = (lo + hi) / 2;
	if (gt(a[lo], a[mid])) swap(a, lo, mid);
	if (gt(a[mid], a[hi])) swap(a, mid, hi);
	if (gt(a[lo], a[mid])) swap(a, lo, mid);
	swap(a, lo, mid);
}

////////////////////////////////////
// Randomised

static inline int randint(int lo, int hi);

static void randomisedQuickSort(Item items[], int lo, int hi)
{
	if (lo >= hi) return;
	swap(items, lo, randint(lo, hi));
	int pivotIndex = partition(items, lo, hi);
	randomisedQuickSort(items, lo, pivotIndex - 1);
	randomisedQuickSort(items, pivotIndex + 1, hi);
}

static inline int randint(int lo, int hi)
{
    int i = rand() % (hi - lo + 1);
    return lo + i;
}

////////////////////////////////////////////////////////////////////////
// Utilities

static inline void swap(Item items[], int i, int j)
{
    Item tmp = items[i];
    items[i] = items[j];
    items[j] = tmp;
}

static void display(Item items[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++) {
		show(items[i]);
		printf("\n");
	}
}

