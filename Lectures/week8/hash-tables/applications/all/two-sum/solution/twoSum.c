
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

bool twoSum(int arr[], int size, int sum) {
	HashTable ht = HashTableNew();
	for (int i = 0; i < size; i++) {
		if (HashTableContains(ht, sum - arr[i])) {
			HashTableFree(ht);
			return true;
		}
		HashTableInsert(ht, arr[i], 0);
	}
	return false;
}

