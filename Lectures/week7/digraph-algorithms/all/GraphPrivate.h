// Ordinarily, these structs would be defined in Graph.c,
// but as I want to separate the functions for cycle, etc.
// into different files instead of storing them all in
// Graph.c, this .h file gives them access to graph
// internals.

#ifndef GRAPH_PRIVATE_H
#define GRAPH_PRIVATE_H

struct graph {
	int nV;
	int nE;
	struct adjNode **edges;
};

struct adjNode {
	Vertex v;
	struct adjNode *next;
};

#endif

