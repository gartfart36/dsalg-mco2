#include<stdio.h>
#include "vertex.h"
#include "edge.h"

Edge newEdge() {
    Edge edge;
    edge.vert1 = newVertex();
    edge.vert2 = newVertex();

    return edge;
}