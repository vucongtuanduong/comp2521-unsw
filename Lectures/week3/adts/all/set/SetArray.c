
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
	if (SetContains(s, elem)) {
		return;
	}

	if (s->size == s->capacity) {
		fprintf(stderr, "error: set is full\n");
		return;
	}

	s->elems[s->size] = elem;
	s->size++;
}

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem) {
	for (int i = 0; i < s->size; i++) {
		if (s->elems[i] == elem) {
			s->elems[i] = s->elems[s->size - 1];
			s->size--;
			return;
		}
	}
}

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem) {
	for (int i = 0; i < s->size; i++) {
		if (s->elems[i] == elem) {
			return true;
		}
	}

	return false;
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

