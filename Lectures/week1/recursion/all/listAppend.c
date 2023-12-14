
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *listAppend(struct node *list, int value);
struct node *newNode(int value);
void printList(struct node *list);
void freeList(struct node *list);

int main(void) {
    struct node *list = NULL;

    int value = 0;
    while (scanf("%d", &value) == 1) {
        list = listAppend(list, value);
    }

    printf("List: ");
    printList(list);
    freeList(list);
}

struct node *listAppend(struct node *list, int value) {
    if (list == NULL) {
        return newNode(value);
    } else {
        list->next = listAppend(list->next, value);
        return list;
    }
}

struct node *newNode(int value) {
    struct node *n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    n->value = value;
    n->next = NULL;
    return n;
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
