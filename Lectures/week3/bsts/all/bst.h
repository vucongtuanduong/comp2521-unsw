
#ifndef BST_H
#define BST_H

#include <stdbool.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};

struct node *bstInsert(struct node *tree, int val);

bool bstSearch(struct node *tree, int val);

struct node *bstJoin(struct node *t1, struct node *t2);

struct node *bstDelete(struct node *tree, int val);

////////////////////////////////////////////////////////////////////////

void bstFree(struct node *tree);

int bstSize(struct node *tree);

int bstHeight(struct node *tree);

struct node *bstPrune(struct node *tree, int lo, int hi);

////////////////////////////////////////////////////////////////////////

void bstShow(struct node *tree);

void bstInOrder(struct node *tree);

void bstPreOrder(struct node *tree);

void bstPostOrder(struct node *tree);

////////////////////////////////////////////////////////////////////////

#endif
