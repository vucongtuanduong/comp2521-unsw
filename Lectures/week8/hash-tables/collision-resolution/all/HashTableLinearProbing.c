// Implementation of the hash table module

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

#define INITIAL_CAPACITY 11

struct hashTable {
	struct slot *slots;
	int numSlots;
	int numItems;
};

struct slot {
	int key;
	int value;
	bool empty;
};

static inline unsigned int hash(int key, int N);

HashTable HashTableNew(void) {
	HashTable ht = malloc(sizeof(*ht));
	if (ht == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	ht->slots = malloc(INITIAL_CAPACITY * sizeof(struct slot));
	if (ht->slots == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < ht->numSlots; i++) {
		ht->slots[i].empty = true;
	}

	ht->numSlots = INITIAL_CAPACITY;
	ht->numItems = 0;
	return ht;
}

void HashTableFree(HashTable ht) {
	free(ht->slots);
	free(ht);
}

void HashTableInsert(HashTable ht, int key, int value) {
	// This is a task in the week 9 lab exercise!
}

void HashTableDelete(HashTable ht, int key) {
	// This is a task in the week 9 lab exercise!
}

bool HashTableContains(HashTable ht, int key) {
	int i = hash(key, ht->numSlots);

	for (int j = 0; j < ht->numSlots; j++) {
		if (ht->slots[i].empty) {
			return false;
		}
		if (ht->slots[i].key == key) {
			return true;
		}
		i = (i + 1) % ht->numSlots;
	}
	return false;
}

int HashTableGet(HashTable ht, int key) {
	int i = hash(key, ht->numSlots);

	for (int j = 0; j < ht->numSlots; j++) {
		if (ht->slots[i].empty) {
			break;
		}
		if (ht->slots[i].key == key) {
			return ht->slots[i].value;
		}
		i = (i + 1) % ht->numSlots;
	}
	
	printf("error: key %d does not exist!\n", key);
	return -1;
}

int HashTableSize(HashTable ht) {
	return ht->numItems;
}

void HashTableShow(HashTable ht) {
	// for debugging purposes
}

static inline unsigned int hash(int key, int N) {
	const unsigned int magic = 0x45d9f3b;
	unsigned int h = 1U + INT_MAX;
	h += key;
	h = ((h >> 16) ^ h) * magic;
	h = ((h >> 16) ^ h) * magic;
	h = (h >> 16) ^ h;
	return h % N;
}

