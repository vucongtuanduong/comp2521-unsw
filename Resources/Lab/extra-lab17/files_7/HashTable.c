// Implementation of the Hash Table ADT that uses separate chaining for
// collision resolution
// Written by John Shepherd, May 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"
#include "List.h"

typedef struct HashTabRep {
	List *lists;  // either use this
	int   nslots; // # elements in array
	int   nitems; // # items stored in HashTable
} HashTabRep;

// converts a key into an index (from Sedgewick)
unsigned int hash(Key k, int tableSize) {
	unsigned int h = 0;
	int a = 31415, b = 27183;
	for (; *k != '\0'; k++) {
		a = a * b % (tableSize - 1);
		h = (a * h + *k) % tableSize;
	}
	return (h % tableSize);
}

HashTable HashTableNew(int N) {
	HashTabRep *new = malloc(sizeof(HashTabRep));
	if (new == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	new->lists = malloc(N * sizeof(List));
	if (new->lists == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < N; i++) {
		new->lists[i] = ListNew();
	}
	new->nslots = N;
	new->nitems = 0;
	return new;
}

void HashTableFree(HashTable ht) {
	for (int i = 0; i < ht->nslots; i++) {
		ListFree(ht->lists[i]);
	}
	free(ht);
}

void HashTableStats(HashTable ht) {
	printf("Hash Table Stats:\n");
	printf("Number of slots = %d\n", 0); // TODO
	printf("Number of items = %d\n", 0); // TODO
	printf("Chain length distribution\n");
	printf("%8s %8s\n","Length","#Chains");

	// TODO... complete this function to show length/frequency pairs
}

void HashTableInsert(HashTable ht, Item it) {
	int i = hash(key(it), ht->nslots);
	if (ListSearch(ht->lists[i], key(it)) == NULL) {
		ListInsert(ht->lists[i], it);
		ht->nitems++;
	}
}

void HashTableDelete(HashTable ht, Key k) {
	int h = hash(k, ht->nslots);
	ListDelete(ht->lists[h], k);
}

// get Item from HashTable using Key
Item *HashTableSearch(HashTable ht, Key k) {
	int i = hash(k, ht->nslots);
	return ListSearch(ht->lists[i], k);
}

