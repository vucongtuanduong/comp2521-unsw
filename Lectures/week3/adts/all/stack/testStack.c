
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int main(void) {
	Stack s = StackNew();

	assert(StackSize(s) == 0);

	StackPush(s, 3);
	assert(StackSize(s) == 1);
	assert(StackPeek(s) == 3);

	StackPush(s, 1);
	assert(StackSize(s) == 2);
	assert(StackPeek(s) == 1);

	StackPush(s, 4);
	assert(StackSize(s) == 3);
	assert(StackPeek(s) == 4);

	assert(StackPop(s) == 4);
	assert(StackSize(s) == 2);
	assert(StackPeek(s) == 1);

	assert(StackPop(s) == 1);
	assert(StackSize(s) == 1);
	assert(StackPeek(s) == 3);

	StackPush(s, 1);
	assert(StackSize(s) == 2);
	assert(StackPeek(s) == 1);

	StackPush(s, 5);
	assert(StackSize(s) == 3);
	assert(StackPeek(s) == 5);

	assert(StackPop(s) == 5);
	assert(StackSize(s) == 2);
	assert(StackPeek(s) == 1);

	assert(StackPop(s) == 1);
	assert(StackSize(s) == 1);
	assert(StackPeek(s) == 3);

	assert(StackPop(s) == 3);
	assert(StackSize(s) == 0);

	StackFree(s);
	
	printf("Tests passed!\n");
}

