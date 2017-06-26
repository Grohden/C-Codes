#include "../utils.h"
#include "../SO/specifics.h"
#include "../random/random.h"
#include "../textualGUI/textualGUI.h"
#include "../chainedList/chainedList.h"
#include "tree.h"


ChainedList * mainMenuChain = NULL;


void main(int argc, int argv[]){

    //We init the chained list
	if(mainMenuChain == NULL){

		mainMenuChain = initChain();

		//Add the items
		addToChain(mainMenuChain, (void *) "Adicionar conta a fila");
		addToChain(mainMenuChain, (void *) "Excluir do conta da fila");
		addToChain(mainMenuChain, (void *) "Ver dados do primeiro");
		addToChain(mainMenuChain, (void *) "Sair");
	}

    Node *root = initTree(getRandomNumber()/100);

    int i = 50;
    while(i--){
        addValueToTree(root, getRandomNumber()/100);
    }

    pause();
}