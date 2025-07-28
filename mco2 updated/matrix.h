#ifndef MATRIX_H
#define MATRIX_H
#include "enums.h"
#include "vertex.h"

// Track input edges for MST in insertion order
typedef struct {
    int u, v, w;
} EdgeInput;

// Adjacency matrix representation
typedef struct {
    int        arr[MAX_VALUE][MAX_VALUE];
    int        size;
    EdgeInput  inputs[MAX_VALUE];
    int        inputCount;
} Matrix;

Matrix newMatrix();
void   addEdge(Matrix *mat, int i, int j, int weight);
void   addVertex(Matrix *mat, VertexList *vertexList, char name[]);
void   displayMatrix(Matrix *mat);
int    getDegree(Matrix *mat, int idx);
int    edgeExists(Matrix *mat, int i, int j);

#endif
