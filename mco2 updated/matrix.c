#include <stdio.h>
#include <string.h>
#include "matrix.h"

// create a new Matrix with size=0, empty adjacency, empty inputs
Matrix newMatrix() {
    Matrix m;
    m.size = 0;
    m.inputCount = 0;
    for (int i = 0; i < MAX_VALUE; i++)
        for (int j = 0; j < MAX_VALUE; j++)
            m.arr[i][j] = 0;
    return m;
}

// add an undirected edge (i,j) with weight; save to inputs in order
void addEdge(Matrix *mat, int i, int j, int weight) {
    mat->inputs[mat->inputCount] = (EdgeInput){i,j,weight};
    mat->inputCount++;
    mat->arr[i][j] = weight;
    mat->arr[j][i] = weight;
}

// add a vertex name and increment size
void addVertex(Matrix *mat, VertexList *vl, char name[]) {
    addVertexToList(vl, name);
    mat->size++;
}

// count nonzero entries in row idx
int getDegree(Matrix *mat, int idx) {
    int deg = 0;
    for (int j = 0; j < mat->size; j++)
        if (mat->arr[idx][j] != 0) deg++;
    return deg;
}

// return 1 if mat.arr[i][j] != 0, else 0
int edgeExists(Matrix *mat, int i, int j) {
    return (mat->arr[i][j] != 0);
}

void printGraph(Matrix *mat, VertexList *vl) {
    int V = vl->end;

    // store values in temporary array for sorting
    SV sv[MAX_VALUE];
    for (int i = 0; i < V; i++) {
        strcpy(sv[i].name, vl->list[i]);
        sv[i].idx = i;
    }

    // lex sorting
    for (int i = 0; i < V-1; i++) {
        for (int j = i+1; j < V; j++) {
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                SV tmp = sv[i];
                sv[i]  = sv[j];
                sv[j]  = tmp;
            }
        }
    }

    printf("10\n");
    printf("G = (V,E)\n");

    // print vertices
    printf("V = {");
    for (int i = 0; i < V; i++) {
        printf("%s", sv[i].name);
        if (i < V-1) printf(", ");
    }
    printf("}\n");

    // print edges
    printf("E = {\n");
    int first = 1;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            int u = sv[i].idx;
            int v = sv[j].idx;
            int w = mat->arr[u][v];
            if (w != 0) {
                if (!first) printf(",\n");
                printf("    (%s, %s, %d)",
                       sv[i].name,
                       sv[j].name,
                       w);
                first = 0;
            }
        }
    }
    printf("\n}\n");
}
