// Implementation of the hash table module

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

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

// Initial number of slots
#define INITIAL_CAPACITY 10

// The maximum load factor (i.e. the ratio size/capacity) of the table to allow
// before resizing. This is just a number that works well empirically.
#define MAX_LOAD_FACTOR 0.5

// The "index" of a key that isn't in the table.
#define MISSING_INDEX -1

static inline unsigned int hash(int key, int N);
static int getIndex(HashTable table, int key);
static void resize(HashTable table);

HashTable HashTableNew(void) {
	HashTable table = malloc(sizeof(*table));
	if (table == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	table->numItems = 0;
	table->numSlots = INITIAL_CAPACITY;
	table->slots = malloc(table->numSlots * sizeof(struct slot));
	if (table->slots == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < table->numSlots; i++) {
		table->slots[i].empty = true;
	}

	return table;
}

void HashTableFree(HashTable table) {
	free(table->slots);
	free(table);
}

/////////////////////////////////////////////////////
// ^^^ DO NOT CHANGE ANYTHING ABOVE THIS LINE! ^^^ //
/////////////////////////////////////////////////////

void HashTableInsert(HashTable table, int key, int value) {
	if (table->numItems >= table->numSlots * MAX_LOAD_FACTOR) {
		resize(table);
	}

	// TODO: Complete the rest of this function!
}

void HashTableDelete(HashTable table, int key) {
	// TODO: Complete this function!
}

/////////////////////////////////////////////////////
// vvv DO NOT CHANGE ANYTHING BELOW THIS LINE! vvv //
/////////////////////////////////////////////////////

bool HashTableContains(HashTable table, int key) {
	return getIndex(table, key) != MISSING_INDEX;
}

int HashTableGet(HashTable table, int key) {
	int i = getIndex(table, key);
	assert(i != MISSING_INDEX);
	return table->slots[i].value;
}

int HashTableGetOrDefault(HashTable table, int key, int defaultValue) {
	int i = getIndex(table, key);
	return (i != MISSING_INDEX) ? table->slots[i].value : defaultValue;
}

int HashTableSize(HashTable table) {
	return table->numItems;
}

void HashTableShow(HashTable table) {
	printf("%-5s %11s %11s\n", "index", "key", "value");
	for (int i = 0; i < table->numSlots; i++) {
		printf("%-5d ", i);
		if (table->slots[i].empty) {
			printf("%11s %11s\n", "---", "---");
		} else {
			printf("%11d %11d\n",
			       table->slots[i].key,
			       table->slots[i].value);
		}
	}
}

////////////////////////////////////////////////////////////////////////

/** Hashes an integer key. The hash is always non-negative. */
static inline unsigned int hash(int key, int N) {
	return key % N;
}

/**
 * Returns a key's index in the table, or `MISSING_INDEX` if it doesn't
 * exist.
 */
static int getIndex(HashTable table, int key) {
	int index = hash(key, table->numSlots);
	while (!table->slots[index].empty) {
		if (table->slots[index].key == key) {
			return index;
		}
		index = (index + 1) % table->numSlots;
	}

	return MISSING_INDEX;
}

/**
 * Resizes the table to accommodate more items.
 */
static void resize(HashTable table) {
	int oldNumSlots = table->numSlots;
	struct slot *oldSlots = malloc(oldNumSlots * sizeof(struct slot));
	memcpy(oldSlots, table->slots, oldNumSlots * sizeof(struct slot));

	table->numItems = 0;
	table->numSlots *= 2;
	table->slots = realloc(table->slots, table->numSlots * sizeof(struct slot));
	for (int i = 0; i < table->numSlots; i++) {
		table->slots[i].empty = true;
	}

	for (int i = 0; i < oldNumSlots; i++) {
		if (!oldSlots[i].empty) {
			HashTableInsert(table, oldSlots[i].key, oldSlots[i].value);
		}
	}

	free(oldSlots);
}

