#include <stdbool.h>

#ifndef _DOUBLE_CHAINED_LIST_
#define _DOUBLE_CHAINED_LIST_


typedef struct TypeDoubleChainedList {
	void * previous;
	void * next;
	void * data;
} DoubleChainedList;


DoubleChainedList * initDoubleChain();

void* getDoubleChainDataAt(DoubleChainedList *chainHead, int elementAt);

void addToDoubleChainEnd(DoubleChainedList *chainHead, void * data);

void addToDoubleChainAt(DoubleChainedList *chainHead, void * data, int index);

void removeFromDoubleChain(DoubleChainedList *chainHead, int index);

int getDoubleChainLength(DoubleChainedList *chainHead);

bool isDoubleChainEmpty(DoubleChainedList * chainHead);
#endif // !_DOUBLE_CHAINED_LIST_