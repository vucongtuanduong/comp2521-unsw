
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasCycle(Graph g);

static bool dfsHasCycle(Graph g, Vertex v, Vertex prev, bool *visited);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	bool answer = hasCycle(g);
	printf("The graph %s a cycle\n",
			answer ? "contains" : "does not contain");

	GraphFree(g);
}

static bool hasCycle(Graph g) {
	bool *visited = calloc(g->nV, sizeof(bool));

	for (Vertex v = 0; v < g->nV; v++) {
		if (!visited[v] && dfsHasCycle(g, v, v, visited)) {
			free(visited);
			return true;
		}
	}

	free(visited);
	return false;
}

static bool dfsHasCycle(Graph g, Vertex v, Vertex prev, bool *visited) {
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (w == prev) {
			continue;
		}
		if (visited[w]) {
			printf("Found cycle going from %d to %d\n", v, w);
			return true;
		} else {
			printf("Going from %d to %d\n", v, w);
			if (dfsHasCycle(g, w, v, visited)) {
				return true;
			}
		}
	}

	return false;
}

