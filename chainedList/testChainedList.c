#include "chainedList.h"
#include "../utils.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

void executeTests(int size);
void testNumbers(ChainedList *list, int size);
void testStrings(ChainedList *list, int size);

void executeQueueTests(int size) {
	ChainedList * l = initChain();
	//testNumbers(l,size);
	testStrings(l,size);
}

void testStrings(ChainedList *list,int size) {
	removeFromChain(list, 0);

	addToChain(list, (void *) "lal");

    println("aa");

	removeFromChain(list, 0);


    println("aa");

	addToChain(list, (void *) "test");
	addToChain(list, (void *) "teste");
	addToChain(list, (void *) "aaaaaa");
	addToChain(list, (void *) "wroking(?)");


	println(
		"Ultimo %s",
		(char *) getChainDataAt(list, getChainLength(list) - 1)
	);
}

void testNumbers(ChainedList *list, int size) {
	
	int *pointer;
	int count = 0;


	do {
		pointer = malloc(sizeof(int));
		*pointer = count;
		addToChain(list, (void *) pointer);

	} while (count++ < size);

	println(
		"Ultimo %d",
		*((int *) getChainDataAt(list, getChainLength(list) - 1))
	);

	repeat(size) {
		removeFromChain(list, 0);
	}
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeQueueTests(10);
	return 0;
}
