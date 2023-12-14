// Interface to the hash table module

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct hashTable *HashTable;

HashTable HashTableNew(void);

void HashTableFree(HashTable ht);

void HashTableInsert(HashTable ht, int key, int value);

void HashTableDelete(HashTable ht, int key);

bool HashTableContains(HashTable ht, int key);

int HashTableGet(HashTable ht, int key);

int HashTableSize(HashTable ht);

void HashTableShow(HashTable ht);

#endif

