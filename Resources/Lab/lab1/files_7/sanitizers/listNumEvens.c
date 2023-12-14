
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int listNumEvens(struct node *list);
struct node *listAppend(struct node *list, int value);
struct node *newNode(int value);
void freeList(struct node *list);

int main(void) {
	struct node *list = NULL;

	int value;
	while (scanf("%d", &value) == 1) {
		list = listAppend(list, value);
	}

	printf("Number of even values: %d\n", listNumEvens(list));
	freeList(list);
}

int listNumEvens(struct node *list) {
	int count = 0;
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		if (curr->value % 2 == 0) {
			count++;
		}
	}
	return count;
}

struct node *listAppend(struct node *list, int value) {
	if (list == NULL) {
		return newNode(value);
	}

	struct node *curr = list;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode(value);
	return list;
}

struct node *newNode(int value) {
	struct node *n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	n->next = NULL;
	return n;
}

void freeList(struct node *list) {
	struct node *curr = list;
	while (curr != NULL) {
		struct node *temp = curr;
		curr = curr->next;
		free(temp);
	}
}

