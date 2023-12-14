
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

static void testQueue1(void);
static void testQueue2(void);
static void testQueue3(void);
static void testQueue4(void);
static void testQueue5(void);

int main(void) {
	testQueue1();
	testQueue2();
	testQueue3();
	testQueue4();
	testQueue5();
}

// tests general enqueueing and dequeueing
static void testQueue1(void) {
	printf("Test 1...\n");

	Queue q = QueueNew();

	// enqueue 1 to 6
	for (int i = 1; i <= 6; i++) {
		QueueEnqueue(q, i);
	}
	assert(QueueSize(q) == 6);

	// dequeue 1 to 3
	for (int j = 1; j <= 3; j++) {
		assert(QueueFront(q) == j);
		assert(QueueDequeue(q) == j);
	}
	assert(QueueSize(q) == 3);

	// enqueue 7 to 12, dequeue 4 to 9
	for (int i = 7, j = 4; i <= 12; i++, j++) {
		QueueEnqueue(q, i);
		assert(QueueFront(q) == j);
		assert(QueueDequeue(q) == j);
	}
	assert(QueueSize(q) == 3);

	QueueFree(q);

	printf("Passed!\n");
}

// tests the queue becoming empty
static void testQueue2(void) {
	printf("Test 2...\n");

	Queue q = QueueNew();

	// enqueue 1 to 6
	for (int i = 1; i <= 6; i++) {
		QueueEnqueue(q, i);
	}

	// dequeue 1 to 6
	for (int j = 1; j <= 6; j++) {
		assert(QueueDequeue(q) == j);
	}
	assert(QueueSize(q) == 0);
	assert(QueueIsEmpty(q));

	// enqueue a number
	QueueEnqueue(q, 42);
	assert(QueueFront(q) == 42);

	QueueFree(q);

	printf("Passed!\n");
}

// tests enqueueing and dequeueing at capacity
static void testQueue3(void) {
	printf("Test 3...\n");

	Queue q = QueueNew();

	// enqueue 1 to 8
	for (int i = 1; i <= 8; i++) {
		QueueEnqueue(q, i);
		assert(QueueSize(q) == i);
	}

	// dequeue 1 to 4, enqueue 9 to 12
	for (int i = 9, j = 1; i <= 12; i++, j++) {
		assert(QueueFront(q) == j);
		assert(QueueDequeue(q) == j);
		QueueEnqueue(q, i);
	}

	assert(QueueSize(q) == 8);

	QueueFree(q);

	printf("Passed!\n");
}

// tests resizing of the queue
static void testQueue4(void) {
	printf("Test 4...\n");

	Queue q = QueueNew();

	// enqueue 1 to 12
	for (int i = 1; i <= 12; i++) {
		QueueEnqueue(q, i);
	}

	// dequeue 1 to 4
	for (int j = 1; j <= 4; j++) {
		assert(QueueDequeue(q) == j);
	}

	// dequeue 5 to 40, enqueue 13 to 48
	for (int i = 13, j = 5; i <= 48; i++, j++) {
		QueueEnqueue(q, i);
		assert(QueueDequeue(q) == j);
	}

	QueueFree(q);

	printf("Passed!\n");
}

static void testQueue5(void) {
	// TODO: For you to test your CircularArrayQueue

	printf("Test 5...\n");
	printf("This is left blank for you to add your own test.\n");

	// printf("Passed!\n");
}

