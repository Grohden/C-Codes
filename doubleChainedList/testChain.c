#include "doubleChainedList.h"
#include "../utils.h"
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
DoubleChainedList *dcl = NULL;

void testString(){
	DoubleChainedList *test = initDoubleChain();

	//Se nao tiver vazia ta errado
	if(!isDoubleChainEmpty(test)){
		println("Pilha devia estar vazia ao ser iniciada");
	}

	addToDoubleChainEnd(test, (void *) "TESTE");

	//Se tiver vazia ta errado
	if(isDoubleChainEmpty(test)){
		println("Pilha nao pode estar vazia apos a adicao de algo");
	}

	removeFromDoubleChain(test, 0);

	//Se nao tiver vazia ta errado
	if(!isDoubleChainEmpty(test)){
		println("Pilha devia estar vazia apos remover o unico item");
	}
}


void showData(DoubleChainedList *chainHead){
	if(isDoubleChainEmpty(chainHead)){
		println("Fila encadeada vazia");
		pause();
		return;
	}

	int index = 0;
	println("Informe o a posicao do dado a ser visualizado: ");
	scanf("%d",&index);

	putCursorAt(0, getScreenHeight() - 5);

	Conta *conta;
	conta = (Conta *) getDoubleChainDataAt(chainHead, index);

	if(conta != NULL){
		println("Nome: %s", conta->nome);
		println("Numero da conta corrente: %d", conta->nrContaCorrente);
	}
	pause();
};

void removeConta(DoubleChainedList* chainHead){
	if(isDoubleChainEmpty(chainHead)){
		println("Fila encadeada vazia");
		pause();
		return;
	}

	int index = 0;
	println("Informe o a posicao do dado a ser removido");
	scanf("%d",&index);

	Conta * conta = (Conta*) getDoubleChainDataAt(chainHead, index);
	if(conta != NULL){
		println("'%s' foi removido da fila.", conta->nome);
		removeFromDoubleChain(chainHead, index);

	}
	pause();
}

void addConta(DoubleChainedList* chainHead){
	Conta *nova = (Conta*) calloc(1, sizeof(Conta));

	nova->nome = (char*) calloc(50, sizeof(char));

	putCursorAt(0, getScreenHeight() - 5);
	int index = 0;
	println("Informe o a posicao na lista do dado a ser adicionado: ");
	scanf("%d",&index);

	printf("Digite o nome (maximo 50 caracteres): ");
	fgets(nova->nome, 50, stdin);

	//Remove o \n
	nova->nome[strlen(nova->nome) - 1] = '\0';
	
	printf("Digite o numero da conta: ");
	scanf("%d", &nova->nrContaCorrente);

	addToDoubleChainAt(chainHead, (void *) nova, index);
}

void userTest(){
	//First we need to set screen size
	setScreenSize(50 * 2, 40);


	//We init the chained list
	if(mainMenuChain == NULL){
		
		dcl = initDoubleChain();
		mainMenuChain = initChain();

		//Add the items
		addToChain(mainMenuChain, (void *) "Adicionar a lista");
		addToChain(mainMenuChain, (void *) "Excluir da lista");
		addToChain(mainMenuChain, (void *) "Ver dado");
		addToChain(mainMenuChain, (void *) "Sair");
	}

	//Draw the seletable list and wait for the response
	int selected = drawSelectableList(mainMenuChain, true);

	switch(selected){
		case 0:
			addConta(dcl);
			userTest();
		break;
		case 1:
			removeConta(dcl);
			userTest();
		break;
		case 2:
			showData(dcl);
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
