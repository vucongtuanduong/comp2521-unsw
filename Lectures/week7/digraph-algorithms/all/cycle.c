
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasCycle(Graph g);

static bool dfsHasCycle(Graph g, Vertex v, bool *visited, bool *onStack);

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
	bool *onStack = calloc(g->nV, sizeof(bool));

	for (Vertex v = 0; v < g->nV; v++) {
		if (!visited[v] && dfsHasCycle(g, v, visited, onStack)) {
			free(visited);
			return true;
		}
	}

	free(visited);
	return false;
}

static bool dfsHasCycle(Graph g, Vertex v, bool *visited, bool *onStack) {
	visited[v] = true;
	onStack[v] = true;
	printf("Recursed into %d\n", v);

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (onStack[w]) {
			printf("%d is on the stack - cycle found!\n", w);
			return true;
		} else if (!visited[w]) {
			if (dfsHasCycle(g, w, visited, onStack)) {
				return true;
			}
		}
	}

	printf("Backtracking from %d\n", v);
	onStack[v] = false;
	return false;
}

