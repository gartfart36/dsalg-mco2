#include <stdio.h>
#include <string.h>
#include "dfs.h"
#include "stack.h"

// depth-first search, neighbours in lex order
void dfs(Matrix *mat, VertexList *vl, char startName[]) {
    int n     = vl->end;
    int start = getIndex(vl, startName);
    if (start < 0) return;

    int visited[MAX_VALUE] = {0};
    Stack s = newStack();
    stackPush(&s, start);

    while (!stackIsEmpty(&s)) {
        int u = stackPop(&s);
        if (visited[u]) continue;
        visited[u] = 1;
        printf("%s\n", vl->list[u]);

        // 1) collect all unvisited neighbours
        int buf[MAX_VALUE], cnt = 0;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && mat->arr[u][v] != 0)
                buf[cnt++] = v;
        }
        // 2) sort by name
        for (int i = 0; i < cnt - 1; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (strcmp(vl->list[ buf[i] ], vl->list[ buf[j] ]) > 0) {
                    int tmp = buf[i]; buf[i] = buf[j]; buf[j] = tmp;
                }
            }
        }
        // 3) push in **reverse** so lex-smallest is popped first
        for (int i = cnt - 1; i >= 0; i--) {
            stackPush(&s, buf[i]);
        }
    }
}
