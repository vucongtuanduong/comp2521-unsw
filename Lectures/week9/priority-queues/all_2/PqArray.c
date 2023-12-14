
#include <assert.h>
#include <stdbool.h>
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

	pq->items[pq->numItems] = (struct pqItem){
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
	int highest = 0;
	for (int i = 1; i < pq->numItems; i++) {
		if (pq->items[i].priority > pq->items[highest].priority) {
			highest = i;
		}
	}

	int item = pq->items[highest].item;
	pq->items[highest] = pq->items[pq->numItems - 1];
	pq->numItems--;
	return item;
}

int PqPeek(Pq pq) {
	if (pq->numItems == 0) {
		fprintf(stderr, "error: pq is empty\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	int highest = 0;
	for (int i = 1; i < pq->numItems; i++) {
		if (pq->items[i].priority > pq->items[highest].priority) {
			highest = i;
		}
	}
	
	return pq->items[highest].item;
}

