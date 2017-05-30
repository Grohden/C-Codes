#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../messageUtils.h"
#include "chainedQueue.h"

//Private

ChainQueueHead * initChainQueue()
{
	ChainQueueHead *head = (ChainQueueHead *) calloc(1, sizeof(ChainQueueHead));

	head->first = NULL;
	head->last = NULL;
	head->length = 0;

	return head;
}


//Public
void * getChainQueueFirstData(ChainQueueHead *chainHead)
{

	if (isChainQueueEmpty(chainHead))
	{
		println("Nao e possivel pegar o item, lista vazia");
		return NULL;
	}

	return (chainHead->first)->data;
}

void addToChainQueue(ChainQueueHead *chainHead, void * data)
{
	ChainQueue *oldLast = chainHead->last;

	//Novo nó
	ChainQueue *newLast = (ChainQueue *) calloc(1, sizeof(ChainQueue));
	
	//Dado
	newLast->data = data;
	
	if(getChainQueueLength(chainHead) == 0){
		chainHead->first = newLast;
	} else {
		//Coloco na chain
		oldLast->next =  newLast;
	}

	//Head
	chainHead->last = newLast;

	chainHead->length++;
}

bool removeFromChainQueue(ChainQueueHead *chainHead)
{
	if (isChainQueueEmpty(chainHead))
	{
		println("Nao e possivel remover, fila encadeada vazia");
		return false;
	}

	ChainQueue *first = chainHead->first;
	if(getChainQueueLength(chainHead) > 1){
		ChainQueue *newFirst = first->next;
		chainHead->first = newFirst;
	}

	free(first);
	chainHead->length--;
	return true;
}

int getChainQueueLength(ChainQueueHead *chainHead)
{
	if (isChainQueueEmpty(chainHead))
	{
		return 0;
	}

	return chainHead->length;
}

bool isChainQueueEmpty(ChainQueueHead * chainHead)
{
	return !chainHead->length;
}