#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

typedef struct TypeDeque {
	int left;
	int right;
	int maxLength;
	int length;
	int * data;
} Deque;

Deque * initDeque(int maxLength);

int getFromLeft(Deque * deque);
void removeFromLeft(Deque * deque);
void insertOnLeft(Deque * deque, int value);

int getFromRight(Deque * deque);
void removeFromRight(Deque * deque);
void insertOnRight(Deque * deque, int value);

bool isDequeEmpty(Deque * deque);
bool isDequeFull(Deque * deque);