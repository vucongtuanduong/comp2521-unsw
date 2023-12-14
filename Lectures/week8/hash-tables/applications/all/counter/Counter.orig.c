
#include <stdio.h>
#include <stdlib.h>

#include "Counter.h"
#include "HashTable.h"

struct counter {
	// TODO
};

Counter CounterNew(void) {
	Counter c = malloc(sizeof(*c));
	if (c == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// TODO

	return c;
}

void CounterFree(Counter c) {
	// TODO
}

void CounterAdd(Counter c, int item) {
	// TODO
}

int CounterGet(Counter c, int item) {
	// TODO
	return 0;
}

