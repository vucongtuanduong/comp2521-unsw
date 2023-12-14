
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "Set.h"

struct set {
	// TODO
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

	// TODO
	return s;
}

/**
 * Frees memory used by set
 */
void SetFree(Set s) {
	// TODO
}

/**
 * Inserts an element into the set
 */
void SetInsert(Set s, int elem) {
	// TODO
}

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem) {
	// TODO
}

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem) {
	// TODO
	return false;
}

/**
 * Returns the size of the set
 */
int SetSize(Set s) {
	// TODO
	return 0;
}

/**
 * Displays the set
 */
void SetShow(Set s) {
	printf("{");
	// TODO
	printf("}");
}

