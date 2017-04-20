#include "queue.h"
#include "../utils.h"


void fillQueue(Queue * q);
void emptyQueue(Queue * q);
void executeQueueTests(int size);
void emptyAndFullTest(Queue * q);
void testCircular(Queue *q, int size);
void printQueueInfos(Queue *q);

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
};

void executeQueueTests(int size) {
	Queue * q = initQueue(size);

	emptyAndFullTest(q);

	testCircular(q, size);


}

void testCircular(Queue *q, int size) {
	fillQueue(q);

	removeFromQueue(q);
	printQueueInfos(q);

	insertOnQueue(q, 666);
	printQueueInfos(q);

	removeFromQueue(q);
	printQueueInfos(q);
}

void emptyAndFullTest(Queue * q) {
	if (isQueueEmpty(q)) {
		println("Fila esta vazia");
	}

	fillQueue(q);

	if (isQueueFull(q)) {
		println("Fila esta cheia");
	}

	emptyQueue(q);

	if (isQueueEmpty(q)) {
		println("Fila esta vazia");
	}
}

void emptyQueue(Queue * q) {
	println("Esvaziando");
	while (!isQueueEmpty(q)) {
		removeFromQueue(q);
	}
	printQueueInfos(q);
}

void fillQueue(Queue * q) {
	println("Preenchendo");
	int count = 0;
	while (!isQueueFull(q)) {
		count++;
		insertOnQueue(q, count);
	}
	printQueueInfos(q);

}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeQueueTests(15);
	return 0;
}
