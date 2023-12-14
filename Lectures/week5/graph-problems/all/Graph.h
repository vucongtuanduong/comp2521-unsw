// Interface to the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdio.h>

typedef struct graph *Graph;

typedef int Vertex;

/**
 * Returns a new graph with nV vertices
 */
Graph GraphNew(int nV);

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph g);

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph g);

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph g);

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w);

/**
 * Adds an edge between v and w
 */
void GraphInsertEdge(Graph g, Vertex v, Vertex w);

/**
 * Displays a graph
 */
void GraphShow(Graph g);

/**
 * Reads a graph from the given file
 * Assumes that the file is open for reading
 */
Graph GraphRead(FILE *in);

#endif

