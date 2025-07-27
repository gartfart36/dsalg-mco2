#ifndef PATH_H
#define PATH_H
#include "matrix.h"
#include "vertex.h"

int pathExists(Matrix mat, VertexList vertexList,
               char srcName[], char destName[]);

#endif
