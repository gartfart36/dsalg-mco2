#include<stdio.h>
#include"matrix.h"

int 
main() {
    Matrix matrix1 = newMatrix();
    VertexList vertexList1 = newVertexList();
    addVertex(&matrix1, &vertexList1, "jeff");
    addVertex(&matrix1, &vertexList1, "john");
    addVertex(&matrix1, &vertexList1, "bob");
    addEdge(&matrix1, 0, 0, 1);
    displayVertexList(vertexList1);
    displayMatrix(matrix1);

    return 0;
}