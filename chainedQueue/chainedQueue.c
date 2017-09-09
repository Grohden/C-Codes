#include "chainedQueue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../messageUtils.h"
#include "../utils.h"

// Private

ChainQueueHead *initChainQueue() {
  ChainQueueHead *head = (ChainQueueHead *)calloc(1, sizeof(ChainQueueHead));

  head->first = NULL;
  head->last = NULL;
  head->length = 0;

  return head;
}

static ChainQueue *initChainQueueNode() {
  ChainQueue *chainQueue = (ChainQueue *) calloc(1, sizeof(ChainQueue));
  return chainQueue;
}

// Public
int* getChainQueueFirstData(ChainQueueHead *chainHead) {
  if (isChainQueueEmpty(chainHead)) {
    println("Nao e possivel pegar o item, lista vazia");
    return NULL;
  }

  return (chainHead->first)->data;
}

void addToChainQueue(ChainQueueHead *chainHead, int *data) {
  ChainQueue *oldLast = chainHead->last;

  ChainQueue *newLast = initChainQueueNode();
  newLast->data = data;

  if (isChainQueueEmpty(chainHead)) {
    chainHead->first = newLast;
  } else {
    // Coloco na chain
    oldLast->next = newLast;
  }

  // Head
  chainHead->last = newLast;

  chainHead->length++;
}

bool removeFromChainQueue(ChainQueueHead *chainHead) {
  if (isChainQueueEmpty(chainHead)) {
    println("Nao e possivel remover, fila encadeada vazia");
    return false;
  }

  ChainQueue *first = chainHead->first;
  if (getChainQueueLength(chainHead) > 1) {
    ChainQueue *newFirst = first->next;
    chainHead->first = newFirst;
  }

  free(first);
  chainHead->length--;
  return true;
}

int getChainQueueLength(ChainQueueHead *chainHead) {
  return chainHead->length;
}

bool isChainQueueEmpty(ChainQueueHead *chainHead) { return !chainHead->length; }