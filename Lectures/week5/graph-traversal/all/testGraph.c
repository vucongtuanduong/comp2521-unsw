
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void bfs(Graph g, Vertex v);
void findPathBfs(Graph g, Vertex src, Vertex dest);
void dfs(Graph g, Vertex v);

int main(int argc, char *argv[]) {
	Graph g = GraphNew(10);

	GraphInsertEdge(g, 0, 1);
	GraphInsertEdge(g, 0, 2);
	GraphInsertEdge(g, 0, 5);
	GraphInsertEdge(g, 1, 5);
	GraphInsertEdge(g, 2, 3);
	GraphInsertEdge(g, 3, 4);
	GraphInsertEdge(g, 3, 5);
	GraphInsertEdge(g, 4, 5);
	GraphInsertEdge(g, 4, 7);
	GraphInsertEdge(g, 4, 8);
	GraphInsertEdge(g, 5, 6);
	GraphInsertEdge(g, 5, 7);
	GraphInsertEdge(g, 7, 8);
	GraphInsertEdge(g, 7, 9);
	GraphInsertEdge(g, 8, 9);

	bfs(g, 0);

	//findPathBfs(g, 0, 8);

	//dfs(g, 0);

	GraphFree(g);
}

