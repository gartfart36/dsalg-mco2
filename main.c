#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "vertex.h"
#include "bfs.h"
#include "dfs.h"
#include "path.h"
#include "mst.h"
#include "dijkstra.h"

int 
main(void) {
    Matrix    mat    = newMatrix();
    VertexList verts = newVertexList();

    int cmd;
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 1) {
            char name[MAX_VALUE];
            scanf("%s", name);
            addVertex(&mat, &verts, name);

        } else if (cmd == 2) {
            char u[MAX_VALUE], v[MAX_VALUE];
            int  w;
            scanf("%s %s %d", u, v, &w);
            int iu = getIndex(verts, u);
            int iv = getIndex(verts, v);
            if (iu >= 0 && iv >= 0) addEdge(&mat, iu, iv, w);

        } else if (cmd == 3) {
            char name[MAX_VALUE];
            scanf("%s", name);
            int idx = getIndex(verts, name);
            int deg = (idx >= 0)? getDegree(mat, idx) : 0;
            printf("%d\n", deg);

        } else if (cmd == 4) {
            char u[MAX_VALUE], v[MAX_VALUE];
            scanf("%s %s", u, v);
            int iu = getIndex(verts, u);
            int iv = getIndex(verts, v);
            int ex = (iu>=0 && iv>=0 && edgeExists(mat, iu, iv)) ? 1 : 0;
            printf("%d\n", ex);

        } else if (cmd == 5) {
            char start[MAX_VALUE];
            scanf("%s", start);
            bfs(mat, verts, start);

        } else if (cmd == 6) {
            char start[MAX_VALUE];
            scanf("%s", start);
            dfs(mat, verts, start);

        } else if (cmd == 7) {
            char u[MAX_VALUE], v[MAX_VALUE];
            scanf("%s %s", u, v);
            int ex = pathExists(mat, verts, u, v);
            printf("%d\n", ex);

        } else if (cmd == 8) {
            mst(mat, verts);

        } else if (cmd == 9) {
            char u[MAX_VALUE], v[MAX_VALUE];
            scanf("%s %s", u, v);
            dijkstra(mat, verts, u, v);

        } else if (cmd == 10) {
            displayVertexList(verts);
            displayMatrix(mat);

        } else if (cmd == 11) {
            break;
        }
    }
    return 0;
}
