// Implementation of the Items data type
// Written by John Shepherd, May 2013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Item.h"

// These would normally be implemented as macros
// We implemented them as functions so that they appear in the
// profile output


Item ItemNew(char *s) {
	return strdup(s);
}

void ItemFree(Item it) {
	free(it);
}

int  ItemCmp(Key k1, Key k2) {
	return strcmp(k1, k2);
}

Item ItemGet(FILE *f) {
	char line[1000];
	if (fgets(line, 1000, f) == NULL) {
		return NULL;
	} else {
		// strip '\n'
		line[strlen(line) - 1] = '\0';
		return ItemNew(line);
	}
}

void ItemShow(Item it) {
	printf("%s", it);
}

