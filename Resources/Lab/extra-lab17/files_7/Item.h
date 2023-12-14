// Interface to the Items data type
// Written by John Shepherd, May 2013

#ifndef ITEM_H
#define ITEM_H

typedef char *Key;

// An item consists of just the key
typedef Key Item;

#define key(it) (it)

// Creates a new item
Item ItemNew(char *s);

// Frees all memory associated with a given item
void ItemFree(Item it);

// Compares two items
// Returns a negative number if the first item is less than the second,
// a positive number if the first item is greater than the second, and
// zero if the items are equal
int  ItemCmp(Key k1, Key k2);
#define less(k1, k2) (ItemCmp(k1, k2) <  0)
#define eq(k1, k2)   (ItemCmp(k1, k2) == 0)

// Read an item from a file
Item ItemGet(FILE *f);

// Displays an item on stdout
void ItemShow(Item it);

#endif

