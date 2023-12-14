// Interface to the String Set ADT

#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct set *Set;

/**
 * Returns a new empty set
 */
Set  SetNew(void);

/**
 * Frees all memory associated with the given set
 */
void SetFree(Set s);

/**
 * Adds a string to the set
 */
void SetAdd(Set s, char *str);

/**
 * Removes a string from the set, if it exists
 */
void SetRemove(Set s, char *str);

/**
 * Returns true if the given string is in the set, and false otherwise
 */
bool SetContains(Set s, char *str);

/**
 * Returns the size of the set
 */
int  SetSize(Set s);

/**
 * Prints the set to stdout, one string per line
 */
void SetShow(Set s);

#endif

