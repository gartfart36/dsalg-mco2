#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "dijkstra.h"
#include "heap.h"

// Dijkstra with heap
void dijkstra(Matrix *mat, VertexList *vl,
              char srcName[], char destName[]) {
    int V = vl->end;
    int s = getIndex(vl, srcName);
    int t = getIndex(vl, destName);
    if (s < 0 || t < 0) return;
    int dist[MAX_VALUE], prev[MAX_VALUE], used[MAX_VALUE] = {0};
    for (int i = 0; i < V; i++) { dist[i] = INT_MAX; prev[i] = -1; }
    dist[s] = 0;

    Heap h = newHeap();
    heapInsert(&h, 0, s);
    while (!heapIsEmpty(&h)) {
        int d, u;
        heapExtractMin(&h, &d, &u);
        if (used[u]) continue;
        used[u] = 1;
        if (u == t) break;
        for (int v = 0; v < V; v++) {
            int w = mat->arr[u][v];
            if (w != 0 && d + w < dist[v]) {
                dist[v] = d + w;
                prev[v] = u;
                heapInsert(&h, dist[v], v);
            }
        }
    }
    if (dist[t] == INT_MAX) return;
    printf("%d\n", dist[t]);
    int path[MAX_VALUE], cnt = 0;
    for (int x = t; x != -1; x = prev[x]) path[cnt++] = x;
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%s\n", vl->list[path[i]]);
    }
}
