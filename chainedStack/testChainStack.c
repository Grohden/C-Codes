#include "chainedStack.h"
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

typedef struct AlunoStruct {
	char* nome;
	int codigo;
	int nota;
} Aluno;

ChainedList * mainMenuChain = NULL;
ChainStackHead *cs = NULL;

#define sectionSeparator() println("==========================")

void testString(){
	ChainStackHead *c = initChainStack();

	//Se nao tiver vazia ta errado
	if(!isChainStackEmpty(c)){
		errorMsg("Pilha devia estar vazia ao ser iniciada");
		sectionSeparator();
	}

	addToChainStackTop(c, (void *) "TESTE");

	//Se tiver vazia ta errado
	if(isChainStackEmpty(c)){
		errorMsg("Pilha nao pode estar vazia apos a adicao de algo");
		sectionSeparator();
	}

	removeChainStackTop(c);

	//Se nao tiver vazia ta errado
	if(!isChainStackEmpty(c)){
		errorMsg("Pilha devia estar vazia apos remover o unico item");
		sectionSeparator();
	}
}


void showTop(ChainStackHead *chainHead){
	if(isChainStackEmpty(chainHead)){
		println("Pilha encadeada vazia");
		system("pause");
		return;
	}

	Aluno *a;
	a = (Aluno *) getChainStackTopData(chainHead);
	putCursorAt(0, getScreenHeight() - 5);

	println("Nome: %s", 	a->nome);
	println("Codigo: %d", 	a->codigo);
	println("Nota: %d", 	a->nota);	
	system("pause");
};

void removeAluno(ChainStackHead* chainHead){
	if(isChainStackEmpty(chainHead)){
		println("Pilha encadeada vazia");
		system("pause");		
		return;
	}
	
	removeChainStackTop(chainHead);
}

void addAluno(ChainStackHead* chainHead){
	Aluno *novo = (Aluno*) calloc(1,sizeof(Aluno));

	novo->nome = (char*) calloc(50,sizeof(char));

	putCursorAt(0, getScreenHeight() - 5);

	fflush(stdin);
	
	printf("Digite o nome (maximo 50 caracteres): ");
	fgets (novo->nome, 50, stdin);

	//Remove o \n
	novo->nome[strlen(novo->nome) - 1] = '\0';
	
	printf("Digite a nota: ");
	scanf("%d", &novo->nota);

	printf("Digite o codigo: ");
	scanf("%d", &novo->codigo);

	addToChainStackTop(chainHead, (void *) novo);
}

void userTest(){
	//First we need to set screen size
	setScreenSize(40 * 2, 40);


	//We init the chained list
	if(mainMenuChain == NULL){
		
		cs = initChainStack();
		mainMenuChain = initChain();

		//Add the items
		addToChain(mainMenuChain, (void *) "Adicionar Aluno ao Topo");
		addToChain(mainMenuChain, (void *) "Excluir do Aluno do Topo");
		addToChain(mainMenuChain, (void *) "Ver topo");
		addToChain(mainMenuChain, (void *) "Sair");
	}

	//Draw the seletable list and wait for the response
	int selected = drawSelectableList(mainMenuChain, true);

	switch(selected){
		case 0:
			addAluno(cs);
			userTest();
		break;
		case 1:
			removeAluno(cs);
			userTest();
		break;
		case 2:
			showTop(cs);
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
	//system("pause");
	userTest();
	return 0;
}
