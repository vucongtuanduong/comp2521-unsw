
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasHamiltonianPath(Graph g);

static bool dfsHamiltonianPath(Graph g, Vertex v, bool *visited, int numVerticesLeft);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	bool answer = hasHamiltonianPath(g);
	printf("The graph %s a Hamiltonian path\n",
			answer ? "has" : "does not have");

	GraphFree(g);
}

static bool hasHamiltonianPath(Graph g) {
	bool *visited = calloc(g->nV, sizeof(bool));

	for (Vertex v = 0; v < g->nV; v++) {
		if (dfsHamiltonianPath(g, v, visited, g->nV)) {
			free(visited);
			return true;
		}
	}

	free(visited);
	return false;
}

static bool dfsHamiltonianPath(Graph g, Vertex v, bool *visited, int numVerticesLeft) {
	visited[v] = true;
	numVerticesLeft--;

	if (numVerticesLeft == 0) {
		return true;
	}

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			if (dfsHamiltonianPath(g, w, visited, numVerticesLeft)) {
				return true;
			}
		}
	}

	visited[v] = false;
	return false;
}

