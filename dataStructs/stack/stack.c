#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"

Stack* initStack(int maxStackSize) {
  Stack* stack = calloc(1, sizeof(Stack));

  stack->top = NULL;
  stack->currentSize = 0;
  stack->maxSize = maxStackSize;
  return stack;
};

static StackNode* initStackNode() {
  StackNode* node = calloc(1, sizeof(StackNode));
  node->below = NULL;
  node->data = NULL;
  return node;
}

int* pop(Stack* stack) {
  if (isStackEmpty(stack)) {
    println("Error, stack is empty, cant pop anything from empty stack.");
    return NULL;
  }

  StackNode* removed = stack->top;
  int* data = stack->top->data;
  stack->top = removed->below;
  stack->currentSize--;

  free(removed);
  return data;
};

bool push(Stack* stack, int* value) {
  if (isStackFull(stack)) {
    println("Error, stack is full.");
    return false;
  }

  StackNode* node = initStackNode();
  node->data = value;
  node->below = stack->top;

  stack->top = node;
  stack->currentSize++;

  return true;
};

int* peek(Stack* stack){
  if(isStackEmpty(stack)){
    println("Can't peek empty stack");
    return NULL;
  } else {
    return stack->top->data;
  }
}

int getStackSize(Stack* stack) { return stack->currentSize; }

int getMaxStackSize(Stack* stack) { return stack->maxSize; }

bool isStackEmpty(Stack* stack) {  
  return getStackSize(stack) <= 0;
}

bool isStackFull(Stack* stack) {
  return getStackSize(stack) == getMaxStackSize(stack);
}
