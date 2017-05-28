#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../messageUtils.h"
#include "chainedStack.h"

//Private

ChainStackHead * initChainStack()
{
	ChainStackHead *head = (ChainStackHead *) calloc(1, sizeof(ChainStackHead));

	head->top = NULL;
	head->length = 0;

	return head;
}


//Public
void * getChainStackTopData(ChainStackHead *chainHead)
{

	if (isChainStackEmpty(chainHead))
	{
		errorMsg("Nao e possivel pegar o item, lista vazia");
		return NULL;
	}

	return ((ChainStack*) chainHead->top)->data;
}

void addToChainStackTop(ChainStackHead *chainHead, void * data)
{
	ChainStack *oldLast = chainHead->top;

	//Novo no
	ChainStack *newLast = (ChainStack *) calloc(1, sizeof(ChainStack));
	
	//Dado
	newLast->data = data;

	newLast->previous =  oldLast;
	
	//Head
	chainHead->top = newLast;
	chainHead->length++;
}

bool removeChainStackTop(ChainStackHead *chainHead)
{
	if (isChainStackEmpty(chainHead))
	{
		errorMsg("Nao e possivel remover, lista encadeada vazia");
		return false;
	}
	
	ChainStack * last = chainHead->top;

	chainHead->top = last->previous;

	free(last);

	chainHead->length--;
	return true;
}

int getChainStackLength(ChainStackHead *chainHead)
{
	if (isChainStackEmpty(chainHead))
	{
		return 0;
	}

	return chainHead->length;
}

bool isChainStackEmpty(ChainStackHead *chainHead)
{
	return !chainHead->length;
}