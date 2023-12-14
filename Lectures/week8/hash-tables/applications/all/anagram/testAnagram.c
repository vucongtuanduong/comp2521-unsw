
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool anagram(char *s, char *t);

int main(void) {
	assert(anagram("abcde", "edcba"));
	assert(!anagram("abcde", "fdcba"));
	assert(!anagram("abcde", "abcdef"));
	assert(!anagram("fedcba", "abcde"));

	assert(anagram("abacababa", "aaaaabbbc"));
	assert(!anagram("abacababa", "aaaabbbbc"));

	assert(anagram("", ""));

	printf("Tests passed!\n");
}

