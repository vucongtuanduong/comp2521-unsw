// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool validVertex(Graph g, Vertex v);

static bool doFindEdge(struct adjNode *list, Vertex v);
static struct adjNode *doInsertEdge(struct adjNode *list, Vertex v);

/**
 * Returns a new graph with nV vertices
 */
Graph GraphNew(int nV) {
	Graph g = malloc(sizeof(struct graph));
	g->edges = calloc(nV, sizeof(struct adjNode *));
	g->nV = nV;
	g->nE = 0;
	return g;
}

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph g) {
	for (int i = 0; i < g->nV; i++) {
		struct adjNode *curr = g->edges[i];
		while (curr != NULL) {
			struct adjNode *temp = curr;
			curr = curr->next;
			free(temp);
		}
	}
	free(g->edges);
	free(g);
}

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph g) {
	return g->nV;
}

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph g) {
	return g->nE;
}

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	return doFindEdge(g->edges[v], w);
}

static bool doFindEdge(struct adjNode *list, Vertex v) {
	if (list == NULL || v < list->v) {
		return false;
	} else if (v == list->v) {
		return true;
	} else {
		return doFindEdge(list->next, v);
	}
}

/**
 * Inserts an edge between v and w
 */
void GraphInsertEdge(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	if (!GraphIsAdjacent(g, v, w)) {
		g->edges[v] = doInsertEdge(g->edges[v], w);
		g->edges[w] = doInsertEdge(g->edges[w], v);
		g->nE++;
	}
}

static struct adjNode *doInsertEdge(struct adjNode *list, Vertex v) {
	if (list == NULL || v < list->v) {
		struct adjNode *n = malloc(sizeof(struct adjNode));
		n->v = v;
		n->next = list;
		return n;
	} else if (v == list->v) {
		return list;
	} else {
		list->next = doInsertEdge(list->next, v);
		return list;
	}
}

/**
 * Displays a graph
 */
void GraphShow(Graph g) {
	printf("Number of vertices: %d\n", g->nV);
	printf("Number of edges: %d\n", g->nE);
	printf("Edges:\n");
	for (int i = 0; i < g->nV; i++) {
		printf("%2d:", i);
		for (struct adjNode *curr = g->edges[i]; curr != NULL; curr = curr->next) {
			printf(" %d", curr->v);
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * Reads a graph from the given file
 * Assumes that the file is open for reading
 */
Graph GraphRead(FILE *in) {
	int nV = 0;
	if (fscanf(in, "%d", &nV) != 1) {
		fprintf(stderr, "error: failed to read number of vertices\n");
		exit(EXIT_FAILURE);
	}

	Graph g = GraphNew(nV);

	int v = 0;
	int w = 0;
	while (fscanf(in, "%d %d", &v, &w) == 2) {
		GraphInsertEdge(g, v, w);
	}

	return g;
}

static bool validVertex(Graph g, Vertex v) {
	return v >= 0 && v < g->nV;
}

