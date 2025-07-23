#ifndef QUEUE_H
#define QUEUE_H

#include"enums.h"

typedef struct {
    int arr[MAX_VALUE];
    int front;
    int rear;
} Queue;

Queue newQueue();
int queueIsEmpty(Queue *queue);
int queueIsFull(Queue *queue);
void queueEnq(Queue *queue, int val);
int queueDeq(Queue *queue);
int queuePeek(Queue *queue);

#endif
