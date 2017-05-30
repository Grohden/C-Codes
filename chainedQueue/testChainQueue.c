#include "chainedQueue.h"
#include "../utils.h"
#include "../messageUtils.h"
#include "../chainedList/chainedList.h"
#include "../SO/specifics.h"
#include "../textualGUI/textualGUI.h"
#include "../chainedList/chainedList.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct ContaStruct {
	char* nome;
	int nrContaCorrente;
} Conta;

ChainedList * mainMenuChain = NULL;
ChainQueueHead *cqh = NULL;

void testString(){
	ChainQueueHead *test = initChainQueue();

	//Se nao tiver vazia ta errado
	if(!isChainQueueEmpty(test)){
		println("Pilha devia estar vazia ao ser iniciada");
	}

	addToChainQueue(test, (void *) "TESTE");

	//Se tiver vazia ta errado
	if(isChainQueueEmpty(test)){
		println("Pilha nao pode estar vazia apos a adicao de algo");
	}

	removeFromChainQueue(test);

	//Se nao tiver vazia ta errado
	if(!isChainQueueEmpty(test)){
		println("Pilha devia estar vazia apos remover o unico item");
	}
}


void showFirst(ChainQueueHead *chainHead){
	if(isChainQueueEmpty(chainHead)){
		println("Fila encadeada vazia");
		pause();
		return;
	}

	Conta *conta;
	conta = (Conta *) getChainQueueFirstData(chainHead);
	putCursorAt(0, getScreenHeight() - 5);

	println("Nome: %s", conta->nome);
	println("Numero da conta corrente: %d", conta->nrContaCorrente);
	pause();
};

void removeConta(ChainQueueHead* chainHead){
	if(isChainQueueEmpty(chainHead)){
		println("Fila encadeada vazia");
		pause();
		return;
	}

	Conta * conta = (Conta*) getChainQueueFirstData(chainHead);

	println("'%s' foi removido da fila.", conta->nome);
	removeFromChainQueue(chainHead);
	pause();
}

void addConta(ChainStackHead* chainHead){
	Conta *nova = (Conta*) calloc(1, sizeof(Conta));

	nova->nome = (char*) calloc(50, sizeof(char));

	putCursorAt(0, getScreenHeight() - 5);
	
	printf("Digite o nome (maximo 50 caracteres): ");
	fgets (nova->nome, 50, stdin);

	//Remove o \n
	nova->nome[strlen(nova->nome) - 1] = '\0';
	
	printf("Digite o numero da conta: ");
	scanf("%d", &nova->nrContaCorrente);

	addToChainQueue(chainHead, (void *) nova);
}

void userTest(){
	//First we need to set screen size
	setScreenSize(50 * 2, 40);


	//We init the chained list
	if(mainMenuChain == NULL){
		
		cqh = initChainQueue();
		mainMenuChain = initChain();

		//Add the items
		addToChain(mainMenuChain, (void *) "Adicionar conta a fila");
		addToChain(mainMenuChain, (void *) "Excluir do conta da fila");
		addToChain(mainMenuChain, (void *) "Ver dados do primeiro");
		addToChain(mainMenuChain, (void *) "Sair");
	}

	//Draw the seletable list and wait for the response
	int selected = drawSelectableList(mainMenuChain, true);

	switch(selected){
		case 0:
			addConta(cqh);
			userTest();
		break;
		case 1:
			removeConta(cqh);
			userTest();
		break;
		case 2:
			showFirst(cqh);
			userTest();
		break;
		case 3:
			//return
		break;
	}


}


//TODO escrever os testes
int main(int argc, char * argv[]) {
	testString();
	userTest();
	return 0;
}
