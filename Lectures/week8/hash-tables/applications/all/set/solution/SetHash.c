
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "Set.h"

struct set {
	HashTable ht;
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
	s->ht = HashTableNew();
	return s;
}

/**
 * Frees memory used by set
 */
void SetFree(Set s) {
	HashTableFree(s->ht);
	free(s);
}

/**
 * Inserts an element into the set
 */
void SetInsert(Set s, int elem) {
	HashTableInsert(s->ht, elem, 0);
}

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem) {
	HashTableDelete(s->ht, elem);
}

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem) {
	// TODO
	return HashTableContains(s->ht, elem);
}

/**
 * Returns the size of the set
 */
int SetSize(Set s) {
	// TODO
	return HashTableSize(s->ht);
}

/**
 * Displays the set
 */
void SetShow(Set s) {
	printf("{");
	// TODO
	printf("}");
}

