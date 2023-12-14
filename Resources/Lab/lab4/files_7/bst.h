// Interface to binary search tree module

// !!! DO NOT MODIFY THIS FILE !!!

#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stdio.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};

////////////////////////////////////////////////////////////////////////

// Creates a new empty BST
struct node *bstNew(void);

// Frees all the memory associated with the given BST
void bstFree(struct node *t);

// Inserts a new value into the given BST and returns the root of the
// updated BST. Does not insert duplicate values.
struct node *bstInsert(struct node *t, int val);

// Checks whether a value is in the given BST.
bool bstFind(struct node *t, int val);

// Prints a BST to the given file.
// Assumes that the file is open for writing.
void bstPrint(struct node *t, FILE *out);

// Prints a BST to stdout.
void bstShow(struct node *t);

////////////////////////////////////////////////////////////////////////

// Returns the number of leaves in the given BST
int bstNumLeaves(struct node *t);

// Returns the range of the given BST
int bstRange(struct node *t);

// Deletes all of the leaves in the given BST and returns the root of
// the updated BST
struct node *bstDeleteLeaves(struct node *t);

// Returns the value in the BST which is closest to the given value
// Assumes that the BST is not empty
int bstClosest(struct node *t, int val);

////////////////////////////////////////////////////////////////////////

// Prints the in-order traversal of the given BST
void bstInOrder(struct node *t);

// Prints the pre-order traversal of the given BST
void bstPreOrder(struct node *t);

// Prints the post-order traversal of the given BST
void bstPostOrder(struct node *t);

// Prints the level-order traversal of the given BST
void bstLevelOrder(struct node *t);

////////////////////////////////////////////////////////////////////////

#endif

