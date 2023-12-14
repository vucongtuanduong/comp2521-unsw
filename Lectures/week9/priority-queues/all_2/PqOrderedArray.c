
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
	pq->numItems = 0;
	pq->capacity = INITIAL_CAPACITY;
	pq->items = malloc(pq->capacity * sizeof(struct pqItem));

	return pq;
}

void PqFree(Pq pq) {
	// TODO
	free(pq->items);
	free(pq);
}

void PqInsert(Pq pq, int item, int priority) {
	if (pq->numItems == pq->capacity) {
		resize(pq);
	}

	int i = 0;
	for (; i < pq->numItems; i++) {
		if (pq->items[i].priority >= priority) {
			break;
		}
	}

	for (int j = pq->numItems - 1; j >= i; j--) {
		pq->items[j + 1] = pq->items[j];
	}

	pq->items[i] = (struct pqItem){
		.item = item,
		.priority = priority,
	};
	pq->numItems++;
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
	int item = pq->items[pq->numItems - 1].item;
	pq->numItems--;
	return item;
}

int PqPeek(Pq pq) {
	if (pq->numItems == 0) {
		fprintf(stderr, "error: pq is empty\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	return pq->items[pq->numItems - 1].item;
}

