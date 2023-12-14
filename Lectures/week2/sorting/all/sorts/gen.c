
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100000000

static inline void swap(int items[], int i, int j);
static void giveUp(char *progName, char *message);

int main(int argc, char *argv[])
{
	char *progName = argv[0];

	if (argc < 3) {
		giveUp(progName, "Not enough arguments");
	}

	// how much data
	int N = atoi(argv[1]);
	if (N < 1) {
		giveUp(progName, "Too few items");
	} else if (N > MAX_ITEMS) {
		giveUp(progName, "Too many items");
	}

	// determine ordering
	int order;
	switch (argv[2][0]) {
		case 'A': case 'a': order = 'A'; break;
		case 'D': case 'd': order = 'D'; break;
		case 'R': case 'r': order = 'R'; break;
		default: giveUp(progName, "Invalid ordering");
	}

	// initialise random number generator
	if (argc > 3) {
		srand(atoi(argv[3]));
	} else {
		srand(time(NULL));
	}

	int *items = malloc(N * sizeof(int));
	if (items == NULL) {
		fprintf(stderr, "Error: Out of memory!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < N; i++) {
		items[i] = i + 1;
	}

	switch (order) {
		case 'A':
			break;

		case 'D':
			for (int i = 0; i < N / 2; i++) {
				swap(items, i, N - i - 1);
			}
			break;

		case 'R':
			for (int i = 1; i < N; i++) {
				int j = rand() % (i + 1);
				swap(items, i, j);
			}
			break;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", items[i]);
	}

	free(items);
}

static inline void swap(int items[], int i, int j)
{
    int tmp = items[i];
    items[i] = items[j];
    items[j] = tmp;
}

static void giveUp(char *progName, char *message)
{
	fprintf(
		stderr,
		"%s\n"
		"Usage: %s  N  A|D|R  [seed]\n"
		"       N = number of items (1-100000000)\n"
		"       A|D|R = Ascending|Descending|Random\n",
		message, progName
	);
	exit(EXIT_FAILURE);
}

