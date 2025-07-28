#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "mst.h"
#include "heap.h"

void mst(Matrix *mat, VertexList *vl) {
    int V = vl->end;
    int used[MAX_VALUE] = {0};
    int dist[MAX_VALUE], parent[MAX_VALUE];

    // initialize distances to “infinite” and no parent
    for (int i = 0; i < V; i++) {
        dist[i]   = INT_MAX;
        parent[i] = -1;
    }
    dist[0] = 0;  // start building MST from vertex index 0

    // use a min-heap (weight,vertex) to pick the next smallest edge
    Heap heap = newHeap();
    heapInsert(&heap, 0, 0);

    // Prim’s main loop
    while (!heapIsEmpty(&heap)) {
        int w, u;
        heapExtractMin(&heap, &w, &u); // get the closest unused vertex
        if (used[u]) continue;        // skip if already added
        used[u] = 1;                   // mark it as in the MST

        // check all neighbors of u
        for (int v = 0; v < V; v++) {
            int edgeW = mat->arr[u][v];
            // if not in MST, and an edge exists, and it’s greater than before
            if (!used[v] && edgeW != 0 && edgeW < dist[v]) {
                dist[v]   = edgeW;  // update best weight
                parent[v] = u;
                heapInsert(&heap, edgeW, v);  
            }
        }
    }

    // gather all chosen edges into a temporary array
    MSTEdge edges[MAX_VALUE];
    int    edgeCount   = 0;
    int    totalWeight = 0;
    for (int v = 1; v < V; v++) {
        int u = parent[v];
        if (u >= 0) {
            const char *A = vl->list[u];
            const char *B = vl->list[v];
            // ensure names are in lex order
            if (strcmp(A, B) > 0) {
                strcpy(edges[edgeCount].uName, B);
                strcpy(edges[edgeCount].vName, A);
            } else {
                strcpy(edges[edgeCount].uName, A);
                strcpy(edges[edgeCount].vName, B);
            }
            edges[edgeCount].weight = mat->arr[u][v];
            totalWeight += edges[edgeCount].weight;
            edgeCount++;
        }
    }

    // sort the list of edges by (uName, then vName)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = i + 1; j < edgeCount; j++) {
            int c = strcmp(edges[i].uName, edges[j].uName);
            if (c > 0 || (c == 0 && strcmp(edges[i].vName, edges[j].vName) > 0)) {
                MSTEdge tmp = edges[i];
                edges[i]    = edges[j];
                edges[j]    = tmp;
            }
        }
    }

    // print the MST header exactly as in the spec
    printf("8\n");
    printf("MST(G) = (V,E)\n");

    // print vertices in alphabetical order
    {
        char sortedV[MAX_VALUE][MAX_VALUE];
        for (int i = 0; i < V; i++) {
            strcpy(sortedV[i], vl->list[i]);
        }
        for (int i = 0; i < V - 1; i++) {
            for (int j = i + 1; j < V; j++) {
                if (strcmp(sortedV[i], sortedV[j]) > 0) {
                    char t[MAX_VALUE];
                    strcpy(t, sortedV[i]);
                    strcpy(sortedV[i], sortedV[j]);
                    strcpy(sortedV[j], t);
                }
            }
        }
        printf("V = {");
        for (int i = 0; i < V; i++) {
            printf("%s", sortedV[i]);
            if (i < V - 1) printf(", ");
        }
        printf(" }\n");
    }

    // print edges in sorted order
    printf("E = {\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("    (%s, %s, %d)",
               edges[i].uName,
               edges[i].vName,
               edges[i].weight);
        if (i < edgeCount - 1) printf(",\n");
        else                    printf("\n");
    }
    printf("}\n");

    // print total weight of the MST
    printf("Total Edge Weight: %d\n", totalWeight);
}
