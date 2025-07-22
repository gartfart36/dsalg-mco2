#include<stdio.h>
#include<string.h>
#include"vertex.h"

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

void 
displayVertexList(VertexList vertexList) {
    for (int i = 0; i < vertexList.end; i++) {
        printf("%d: %s\n", i, vertexList.list[i]);
    }
    printf("\n");
}