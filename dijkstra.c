#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "dijkstra.h"

void 
dijkstra(Matrix mat, VertexList vertexList,
         char srcName[], char destName[]) {
    int V = vertexList.end;
    int s = getIndex(vertexList, srcName);
    int t = getIndex(vertexList, destName);
    if (s < 0 || t < 0) return;

    int dist[MAX_VALUE];
    int prev[MAX_VALUE];
    int used[MAX_VALUE] = {0};
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[s] = 0;

    for (int k = 0; k < V; k++) {
        int u = -1;
        int best = INT_MAX;
        for (int i = 0; i < V; i++) {
            if (!used[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }
        if (u < 0) break;
        used[u] = 1;
        for (int v = 0; v < V; v++) {
            int w = mat.arr[u][v];
            if (w != 0 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    if (dist[t] == INT_MAX) return;
    printf("%d\n", dist[t]);
    int path[MAX_VALUE];
    int count = 0;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path[count++] = cur;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%s\n", vertexList.list[path[i]]);
    }
}
