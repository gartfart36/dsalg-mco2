#include<stdio.h>
#include"matrix.h"
#include"stack.h"
#include"queue.h"
#include"bfs.h"

int 
main() {
    Matrix matrix1 = newMatrix();
    VertexList vertexList1 = newVertexList();
    Stack stack1 = newStack();
    Queue queue1 = newQueue();
    
    addVertex(&matrix1, &vertexList1, "jeff");
    addVertex(&matrix1, &vertexList1, "john");
    addVertex(&matrix1, &vertexList1, "bob");
    addEdge(&matrix1, getIndex(vertexList1, "jeff"), getIndex(vertexList1, "john"), 1);
    displayVertexList(vertexList1);
    displayMatrix(matrix1);

    return 0;
}