#include <stdio.h>
#include "dfs.h"
#include "stack.h"

void 
dfs(Matrix mat, VertexList vertexList, char startName[]) {
    int n = vertexList.end;
    int start = getIndex(vertexList, startName);
    if (start < 0) return;

    int visited[MAX_VALUE] = {0};
    Stack s = newStack();
    stackPush(&s, start);

    while (!stackIsEmpty(&s)) {
        int u = stackPop(&s);
        if (!visited[u]) {
            visited[u] = 1;
            printf("%s\n", vertexList.list[u]);
            for (int v = n - 1; v >= 0; v--) {
                if (!visited[v] && mat.arr[u][v] != 0) {
                    stackPush(&s, v);
                }
            }
        }
    }
}
