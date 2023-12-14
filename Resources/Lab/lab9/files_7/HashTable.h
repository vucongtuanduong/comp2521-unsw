// Interface to the hash table module

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct hashTable *HashTable;

/**
 * Creates a new empty hash table
 */
HashTable HashTableNew(void);

/**
 * Frees all memory associated with the hash table
 */
void HashTableFree(HashTable table);

/**
 * Inserts a key-value pair into the hash table. If the key already
 * exists, the existing value is replaced with the given value.
 */
void HashTableInsert(HashTable table, int key, int value);

/**
 * Deletes a key-value pair from the hash table, if it exists
 */
void HashTableDelete(HashTable table, int key);

/**
 * Returns true if the hash table contains the given key, and false
 * otherwise
 */
bool HashTableContains(HashTable table, int key);

/**
 * Gets the value for a certain key in the hash table.
 * Assumes that the key exists.
 */
int HashTableGet(HashTable table, int key);

/**
 * Gets the value for a certain key in the hash table. If the key does
 * not exist, then the supplied default value is returned instead.
 */
int HashTableGetOrDefault(HashTable table, int key, int defaultValue);

/**
 * Returns the number of key-value pairs in the hash table
 */
int HashTableSize(HashTable table);

/**
 * Displays the hash table on stdout
 */
void HashTableShow(HashTable table);

#endif // HASH_TABLE_H

