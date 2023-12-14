// Implementation of trie module

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

typedef unsigned long long uint64;
static void doShow(Trie t, int level, uint64 arms);

Trie trieNew(void) {
	Trie t = calloc(1, sizeof(*t));
	if (t == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	return t;
}

void trieFree(Trie t) {
	if (t == NULL) {
		return;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		trieFree(t->children[i]);
	}
	free(t);
}

Trie trieInsert(Trie t, char *key) {
	if (t == NULL) {
		t = calloc(1, sizeof(*t));
	}

	if (key[0] == '\0') {
		t->finish = true;
		return t;
	}

	int i = key[0] - 'a';
	t->children[i] = trieInsert(t->children[i], &key[1]);
	return t;
}

bool trieSearch(Trie t, char *key) {
	if (t == NULL) {
		return false;
	}

	if (key[0] == '\0') {
		return t->finish;
	}

	char first = key[0];
	int i = first - 'a';
	return trieSearch(t->children[i], &key[1]);
}

Trie trieDelete(Trie t, char *key) {
	if (t == NULL) {
		return t;
	} else if (key[0] == '\0') {
		t->finish = false;
	} else {
		int i = key[0] - 'a';
		t->children[i] = trieDelete(t->children[i], &key[1]);
	}

	if (t->finish) {
		return t;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (t->children[i] != NULL) {
			return t;
		}
	}
	free(t);
	return NULL;
}

void trieShow(Trie t) {
	printf("root\n|");
	doShow(t, 0, 0);
}

static void doShow(Trie t, int level, uint64 arms) {
	if (t == NULL) return;

	printf("%s\n", t->finish ? " (finish)" : "");

	int numChildren = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (t->children[i] != NULL) {
			numChildren++;
		}
	}

	int childNo = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (t->children[i] == NULL) continue;

		childNo++;
		for (int i = 0; i < level; i++) {
			if ((1LLU << i) & arms) {
				printf("|   ");
			} else {
				printf("    ");
			}
		}
		printf("+-- ");
		printf("%c", i + 'a');
		if (childNo < numChildren) {
			arms |= (1LLU << level);
		} else {
			arms &= ~(1LLU << level);
		}
		doShow(t->children[i], level + 1, arms);
	}
}

