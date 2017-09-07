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
  int size = getDoublyChainLength(head) - 1;
  if (isDoublyChainEmpty(head))
  {
    println("Empty list");
  }
  else
  {
    do
    {
      printf("number at %d is %d\t|\t", index,
             (int) getDoublyChainDataAt(head, index));

      println("number at %d is %d", (size - index) - 1,
              (int) getDoublyChainDataAt(head, size - index)
      );

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
  int d;  
  /*do
  {
    d = getRandomBetweenRange(1,100);
    println("%d",d);    
    addToDoublyChainEnd(list, (int *) d);
    //addToDoublyChainEnd(list, 11);
  } while (++index < randomSize);
  */

  addToDoublyChainEnd(list, 10);
  addToDoublyChainEnd(list, 17);
  addToDoublyChainEnd(list, 14);
  addToDoublyChainEnd(list, 13);
  addToDoublyChainEnd(list, 11);
  

  printList(list);
  
  index = 0;
  do
  {
    d = (int) getDoublyChainDataAt(list, index);
    isEven = (d) % 2 == 0;
    
    if (isEven)
    {
      println("%d",d);    
      removeFromDoublyChain(list, index);
      index--;      
    }

  } while (++index < getDoublyChainLength(list));

  printList(list);
}

int main(int argc, char *argv[])
{
  userTest();
  return 0;
}
