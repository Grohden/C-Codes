#include "inverter.h"
#include <time.h>
#include <stdlib.h>

void fillQueue(Queue * q);
void executeTests(int size);
void printQueueInfos(Queue *q);

void executeTests(int size) {
	Queue * q = initQueue(size);
	printQueueInfos(q);
	
	fillQueue(q);
	printQueueInfos(q);
	
	invert(q);
	printQueueInfos(q);
}

void printQueueInfos(Queue *q) {
	println("==============================");
	println("tamanho  maximo: %d", q->maxLength);
	println("tamanho: %d", q->length);
	println("index do primeiro: %d", q->first);
	println("index do ultimo: %d", q->last);

	printf("|");
	int count = 0;
	each(count, q->maxLength) {
		printf("%3d |", q->queueData[count]);
	}
	printf("\n");

	println("==============================");
}

void fillQueue(Queue * q) {
	while (!isQueueFull(q)) {
		insertOnQueue(q, rand());
	}
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	srand(time(NULL));   // should only be called once
	executeTests(15);
	return 0;
}
