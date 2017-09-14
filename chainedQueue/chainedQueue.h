#include <stdbool.h>

//Support to define chain queue data.
#ifndef CHAIN_QUEUE_DATA
#define CHAIN_QUEUE_DATA int*
#endif  // !CHAIN_QUEUE_DATA

#ifndef _CHAINED_QUEUE_
#define _CHAINED_QUEUE_

typedef struct ChainQueueHead ChainQueueHead;
typedef struct ChainQueue ChainQueue;

struct ChainQueue {
  ChainQueue *next;
  CHAIN_QUEUE_DATA data;
};

struct ChainQueueHead {
  ChainQueue *last;
  ChainQueue *first;
  int length;
};


ChainQueueHead * initChainQueue();

CHAIN_QUEUE_DATA getChainQueueFirstData(ChainQueueHead *chainHead);

void addToChainQueue(ChainQueueHead *chainHead, CHAIN_QUEUE_DATA data);

CHAIN_QUEUE_DATA removeFromChainQueue(ChainQueueHead *chainHead);

int getChainQueueLength(ChainQueueHead *chainHead);

bool isChainQueueEmpty(ChainQueueHead * chainHead);

#endif // !_CHAINED_QUEUE_
