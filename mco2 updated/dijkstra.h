#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "matrix.h"
#include "vertex.h"

void dijkstra(Matrix *mat, VertexList *vertexList,
              char srcName[], char destName[]);
#endif
