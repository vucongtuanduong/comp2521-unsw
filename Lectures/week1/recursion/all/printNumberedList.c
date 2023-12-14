
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void printNumberedList(struct node *list);
void doPrintNumberedList(struct node *list, int num); 
struct node *newNode(int value);
void freeList(struct node *list);

int main(void) {
    struct node *list = NULL;
    struct node *curr = NULL;

    int value = 0;
    while (scanf("%d", &value) == 1) {
        struct node *node = newNode(value);
        if (list == NULL) {
            list = node;
        } else {
            curr->next = node;
        }
        curr = node;
    }

    printNumberedList(list);
    freeList(list);
}

void printNumberedList(struct node *list) {
    doPrintNumberedList(list, 1);
}

void doPrintNumberedList(struct node *list, int num) {
    if (list == NULL) {
        return;
    } else {
        printf("%d. %d\n", num, list->value);
        doPrintNumberedList(list->next, num + 1);
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

void freeList(struct node *list) {
    struct node *curr = list;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
