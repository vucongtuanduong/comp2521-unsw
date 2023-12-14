
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

static HashTable strToHashTable(char *s);

bool anagram(char *s, char *t) {
	// TODO
	if (strlen(s) != strlen(t)) {
		return false;
	}

	HashTable ht1 = strToHashTable(s);
	HashTable ht2 = strToHashTable(t);

	bool answer = true;
	for (int i = 0; s[i] != '\0'; i++) {
		int count1 = HashTableGet(ht1, s[i]);
		int count2 = HashTableGetOrDefault(ht2, s[i], 0);
		if (count1 != count2) {
			answer = false;
			break;
		}
	}

	HashTableFree(ht1);
	HashTableFree(ht2);
	return answer;
}

static HashTable strToHashTable(char *s) {
	HashTable ht = HashTableNew();
	for (int i = 0; s[i] != '\0'; i++) {
		int count = HashTableGetOrDefault(ht, s[i], 0);
		HashTableInsert(ht, s[i], count + 1);
	}
	return ht;
}

