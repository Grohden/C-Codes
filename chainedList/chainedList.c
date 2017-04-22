#include "chainedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

ChainedList * initChainedList() {
	ChainedList * c = calloc(1, sizeof(ChainedList));
	c->next = NULL;



	//O tamanho da lista encadeada vai estar no primeiro
	c->data = calloc(1, sizeof(int));
	int *size = (c->data);
	*size = 0;

	return c;
}

void* getFromChainedList(ChainedList *chainedList, int index) {
	
	if (index > getChainedListLength(chainedList) - 1) {
		println("Nao e possivel pegar o item, index fora dos limites");
		return NULL;
	}

	if (isChanedListEmpty(chainedList)) {
		println("Nao e possivel pegar o item, lista vazia");
		return NULL;
	}


	ChainedList * chainRef = chainedList->next;

	int count = 0;

	while(chainRef->next != 0 && count != index) {
		chainRef = chainRef->next;
		count++;
	}

	if (count==index) {
		return chainRef->data;
	}

	println("Item no index %d nao foi achado", index);
	return NULL;
}

ChainedList* getLastRef(ChainedList *chainedList) {
	//Deve procurar a referencia ao ultimo?
	if (isChanedListEmpty(chainedList)) {
		return chainedList;
	}

	ChainedList * nextRef = chainedList->next;

	//Enquanto não achar o ultimo
	while (nextRef->next != 0) {
		//Nao printar nada aqui hehe
		nextRef = nextRef->next;
	}

	//Retorna referencia ao ultimo
	return nextRef;
}

void addIntegerToChainedList(ChainedList *chainedList, int value) {
	int * reference = calloc(1, sizeof(int));
	*reference = value;

	addToChainedList(chainedList, (void *) reference);
}

void addToChainedList(ChainedList *chainedList, void * data) {
	ChainedList * next = calloc(1, sizeof(ChainedList));
	next->data = data;
	next->next = NULL;
	
	(getLastRef(chainedList))->next = next;

	(*(int*)chainedList->data)++;
}

void removeFromChainedList(ChainedList *chainedList, int index) {
	if (isChanedListEmpty(chainedList)) {
		println("Nao é possivel remover, lista encadeada vazia");
		return;
	}

	if (index > getChainedListLength(chainedList) - 1) {
		println("Index fora dos limites");
		return;
	}

	ChainedList * actualRef = chainedList->next;
	ChainedList * prevRef = chainedList;

	int count = 0;

	while (actualRef->next != 0 && count != index) {
		prevRef = actualRef;
		actualRef = actualRef->next;
		count++;
	}

	prevRef->next = actualRef->next;

	free(actualRef);

	(*(int*) chainedList->data)--;
}

int getChainedListLength(ChainedList *chainedList) {
	if (isChanedListEmpty(chainedList)) {
		return 0;
	}

	return (*(int*) chainedList->data);
}

bool isChanedListEmpty(ChainedList *chainedList) {
	return chainedList->next == 0;
}