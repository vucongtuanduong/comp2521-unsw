
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

#define DEFAULT_CAPACITY 64

struct set {
	int *elems;
	int size;
	int capacity;
};

static int getCeilingIndex(Set s, int elem);

/**
 * Creates a new empty set
 */
Set SetNew(void) {
	Set s = malloc(sizeof(struct set));
	if (s == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	s->elems = malloc(DEFAULT_CAPACITY * sizeof(int));
	if (s->elems == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	s->size = 0;
	s->capacity = DEFAULT_CAPACITY;
	return s;
}

/**
 * Frees memory used by set
 */
void SetFree(Set s) {
	free(s->elems);
	free(s);
}

/**
 * Inserts an element into the set
 */
void SetInsert(Set s, int elem) {
	int index = getCeilingIndex(s, elem);

	// already in set
	if (index != -1 && s->elems[index] == elem) {
		return;
	}

	if (s->size == s->capacity) {
		fprintf(stderr, "error: set is full\n");
		return;
	}

	int insertIndex = index;
	if (index == -1) {
		insertIndex = s->size;
	}

	// 
	for (int i = s->size - 1; i >= insertIndex; i--) {
		s->elems[i + 1] = s->elems[i];
	}

	s->elems[insertIndex] = elem;
	s->size++;
}

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem) {
	int index = getCeilingIndex(s, elem);

	if (index != -1 && s->elems[index] == elem) {
		for (int i = index; i < s->size - 1; i++) {
			s->elems[i] = s->elems[i + 1];
		}
		s->size--;
	}
}

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem) {
	int index = getCeilingIndex(s, elem);

	return index != -1 && s->elems[index] == elem;
}

/**
 * Returns the index of the smallest element
 * that is greater than or equal to the given element
 * or -1 if there is no such element
 */
static int getCeilingIndex(Set s, int elem) {
	int lo = 0;
	int hi = s->size - 1;
	int closest = -1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (elem < s->elems[mid]) {
			closest = mid;
			hi = mid - 1;
		} else if (elem > s->elems[mid]) {
			lo = mid + 1;
		} else {
			return mid;
		}
	}

	return closest;
}

/**
 * Returns the size of the set
 */
int SetSize(Set s) {
	return s->size;
}

/**
 * Displays the set
 */
void SetShow(Set s) {
	printf("{");
	for (int i = 0; i < s->size; i++) {
		if (i > 0) {
			printf(",");
		}
		printf("%d", s->elems[i]);
	}
	printf("}");
}

