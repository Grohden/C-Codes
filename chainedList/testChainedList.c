#include "chainedList.h"
#include "../utils.h"


void executeTests(int size);

void executeQueueTests(int size) {
	ChainedList * l = initChainedList();

	int count = 0;
	do {
		addToChainedList(l, count);
	} while (count++ < size);

	int sla = 30;
	repeat(10) {
		removeFromChainedList(l, sla);
		sla++;
	}

	println("%d", getFromChainedList(l, getChainedListLength(l)-1));


	println("%d", getChainedListLength(l));

}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeQueueTests(150);
	return 0;
}
