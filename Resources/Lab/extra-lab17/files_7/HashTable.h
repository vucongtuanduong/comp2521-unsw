// Interface to the Hash Table ADT
// Written by John Shepherd, March 2013

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Item.h"

typedef struct HashTabRep *HashTable;

// Creates a new empty hash table with N slots
HashTable HashTableNew(int N);

// Frees all memory associated with the given hash table
void  HashTableFree(HashTable ht);

// Display the stats of a hash table
void  HashTableStats(HashTable ht);

// Inserts a new item into a hash table
void  HashTableInsert(HashTable ht, Item it);

// Deletes an item with the given key from a hash table
void  HashTableDelete(HashTable ht, Key k);

// Gets the item with the given key from a hash table
Item *HashTableSearch(HashTable ht, Key k);

#endif
