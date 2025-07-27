#ifndef BFS_H
#define BFS_H
#include "matrix.h"
#include "vertex.h"

void bfs(Matrix mat, VertexList vertexList, char startName[]);
int  isNeighbor(Matrix mat, int i, int j);

#endif
