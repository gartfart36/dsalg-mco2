#include <stdio.h>
#include "stack.h"

// create a fresh empty stack
Stack newStack() {
    Stack stack;
    stack.top = -1;     // -1 means stack is empty
    return stack;
}

// check if stack has no elements
int stackIsEmpty(Stack *stack) {
    return stack->top == -1;
}

// check if stack is full (reached max capacity)
int stackIsFull(Stack *stack) {
    return stack->top == MAX_VALUE - 1;
}

// add an item to top of stack
void stackPush(Stack *stack, int val) {
    if (!stackIsFull(stack)) {
        stack->top++;                     // move top pointer up
        stack->arr[stack->top] = val;   // store token at top
    } else {
        printf("stack overflow\n");
    }
}

// remove and return top item from stack
int stackPop(Stack *stack) {
    int val = 0;

    if (!stackIsEmpty(stack)) {
        val = stack->arr[stack->top];  // get top token
        stack->top--;                    // move top pointer down
    } else {
        printf("stack underflow\n");
    }
    return val;
}

// look at top item without removing it
int stackPeek(Stack *stack) {
    int val = 0;
    if (!stackIsEmpty(stack)) {
        val = stack->arr[stack->top];  // return top token
    } else {
        printf("stack is empty\n");
    }
    return val;
}
