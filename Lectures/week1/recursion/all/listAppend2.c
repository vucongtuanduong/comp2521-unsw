
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listAppend(struct list *list, int value);
struct node *doListAppend(struct node *node, int value);
struct list *newList(void);
struct node *newNode(int value);
void printList(struct list *list);
void freeList(struct list *list);

int main(void) {
    struct list *list = newList();

    int value = 0;
    while (scanf("%d", &value) == 1) {
        listAppend(list, value);
    }

    printf("List: ");
    printList(list);
    freeList(list);
}

void listAppend(struct list *list, int value) {
    list->head = doListAppend(list->head, value);
}

struct node *doListAppend(struct node *node, int value) {
    if (node == NULL) {
        return newNode(value);
    } else {
        node->next = doListAppend(node->next, value);
        return node;
    }
}

struct list *newList(void) {
    struct list *l = malloc(sizeof(*l));
    if (l == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    l->head = NULL;
    return l;
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

void printList(struct list *list) {
    printf("[");
    for (struct node *curr = list->head; curr != NULL; curr = curr->next) {
        printf("%d", curr->value);
        if (curr->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void freeList(struct list *list) {
    struct node *curr = list->head;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}
