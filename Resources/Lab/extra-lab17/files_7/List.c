// Implementation of the List ADT using a linked list
// Written by John Shepherd, March 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct ListNode {
	Item value;
	struct ListNode *next;
} ListNode;

typedef struct ListRep {
	ListNode *first;  // ptr to first node
	ListNode *last;   // ptr to last node
} ListRep;

List ListNew(void) {
	List l = malloc(sizeof(ListRep));
	if (l == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	l->first = NULL;
	l->last = NULL;
	return l;
}

void ListFree(List l) {
	ListNode *curr, *next;
	curr = l->first;
	while (curr != NULL) {
		next = curr->next;
		ItemFree(curr->value);
		free(curr);
		curr = next;
	}
	free(l);
}

void showList(List l) {
	ListNode *curr = l->first;
	printf("[");
	while (curr != NULL) {
		ItemShow(curr->value);
		if (curr->next != NULL) {
			printf(",");
		}
	}
	printf("]");
}

// Note: No check for duplicates
void ListInsert(List l, Item it) {
	ListNode *new = malloc(sizeof(ListNode));
	if (new == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	new->value = it;
	new->next = NULL;

	if (l->first == NULL) {
		l->first = new;
	} else {
		l->last->next = new;
	}
	l->last = new;
}

void ListDelete(List l, Key k) {
	ListNode *prev, *curr;
	prev = NULL; curr = l->first;
	while (curr != NULL) {
		if (eq(k, key(curr->value))) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL) {
		if (prev == NULL) {
			l->first = curr->next;
		} else {
			prev->next = curr->next;
		}
		free(curr);
		if (l->first == NULL) {
			l->last = NULL;
		}
	}
}

Item *ListSearch(List l, Key k) {
	ListNode *curr = l->first;
	while (curr != NULL) {
		if (eq(k, key(curr->value))) {
			return &(curr->value);
		} else {
			curr = curr->next;
		}
	}
	return NULL; // key not found
}

int ListLength(List l) {
	int n = 0;
	ListNode *curr = l->first; 
	while (curr != NULL) {
		n++;
		curr = curr->next;
	}
	return n;
}

