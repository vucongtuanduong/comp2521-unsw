// Program to test the String Queue ADT

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

void randomString(char *buf);

int main(int argc, char *argv[]) {
	int N = (argc < 2) ? 20 : atoi(argv[1]);
	if (N < 20) {
		N = 20;
	}
	Queue q = QueueNew();
	int i;
	char x[50];
	for (i = 0; i < N; i++) {
		if (random() % 10 > 5) {
			if (!QueueIsEmpty(q)) {
				char *str = QueueDequeue(q);
				printf("Remove %s\n", str);
				free(str);
			}
		} else {
			randomString(x);
			QueueEnqueue(q, x);
			printf("Insert %s\n", x);
		}
		QueueShow(q);
	}
	QueueFree(q);
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

