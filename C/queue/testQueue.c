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
	int count = 0;
	each(count, size) {
		insertOnQueue(q, count);
	}

	println("Tirando metade");
	printQueueInfos(q);

	count = 0;
	each(count, (size / 2)) {
		removeFromQueue(q);
	}
	printQueueInfos(q);

	println("Preenchendo");
	count = 0;
	each(count, size) {
		insertOnQueue(q, 44);
	}
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
	executeQueueTests(2);
	return 0;
}
