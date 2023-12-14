
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static int *components(Graph g);

static void dfsComponents(Graph g, Vertex v, int *componentOf, int compNo);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	int *componentOf = components(g);
	for (Vertex v = 0; v < g->nV; v++) {
		printf("componentOf[%d]: %d\n", v, componentOf[v]);
	}

	free(componentOf);
	GraphFree(g);
}

static int *components(Graph g) {
	int *componentOf = malloc(g->nV * sizeof(int));
	for (Vertex v = 0; v < g->nV; v++) {
		componentOf[v] = -1;
	}

	int compNo = 0;
	for (Vertex v = 0; v < g->nV; v++) {
		if (componentOf[v] == -1) {
			dfsComponents(g, v, componentOf, compNo);
			compNo++;
		}
	}

	return componentOf;
}

static void dfsComponents(Graph g, Vertex v, int *componentOf, int compNo) {
	componentOf[v] = compNo;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (componentOf[w] == -1) {
			dfsComponents(g, w, componentOf, compNo);
		}
	}
}

