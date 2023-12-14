
#ifndef PQ_H
#define PQ_H

typedef struct pq *Pq;

Pq PqNew(void);

void PqFree(Pq pq);

void PqInsert(Pq pq, int item, int priority);

int PqDelete(Pq pq);

int PqPeek(Pq pq);

#endif

