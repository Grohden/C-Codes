#include "chainedList.h"
#include "../utils.h"
#include <math.h>
#include <string.h>

void executeTests(int size);
void testNumbers(ChainedList *list, int size);
void testStrings(ChainedList *list, int size);

void executeQueueTests(int size) {
	ChainedList * l = initChainedList();
	testNumbers(l,size);
	testStrings(l,size);
}

void testStrings(ChainedList *list,int size) {
	addToChainedList(list, (void *) "lal");
	addToChainedList(list, (void *) "test");
	addToChainedList(list, (void *) "teste");
	addToChainedList(list, (void *) "aaaaaa");
	addToChainedList(list, (void *) "wroking(?)");


	println(
		"Ultimo %s",
		(char *) getFromChainedList(list, getChainedListLength(list) - 1)
	);
}

void testNumbers(ChainedList *list, int size) {
	
	int count = 1;

	do {
		addIntegerToChainedList(list, count);
	} while (count++ < size);

	println(
		"Ultimo %d",
		*((int *) getFromChainedList(list, getChainedListLength(list) - 1))
	);

	repeat(size) {
		removeFromChainedList(list, 0);
	}
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeQueueTests(10);
	return 0;
}
