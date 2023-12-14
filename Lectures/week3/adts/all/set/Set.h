
#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set *Set;

/**
 * Creates a new empty set
 */
Set SetNew(void);

/**
 * Frees memory used by set
 */
void SetFree(Set s);

/**
 * Inserts an element into the set
 */
void SetInsert(Set s, int elem);

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem);

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem);

/**
 * Returns the size of the set
 */
int SetSize(Set s);

/**
 * Displays the set
 */
void SetShow(Set s);

#endif

