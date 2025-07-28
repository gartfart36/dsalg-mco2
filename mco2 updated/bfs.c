#include <stdio.h>
#include <string.h>
#include "bfs.h"
#include "queue.h"

// breadth-first search, neighbours in lex order
void bfs(Matrix *mat, VertexList *vl, char startName[]) {
    int n     = vl->end;
    int start = getIndex(vl, startName);
    if (start < 0) return;

    int visited[MAX_VALUE] = {0};
    Queue q = newQueue();

    visited[start] = 1;
    printf("%s\n", vl->list[start]);
    queueEnq(&q, start);

    while (!queueIsEmpty(&q)) {
        int u = queueDeq(&q);

        // 1) collect all unvisited neighbours of u
        int buf[MAX_VALUE], cnt = 0;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && mat->arr[u][v] != 0)
                buf[cnt++] = v;
        }
        // 2) sort them by name
        for (int i = 0; i < cnt - 1; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (strcmp(vl->list[ buf[i] ], vl->list[ buf[j] ]) > 0) {
                    int tmp = buf[i]; buf[i] = buf[j]; buf[j] = tmp;
                }
            }
        }
        // 3) visit in that lex order
        for (int i = 0; i < cnt; i++) {
            int v = buf[i];
            visited[v] = 1;
            printf("%s\n", vl->list[v]);
            queueEnq(&q, v);
        }
    }
}
