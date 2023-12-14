
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int listSum(struct node *list);
struct node *newNode(int value);
void printList(struct node *list);
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

    printf("List: ");
    printList(list);

    printf("Sum: %d\n", listSum(list));

    freeList(list);
}

int listSum(struct node *list) {
    if (list == NULL) {
        return 0;
    } else {
        return list->value + listSum(list->next);
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
