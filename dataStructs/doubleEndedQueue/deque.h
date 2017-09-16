#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"

typedef struct TypeDeque {
	int left;
	int right;
	int maxLength; //Tamanho maximo
	int length; // Tamanho atual
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