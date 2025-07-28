#ifndef HEAP_H
#define HEAP_H

#include "enums.h"

// Min-heap of (key,value) pairs
// key   = priority
// value = payload (e.g. vertex index)

typedef struct {
    int keys[MAX_VALUE];
    int values[MAX_VALUE];
    int size;
} Heap;

// Create a new, empty heap
Heap newHeap();

// True if no elements remain
int  heapIsEmpty(Heap *h);

// Insert a (key,value) pair
void heapInsert(Heap *h, int key, int value);

// Extract the min-key pair into *outKey,*outValue
void heapExtractMin(Heap *h, int *outKey, int *outValue);

#endif
