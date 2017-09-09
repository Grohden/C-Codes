#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../utils.h"
#include "chainedQueue.h"

void testString() {
  ChainQueueHead *test = initChainQueue();

  // Se nao tiver vazia ta errado
  if (!isChainQueueEmpty(test)) {
    println("Pilha devia estar vazia ao ser iniciada");
  }

  addToChainQueue(test, (void *) "TESTE");

  // Se tiver vazia ta errado
  if (isChainQueueEmpty(test)) {
    println("Pilha nao pode estar vazia apos a adicao de algo");
  }

  removeFromChainQueue(test);

  // Se nao tiver vazia ta errado
  if (!isChainQueueEmpty(test)) {
    println("Pilha devia estar vazia apos remover o unico item");
  }
}

void userTest() {}

// TODO escrever os testes
int main(int argc, char *argv[]) {
  testString();
  userTest();
  return 0;
}
