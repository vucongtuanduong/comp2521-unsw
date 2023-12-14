
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool twoSum(int arr[], int size, int sum);

int main(void) {
	int arr[] = {12, 6, 3, 3, 7, 8};

	assert( twoSum(arr, 6, 13));
	assert( twoSum(arr, 6, 15));
	assert( twoSum(arr, 6, 18));
	assert(!twoSum(arr, 6, 16));
	assert(!twoSum(arr, 6,  3));
	assert( twoSum(arr, 6,  6));
	assert(!twoSum(arr, 6,  0));
	assert(!twoSum(arr, 6, 27));

	printf("Tests passed!\n");
}

