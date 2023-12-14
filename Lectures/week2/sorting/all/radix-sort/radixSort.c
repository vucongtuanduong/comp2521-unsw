
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10000000

#define MAX_KEY_LEN 8

#define ALPHABET_SIZE 26

typedef struct item {
	char key[MAX_KEY_LEN + 1];
} Item;

struct bucket {
	Item *items;
	int size;
	int capacity;
};

void radixSort(Item items[], int numItems);

void clearBucket(struct bucket *b);
void addToBucket(struct bucket *b, Item item);

int main(void) {
	Item *items = calloc(MAX_ITEMS, sizeof(Item));
	if (items == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	int numItems = 0;

	char format[16];
	snprintf(format, sizeof(format), "%%%ds", MAX_KEY_LEN);
	while (numItems < MAX_ITEMS && scanf(format, items[numItems].key) == 1) {
		numItems++;
	}

	radixSort(items, numItems);

	for (int i = 0; i < numItems; i++) {
		printf("%s\n", items[i].key);
	}
}

void radixSort(Item items[], int numItems) {
	struct bucket *buckets = calloc(
		(ALPHABET_SIZE + 1), sizeof(struct bucket)
	);

	for (int i = MAX_KEY_LEN - 1; i >= 0; i--) {
		for (int j = 0; j <= ALPHABET_SIZE; j++) {
			clearBucket(&buckets[j]);
		}

		for (int j = 0; j < numItems; j++) {
			char ch = items[j].key[i];
			if (ch == '\0') {
				addToBucket(&buckets[0], items[j]);
			} else if (ch >= 'a' && ch <= 'z') {
				addToBucket(&buckets[ch - 'a' + 1], items[j]);
			} else {
				fprintf(stderr, "error: unexpected character '%c'\n", ch);
				exit(EXIT_FAILURE);
			}
		}

		int num = 0;
		for (int j = 0; j <= ALPHABET_SIZE; j++) {
			for (int k = 0; k < buckets[j].size; k++) {
				items[num++] = buckets[j].items[k];
			}
		}
	}

	for (int j = 0; j <= ALPHABET_SIZE; j++) {
		free(buckets[j].items);
	}
	free(buckets);
}

////////////////////////////////////////////////////////////////////////

void clearBucket(struct bucket *b) {
	b->items = realloc(b->items, 1 * sizeof(Item));
	b->size = 0;
	b->capacity = 1;
}

void addToBucket(struct bucket *b, Item item) {
	if (b->size == b->capacity) {
		b->capacity *= 2;
		b->items = realloc(b->items, b->capacity * sizeof(Item));
		if (b->items == NULL) {
			fprintf(stderr, "error: out of memory\n");
			exit(EXIT_FAILURE);
		}
	}

	b->items[b->size++] = item;
}

////////////////////////////////////////////////////////////////////////

