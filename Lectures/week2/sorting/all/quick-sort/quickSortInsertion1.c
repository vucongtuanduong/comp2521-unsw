
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Item.h"

#define MAX_ELEMS 100000000

#define THRESHOLD 10

static void quickSort(Item items[], int lo, int hi);
static int partition(Item items[], int lo, int hi);
static void insertionSort(Item items[], int lo, int hi);

// Utilities
static inline void swap(Item items[], int i, int j);
static void display(Item items[], int, int);

int main(int argc, char *argv[])
{
	Item *items = malloc(MAX_ELEMS * sizeof(Item));
	if (items == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// read input
	int n = 0;
	while (n < MAX_ELEMS && read(items[n]) == 1) {
		n++;
	}

	quickSort(items, 0, n - 1);

	// display results
	display(items, 0, n - 1);
}

////////////////////////////////////////////////////////////////////////

static void quickSort(Item items[], int lo, int hi)
{
	if (hi - lo < THRESHOLD) {
		insertionSort(items, lo, hi);
		return;
	}

	int pivotIndex = partition(items, lo, hi);
	quickSort(items, lo, pivotIndex - 1);
	quickSort(items, pivotIndex + 1, hi);
}

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

