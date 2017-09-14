#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Redefine queue data to int
#ifndef CHAIN_QUEUE_DATA
#define CHAIN_QUEUE_DATA int
#endif  // !CHAIN_QUEUE_DATA

#include "../chainedQueue.h"
#include "../../utils.h"

void printDiscardedQueue(ChainQueueHead *queue) {
  int queueSize = getChainQueueLength(queue);
  int elementValue = 0;
  int index = 0;

  printf("Discarded cards are: |");
  for (index = 0; index < queueSize; index++) {
    elementValue = removeFromChainQueue(queue);
    printf(" %d |", elementValue);
    addToChainQueue(queue, elementValue);
  }
}

void printCardForSize() {
  int i = 1;
  int deckSize = 0;

  printf("Inform deck size:");
  scanf("%d",&deckSize);

  ChainQueueHead *deckQueue = initChainQueue();
  ChainQueueHead *discardedQueue = initChainQueue();

  for (i = 1; i <= deckSize; i++) {
    addToChainQueue(deckQueue, i);
  }

  while (getChainQueueLength(deckQueue) > 1) {
    // Adiciona a fila de descartadas
    addToChainQueue(discardedQueue, getChainQueueFirstData(deckQueue));

    // Remove da fila do baralho
    removeFromChainQueue(deckQueue);

    // Pega o começo da fila e coloca no fim
    addToChainQueue(deckQueue,  getChainQueueFirstData(deckQueue));

    //remove a carta do inicio
    removeFromChainQueue(deckQueue);
  }

  println("Remaining card: %d", getChainQueueFirstData(deckQueue));
  printDiscardedQueue(discardedQueue);
}

int main(int argc, char** argv) { 
  printCardForSize();
  return 0;
}
