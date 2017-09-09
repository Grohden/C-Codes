#include <stdbool.h>

#ifndef _CHAINED_QUEUE_
#define _CHAINED_QUEUE_

#define CQ_DATA int*


typedef struct ChainQueueHead ChainQueueHead;
typedef struct ChainQueue ChainQueue;

struct ChainQueue {
  ChainQueue *next;
  CQ_DATA data;
};

struct ChainQueueHead {
  ChainQueue *last;
  ChainQueue *first;
  int length;
};


ChainQueueHead * initChainQueue();

int* getChainQueueFirstData(ChainQueueHead *chainHead);

void addToChainQueue(ChainQueueHead *chainHead, int* data);

bool removeFromChainQueue(ChainQueueHead *chainHead);

int getChainQueueLength(ChainQueueHead *chainHead);

bool isChainQueueEmpty(ChainQueueHead * chainHead);

#endif // !_CHAINED_QUEUE_
