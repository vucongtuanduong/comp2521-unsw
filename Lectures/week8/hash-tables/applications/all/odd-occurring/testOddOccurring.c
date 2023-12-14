
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int oddOccurring(int arr[], int size);

int main(void) {
	assert(oddOccurring((int[]){4, 3, 4, 8, 8, 4}, 6) == 2);
	assert(oddOccurring((int[]){7, 2, 1, 5, 6, 9}, 6) == 6);
	assert(oddOccurring((int[]){1, 1, 3, 3, 7, 7}, 6) == 0);

	printf("Tests passed!\n");
}

