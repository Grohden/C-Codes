#include "chainedList.h"
#include "../utils.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void executeTests(int size);
void testNumbers(ChainedList *list, int size);
bool testStrings(ChainedList *list, int size);

void printChainData(ChainedList * head) {
	println("========");
	println("Next: %p", head->next);
	println("Data: %p", head->data);
	println("Lenght: %d", getChainLength(head));
	println("========");
}

void executeQueueTests(int size) {
	ChainedList * l = initChain();
	//testNumbers(l,size);
	testStrings(l,size);
}

bool testStrings(ChainedList *list,int size) {
	removeFromChain(list, 0);

	addToChain(list, (void *) "lal");

    removeFromChain(list, 0);

	addToChain(list, (void *) "test");
	addToChain(list, (void *) "teste");
	addToChain(list, (void *) "aaaaaa");
	addToChain(list, (void *) "wroking(?)");
	addToChainAt(list, (void *) "TestAtMiddle",4);

    removeFromChain(list, getChainLength(list)-1);

    printChainData(list);

	repeat(getChainLength(list)){
	    println("%s", (char *) getChainDataAt(list,i));
	}

    int len = getChainLength(list);

	repeat(len+1){
	    printChainData(list);
        removeFromChain(list, 0);
    }

    printChainData(list);

	return true;
}

void testNumbers(ChainedList *list, int size) {
	
	int *pointer;
	int count = 0;


	do {
		pointer = (int*) malloc(sizeof(int));
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
