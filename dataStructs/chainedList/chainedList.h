#include <stdbool.h>

#ifndef _CHAINED_LIST_
#define _CHAINED_LIST_ 1

typedef struct TypeChainedList {
	void * next;
	void * data;
} ChainedList;


ChainedList * initChain();

void* getChainDataAt(ChainedList *chainHead, int elementAt);

void addToChain(ChainedList *chainHead, void * data);

void addToChainAt(ChainedList *chainHead, void * data, int index);

void removeFromChain(ChainedList *chainHead, int index);

int getChainLength(ChainedList *chainHead);

bool isChainEmpty(ChainedList * chainHead);
#endif // !_CHAINED_LIST_
