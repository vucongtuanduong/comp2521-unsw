
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 8

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <N>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int N = atoi(argv[1]);

	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < KEY_LEN; j++) {
			putchar(rand() % 26 + 'a');
		}
		putchar('\n');
	}
}

