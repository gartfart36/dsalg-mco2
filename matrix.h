#ifndef MATRIX_H
#define MATRIX_H
#include"enums.h"
#include"vertex.h"

typedef struct {
    int arr[MAX_VALUE][MAX_VALUE];
    int size;
} Matrix;

Matrix newMatrix();
void addEdge(Matrix *mat, int i, int j, int weight);
void addVertex(Matrix *mat, VertexList *vertexList, char name[]);
void displayMatrix(Matrix mat);
#endif