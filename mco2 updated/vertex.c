#include <stdio.h>
#include <string.h>
#include "vertex.h"

// return a fresh VertexList with zero entries
VertexList newVertexList() {
    VertexList vl;
    vl.end = 0;
    return vl;
}

// append a vertex name to the list
void addVertexToList(VertexList *vertexList, char name[]) {
    strcpy(vertexList->list[vertexList->end++], name);
}

// return the index of name in list, or -1 if not found
int getIndex(VertexList *vertexList, char name[]) {
    for (int i = 0; i < vertexList->end; i++) {
        if (strcmp(name, vertexList->list[i]) == 0)
            return i;
    }
    return -1;
}

// print V = { name0, name1, ..., name[i]}
void displayVertexList(VertexList *vertexList) {
    printf("V = { ");
    for (int i = 0; i < vertexList->end; i++) {
        printf("%s", vertexList->list[i]);
        if (i < vertexList->end - 1) printf(", ");
    }
    printf(" }\n");
}
