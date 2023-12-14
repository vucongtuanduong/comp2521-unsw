
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int key);

int main(void) {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int key = 0;
    printf("Enter key to search for: ");
    scanf("%d", &key);

    int *a = malloc(size * sizeof(int));

    printf("Enter array values: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    int result = linearSearch(a, size, key);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Did not find element %d\n", key);
    }

    free(a);
}

// Returns the index of the given key in the array if it exists,
// or -1 otherwise
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
