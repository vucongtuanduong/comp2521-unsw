
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

#define BENCHMARK_SIZE 50000

int main(void) {
	Set s = SetNew();

	for (int i = 0; i < BENCHMARK_SIZE; i += 2) {
		SetInsert(s, i);
	}
	for (int i = 1; i < BENCHMARK_SIZE; i += 2) {
		SetInsert(s, i);
	}

	SetFree(s);
}

