// Interface to the String Queue ADT

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue *Queue;

/**
 * Creates a new empty queue
 */
Queue QueueNew(void);

/**
 * Frees all memory associated with the given queue
 */
void  QueueFree(Queue q);

/**
 * Adds a string to the end of the queue
 */
void  QueueEnqueue(Queue q, char *s);

/**
 * Removes a string from the front of the queue and returns it. It is
 * the caller's responsibility to free the returned string.
 * Assumes that the queue is not empty
 */
char *QueueDequeue(Queue q);

/**
 * Returns true if the queue is empty, and false otherwise
 */
bool  QueueIsEmpty(Queue q);

/**
 * Prints the queue to stdout, front to back, one string per line
 */
void  QueueShow(Queue q);

#endif

