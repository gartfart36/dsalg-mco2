#include <stdio.h>
#include "path.h"
#include "queue.h"

int 
pathExists(Matrix mat, VertexList vertexList,
           char srcName[], char destName[]) {
    int n = vertexList.end;
    int s = getIndex(vertexList, srcName);
    int t = getIndex(vertexList, destName);
    if (s < 0 || t < 0) return 0;

    int visited[MAX_VALUE] = {0};
    Queue q = newQueue();

    visited[s] = 1;
    queueEnq(&q, s);

    while (!queueIsEmpty(&q)) {
        int u = queueDeq(&q);
        if (u == t) return 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && mat.arr[u][v] != 0) {
                visited[v] = 1;
                queueEnq(&q, v);
            }
        }
    }
    return 0;
}
