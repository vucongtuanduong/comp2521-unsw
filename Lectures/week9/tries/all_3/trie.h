// Interface to trie module

#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct node *Trie;

struct node {
	struct node *children[ALPHABET_SIZE];
	bool finish;
};

/**
 * Creates a new empty trie
 */
Trie trieNew(void);

/**
 * Frees all memory allocated to the trie
 */
void trieFree(Trie t);

/**
 * Inserts a key into the trie
 * Returns the trie
 */
Trie trieInsert(Trie t, char *key);

/**
 * Returns true if the given key is in the trie, and false otherwise
 */
bool trieSearch(Trie t, char *key);

/**
 * Deletes a key from the trie if it exists
 * Returns the trie
 */
Trie trieDelete(Trie t, char *key);

/**
 * Prints the trie to stdout
 */
void trieShow(Trie t);

#endif

