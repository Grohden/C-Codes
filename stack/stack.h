#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

#ifndef _STACK_DEBUG
#define _STACK_DEBUG  0
#endif // !_STACK_DEBUG

//Mensagens de debug
#if _STACK_DEBUG
#define DEBUG_MSG(...); printf(__VA_ARGS__); 
#else
#define DEBUG_MSG(...); NULL; 
#endif // 0


typedef struct TypeStack {
	int top;
	int * stackList;
	int maxStackSize;
} Stack;

Stack * initStack(int maxStackSize);

int getTopValue(Stack * stack);

int getAndPopTopValue(Stack * stack);

void pop(Stack * stack);

void push(Stack * stack, int value);

bool isStackEmpty(Stack * stack);

bool isStackFull(Stack * stack);