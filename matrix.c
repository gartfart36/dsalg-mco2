#include<stdio.h>
#include<string.h>
#include"matrix.h"

Matrix 
newMatrix() {
    Matrix matrix;
    matrix.size = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < MAX_VALUE; j++) {
            matrix.arr[i][j] = 0;
        }
    }
    return matrix;
}

void 
addEdge(Matrix *mat, int i, int j, int weight) {
    mat->arr[i][j] = weight;
    mat->arr[j][i] = weight;
}

void 
addVertex(Matrix *mat, VertexList *vertexList, char name[]) {
    mat->size++;
    addVertexToList(vertexList, name);
}

void 
displayMatrix(Matrix mat) {
    printf("   ");
    for (int i = 0; i < mat.size; i++) {
        if (i < 10) {
            printf("%d  ", i);
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int i = 0; i < mat.size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < mat.size; j++) {
            if (mat.arr[i][j] < 10) {
                printf("%d  ", mat.arr[i][j]);
            } else {
                printf("%d ", mat.arr[i][j]);
            }
        }
        printf("\n");
    }
}