
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
static void fixUp(struct pqItem *items, int i);
static void swap(struct pqItem *items, int i, int j);
static void fixDown(struct pqItem *items, int i, int N);

Pq PqNew(void) {
	Pq pq = malloc(sizeof(struct pq));
	if (pq == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	pq->numItems = 0;
	pq->capacity = INITIAL_CAPACITY;
	pq->items = malloc((pq->capacity + 1) * sizeof(struct pqItem));

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

	pq->numItems++;
	pq->items[pq->numItems] = (struct pqItem){
		.item = item,
		.priority = priority,
	};
	fixUp(pq->items, pq->numItems);
}

static void fixUp(struct pqItem *items, int i) {
	while (i > 1 && items[i].priority > items[i / 2].priority) {
		swap(items, i, i / 2);
		i = i / 2;
	}
}

static void swap(struct pqItem *items, int i, int j) {
	struct pqItem tmp = items[i];
	items[i] = items[j];
	items[j] = tmp;
}

static void resize(Pq pq) {
	pq->capacity *= 2;
	pq->items = realloc(pq->items, (pq->capacity + 1) * sizeof(struct pqItem));
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
	int item = pq->items[1].item;
	pq->items[1] = pq->items[pq->numItems];
	pq->numItems--;
	fixDown(pq->items, 1, pq->numItems);
	return item;
}

static void fixDown(struct pqItem *items, int i, int N) {
	while (2 * i <= N) {
		int j = 2 * i;
		if (j < N && items[j + 1].priority > items[j].priority) {
			j++;
		}
		if (items[i].priority >= items[j].priority) {
			break;
		}
		swap(items, i, j);
		i = j;
	}
}

int PqPeek(Pq pq) {
	if (pq->numItems == 0) {
		fprintf(stderr, "error: pq is empty\n");
		exit(EXIT_FAILURE);
	}

	// TODO
	return 0;
}

