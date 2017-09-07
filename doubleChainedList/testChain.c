#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../chainedList/chainedList.h"
#include "../random/random.h"
#include "../textualGUI/textualGUI.h"
#include "../utils.h"
#include "doubleChainedList.h"

static void printList(DoublyChainedListHead *list)
{
  int index = 0;
  int size = getDoublyChainLength(list);
  if (!size)
  {
    println("Empty list");
  }
  else
  {
    do
    {
      printf("number at %d is %d\t|\t", index,
             (int)getDoublyChainDataAt(list, index));

      println("number at %d is %d", size - index,
              (int)getDoublyChainDataAt(list, size - index));

    } while (++index < size);
  }

  println("===========================================");
}

void userTest()
{
  int randomSize = 5; //getRandomBetweenRange(1, 20) - 1;
  int index;
  bool isEven = false;
  println("sizeof random list %d", randomSize + 1);

  DoublyChainedListHead *list = initDoublyChain();
  index = 0;
  do
  {
    //addToDoubleChainEnd(list, (void *) getRandomBetweenRange(1,100));
    addToDoublyChainEnd(list, 10);
  } while (++index < randomSize);

  printList(list);
  
  index = 0;
  do
  {
    //isEven = ((int)getDoublyChainDataAt(list, index)) % 2 == 0;
    removeFromDoublyChainEnd(list);
    
    //if (isEven)
    //{
    //}

  } while (++index < randomSize);

  printList(list);
}

int main(int argc, char *argv[])
{
  userTest();
  return 0;
}
