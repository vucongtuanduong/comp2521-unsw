// Implementation of the String Stack ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

typedef struct node *Node;

struct node {
	char *value;
	Node next;
};

struct stack {
	Node head;
};

static Node newNode(char *s);
static void freeNode(Node n);

Stack StackNew(void) {
	Stack s = malloc(sizeof(*s));
	if (s == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	s->head = NULL;
	return s;
}

void StackFree(Stack s) {
	Node curr = s->head;
	while (curr != NULL) {
		Node temp = curr;
		curr = curr->next;
		freeNode(temp);
	}
	free(s);
}

void StackPush(Stack s, char *str) {
	Node n = newNode(str);
	n->next = s->head;
	s->head = n;
}

char *StackPop(Stack s) {
	assert(s->head != NULL);
	
	char *str = s->head->value;
	Node temp = s->head;
	s->head = temp->next;
	free(temp);
	return str;
}

bool StackIsEmpty(Stack s) {
	return (s->head == NULL);
}

void StackShow(Stack s) {
	int id = 0;
	for (Node curr = s->head; curr != NULL; curr = curr->next) {
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

