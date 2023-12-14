// Implementation of the String Set ADT

#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Set.h"

#define strEQ(s, t) (strcmp((s), (t)) == 0)
#define strLT(s, t) (strcmp((s), (t)) < 0)

typedef struct node *Node;

struct node {
	char *value;
	Node next;
};

struct set {
	int size;
	Node elems;
};

static Node newNode(char *s);
static void freeNode(Node n);
static bool findNode(Node n, char *s, Node *curr, Node *prev);

Set SetNew(void) {
	Set s = malloc(sizeof(*s));
	if (s == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	s->size = 0;
	s->elems = NULL;
	return s;
}

void SetFree(Set s) {
	Node curr = s->elems;
	while (curr != NULL) {
		Node temp = curr;
		curr = curr->next;
		freeNode(temp);
	}
	free(s);
}

void SetAdd(Set s, char *str) {
	Node curr = NULL;
	Node prev = NULL;
	bool found = findNode(s->elems, str, &curr, &prev);
	if (found) {
		return; // already in Set
	}
	
	Node n = newNode(str);
	s->size++;
	if (prev == NULL) {
		n->next = s->elems;
		s->elems = n;
	} else {
		n->next = prev->next;
		prev->next = n;
	}
}

void SetRemove(Set s, char *str) {
	Node curr = NULL;
	Node prev = NULL;
	bool found = findNode(s->elems, str, &curr, &prev);
	if (!found) {
		return;
	}
	
	s->size--;
	if (prev == NULL) {
		s->elems = curr->next;
	} else {
		prev->next = curr->next;
	}
	freeNode(curr);
}

bool SetContains(Set s, char *str) {
	Node curr = NULL;
	Node prev = NULL;
	return findNode(s->elems, str, &curr, &prev);
}

int SetSize(Set s) {
	return s->size;
}

void SetShow(Set s) {
	int id = 0;
	for (Node curr = s->elems; curr != NULL; curr = curr->next) {	
		printf("[%03d] %s\n", id, curr->value);
		id++;
	}
}

static Node newNode(char *str) {
	Node n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	n->value = strdup(str);
	n->next = NULL;
	return n;
}

static void freeNode(Node n) {
	free(n->value);
	free(n);
}

// - finds where Str could be added into L
// - if already in L, curr->val == Str
// - if not already in L, curr and prev indicate where to insert
// - return value indicates whether Str found or not
static bool findNode(Node list, char *str, Node *curr, Node *prev) {
	Node cur = list;
	Node pre = NULL;
	while (cur != NULL && strLT(cur->value, str)) {
		pre = cur;
		cur = cur->next;
	}
	
	*curr = cur;
	*prev = pre;
	return (cur != NULL && strEQ(str, cur->value));
}

