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
  int size = getDoublyChainLength(head);
  if (isDoublyChainEmpty(head))
  {
    println("Empty list");
  }
  else
  {
    for (index = 0; index < getDoublyChainLength(head); index++) {
      println("number at %d is %d", index,
              (int) getDoublyChainDataAt(head, index));
    }
  }

  println("===========================================");
}

void userTest()
{
  int randomSize = 5; //getRandomBetweenRange(1, 20) - 1;
  int index;
  bool isEven = false;

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
  
  println("list length %d", getDoublyChainLength(list));
  printList(list);
  
  index = 0;
  d = (int) getDoublyChainDataAt(list, index);
  isEven = (d) % 2 == 0;
  println("%d %s",d, isEven ? "iseven":"isodd"); 

  removeFromDoublyChain(list, 0);

  printList(list);
  return;

  do
  {

    if (isEven)
    {
      //removeFromDoublyChain(list, index);
      //index--;      
    }

  } while (++index < getDoublyChainLength(list));

}

int main(int argc, char *argv[])
{
  userTest();
  return 0;
}
