#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "vertex.h"

// returns 1 if there is any path between srcName and destName
int pathExists(Matrix *mat, VertexList *vertexList,
               char srcName[], char destName[]);

#endif
