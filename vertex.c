#include <stdio.h>
#include <string.h>
#include "vertex.h"

VertexList 
newVertexList() {
    VertexList vertexList;
    for (int i = 0; i < MAX_VALUE; i++) {
        strcpy(vertexList.list[i], "");
    }
    vertexList.end = 0;
    return vertexList;
}

void 
addVertexToList(VertexList *vertexList, char name[]) {
    strcpy(vertexList->list[vertexList->end], name);
    vertexList->end++;
}

int 
getIndex(VertexList vertexList, char name[]) {
    int idx = -1;
    for (int i = 0; i < vertexList.end; i++) {
        if (strcmp(name, vertexList.list[i]) == 0) {
            idx = i;
        }
    }
    return idx;
}

void 
displayVertexList(VertexList vertexList) {
    printf("V = { ");
    for (int i = 0; i < vertexList.end; i++) {
        printf("%s", vertexList.list[i]);
        if (i < vertexList.end - 1) printf(", ");
    }
    printf(" }\n");
}
