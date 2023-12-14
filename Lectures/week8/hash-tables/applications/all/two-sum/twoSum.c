
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

	/*
	// Note: this does not work
	HashTable ht = HashTableNew();

	for (int i = 0; i < size; i++) {
		HashTableInsert(ht, arr[i], 0);
	}

	for (int i = 0; i < size; i++) {
		if (HashTableContains(ht, sum - arr[i])) {
			HashTableFree(ht);
			return true;
		}
	}

	HashTableFree(ht);
	return false;
	*/

	/*
	// This method is inefficient (O(n^2))
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] + arr[j] == sum) {
				return true;
			}
		}
	}

	return false;
	*/
}

