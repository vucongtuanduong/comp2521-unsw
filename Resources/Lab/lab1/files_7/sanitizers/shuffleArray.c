// Reads in values, then outputs them in random order

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int size);
void printArray(int *arr, int size);

int main(void) {
	srand(time(NULL));

	printf("Enter array size: ");

	int maxVals = 0;
	if (scanf("%d", &maxVals) != 1 || maxVals < 0) {
		fprintf(stderr, "error: invalid array size\n");
	}

	int *vals = malloc(maxVals);
	if (vals == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter array values: ");
	int numVals = 0;
	while (numVals < maxVals && scanf("%d", &vals[numVals]) == 1) {
		numVals++;
	}

	printf("Original array: ");
	printArray(vals, numVals);
	shuffle(vals, numVals);
	printf("Shuffled array: ");
	printArray(vals, numVals);

	free(vals);
}

// Randomly shuffles the given array
void shuffle(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}

// Prints the given array
void printArray(int *arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		if (i > 0) {
			printf(", ");
		}
		printf("%d", arr[i]);
	}
	printf("]\n");
}

