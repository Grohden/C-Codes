#include <stdbool.h>

#ifndef _DOUBLY_CHAINED_LIST_
#define _DOUBLY_CHAINED_LIST_

typedef struct DoublyChainedListHead DoublyChainedListHead;
typedef struct DoublyChain DoublyChain;

struct DoublyChain {
	DoublyChain * previous;
	DoublyChain * next;
	int *data;
};

struct DoublyChainedListHead {
	DoublyChain *start;
	DoublyChain *end;
	int length;
};

DoublyChainedListHead * initDoublyChain();

//Get
int* getDoublyChainDataAt(DoublyChainedListHead *chainHead, int elementAt);

//Add
bool addToDoublyChainStart(DoublyChainedListHead *chainHead, int *data);
bool addToDoublyChainEnd(DoublyChainedListHead *chainHead, int *data);
//bool addToDoublyChainAt(DoublyChainedListHead *chainHead, int *data, int index);

//Remove
bool removeFromDoublyChain(DoublyChainedListHead *chainHead, int index);
bool removeFromDoublyChainEnd(DoublyChainedListHead *chainHead);
bool removeFromDoublyChainStart(DoublyChainedListHead *chainHead);

//Infos
int getDoublyChainLength(DoublyChainedListHead *chainHead);
bool isDoublyChainEmpty(DoublyChainedListHead * chainHead);
#endif // !_DOUBLY_CHAINED_LIST_
