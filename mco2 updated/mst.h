#ifndef MST_H
#define MST_H
#include "matrix.h"
#include "vertex.h"

typedef struct {
    char uName[MAX_VALUE];
    char vName[MAX_VALUE];
    int  weight;
} MSTEdge;

void mst(Matrix *mat, VertexList *vertexList);
#endif
