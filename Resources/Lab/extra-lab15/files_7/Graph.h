// Interface to the Directed String Graph ADT
// - Vertices are strings

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct GraphRep *Graph;

/**
 * Creates a new graph with 0 vertices that can contain up to maxV
 * vertices
 */
Graph GraphNew(int maxV);

/**
 * Frees all memory associated with the given graph
 */
void  GraphFree(Graph g);

/**
 * Adds an edge from s to t. If either vertex s or t don't exist in the
 * graph, they are added to the graph first, unless the graph is already
 * full (i.e., has the maximum number of vertices as given in GraphNew).
 * Returns false if the edge could not be added due to the graph being
 * full, and true otherwise.
 */
bool  GraphAddEdge(Graph g, char *s, char *t);

/**
 * Returns the number of vertices in the graph
 */
int   GraphNumVertices(Graph g);

/**
 * Returns true if the graph contains an edge from s to t, and false
 * otherwise
 */
bool  GraphHasEdge(Graph g, char *s, char *t);

/**
 * Displays the graph
 * When mode is 0, displays an adjacency list, otherwise displays an
 * adjacency matrix
 */
void  GraphShow(Graph g, int mode);

#endif

