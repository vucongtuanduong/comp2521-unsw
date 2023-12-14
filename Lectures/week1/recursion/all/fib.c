
#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num = atoi(argv[1]);
    printf("fib(%d) = %d\n", num, fib(num));
}

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}
