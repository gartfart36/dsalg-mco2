#ifndef STACK_H
#define STACK_H

#include"enums.h"

typedef struct {
    int arr[MAX_VALUE];
    int top;
} Stack;

Stack newStack();
int stackIsEmpty(Stack *stack);
int stackIsFull(Stack *stack);
void stackPush(Stack *stack, int val);
int stackPop(Stack *stack);
int stackPeek(Stack *stack);

#endif
