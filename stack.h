#ifndef STACK_H
#define STACK_H

#include "token.h"
#include "enums.h"

typedef struct {
    Token arr[MAX_SIZE];
    int top;
} Stack;

Stack newStack();
int stackIsEmpty(Stack *stack);
int stackIsFull(Stack *stack);
void stackPush(Stack *stack, Token token);
Token stackPop(Stack *stack);
Token stackPeek(Stack *stack);

#endif
