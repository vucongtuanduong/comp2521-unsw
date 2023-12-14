// Implementation of the Queue ADT

// !!! DO NOT MODIFY THIS FILE !!!

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define a if
#define b else
#define c while
#define d for
#define e return
#define f int
#define g bool
#define h void
#define i struct
#define j typedef
#define k sizeof
#define l Queue
#define m Item
#define n malloc
#define o free
#define p fprintf
#define q exit
#define r stderr
#define s FILE
#define t "error: out of memory\n"
#define u "error: queue is empty\n"

j i v {m v;i v*w;}*v;i queue{v v;v w;f x;};l QueueNew(h){l w=n(k*w);a(!w
){p(r,t);q(1);}w->v=0;w->w=0;w->x=0;e w;}h QueueFree(l w){v x=w->v;c(x){
v y=x;x=x->w;o(y);}o(w);}h QueueEnqueue(l w,m y){v x=n(k*x);a(!x){p(r,t)
;q(1);}x->v=y;x->w=0;a(!w->x)w->v=x;b w->w->w=x;w->w=x;w->x++;}m
QueueDequeue(l w){a(!w->x){p(r,u);q(1);}v x=w->v->w;m y=w->v->v;o(w->v);
w->v=x;a(!x)w->w=0;w->x--;e y;}m QueueFront(l w){a(!w->x){p(r,u);q(1);}e
w->v->v;}f QueueSize(l w){e w->x;}g QueueIsEmpty(l w){e!w->x;}h
QueueDump(l w,s*y){d(v x=w->v;x;x=x->w)p(y,"(%d, %d) ",x->v.row,x->v.col
);p(y,"\n");}
