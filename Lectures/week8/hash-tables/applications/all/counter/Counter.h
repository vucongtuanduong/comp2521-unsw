
#ifndef COUNTER_H
#define COUNTER_H

typedef struct counter *Counter;

Counter CounterNew(void);

void CounterFree(Counter c);

void CounterAdd(Counter c, int item);

int CounterGet(Counter c, int item);

#endif

