#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "chainedList.h"

ChainedList * initChainedList() {
	ChainedList * c = calloc(1, sizeof(ChainedList));
	c->next = NULL;



	//O tamanho da lista encadeada vai estar no primeiro elo da lista
	c->data = calloc(1, sizeof(int)); //Aloca espaço para o contador do tamanho
	int *size = (c->data); //Pega o ponteiro para o espaço alocado
	*size = 0; //Seta o valor na memoria

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

	//Next pois o primeiro elo nao é contado
	ChainedList * chainRef = chainedList->next;

	int count = 0;

	//Enquanto existir proximo e o contador não for igual ao index
	while(chainRef->next != 0 && count != index) {
		chainRef = chainRef->next;
		count++;
	}

	//Se achou o item o retorna
	if (count == index) {
		return chainRef->data;
	}

	//Em teoria nao vai cair aqui nunca pelo primeiro if, so se a index for negativa
	println("Item no index %d nao foi achado", index);
	return NULL;
}

ChainedList* getLastRef(ChainedList *chainedList) {

	if (isChanedListEmpty(chainedList)) {
		return chainedList;
	}

	//Next pois o primeiro elo nao é contado
	ChainedList * nextRef = chainedList->next;

	//Enquanto não achar o ultimo
	while (nextRef->next != 0) {
		//ALERT: Nao printar nada aqui hehe
		nextRef = nextRef->next;
	}

	//Retorna referencia ao ultimo
	return nextRef;
}

void addIntegerToChainedList(ChainedList *chainedList, int value) {
	//Essa funcao nao deveria existir, nao é do escopo da lista encadeada
	//Alocar memoria para um inteiro e guarda-lo, quem deve fazer isto
	//é o programador que estiver usando a implementaçao
	int * reference = calloc(1, sizeof(int));
	*reference = value;

	addToChainedList(chainedList, (void *) reference);
}

void addToChainedList(ChainedList *chainedList, void * data) {
	//Cria um novo elo (ALERT: nao usar o inicializar aqui, nao sao o mesmo tipo de elo)
	ChainedList * next = calloc(1, sizeof(ChainedList));
	//Coloca o dado fornecido
	next->data = data;
	//Aponta para o nada (0==NULL)
	next->next = NULL;
	
	//Pega a ultima referencia e adiciona o proximo
	(getLastRef(chainedList))->next = next;

	//de-referenciando ponteiro para inteiro com cast e somando +1
	(*(int*)chainedList->data)++;  //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
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

	//Next pois o primeiro elo nao é contado
	ChainedList * actualRef = chainedList->next;
	ChainedList * prevRef = chainedList; //Rever se isto esta certo..deveria ser NULL

	int count = 0;

	//Enquanto existir proximo e o contador não for igual ao index
	while (actualRef->next != 0 && count != index) {
		//Referencia anterior recebe a atual
		prevRef = actualRef;
		//Atual recebe a proxima
		actualRef = actualRef->next;
		count++;
	}

	//A referencia do anterior ao elo procurado recebe a referencia do 'proximo-proximo'
	prevRef->next = actualRef->next;

	//Libera a memoria
	free(actualRef);

	//de-referenciando ponteiro para inteiro e tirando 1
	(*(int*) chainedList->data)--; //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
}

int getChainedListLength(ChainedList *chainedList) {
	if (isChanedListEmpty(chainedList)) {
		return 0;
	}

	//de-referenciando ponteiro para inteiro (em teoria, aqui deve sempre no minimo retornar 1)
	return (*(int*) chainedList->data);
}

bool isChanedListEmpty(ChainedList *chainedList) {
	return chainedList->next == 0;
}