// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

#define DEFAULT_CAPACITY 16

struct graph {
	int nV;
	int nE;
	struct edge *edges;
	int maxE;
};

struct edge {
	Vertex v;
	Vertex w;
};

static bool validVertex(Graph g, Vertex v);

/**
 * Returns a new graph with nV vertices
 */
Graph GraphNew(int nV) {
	Graph g = malloc(sizeof(struct graph));
	g->nV = nV;
	g->nE = 0;

	g->edges = malloc(DEFAULT_CAPACITY * sizeof(struct edge));
	g->maxE = DEFAULT_CAPACITY;
	return g;
}

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph g) {
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

	for (int i = 0; i < g->nE; i++) {
		if ((g->edges[i].v == v && g->edges[i].w == w) ||
				(g->edges[i].v == w && g->edges[i].w == v)) {
			return true;
		}
	}
	return false;
}

/**
 * Inserts an edge between v and w
 */
void GraphInsertEdge(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	if (!GraphIsAdjacent(g, v, w)) {
		if (g->nE == g->maxE) {
			g->maxE *= 2;
			g->edges = realloc(g->edges, g->maxE * sizeof(struct edge));
		}
		g->edges[g->nE] = (struct edge){v, w};
		g->nE++;
	}
}

/**
 * Removes an edge between v and w
 */
void GraphRemoveEdge(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	for (int i = 0; i < g->nE; i++) {
		if ((g->edges[i].v == v && g->edges[i].w == w) ||
				(g->edges[i].v == w && g->edges[i].w == v)) {
			g->edges[i] = g->edges[g->nE - 1];
			g->nE--;
			return;
		}
	}
}

/**
 * Returns the degree of a vertex
 */
int GraphDegree(Graph g, Vertex v) {
	assert(validVertex(g, v));

	int degree = 0;
	for (int i = 0; i < g->nE; i++) {
		if (g->edges[i].v == v || g->edges[i].w == v) {
			degree++;
		}
	}
	return degree;
}

/**
 * Displays a graph
 */
void GraphShow(Graph g) {
	printf("Number of vertices: %d\n", g->nV);
	printf("Number of edges: %d\n", g->nE);
	printf("Edges:\n");
	for (int i = 0; i < g->nE; i++) {
		printf("(%d, %d)\n", g->edges[i].v, g->edges[i].w);
	}
	printf("\n");
}

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}

