
#ifndef ITEM_H
#define ITEM_H

#include <string.h>

typedef struct item {
	char str[10];
} Item;

#define key(x) x.str

#define lt(x, y) (strcmp(x.str, y.str) <  0)
#define le(x, y) (strcmp(x.str, y.str) <= 0)
#define ge(x, y) (strcmp(x.str, y.str) >= 0)
#define gt(x, y) (strcmp(x.str, y.str) >  0)

#define show(x) printf("%s", (x).str)
#define read(x) scanf("%9s", (x).str)

#endif

