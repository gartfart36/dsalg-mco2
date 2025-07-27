#include <stdio.h>
#include <string.h>
#include "bfs.h"
#include "queue.h"

int 
isNeighbor(Matrix mat, int i, int j) {
    return mat.arr[i][j] != 0;
}

void 
bfs(Matrix mat, VertexList vertexList, char startName[]) {
    int n = vertexList.end;
    int start = getIndex(vertexList, startName);
    if (start < 0) return;

    int visited[MAX_VALUE] = {0};
    Queue q = newQueue();

    visited[start] = 1;
    printf("%s\n", vertexList.list[start]);
    queueEnq(&q, start);

    while (!queueIsEmpty(&q)) {
        int u = queueDeq(&q);
        for (int v = 0; v < n; v++) {
            if (!visited[v] && isNeighbor(mat, u, v)) {
                visited[v] = 1;
                printf("%s\n", vertexList.list[v]);
                queueEnq(&q, v);
            }
        }
    }
}
