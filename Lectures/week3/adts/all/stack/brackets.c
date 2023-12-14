
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int getMatchingBracket(int ch);

int main(void) {
	bool balanced = true;
	Stack s = StackNew();

	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == '(' || ch == '[' || ch == '{') {
			StackPush(s, ch);
		} else if (ch == ')' || ch == ']' || ch == '}') {
			if (StackSize(s) == 0) {
				balanced = false;
				break;
			}

			int top = StackPop(s);
			if (top != getMatchingBracket(ch)) {
				balanced = false;
				break;
			}
		}
	}

	if (StackSize(s) != 0) {
		balanced = false;
	}

	StackFree(s);

	if (balanced) {
		printf("brackets are balanced!\n");
	} else {
		printf("brackets are not balanced!\n");
	}
}

int getMatchingBracket(int ch) {
	if (ch == ')') {
		return '(';
	} else if (ch == ']') {
		return '[';
	} else if (ch == '}') {
		return '{';
	} else {
		return '?';
	}
}

