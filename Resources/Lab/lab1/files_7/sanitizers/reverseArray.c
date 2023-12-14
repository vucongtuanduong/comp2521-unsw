// Reads in values, then outputs them in reverse order

#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int size);
void printArray(int *arr, int size);

int main(void) {
	printf("Enter array size: ");

	int maxVals = 0;
	if (scanf("%d", &maxVals) != 1 || maxVals < 0) {
		fprintf(stderr, "error: invalid array size\n");
	}

	int *vals = malloc(maxVals * sizeof(int));
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
	reverse(vals, numVals);
	printf("Reversed array: ");
	printArray(vals, numVals);

	free(vals);
}

// Reverses the given array
void reverse(int *arr, int size) {
	for (int i = 0; i < size / 2; i++) {
		int tmp = arr[i];
		arr[i] = arr[size - i];
		arr[size - i] = tmp;
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

