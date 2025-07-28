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

typedef struct {
    char uName[MAX_VALUE];
    char vName[MAX_VALUE];
    int  weight;
} GraphEdge;

// For sorting in printGraph
typedef struct { 
    char name[MAX_VALUE]; int idx; 
} SV;

Matrix newMatrix();
void   addEdge(Matrix *mat, int i, int j, int weight);
void   addVertex(Matrix *mat, VertexList *vertexList, char name[]);
int    getDegree(Matrix *mat, int idx);
int    edgeExists(Matrix *mat, int i, int j);
void   printGraph(Matrix *mat, VertexList *vertexList);

#endif
