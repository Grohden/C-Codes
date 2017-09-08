#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../chainedList/chainedList.h"
#include "../random/random.h"
#include "../textualGUI/textualGUI.h"
#include "../utils.h"
#include "doubleChainedList.h"

static void printList(DoublyChainedListHead *head)
{
  int index = 0;
  int length = getDoublyChainLength(head);
  if (isDoublyChainEmpty(head)) {
    println("Empty list");
  }
  else
  {
    println("list length %d", length);
    for (index = 0; index < length; index++) {
      printf("number at %d is %d \t|\t", index,
              (int) getDoublyChainDataAt(head, index)
      );
      println("number at %d is %d", (length - 1) - index,
              (int) getDoublyChainDataAt(head, (length - 1) - index)
      );
    }
  }

  println("===============================================");
}

void userTest()
{
  int randomSize = getRandomBetweenRange(10, 100);
  int index;
  bool isEven = false;

  DoublyChainedListHead *list = initDoublyChain();

  for (index = 0; index++ < randomSize; index++) {
    addToDoublyChainEnd(list, (int *) getRandomBetweenRange(1,100));
  }
  printList(list);

  for (index = 0; index < getDoublyChainLength(list); index++) {
    isEven = ((int)getDoublyChainDataAt(list, index)) % 2 == 0;

    if (isEven) {
      removeFromDoublyChain(list, index);
      index--;
    }
  }
  printList(list);
}

int main(int argc, char *argv[])
{
  userTest();
  return 0;
}
