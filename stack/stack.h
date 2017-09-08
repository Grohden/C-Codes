#include <stdbool.h>

#ifndef _STACK_
#define _STACK_

typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct Stack {
  StackNode *top;
  int currentSize;
  int maxSize;
};

struct StackNode {
  int *data;
  StackNode *below;
};

Stack * initStack(int maxStackSize);

int *peek(Stack *stack);

int* pop(Stack *stack);

bool push(Stack *stack, int *value);

int getStackSize(Stack *stack);

int getMaxStackSize(Stack *stack);

bool isStackEmpty(Stack *stack);

bool isStackFull(Stack *stack);

#endif //!_STACK_