// Reads in values into a linked list, then deletes the first value

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct node *listDeleteFirst(struct node *list);
void printList(struct node *list);
void freeList(struct node *list);

int main(void) {
	int value;
	struct node *list = NULL;
	struct node *curr = NULL;

	while (scanf("%d", &value) == 1) {
		struct node *n = malloc(sizeof(*n));
		n->value = value;
		n->next = NULL;

		if (list == NULL) {
			list = n;
		} else {
			curr->next = n;
		}
		curr = n;
	}

	printf("List before: ");
	printList(list);
	list = listDeleteFirst(list);
	printf("List after: ");
	printList(list);

	freeList(list);
	return EXIT_SUCCESS;
}

struct node *listDeleteFirst(struct node *list) {
	if (list == NULL) {
		return NULL;
	}

	free(list);
	return list->next;
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

