#include <stdbool.h>

#ifndef _CHAINED_STACK_
#define _CHAINED_STACK_


typedef struct ChainStack {
	ChainStack * previous;
	void * data;
} ChainStack;


typedef struct ChainStackHead {
	ChainStack * top;
	int length;
} ChainStackHead;



ChainStackHead * initChainStack();

void addToChainStackTop(ChainStackHead *chainHead, void * data);

bool removeChainStackTop(ChainStackHead *chainHead);

void * getChainStackTopData(ChainStackHead *chainHead);

int getChainStackLength(ChainStackHead *chainHead);

bool isChainStackEmpty(ChainStackHead * chainHead);

#endif // !_CHAINED_STACK_
