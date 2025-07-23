#include <stdio.h>
#include "queue.h"

// create a fresh empty queue
Queue newQueue() {
    Queue queue;
    queue.front = -1;  // -1 means no elements yet
    queue.rear = 0;    // next position to add element
    return queue;
}

// check if queue has no elements
int queueIsEmpty(Queue *queue) {
    return queue->front == queue->rear - 1;
}

// check if queue is full (reached max capacity)
int queueIsFull(Queue *queue) {
    return queue->rear == MAX_VALUE;
}

// add an item to end of queue
void queueEnq(Queue *queue, int val) {
    if (!queueIsFull(queue)) {
        queue->arr[queue->rear] = val;  // store token at rear
        queue->rear++;                    // move rear pointer
    } else {
        printf("queue is full\n");
    }
}

// remove and return front item from queue
int queueDeq(Queue *queue) {
    int val = 0;
    if (!queueIsEmpty(queue)) {
        queue->front++;                     // move front pointer
        val = queue->arr[queue->front];   // get front token
    } else {
        printf("queue is empty\n");
    }
    return val;
}

// look at front item without removing it
int queuePeek(Queue *queue) {
    int val = 0;

    if (!queueIsEmpty(queue)) {
        val = queue->arr[queue->front+1];  // front+1 is first element
    } else {
        printf("queue is empty\n");
    }
    return val;
}
