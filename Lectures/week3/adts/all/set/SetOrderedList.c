
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

struct set {
	struct node *elems;
	int size;
};

struct node {
	int elem;
	struct node *next;
};

static struct node *listInsert(struct node *list, int elem, bool *inserted);
static struct node *newNode(int elem);
static struct node *listDelete(struct node *list, int elem, bool *deleted);

/**
 * Creates a new empty set
 */
Set SetNew(void) {
	Set s = malloc(sizeof(struct set));
	if (s == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	s->elems = NULL;
	s->size = 0;
	return s;
}

/**
 * Frees memory used by set
 */
void SetFree(Set s) {
	struct node *curr = s->elems;
	while (curr != NULL) {
		struct node *temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(s);
}

/**
 * Inserts an element into the set
 */
void SetInsert(Set s, int elem) {
	bool inserted = false;
	s->elems = listInsert(s->elems, elem, &inserted);
	if (inserted) {
		s->size++;
	}
}

static struct node *listInsert(struct node *list, int elem, bool *inserted) {
	if (list == NULL || elem < list->elem) {
		struct node *new = newNode(elem);
		new->next = list;
		*inserted = true;
		return new;
	} else if (elem == list->elem) {
		return list;
	} else {
		list->next = listInsert(list->next, elem, inserted);
		return list;
	}
}

static struct node *newNode(int elem) {
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	new->elem = elem;
	new->next = NULL;
	return new;
}

/**
 * Deletes an element from the set
 */
void SetDelete(Set s, int elem) {
	bool deleted = false;
	s->elems = listDelete(s->elems, elem, &deleted);
	if (deleted) {
		s->size--;
	}
}

static struct node *listDelete(struct node *list, int elem, bool *deleted) {
	if (list == NULL || elem < list->elem) {
		return list;
	} else if (elem == list->elem) {
		struct node *temp = list->next;
		free(list);
		*deleted = true;
		return temp;
	} else {
		list->next = listDelete(list->next, elem, deleted);
		return list;
	}
}

/**
 * Checks if an element is in the set
 */
bool SetContains(Set s, int elem) {
	struct node *curr = s->elems;
	for (; curr != NULL && elem >= curr->elem; curr = curr->next) {
		if (curr->elem == elem) {
			return true;
		}
	}

	return false;
}

/**
 * Returns the size of the set
 */
int SetSize(Set s) {
	return s->size;
}

/**
 * Displays the set
 */
void SetShow(Set s) {
	printf("{");
	for (struct node *curr = s->elems; curr != NULL; curr = curr->next) {
		printf("%d", curr->elem);
		if (curr->next != NULL) {
			printf(",");
		}
	}
	printf("}");
}

