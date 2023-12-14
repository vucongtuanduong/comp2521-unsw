
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Item.h"

#define MAX_ITEMS 100000000

////////////////////////////////////////////////////////////////////////

static void mergeSort(Item items[], int lo, int hi);
static void merge(Item items[], int lo, int mid, int hi);

// Utilities
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

	mergeSort(items, 0, n - 1);

	// display results
	display(items, 0, n - 1);
}

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

static void display(Item items[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++) {
		show(items[i]);
		printf("\n");
	}
}

