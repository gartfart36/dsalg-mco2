#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "mst.h"

void 
mst(Matrix mat, VertexList vertexList) {
    int V = vertexList.end;
    int used[MAX_VALUE] = {0};
    int dist[MAX_VALUE];
    int parent[MAX_VALUE];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[0] = 0;

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
            if (!used[v] && w != 0 && w < dist[v]) {
                dist[v]   = w;
                parent[v] = u;
            }
        }
    }

    printf("MST = (V,E)\n");
    displayVertexList(vertexList);
    printf("E = {\n");
    for (int v = 1; v < V; v++) {
        int u = parent[v];
        const char *a = vertexList.list[u];
        const char *b = vertexList.list[v];
        int w = mat.arr[u][v];
        if (strcmp(a, b) < 0)
            printf("(%s, %s, %d)", a, b, w);
        else
            printf("(%s, %s, %d)", b, a, w);
        printf(v < V-1 ? ",\n" : "\n");
    }
    printf("}\n");
}
