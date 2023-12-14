// Time this program by using the time command:
// 
// time ./timeLinearSearch <array size>

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int key);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <array size>\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int size = atoi(argv[1]);

    int *a = calloc(size, sizeof(int));

    int key = -99; // we know this won't be in the array

    linearSearch(a, size, key);

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