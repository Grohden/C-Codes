#include "doubleChainedList.h"
#include "../utils.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define sectionSeparator() println("==========================")

void testString(){
	DoubleChainedList *c = initDoubleChain();

	//Deve dizer que ta vazia
	getDoubleChainDataAt(c, 0);

	//Deve adicionar e printar o elemento
	addToDoubleChainAt(c,(void *) "Teste" ,0);
	println("%s", (char*) getDoubleChainDataAt(c, 0));

	//Deve dizer que esta fora dos limites
	getDoubleChainDataAt(c, 1);

	//Deve adicionr no lugar da primeira
	addToDoubleChainAt(c,(void *) "Nova primeira" ,0);	
	println("%s", (char*) getDoubleChainDataAt(c, 0));
	println("%s", (char*) getDoubleChainDataAt(c, 1));

	sectionSeparator();

	DoubleChainedList * previous = c;
	repeat(10){
		previous = (DoubleChainedList*) previous->previous;
		println("%s", (char*) previous->data);
	} //Testa a circularidade 

	sectionSeparator();

	println("%s", (char*) getDoubleChainDataAt(c, 0));
	removeFromDoubleChain(c,0);
	println("%s", (char*) getDoubleChainDataAt(c, 0));
	removeFromDoubleChain(c,0);
	if(isDoubleChainEmpty(c)){
		println("Chain vazia");
	}

	//Chain ta vazia, deve printar vazia
	removeFromDoubleChain(c,0);	

	system("pause && cls");

	addToDoubleChainAt(c,(void *) "Nova 0" ,0);	
	addToDoubleChainAt(c,(void *) "Nova 1" ,0);	
	addToDoubleChainAt(c,(void *) "Nova 2" ,0);	
	addToDoubleChainAt(c,(void *) "Nova 3" ,0);	
	addToDoubleChainAt(c,(void *) "Nova 4" ,0);	
	addToDoubleChainAt(c,(void *) "Nova 5" ,0);	

	int i = 0;
	each(i, 6){
		println("%s", (char*) getDoubleChainDataAt(c, i));
	}

}


//TODO escrever os testes
int main(int argc, char * argv[]) {
	testString();
	system("pause");
	return 0;
}
