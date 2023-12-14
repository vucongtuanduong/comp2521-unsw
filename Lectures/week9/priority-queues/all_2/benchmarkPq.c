
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Pq.h"

#define BENCHMARK_SIZE 50000

int main(void) {
	Pq pq = PqNew();

	clock_t start;
	clock_t end;

	start = clock();
	for (int i = 1; i <= BENCHMARK_SIZE; i++) {
		PqInsert(pq, i, i);
	}
	end = clock();

	printf("Insertion of %d items took %lf seconds\n",
	       BENCHMARK_SIZE, (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for (int i = BENCHMARK_SIZE; i >= 1; i--) {
		assert(PqDelete(pq) == i);
	}
	end = clock();

	printf("Deletion of %d items took %lf seconds\n",
	       BENCHMARK_SIZE, (double)(end - start) / CLOCKS_PER_SEC);

	PqFree(pq);
}

