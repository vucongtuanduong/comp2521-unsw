// Interface to the String Stack ADT

#ifndef STACK_H
#define STACK_H

typedef struct stack *Stack;

#include <stdbool.h>

/**
 * Creates a new empty stack
 */
Stack StackNew(void);

/**
 * Frees all memory associated with the given stack
 */
void  StackFree(Stack s);

/**
 * Adds a string to the top of the stack
 */
void  StackPush(Stack s, char *);

/**
 * Removes a string from the top of the stack and returns it. It is
 * the caller's responsibility to free the returned string.
 * Assumes that the stack is not empty
 */
char *StackPop(Stack s);

/**
 * Returns true if the stack is empty, and false otherwise
 */
bool  StackIsEmpty(Stack s);

/**
 * Prints the stack to stdout, top to bottom, one string per line
 */
void  StackShow(Stack s);

#endif

