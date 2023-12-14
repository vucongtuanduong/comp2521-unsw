
CC = gcc
CFLAGS = -Wall -Werror -g

.PHONY: all
all: ts tq tk tg crawl

crawl:		crawl.o url_file.o html.o Set.o Queue.o Stack.o Graph.o
crawl:		LDFLAGS	= $(shell pkg-config --libs-only-L libcurl)
crawl:		LDLIBS	= $(shell pkg-config --libs-only-l libcurl)

crawl.o:	crawl.c url_file.h html.h Set.h Queue.h Stack.h Graph.h
crawl.o:	CFLAGS	= $(shell pkg-config --cflags libcurl)
url_file.o:	url_file.c url_file.h
url_file.o:	CFLAGS	= $(shell pkg-config --cflags libcurl)
html.o:		html.c html.h

ts:		ts.o Set.o
ts.o:		ts.c Set.h
Set.o:		Set.c Set.h

tq:		tq.o Queue.o
tq.o:		tq.c Queue.h
Queue.o:	Queue.c Queue.h

tk:		tk.o Stack.o
tk.o:		tk.c Stack.h
Stack.o:	Stack.c Stack.h

tg:		tg.o Graph.o
tg.o:		tg.c Graph.h
Graph.o:	Graph.c Graph.h

.PHONY: clean
clean:
	-rm -f crawl crawl.o url_file.o html.o
	-rm -f ts ts.o Set.o
	-rm -f tq tq.o Queue.o
	-rm -f tk tk.o Stack.o
	-rm -f tg tg.o Graph.o

