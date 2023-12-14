
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Pq.h"

#define INITIAL_CAPACITY 8

struct pq {
	struct pqItem *items;
	int numItems;
	int capacity;
};

struct pqItem {
	int item;
	int priority;
};

static void resize(Pq pq);

Pq PqNew(void) {
	Pq pq = malloc(sizeof(struct pq));
	if (pq == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// TODO

	return pq;
}

void PqFree(Pq pq) {
	// TODO
}

void PqInsert(Pq pq, int item, int priority) {
	if (pq->numItems == pq->capacity) {
		resize(pq);
	}
}

static void resize(Pq pq) {
	pq->capacity *= 2;
	pq->items = realloc(pq->items, pq->capacity * sizeof(struct pqItem));
	if (pq->items == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
}

int PqDelete(Pq pq) {
	if (pq->numItems == 0) {
		fprintf(stderr, "error: pq is empty\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	return 0;
}

int PqPeek(Pq pq) {
	if (pq->numItems == 0) {
		fprintf(stderr, "error: pq is empty\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	return 0;
}

