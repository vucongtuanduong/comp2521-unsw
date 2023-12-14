// Reads in a line of text and finds the most frequent letter

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

#define ALPHABET_SIZE 26

char mostFrequent(char *str);

int main(void) {
	printf("Enter some text: ");

	char line[MAXLINE];
	fgets(line, MAXLINE, stdin);
	char letter = mostFrequent(line);
	printf("The most frequent letter is: %c\n", letter);
}

char mostFrequent(char *str) {
	char counts[ALPHABET_SIZE];

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			counts[str[i] - 'a']++;
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			counts[str[i] - 'A']++;
		}
	}

	int freq = 0;
	char letter = '\0';
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (counts[i] > freq) {
			freq = counts[i];
			letter = 'a' + i;
		}
	}

	return letter;
}

