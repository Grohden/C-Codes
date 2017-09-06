#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../SO/specifics.h"
#include "../chainedList/chainedList.h"
#include "../random/random.h"
#include "../textualGUI/textualGUI.h"
#include "../utils.h"
#include "doubleChainedList.h"

typedef struct ContaStruct {
  char *nome;
  int nrContaCorrente;
} Conta;

ChainedList *mainMenuChain = NULL;
DoubleChainedList *dcl = NULL;

void testString() {
  DoubleChainedList *test = initDoubleChain();

  // Se nao tiver vazia ta errado
  if (!isDoubleChainEmpty(test)) {
    println("Pilha devia estar vazia ao ser iniciada");
  }

  addToDoubleChainEnd(test, (void *)"TESTE");

  // Se tiver vazia ta errado
  if (isDoubleChainEmpty(test)) {
    println("Pilha nao pode estar vazia apos a adicao de algo");
  }

  removeFromDoubleChain(test, 0);

  // Se nao tiver vazia ta errado
  if (!isDoubleChainEmpty(test)) {
    println("Pilha devia estar vazia apos remover o unico item");
  }
}

static void printList(DoubleChainedList *list) {
  int index = 0;
  int size = getDoubleChainLength(list);
  do {
    printf("number at %d is %d\t|\t", index,
           (int)getDoubleChainDataAt(list, index));
    println("number at %d is %d", size - index,
            (int)getDoubleChainDataAt(list, size - index));

  } while (index++ < size);
}

void userTest() {
  int randomSize = getRandomBetweenRange(1, 100);
  int index;
  int storedNumber;
  println("sizeof random list %d", randomSize);

  DoubleChainedList *list = initDoubleChain();

  index = 0;
  do {
    addToDoubleChainEnd(list, (void *) getRandomNumber());
  } while (index++ < randomSize);

  printList(list);
  pause();

  index = 0;
  do {
    storedNumber = (int) getDoubleChainDataAt(list, index);
    if (!(storedNumber % 2)) {
      removeFromDoubleChainEnd(list);
    }
  } while (index++ < randomSize);

  printList(list);
  pause();
}

// TODO escrever os testes
int main(int argc, char *argv[]) {
  //testString();
  pause();
  userTest();
  return 0;
}
