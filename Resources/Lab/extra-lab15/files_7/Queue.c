// Implementation of the String Queue ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

typedef struct node *Node;

struct node {
	char *value;
	Node next;
};

struct queue {
	Node head;
	Node tail;
};

static Node newNode(char *s);
static void freeNode(Node n);

Queue QueueNew(void) {
	Queue q = malloc(sizeof(*q));
	if (q == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	q->head = NULL;
	q->tail = NULL;
	return q;
}

void QueueFree(Queue q) {
	Node curr = q->head;
	while (curr != NULL) {
		Node temp = curr;
		curr = curr->next;
		freeNode(temp);
	}
	free (q);
}

void QueueEnqueue(Queue q, char *s) {
	Node n = newNode(s);
	if (q->head == NULL) {
		q->head = n;
	} else {
		q->tail->next = n;
	}
	q->tail = n;
}

char *QueueDequeue(Queue q) {
	assert(q->head != NULL);
	
	char *s = q->head->value;
	Node temp = q->head;
	q->head = temp->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(temp);
	return s;
}

bool QueueIsEmpty(Queue q) {
	return (q->head == NULL);
}

void QueueShow(Queue q) {
	int id = 0;
	for (Node curr = q->head; curr != NULL; curr = curr->next) {
		printf("[%03d] %s\n", id, curr->value);
		id++;
	}
}

static Node newNode(char *s) {
	Node n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	n->value = strdup(s);
	n->next = NULL;
	return n;
}

static void freeNode(Node n) {
	free(n->value);
	free(n);
}

