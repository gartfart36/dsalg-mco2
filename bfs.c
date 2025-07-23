#include"bfs.h"

int 
isNeighbor(Matrix mat, int i, int j) {
    return !mat.arr[i][j] == 0;
}