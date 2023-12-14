// Implementation of the hash table module

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

struct hashTable {

};

HashTable HashTableNew(void) {
	HashTable ht = malloc(sizeof(*ht));
	if (ht == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	return ht;
}

void HashTableFree(HashTable ht) {

}

void HashTableInsert(HashTable ht, int key) {

}

void HashTableDelete(HashTable ht, int key) {

}

bool HashTableContains(HashTable ht, int key) {
	return false;
}

int HashTableSize(HashTable ht) {
	return 0;
}

void HashTableShow(HashTable ht) {

}

