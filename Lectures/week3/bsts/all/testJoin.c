
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

static void test1(void);
static void test2(void);

int main(void) {
	test1();
	test2();
}

static void test1(void) {
	printf("======== TEST 1 =======\n\n");

	struct node *t1 = NULL;
	t1 = bstInsert(t1, 10);
	t1 = bstInsert(t1, 5);
	t1 = bstInsert(t1, 14);

	struct node *t2 = NULL;
	t2 = bstInsert(t2, 30);
	t2 = bstInsert(t2, 24);
	t2 = bstInsert(t2, 29);
	t2 = bstInsert(t2, 26);
	t2 = bstInsert(t2, 32);

	printf("t1:\n\n");
	bstShow(t1);
	printf("\n");

	printf("t2:\n\n");
	bstShow(t2);
	printf("\n");

	struct node *joined = bstJoin(t1, t2);
	printf("join(t1, t2):\n\n");
	bstShow(joined);
	printf("\n");

	bstFree(joined);
}

static void test2(void) {
	printf("======== TEST 2 =======\n\n");

	struct node *t1 = NULL;
	t1 = bstInsert(t1, 10);
	t1 = bstInsert(t1, 5);
	t1 = bstInsert(t1, 14);

	struct node *t2 = NULL;
	t2 = bstInsert(t2, 24);
	t2 = bstInsert(t2, 29);
	t2 = bstInsert(t2, 30);
	t2 = bstInsert(t2, 32);

	printf("t1:\n\n");
	bstShow(t1);
	printf("\n");

	printf("t2:\n\n");
	bstShow(t2);
	printf("\n");

	struct node *joined = bstJoin(t1, t2);
	printf("join(t1, t2):\n\n");
	bstShow(joined);
	printf("\n");

	bstFree(joined);
}
