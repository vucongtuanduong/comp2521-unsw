// Implementation of the hash table module

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

#define INITIAL_CAPACITY 11

#define MAX_LOAD_FACTOR 0.9

struct hashTable {
	struct slot *slots;
	int numSlots;
	int numItems;
	int hash2Mod;
};

struct slot {
	int key;
	int value;
	bool empty;
};

static int findSuitableMod(int N);
static bool isPrime(int num);

static inline unsigned int hash(int key, int N);
static inline unsigned int hash2(int key, int hash2Mod);

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

	ht->numSlots = INITIAL_CAPACITY;
	ht->numItems = 0;
	ht->hash2Mod = findSuitableMod(INITIAL_CAPACITY);
	return ht;
}

static int findSuitableMod(int N) {
	for (int i = N - 1; i >= 2; i--) {
		if (isPrime(i)) {
			return i;
		}
	}
	return 2;
}

static bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return true;
		}
	}
	return false;
}

void HashTableFree(HashTable ht) {
	free(ht->slots);
	free(ht);
}

void HashTableInsert(HashTable ht, int key, int value) {
	if (ht->numItems >= MAX_LOAD_FACTOR * ht->numSlots) {
		printf("warning: resize not implemented!\n");
	}

	int i = hash(key, ht->numSlots);
	int inc = hash2(key, ht->hash2Mod);

	for (int j = 0; j < ht->numSlots; j++) {
		if (ht->slots[i].empty) {
			ht->slots[i].key = key;
			ht->slots[i].value = value;
			ht->slots[i].empty = false;
			ht->numItems++;
			return;
		}
		if (ht->slots[i].key == key) {
			ht->slots[i].value = value;
			return;
		}

		i = (i + inc) % ht->numSlots;
	}
}

void HashTableDelete(HashTable ht, int key) {
	printf("warning: delete not implemented!\n");
}

bool HashTableContains(HashTable ht, int key) {
	int i = hash(key, ht->numSlots);
	int inc = hash2(key, ht->hash2Mod);

	for (int j = 0; j < ht->numSlots; j++) {
		if (ht->slots[i].empty) {
			return false;
		}
		if (ht->slots[i].key == key) {
			return true;
		}

		i = (i + inc) % ht->numSlots;
	}

	return false;
}

int HashTableGet(HashTable ht, int key) {
	int i = hash(key, ht->numSlots);
	int inc = hash2(key, ht->hash2Mod);

	for (int j = 0; j < ht->numSlots; j++) {
		if (ht->slots[i].empty) {
			break;
		}
		if (ht->slots[i].key == key) {
			return ht->slots[i].value;
		}

		i = (i + inc) % ht->numSlots;
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

static inline unsigned int hash2(int key, int hash2Mod) {
	return key % hash2Mod + 1;
}

