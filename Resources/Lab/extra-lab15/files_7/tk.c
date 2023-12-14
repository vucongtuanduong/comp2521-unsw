// Program to test the String Stack ADT

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

void randomString(char *buf);

int main(int argc, char *argv[]) {
	int N = (argc < 2) ? 20 : atoi(argv[1]);
	if (N < 20) {
		N = 20;
	}
	Stack s = StackNew();
	int i;
	char x[50];
	for (i = 0; i < N; i++) {
		if (random() % 10 > 5) {
			if (!StackIsEmpty(s)) {
				char *str = StackPop(s);
				printf("Remove %s\n", str);
				free(str);
			}
		} else {
			randomString(x);
			StackPush(s, x);
			printf("Insert %s\n", x);
		}
		StackShow(s);
	}
	StackFree(s);
}

void randomString(char *buf) {
	char *choices = "abcd efgh ijkl mnop qrst uvw xyz";
	int i, n;
	n = random() % 48;
	*buf++ = 'A' + random() % 26;
	for (i = 0; i < n; i++) {
		*buf++ = choices[random() % 32];
	}
	*buf = '\0';
}

