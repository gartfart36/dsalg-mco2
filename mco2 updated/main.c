// Compile: gcc -Wall bfs.c dfs.c dijkstra.c matrix.c mst.c path.c queue.c stack.c vertex.c main.c heap.c
#include <stdio.h>
#include "matrix.h"
#include "vertex.h"
#include "bfs.h"
#include "dfs.h"
#include "path.h"
#include "mst.h"
#include "dijkstra.h"

int main() {
    Matrix mat = newMatrix();
    VertexList verts = newVertexList();

    int cmd;
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 1) {             // 1
            char name[MAX_VALUE]; scanf("%s", name);
            addVertex(&mat, &verts, name);
        } else if (cmd == 2) {      // 2
            char u[MAX_VALUE], v[MAX_VALUE]; int w;
            scanf("%s %s %d", u, v, &w);
            int iu = getIndex(&verts, u);
            int iv = getIndex(&verts, v);
            if (iu >= 0 && iv >= 0) addEdge(&mat, iu, iv, w);
        } else if (cmd == 3) {      // 3
            char name[MAX_VALUE]; scanf("%s", name);
            int idx = getIndex(&verts, name);
            int deg = (idx >= 0) ? getDegree(&mat, idx) : 0;
            printf("%d\n", deg);
        } else if (cmd == 4) {      // 4
            char u[MAX_VALUE], v[MAX_VALUE]; scanf("%s %s", u, v);
            int iu = getIndex(&verts, u), iv = getIndex(&verts, v);
            printf("%d\n", (iu>=0 && iv>=0 && edgeExists(&mat, iu, iv)) ? 1 : 0);
        } else if (cmd == 5) {      // 5
            char st[MAX_VALUE]; scanf("%s", st);
            bfs(&mat, &verts, st);
        } else if (cmd == 6) {      // 6
            char st[MAX_VALUE]; scanf("%s", st);
            dfs(&mat, &verts, st);
        } else if (cmd == 7) {      // 7
            char u[MAX_VALUE], v[MAX_VALUE]; scanf("%s %s", u, v);
            printf("%d\n", pathExists(&mat, &verts, u, v));
        } else if (cmd == 8) {      // 8
            mst(&mat, &verts);
        } else if (cmd == 9) {      // 9
            char u[MAX_VALUE], v[MAX_VALUE]; scanf("%s %s", u, v);
            dijkstra(&mat, &verts, u, v);
        } else if (cmd == 10) {     // 10
            displayVertexList(&verts);
            displayMatrix(&mat);
        } else if (cmd == 11) {     // terminate
            break;
        }
    }
    return 0;
}
