#include <stdbool.h>

#ifndef _CHAINED_QUEUE_
#define _CHAINED_QUEUE_


typedef struct ChainQueue {
	ChainQueue * next;
	void * data;
} ChainQueue;


typedef struct ChainQueueHead {
	ChainQueue * last;
	ChainQueue * first;
	int length;
} ChainStackHead;



ChainQueueHead * initChainQueue();

void * getChainQueueFirstData(ChainQueueHead *chainHead);

void addToChainQueue(ChainQueueHead *chainHead, void * data);

bool removeFromChainQueue(ChainQueueHead *chainHead);

int getChainQueueLength(ChainQueueHead *chainHead);

bool isChainQueueEmpty(ChainQueueHead * chainHead);

#endif // !_CHAINED_QUEUE_
