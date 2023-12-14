
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

int main(void) {
	Trie t = trieNew();

	trieInsert(t, "sea");
	trieInsert(t, "shell");
	trieInsert(t, "sell");
	trieInsert(t, "shore");
	//trieInsert(t, "she");

	trieShow(t);

	assert(trieSearch(t, "sea"));
	assert(trieSearch(t, "shell"));
	assert(!trieSearch(t, "she"));
	assert(!trieSearch(t, "sand"));

	trieDelete(t, "shore");
	trieShow(t);

	trieFree(t);
}

