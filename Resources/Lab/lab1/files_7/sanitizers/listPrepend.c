// Reads in a list of values, then prints it out in reverse

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *listPrepend(struct node *list, int value);
void printList(struct node *list);
void freeList(struct node *list);

int main(void) {
	struct node *list = NULL;

	int value;
	while (scanf("%d", &value) == 1) {
		list = listPrepend(list, value);
	}

	printList(list);
	freeList(list);
}

struct node *listPrepend(struct node *list, int value) {
	struct node *n = malloc(sizeof(*n));
	if (n == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	n->value = value;

	if (list == NULL) {
		return n;
	} else {
		n->next = list;
		return n;
	}
}

void printList(struct node *list) {
	printf("[");
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		printf("%d", curr->value);
		if (curr->next != NULL) {
			printf(", ");
		}
	}
	printf("]\n");
}

void freeList(struct node *list) {
	struct node *curr = list;
	while (curr != NULL) {
		struct node *temp = curr;
		curr = curr->next;
		free(temp);
	}
}

