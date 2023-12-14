
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

void predict(Trie t, char *keypad[], char *keyPresses);
void doPredict(Trie t, char *keypad[], char *keyPresses, char key[], int i);

int main(void) {
	char *keypad[] = {
		[0] = "",
		[1] = "",
		[2] = "abc",
		[3] = "def",
		[4] = "ghi",
		[5] = "jkl",
		[6] = "mno",
		[7] = "pqrs",
		[8] = "tuv",
		[9] = "wxyz",
	};

	Trie t = trieNew();
	char *keys[] = {
		"hive", "five", "goop", "good", "gold",
		"home", "hood", "hoof", "horn", "hoop",
		"mood", "goodie"
	};
	for (int i = 0; i < 12; i++) {
		trieInsert(t, keys[i]);
	}

	predict(t, keypad, "4663");

	trieFree(t);
}

void predict(Trie t, char *keypad[], char *keyPresses) {
	char key[100] = {0};
	int i = 0;
	doPredict(t, keypad, keyPresses, key, i);
}

void doPredict(Trie t, char *keypad[], char *keyPresses, char key[], int i) {
	if (t == NULL) {
		return;
	}
	if (keyPresses[0] == '\0') {
		if (t->finish) {
			printf("%s\n", key);
		}
		return;
	}
	
	char keyPress = keyPresses[0];
	int keyPadIndex = keyPress - '0';

	for (int j = 0; keypad[keyPadIndex][j] != '\0'; j++) {
		char c = keypad[keyPadIndex][j];
		key[i] = c;
		doPredict(t->children[c - 'a'], keypad, &keyPresses[1], key, i + 1);
	}
}

