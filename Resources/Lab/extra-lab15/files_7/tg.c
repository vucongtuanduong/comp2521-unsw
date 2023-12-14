// Program to test the String Graph ADT

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void randomString(char *buf);

int main(int argc, char *argv[]) {
	int N = (argc < 2) ? 10 : atoi(argv[1]);
	if (N < 20) {
		N = 20;
	}
	int i, a, b;
	char x[10][20];
	for (i = 0; i < 10; i++) {
		randomString(x[i]);
	}
	
	Graph g = GraphNew(10);
	for (i = 0; i < N; i++) {
		a = random() % 10;
		b = random() % 10;
		GraphAddEdge(g, x[a], x[b]);
		printf("Added %s -> %s\n", x[a], x[b]);
		GraphShow(g, 0);
	}
	GraphFree(g);
}

void randomString(char *buf) {
	char *choices = "abcd efgh ijkl mnop qrst uvw xyz";
	int i, n;
	n = random() % 10;
	*buf++ = 'A' + random() % 26;
	for (i = 0; i < n; i++) {
		*buf++ = choices[random() % 32];
	}
	*buf = '\0';
}

