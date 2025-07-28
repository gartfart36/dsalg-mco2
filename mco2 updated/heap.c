#include "heap.h"

// create new heap
Heap newHeap() {
    Heap h;
    h.size = 0;
    return h;
}

// returns true if heap is empty
int heapIsEmpty(Heap *h) {
    return h->size == 0;
}

// insert a (key,value) pair
void heapInsert(Heap *h, int key, int value) {
    int i = h->size++;
    h->keys[i]   = key;
    h->values[i] = value;
    // sift up
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->keys[p] <= h->keys[i]) break;
        // swap
        int tmpK = h->keys[p], tmpV = h->values[p];
        h->keys[p]   = h->keys[i];
        h->values[p] = h->values[i];
        h->keys[i]   = tmpK;
        h->values[i] = tmpV;
        i = p;
    }
}

// extract the min-key pair into *outKey,*outValue
void heapExtractMin(Heap *h, int *outKey, int *outValue) {
    if (h->size == 0) {
        *outKey = -1;
        *outValue = -1;
        return;
    }
    *outKey   = h->keys[0];
    *outValue = h->values[0];
    // move last to root
    h->size--;
    h->keys[0]   = h->keys[h->size];
    h->values[0] = h->values[h->size];
    // sift down
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if (l < h->size && h->keys[l] < h->keys[smallest]) smallest = l;
        if (r < h->size && h->keys[r] < h->keys[smallest]) smallest = r;
        if (smallest == i) break;
        int tmpK = h->keys[i], tmpV = h->values[i];
        h->keys[i]   = h->keys[smallest];
        h->values[i] = h->values[smallest];
        h->keys[smallest]   = tmpK;
        h->values[smallest] = tmpV;
        i = smallest;
    }
}
