// Interface to the List ADT
// Written by John Shepherd, March 2013

#ifndef LIST_H
#define LIST_H

#include "Item.h"

typedef struct ListRep *List;

// Creates a new empty list
List  ListNew(void);

// Frees all memory associated with the given list
void  ListFree(List l);

// Displays a list as [1,2,3,...]
void  ListShow(List l);

// Adds an item to a list
void  ListInsert(List l, Item it);

// Removes an item with the given key from a list
void  ListDelete(List l, Key k);

// Returns the item in a list that has the given key
Item *ListSearch(List l, Key k);

// Gets the number of items in a list
int   ListLength(List l);

#endif

