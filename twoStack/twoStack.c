#include "twoStack.h"

/*==========================*\
		Gerais de pilha
\*==========================*/

DualStack * initDualStack(int stackSize)
{
	DualStack * s = malloc(sizeof(DualStack));
	
	//Tamanho maximo
	s->maxCapacity = (stackSize);
	
	//Não há nada em nenhum dos das duas pilhas
	s->sizeInfo = 0;

	//Deve começar em -1
	s->topOne = -1;
	//Deve começar no maxCapacity valor normal
	s->topTwo = s->maxCapacity;

	//Aloca o espaço para o array onde as stacks duplas estarão
	s->data = (int *) malloc(sizeof(int) * stackSize);
	return s;
}

bool isDualStackFull(DualStack * dualStack) {
	return dualStack->sizeInfo >= dualStack->maxCapacity;
}

void pushTo(DualStack * dualStack, int value, int stackPos) {
	//Verifica se a "pilha pai" esta cheia
	if (isDualStackFull(dualStack)) {
		printf("Nao e possivel adicionar, pilha dupla cheia\n");
		return;
	}

	//Verifica conflito das pilhas
	if (dualStack->topTwo == dualStack->topOne) {
		printf("Conflito de pilhas\n");
		return;
	}

	if (stackPos == 1) {
		dualStack->topOne+= 1;
		(dualStack->data)[dualStack->topOne] = value;
	} else {
		dualStack->topTwo-= 1;
		(dualStack->data)[dualStack->topTwo] = value;
	}

	//Diz que a "pilha pai" tem mais um elemento
	dualStack->sizeInfo+= 1;
}

void popFrom(DualStack * dualStack, int stackPos)
{
	if ((stackPos == 1 && isFirstStackEmpty(dualStack)) || (stackPos == 2 && isSecondStackEmpty(dualStack))) {
		printf("Erro ao retirar, a pilha %d esta vazia\n", stackPos);
		return;
	}

	if ( stackPos == 1 ) {
		dualStack->data[dualStack->topOne] = 0;
		dualStack->topOne--;
	} else {
		dualStack->data[dualStack->topTwo] = 0;
		dualStack->topTwo++;
	}

	//Diz que o array pai tem uma quantidade menor de elementos
	dualStack->sizeInfo--;
}

/*==========================*\
  Coisas da Primeira pilha
\*==========================*/

void popFromFirst(DualStack * dualStack){
	popFrom(dualStack, 1);
}

void pushToFirst(DualStack * dualStack, int value){
	pushTo(dualStack, value, 1);
}

int getTopFromFirst(DualStack * dualStack) {
	return dualStack->data[dualStack->topOne - 1];
}

bool isFirstStackEmpty(DualStack * dualStack) {
	return dualStack->topOne < 0;
}


/*==========================*\
	Coisas da Segunda pilha
\*==========================*/

void popFromSecond(DualStack * dualStack){
	popFrom(dualStack, 2);
}

void pushToSecond(DualStack * dualStack, int value) {
	pushTo(dualStack, value, 2);
}

int getTopFromSecond(DualStack * dualStack) {
	return dualStack->data[dualStack->topTwo + 1];
}

bool isSecondStackEmpty(DualStack * dualStack) {
	//Se o topo da pilha maior é igual ao topo da segunda pilha filha
	return (dualStack->topTwo) >= (dualStack->maxCapacity);
}