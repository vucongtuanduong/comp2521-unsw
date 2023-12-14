
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int key);

int main(void) {
    int size = 0;
    printf("Enter array size: ");
    scanf("%d", &size);

    int *a = malloc(size * sizeof(int));

    printf("Enter array values (must be in ascending order): ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    int key = -99;
    printf("Enter key to search for: ");
    scanf("%d", &key);

    int result = binarySearch(a, size, key);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Did not find element %d\n", key);
    }

    free(a);
}

// Returns the index of the given key in the array if it exists,
// or -1 otherwise
int binarySearch(int arr[], int size, int key) {
    int lo = 0;
    int hi = size - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (key < arr[mid]) {
            hi = mid - 1;
        } else if (key > arr[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}
