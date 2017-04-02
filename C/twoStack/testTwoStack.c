#include "twoStack.h"
#include "../utils.h"

//Como é um programa de teste, não é feito para ser usado como lib
//então não faz muito sentido colocar um header (e tambem ainda é algo pequeno)
void executeTests();
void showGraphicInfoAbout(DualStack * dualStack);
void testFirstStack(int stackSize);
void testSecondStack(int stackSize);

void showGraphicInfoAbout(DualStack * dualStack) {
	//Isso não fere os conceitos de pilha pois não acessa os valores, so acessa o tamanho
	int i = 0;
	printf("\n|");
	each(i, dualStack->maxCapacity) {
		if ((dualStack->topOne >= i) || (dualStack->topTwo <= i)) {
			printf(" %c |", 178);
		} else {
			printf(" %c |", 176);
		}
	}
	printf("\n");
};

/*==========================*\
			Testes
\*==========================*/
void testFirstStack(int stackSize) {
	DualStack * d = initDualStack(stackSize);

	println("======== Teste 1 - Preenchendo %d na 1 =========", stackSize+1);
	repeat(stackSize + 1) {
		pushToFirst(d, i);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 1 - Removendo %d na 1 =========", stackSize + 1);
	repeat(stackSize + 1) {
		popFromFirst(d);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 1 - Adicionado %d na 2 =========", stackSize + 1);
	repeat(stackSize + 1) {
		pushToSecond(d, i);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 1 - Removendo %d na 2 =========", stackSize + 1);
	repeat(stackSize + 1) {
		popFromSecond(d);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");
}

void testSecondStack(int stackSize) {
	DualStack * d = initDualStack(stackSize);

	println("======== Teste 2 - Preenchendo %d na 2 =========", stackSize + 1);
	repeat(stackSize + 1) {
		pushToSecond(d, i);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 2 - Removendo %d na 2 =========", stackSize + 1);
	repeat(stackSize + 1) {
		popFromSecond(d);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 2 - Adicionado %d na 1 =========", stackSize + 1);
	repeat(stackSize + 1) {
		pushToFirst(d, i);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");

	println("======== Teste 2 - Removendo %d na 1 =========", stackSize + 1);
	repeat(stackSize + 1) {
		popFromFirst(d);
		showGraphicInfoAbout(d);
	}
	system("PAUSE && CLS");
}

void executeTests() {
	int stackSizeForTest = 15;
	testFirstStack(stackSizeForTest);
	testSecondStack(stackSizeForTest);
	//testColision();
}

int main(int argc, char * argv[]) {

	executeTests();
	
	return 0;
}
