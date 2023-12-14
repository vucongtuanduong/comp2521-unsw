
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

#define MAX_ELEM 50

int main(void) {
	Set s = SetNew();

	for (int i = 0; i <= MAX_ELEM; i += 3) {
		SetInsert(s, i);
	}

	for (int i = 0; i <= MAX_ELEM; i += 5) {
		SetInsert(s, i);
	}

	for (int i = 0; i <= MAX_ELEM; i += 15) {
		SetDelete(s, i);
	}

	// Now all numbers between 0 and MAX_ELEM which
	// are divisible by 3 or 5, but not both, should
	// be in the set.
	for (int i = 0; i <= MAX_ELEM; i++) {
		// ^ is the xor operator
		// a ^ b is true iff one of a or b is true
		if (i % 3 == 0 ^ i % 5 == 0) {
			assert(SetContains(s, i));
		} else {
			assert(!SetContains(s, i));
		}
	}

	SetShow(s);
	printf("\n");

	SetFree(s);
}

