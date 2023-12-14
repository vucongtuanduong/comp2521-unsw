
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
	return HashTableContains(s->ht, elem);
}

/**
 * Returns the size of the set
 */
int SetSize(Set s) {
	return HashTableSize(s->ht);
}

/**
 * Displays the set
 */
void SetShow(Set s) {
	printf("{");
	// If HashTableShow was implemented, it would show both keys
	// and values, which is not ideal for a set since we want to
	// show the items in the set
	HashTableShow(s->ht);
	printf("}");
}

