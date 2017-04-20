#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

typedef struct StackType {
	//Dados (array de uma dimensao com pilhas ficticias)
	//Nao entendi o porque do ponteiro duplo void, entao mudei
	//Se fosse ponteiro duplo, podia fazer um array com 2 elementos contendo duas pilhas
	//ja feitas nos exercicios anteriores de pilha
	int *data;
	//Topo da primeira
	int topOne;
	//Topo da segunda
	int topTwo;
	//Tamanho maximo da "pilha pai"
	int maxCapacity;
	//Tamanho atual da "pilha pai"
	int sizeInfo;
} DualStack;


//Geral
void pushTo(DualStack * dualStack, int value, int stackPos);
void popFrom(DualStack * dualStack, int stackPos);
DualStack * initDualStack(int stackSize);
bool isDualStackFull(DualStack * dualStack);

//Primeira pilha
void pushToFirst(DualStack * dualStack, int value);
void popFromFirst(DualStack * dualStack);
int getTopFromFirst(DualStack * dualStack);
bool isFirstStackEmpty(DualStack * dualStack);

//Segunda pilha
void pushToSecond(DualStack * dualStack, int value);
void popFromSecond(DualStack * dualStack);
bool isSecondStackEmpty(DualStack * dualStack);
int getTopFromSecond(DualStack * dualStack);
