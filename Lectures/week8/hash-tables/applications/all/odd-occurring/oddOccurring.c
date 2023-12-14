
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

int oddOccurring(int arr[], int size) {
	HashTable ht = HashTableNew();
	for (int i = 0; i < size; i++) {
		int count = HashTableGetOrDefault(ht, arr[i], 0);
		HashTableInsert(ht, arr[i], count + 1);
	}

	int numOddOccurring = 0;
	for (int i = 0; i < size; i++) {
		int count = HashTableGetOrDefault(ht, arr[i], 0);
		if (count % 2 == 1) {
			numOddOccurring++;
			HashTableDelete(ht, arr[i]);
		}
	}
	return numOddOccurring;
}

