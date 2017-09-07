#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#include "doubleChainedList.h"

DoublyChainedListHead *initDoublyChain()
{
  DoublyChainedListHead *head = (DoublyChainedListHead *)calloc(1, sizeof(DoublyChainedListHead));

  head->start = NULL;
  head->end = NULL;
  head->length = 0;
  return head;
}

static DoublyChain *initDoublyNode()
{
  return (DoublyChain *)calloc(1, sizeof(DoublyChain));
}

static DoublyChain *getDoublyChainAt(DoublyChainedListHead *head, int chainAt)
{
  if (isDoublyChainEmpty(head))
  {
    println("Doubly list is empty");
    return NULL;
  }

  if ((getDoublyChainLength(head) - 1) < chainAt || chainAt < 0)
  {
    println("Index fora dos limites: %d", chainAt);
    return NULL;
  }

  DoublyChain *reference;
  int index = 0;
  const int len = getDoublyChainLength(head);

  if ((len / 2) >= chainAt)
  {
    // println(" ===== Procura normal ===== ");

    reference = head->start;
    index = 0;

    while (index != chainAt && len > index)
    {
      reference = reference->next;
      index++;
    }
  }
  else
  {
    // println(" ===== Procura Reversa ===== ");
    reference = head->end;
    index = len - 1;

    while (index != chainAt && index >= 0)
    {
      reference = reference->previous;
      index--;
    }
  }

  // Retorna referencia ao ultimo
  return reference;
}

bool addToDoublyChainStart(DoublyChainedListHead *head, int *data)
{
  DoublyChain *newFirst = initDoublyNode();
  newFirst->data = data;

  if (isDoublyChainEmpty(head))
  {
    head->start = newFirst;
    head->end = newFirst;
    newFirst->next = newFirst;
    newFirst->previous = newFirst;
  }
  else
  {
    DoublyChain *start = head->start;
    DoublyChain *end = head->end;

    //New references
    newFirst->next = start;
    newFirst->previous = end;

    //Previous and next nodes references to the new
    start->previous = newFirst;
    end->next = newFirst;

    //Head references
    head->start = newFirst;
  }

  head->length++;
  return true;
}

// Public
int *getDoublyChainDataAt(DoublyChainedListHead *head, int elementAt)
{
  if (isDoublyChainEmpty(head))
  {
    println("Nao e possivel pegar o item, lista vazia");
    return NULL;
  }
  else if (elementAt > getDoublyChainLength(head) - 1)
  {
    println("Nao e possivel pegar o item, index %d fora dos limites", elementAt);
    return NULL;
  }
  else
  {
    return getDoublyChainAt(head, elementAt)->data;
  }
}

// Adiciona no fim
bool addToDoublyChainEnd(DoublyChainedListHead *head, int *data)
{
  DoublyChain *newLast = initDoublyNode();
  DoublyChain *end = head->end;

  // Seta o dado
  newLast->data = data;

  if (getDoublyChainLength(head) == 0)
  {
    //all of them are the new last
    newLast->previous = newLast;
    newLast->next = newLast;
    head->start = newLast;
    head->end = newLast;
  }
  else if (getDoublyChainLength(head) == 1)
  {
    newLast->next = head->end;
    newLast->previous = head->end;

    head->end->next = newLast;
    head->end->previous = newLast;
  }
  else
  {
    DoublyChain *start = head->start;

    //New references
    newLast->next = start;
    newLast->previous = end;

    //Previous and next nodes references to the new
    start->previous = newLast;
    end->next = newLast;

    //Head references
    head->end = newLast;
  }

  head->length++;
  return true;
}

bool addToDoublyChainAt(DoublyChainedListHead *head, int *data, int index)
{
  println("FIXME!!!!! ISNT WORKING");
  return false;

  if (index > getDoublyChainLength(head))
  {
    println("Index out of bounds");
    return false;
  }

  if (index == 0)
  {
    return addToDoublyChainStart(head, data);
  }
  else if (getDoublyChainLength(head) == index + 1)
  {
    return addToDoublyChainEnd(head, data);
  }
  else
  {
    DoublyChain *old = getDoublyChainAt(head, index);
    DoublyChain *newChain = initDoublyNode();
    DoublyChain *previous = old->previous;

    newChain->next = old;

    newChain->previous = previous;

    previous->next = newChain;

    old->previous = newChain;
    head->length++;
  }

  return true;
}

bool removeFromDoublyChain(DoublyChainedListHead *head, int index)
{
  if (isDoublyChainEmpty(head))
  {
    println("Nao e possivel remover, lista encadeada vazia");
    return false;
  }

  if (getDoublyChainLength(head) < index)
  {
    println("Nao e possivel remover na posicao %d", index);
    return false;
  }

  int len = getDoublyChainLength(head) - 1;

  if (len == index)
  {
    return removeFromDoublyChainEnd(head);
  }
  else if (!index)
  {
    return removeFromDoublyChainStart(head);
  }
  else
  {
    DoublyChain *node = getDoublyChainAt(head, index);
    DoublyChain *previous = node->previous;
    DoublyChain *next = node->next;

    previous->next = next;
    next->previous = previous;
    
    free(node);
    
    head->length--;
  }

  return true;
}

bool removeFromDoublyChainEnd(DoublyChainedListHead *head)
{
  if (isDoublyChainEmpty(head))
  {
    println("Nao e possivel remover, lista encadeada vazia");
    return false;
  }

  if (getDoublyChainLength(head) == 1)
  {
    free(head->end);
    head->end = NULL;
    head->start = NULL;
  }
  else
  {
    DoublyChain *last = head->end;
    DoublyChain *first = head->start;
    DoublyChain *newLast = last->previous;

    newLast->next = first;
    first->previous = newLast;

    head->end = newLast;
    free(last);
  }

  head->length--;
  return true;
}

bool removeFromDoublyChainStart(DoublyChainedListHead *head)
{
  if (isDoublyChainEmpty(head))
  {
    println("Nao e possivel remover, lista encadeada vazia");
    return false;
  }

  if (getDoublyChainLength(head) == 1)
  {
    free(head->start);
    head->start = NULL;
    head->end = NULL;
  }
  else
  {
    DoublyChain *first = head->start;
    DoublyChain *last = head->end;
    DoublyChain *newFirst = first->previous;

    last->next = newFirst;
    newFirst->previous = last;

    head->start = newFirst;
    //free(first);
  }

  head->length--;
  return true;
}

int getDoublyChainLength(DoublyChainedListHead *head)
{
  return head->length;
}

bool isDoublyChainEmpty(DoublyChainedListHead *head)
{
  return head->length <= 0;
}