#include "chainedList.h"

ChainedList * initChainedList() {
	ChainedList * c = calloc(1, sizeof(ChainedList));
	c->next = NULL;
	return c;
}

int getFromChainedList(ChainedList *chainedList, int index) {
	
	ChainedList * chainRef = chainedList->next;

	int count = 0;

	while(chainRef->next != 0 && count != index) {
		println("%d", chainRef->data);
		chainRef = chainRef->next;
		count++;
	}

	if (count==index) {
		return chainRef->data;
	}

	println("Item no index %d nao foi achado", index);
	return NULL;
}

ChainedList * getLastRef(ChainedList *chainedList) {
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

void addToChainedList(ChainedList *chainedList, int value) {
	ChainedList * next = initChainedList();
	next->data = value;
	
	(getLastRef(chainedList))->next = next;
}

void removeFromChainedList(ChainedList *chainedList, int index) {
	if (isChanedListEmpty(chainedList)) {
		println("Nao é possivel remover, lista encadeada vazia");
		return;
	}

	if (index > getChainedListLength(chainedList)-1) {
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

}

int getChainedListLength(ChainedList *chainedList) {
	if (isChanedListEmpty(chainedList)) {
		return 0;
	}

	ChainedList * nextRef = chainedList->next;

	int length = 1;
	//Enquanto não achar o ultimo
	while (nextRef->next != 0) {
		nextRef = nextRef->next;
		length++;
	}

	return length;
}

bool isChanedListEmpty(ChainedList *chainedList) {
	return chainedList->next == 0;
}