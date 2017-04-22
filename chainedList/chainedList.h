#include <stdbool.h>

typedef struct TypeChainedList {
	void * next;
	void * data;
} ChainedList;


ChainedList * initChainedList();
ChainedList * getLastRef(ChainedList *chainedList);

void* getFromChainedList(ChainedList *chainedList, int index);

void addToChainedList(ChainedList *chainedList, void * data);

void addIntegerToChainedList(ChainedList *chainedList, int value);

void removeFromChainedList(ChainedList *chainedList, int index);
int getChainedListLength(ChainedList *chainedList);

bool isChanedListEmpty(ChainedList * chainedList);