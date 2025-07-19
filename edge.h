#ifndef EDGE_H
#define EDGE_H
#endif

#include "vertex.h"
#include "enums.h"

typedef struct {
    Vertex vert1;
    Vertex vert2;
    int weight;
} Edge;

Edge newEdge();