#include <stdio.h>
#include <string.h>
#include "matrix.h"

// create a new Matrix with size=0, empty adjacency, empty inputs
Matrix newMatrix() {
    Matrix m;
    m.size = 0;
    m.inputCount = 0;
    for (int i = 0; i < MAX_VALUE; i++)
        for (int j = 0; j < MAX_VALUE; j++)
            m.arr[i][j] = 0;
    return m;
}

// add an undirected edge (i,j) with weight; save to inputs in order
void addEdge(Matrix *mat, int i, int j, int weight) {
    mat->inputs[mat->inputCount] = (EdgeInput){i,j,weight};
    mat->inputCount++;
    mat->arr[i][j] = weight;
    mat->arr[j][i] = weight;
}

// add a vertex name and increment size
void addVertex(Matrix *mat, VertexList *vl, char name[]) {
    addVertexToList(vl, name);
    mat->size++;
}

// print the adjacency matrix as a grid with indices
void displayMatrix(Matrix *mat) {
    printf("   ");
    for (int i = 0; i < mat->size; i++) printf(" %2d", i);
    printf("\n");
    for (int i = 0; i < mat->size; i++) {
        printf("%2d:", i);
        for (int j = 0; j < mat->size; j++)
            printf(" %2d", mat->arr[i][j]);
        printf("\n");
    }
}

// count nonzero entries in row idx
int getDegree(Matrix *mat, int idx) {
    int deg = 0;
    for (int j = 0; j < mat->size; j++)
        if (mat->arr[idx][j] != 0) deg++;
    return deg;
}

// return 1 if mat.arr[i][j] != 0, else 0
int edgeExists(Matrix *mat, int i, int j) {
    return (mat->arr[i][j] != 0);
}
