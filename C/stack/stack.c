#include "stack.h"


Stack * initStack(int maxStackSize){
	Stack * stack = malloc(sizeof(Stack));
	stack->stackList = malloc(maxStackSize * sizeof(int));
	stack->top = -1;
	stack->maxStackSize = maxStackSize;
	return stack;
};

void pop(Stack * stack) {
	if (isStackEmpty(stack)) {
		printf("\nError, stack is empty, cant pop anything from empty stack.");
		return;
	}

	DEBUG_MSG("\npoped %i from stack top", getTopValue(stack));

	stack->stackList[stack->top] = 0;
	stack->top--;

};

void push(Stack * stack, int value){
	if (isStackFull(stack)) {
		printf("\nError, stack is full.");
		return;
	}

	stack->top++;
	stack->stackList[stack->top] = value;
	DEBUG_MSG("\npushed %i to stack top", value);

};

bool isStackEmpty(Stack * stack) {
	return (stack->top) <= 0;
};

bool isStackFull(Stack * stack) {
	return (stack->top) >= stack->maxStackSize -1;
};


int getTopValue(Stack * stack) {
	return stack->stackList[stack->top];
};