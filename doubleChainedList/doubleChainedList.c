#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "DoubleChainedList.h"

DoubleChainedList *getDoubleChainAt(DoubleChainedList *chainHead, int chainAt);
void addToChainStart(DoubleChainedList *chainHead, void *data);

//Private
DoubleChainedList *getDoubleChainAt(DoubleChainedList *chainHead, int chainAt)
{
	if (isDoubleChainEmpty(chainHead))
	{
		println("Lista dupla vazia");
		return NULL;
	}

	if ((getDoubleChainLength(chainHead) - 1) < chainAt || chainAt < 0)
	{
		println("Index fora dos limites: %d", chainAt);
		return NULL;
	}

	//Next pois o head nao � contado
	DoubleChainedList *reference;
	int index;
	int len = getDoubleChainLength(chainHead);
	
	if( (len/2) <= chainAt){
		//println(" ===== Normal ===== ");

		reference =  (DoubleChainedList *) chainHead->next;
		index = 0;

		while (index != chainAt && len > index)
		{
			reference = (DoubleChainedList *) reference->next;
			index++;
		}
	} else {
		//println(" ===== Reverse ===== ");
		reference =  (DoubleChainedList *) chainHead->previous;
		index = len-1;

		while (index != chainAt && index >= 0)
		{
			reference = (DoubleChainedList *) reference->previous;
			index--;
		}
	}
	

	//Retorna referencia ao ultimo
	return reference;
}

DoubleChainedList *initDoubleChain()
{
	DoubleChainedList *head = (DoubleChainedList *)calloc(1, sizeof(DoubleChainedList));
	head->next = NULL;
	head->previous = NULL;

	//O tamanho da lista encadeada vai estar no primeiro elo da lista
	head->data = calloc(1, sizeof(int)); //Aloca espa�o para o contador do tamanho
	int *size = (int *)(head->data);	 //Pega o ponteiro para o espa�o alocado
	*size = 0;							 //Seta o valor na memoria

	return head;
}

void addToChainStart(DoubleChainedList *chainHead, void *data)
{
	//Insere no comeco
	DoubleChainedList *newFirst = (DoubleChainedList *)calloc(1, sizeof(DoubleChainedList));

	newFirst->data = data;

	if (isDoubleChainEmpty(chainHead))
	{
		//A head é virtual, nao existe acesso direto para o programador
		//Por isso so vai ter referencia ao primeiro elo
		chainHead->previous = newFirst;

		newFirst->next = newFirst;
		newFirst->previous = newFirst;

	}
	else
	{
		DoubleChainedList *oldFirst = (DoubleChainedList *) chainHead->next;
		DoubleChainedList *last = (DoubleChainedList *) chainHead->previous;

		//Ultimo
		newFirst->previous = chainHead->previous;

		//Atribui o segundo
		newFirst->next = oldFirst;

		//Segundo aponta para o primeiro
		oldFirst->previous = newFirst;

		//Ultimo aponta para o novo primeiro
		last->next = newFirst;

	}

	//Registra o primeira na head
	chainHead->next = newFirst;

	(*(int *)chainHead->data)++;
}

//Public
void * getDoubleChainDataAt(DoubleChainedList *chainHead, int elementAt)
{

	if (elementAt > getDoubleChainLength(chainHead) - 1)
	{
		println("Nao e possivel pegar o item, index fora dos limites");
		return NULL;
	}

	if (isDoubleChainEmpty(chainHead))
	{
		println("Nao e possivel pegar o item, lista vazia");
		return NULL;
	}

	return ((DoubleChainedList*) getDoubleChainAt(chainHead, elementAt))->data;
}

//Adiciona no fim
void addToDoubleChainEnd(DoubleChainedList *chainHead, void *data)
{
	DoubleChainedList *newLast = (DoubleChainedList *) calloc(1, sizeof(DoubleChainedList));
	DoubleChainedList *oldLast = (DoubleChainedList *) chainHead->previous;

	//Seta o dado
	newLast->data = data;

	if(getDoubleChainLength(chainHead) == 0)
	{
		newLast->previous = newLast;
		newLast->next = newLast;

		chainHead->next = newLast;
	}
	else if (getDoubleChainLength(chainHead) == 1)
	{

		newLast->next = oldLast;
		newLast->previous = oldLast;

		oldLast->previous = newLast;
		oldLast->next = newLast;
	}
	else
	{
		DoubleChainedList *first = (DoubleChainedList *) chainHead->next;

		//Um referencia ao outro
		newLast->previous = oldLast;
		oldLast->next = newLast;

		//Fecha o circulo
		newLast->next = first;

		//Atualiza a referencia do anterior ao ultimo.
		first->previous = newLast;
	}

	//Ultimo é o novo
	chainHead->previous = newLast;

	(*(int *)chainHead->data)++;
	return;
}

void addToDoubleChainAt(DoubleChainedList *chainHead, void *data, int index)
{
	println("FIXME!!!!! ISNT WORKING");
	return;

	if(index > getDoubleChainLength(chainHead)){
		println("Index out of bounds");
		return;
	}

	if (index == 0)
	{
		addToChainStart(chainHead, data);
		return;
	}
	else if (getDoubleChainLength(chainHead) == index + 1)
	{
		//Insere no fim
		addToDoubleChainEnd(chainHead, data);
		return;
	}
	else
	{
		DoubleChainedList *old = getDoubleChainAt(chainHead, index);
		DoubleChainedList *newChain = (DoubleChainedList *) calloc(1, sizeof(DoubleChainedList));
		DoubleChainedList *previous = (DoubleChainedList *) old->previous;
		
		newChain->next = old;

		newChain->previous = previous;

		previous->next = newChain;

		old->previous= newChain;
		
		//de-referenciando ponteiro para inteiro com cast e somando +1
		(*(int *)chainHead->data)++; //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
	}
}

void removeFromDoubleChain(DoubleChainedList *chainHead, int index)
{
	if (isDoubleChainEmpty(chainHead))
	{
		println("Nao e possivel remover, lista encadeada vazia");
		return;
	}
	

	if(getDoubleChainLength(chainHead) == 1){
		free(chainHead->next);
		chainHead->next = NULL;
		chainHead->previous = NULL;
	} else {
		DoubleChainedList * chain = getDoubleChainAt(chainHead, index);
		DoubleChainedList * previous = (DoubleChainedList*) chain->previous;
		DoubleChainedList * next = (DoubleChainedList*) chain->next;

		//Atualiza as referencias da head
		if(index == 0){
			chainHead->next = ((DoubleChainedList*) chainHead->next)->next;
		} else if(getDoubleChainLength(chainHead) - 1 == index){
			chainHead->previous = ((DoubleChainedList*) chainHead->previous)->previous;
		}

		next->previous = previous;
		previous->next = next;

		free(chain);
	}

	//de-referenciando ponteiro para inteiro e tirando 1
	(*(int *)chainHead->data)--; //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
}

int getDoubleChainLength(DoubleChainedList *chainHead)
{
	if (isDoubleChainEmpty(chainHead))
	{
		return 0;
	}

	//de-referenciando ponteiro para inteiro (em teoria, aqui deve sempre no minimo retornar 1)
	return (*(int *)chainHead->data);
}

bool isDoubleChainEmpty(DoubleChainedList *chainHead)
{
	return chainHead->next == 0 && chainHead->previous == 0;
}