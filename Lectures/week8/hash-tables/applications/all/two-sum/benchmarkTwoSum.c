
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BENCHMARK_SIZE 50000

bool twoSum(int arr[], int size, int sum);

int main(void) {
	int *arr = malloc(BENCHMARK_SIZE * sizeof(int));
	if (arr == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < BENCHMARK_SIZE; i++) {
		arr[i] = i;
	}

	twoSum(arr, BENCHMARK_SIZE, 0);
	free(arr);
}

