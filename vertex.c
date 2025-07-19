#include<stdio.h>
#include<string.h>
#include "vertex.h"

Vertex newVertex() {
    Vertex vertex;
    strcpy(vertex.value, "");
    return vertex;
}