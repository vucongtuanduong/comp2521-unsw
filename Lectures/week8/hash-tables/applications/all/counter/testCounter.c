
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Counter.h"

#define MAX_ELEM 50

int main(void) {
	Counter c = CounterNew();

	for (int i = 0; i <= MAX_ELEM; i += 3) {
		CounterAdd(c, i);
	}
	for (int i = 0; i <= MAX_ELEM; i += 5) {
		CounterAdd(c, i);
	}

	for (int i = 0; i <= MAX_ELEM; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			assert(CounterGet(c, i) == 2);
		} else if (i % 3 == 0 || i % 5 == 0) {
			assert(CounterGet(c, i) == 1);
		} else {
			assert(CounterGet(c, i) == 0);
		}
	}
}

