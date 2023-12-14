// Implementation of the Directed String Graph ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

#define strEQ(g, t) (strcmp ((g), (t)) == 0)

typedef struct GraphRep {
	int nV;
	int maxV;
	char **vertex;
	bool **edges;
} GraphRep;

static int vertexID(Graph g, char *str);
static int addVertex(Graph g, char *str);

Graph GraphNew(int maxV) {
	assert(maxV > 0);
	
	Graph g = malloc(sizeof(*g));
	if (g == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	
	g->nV = 0;
	g->maxV = maxV;
	
	g->vertex = calloc(maxV, sizeof(char *));
	if (g->vertex == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	
	g->edges = calloc(maxV, sizeof(bool *));
	if (g->edges == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < maxV; i++) {
		g->edges[i] = calloc(maxV, sizeof(bool));
		if (g->edges[i] == NULL) {
			fprintf(stderr, "error: out of memory\n");
			exit(EXIT_FAILURE);
		}
		
		for (int j = 0; j < maxV; j++) {
			g->edges[i][j] = 0;
		}
	}

	return g;
}

void GraphFree(Graph g) {
	for (size_t i = 0; i < g->nV; i++) {
		free(g->vertex[i]);
	}
	for (size_t i = 0; i < g->maxV; i++) {
		free(g->edges[i]);
	}
	
	free(g->vertex);
	free(g->edges);
	free(g);
}

bool GraphAddEdge(Graph g, char *src, char *dest) {
	int v = vertexID(g, src);
	if (v < 0) {
		if (g->nV >= g->maxV) {
			return false;
		}
		v = addVertex(g, src);
	}

	int w = vertexID(g, dest);
	if (w < 0) {
		if (g->nV >= g->maxV) {
			return false;
		}
		w = addVertex(g, dest);
	}
	
	g->edges[v][w] = true;
	return true;
}

bool GraphHasEdge(Graph g, char *src, char *dest) {
	int v = vertexID(g, src);
	int w = vertexID(g, dest);
	if (v < 0 || w < 0) {
		return false;
	}
	return g->edges[v][w];
}

int GraphNumVertices(Graph g) {
	return g->nV;
}

void GraphShow(Graph g, int mode) {
	if (g->nV == 0) {
		printf("Empty graph\n");
		return;
	}

	printf("Graph has %d vertices:\n", g->nV);
	if (mode == 0) {
		for (int i = 0; i < g->nV; i++) {
			printf("Vertex: %s\n", g->vertex[i]);
			for (int j = 0; j < g->nV; j++) {
				if (g->edges[i][j]) {
					printf("    -> %s\n", g->vertex[j]);
				}
			}
		}
	} else {
		for (int i = 0; i < g->nV; i++) {
			for (int j = 0; j < g->nV; j++) {
				printf("%d", g->edges[i][j]);
			}
			printf("\n");
		}
	}
}

static int vertexID(Graph g, char *str) {
	for (int i = 0; i < g->nV; i++) {
		if (strEQ(str, g->vertex[i])) {
			return i;
		}
	}
	return -1;
}

static int addVertex(Graph g, char *str) {
	int id = g->nV;
	g->vertex[g->nV++] = strdup(str);
	return id;
}

