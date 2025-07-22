#ifndef VERTEX_H
#define VERTEX_H
#include"enums.h"

typedef struct {
    char list[MAX_VALUE][MAX_VALUE];
    int end;
} VertexList;

VertexList newVertexList();
void addVertexToList(VertexList *vertexList, char name[]);
void displayVertexList(VertexList vertexList);

#endif