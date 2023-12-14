// Program to test the String Set ADT

#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

void randomString(char *buf);

int main(int argc, char *argv[]) {
	int N = (argc < 2) ? 20 : atoi(argv[1]);
	if (N < 20) {
		N = 20;
	}
	Set s = SetNew();
	int i;
	char x[50];
	for (i = 0; i < N; i++) {
		randomString(x);
		SetAdd(s, x);
		printf("Insert %s\n", x);
		SetShow(s);
	}
	SetFree(s);
}

void randomString(char *buf) {
	char *choices = "abcd efgh ijkl mnop qrst uvw xyz";
	int i, n;
	n = random() % 49;
	for (i = 0; i < n; i++) {
		*buf++ = choices[random() % 32];
	}
	*buf = '\0';
}

