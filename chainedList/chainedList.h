#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

typedef struct TypeChainedList {
	void * next;
	int data;
} ChainedList;


ChainedList * initChainedList();
ChainedList * getLastRef(ChainedList *chainedList);

int getFromChainedList(ChainedList *chainedList, int index);
void addToChainedList(ChainedList *chainedList, int value);
void removeFromChainedList(ChainedList *chainedList, int index);
int getChainedListLength(ChainedList *chainedList);

bool isChanedListFull(ChainedList * chainedList); 
bool isChanedListEmpty(ChainedList * chainedList);