
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(void) {
	Queue q = QueueNew();

	assert(QueueSize(q) == 0);

	QueueEnqueue(q, 3);
	assert(QueueSize(q) == 1);

	QueueEnqueue(q, 1);
	assert(QueueSize(q) == 2);

	QueueEnqueue(q, 4);
	assert(QueueSize(q) == 3);
	assert(QueuePeek(q) == 3);

	assert(QueueDequeue(q) == 3);
	assert(QueueSize(q) == 2);
	assert(QueuePeek(q) == 1);

	assert(QueueDequeue(q) == 1);
	assert(QueueSize(q) == 1);
	assert(QueuePeek(q) == 4);

	QueueEnqueue(q, 1);
	assert(QueueSize(q) == 2);

	QueueEnqueue(q, 5);
	assert(QueueSize(q) == 3);

	assert(QueueDequeue(q) == 4);
	assert(QueueSize(q) == 2);
	assert(QueuePeek(q) == 1);

	assert(QueueDequeue(q) == 1);
	assert(QueueSize(q) == 1);
	assert(QueuePeek(q) == 5);

	assert(QueueDequeue(q) == 5);
	assert(QueueSize(q) == 0);

	QueueFree(q);

	printf("Tests passed!\n");
}

