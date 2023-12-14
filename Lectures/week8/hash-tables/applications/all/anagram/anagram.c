
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

static HashTable stringToHashTable(char *s);

bool anagram(char *s, char *t) {
	// TODO
	if (strlen(s) != strlen(t)) {
		return false;
	}

	HashTable ht1 = stringToHashTable(s);
	HashTable ht2 = stringToHashTable(t);

	//if (HashTableSize(ht1) != HashTableSize(ht2)) {
	//	return false;
	//}

	bool result = true;
	for (int i = 0; s[i] != '\0'; i++) {
		int count1 = HashTableGetOrDefault(ht1, s[i], 0);
		int count2 = HashTableGetOrDefault(ht2, s[i], 0);
		if (count1 != count2) {
			result = false;
			break;
		}
	}

	HashTableFree(ht1);
	HashTableFree(ht2);
	return result;
}

static HashTable stringToHashTable(char *s) {
	HashTable ht = HashTableNew();
	for (int i = 0; s[i] != '\0'; i++) {
		int count = HashTableGetOrDefault(ht, s[i], 0);
		HashTableInsert(ht, s[i], count + 1);
	}
	return ht;
}

