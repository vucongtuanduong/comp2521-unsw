
#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num = atoi(argv[1]);
    printf("%d! = %d\n", num, factorial(num));
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
