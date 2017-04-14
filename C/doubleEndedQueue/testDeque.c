#include <stdlib.h>
#include <stdio.h>
#include "deque.h"
#include "../utils.h"

void executeTests(int dequeSize);
void printDequeInfos(Deque *d);


void printDequeInfos(Deque *d) {
	println("=========================");
	println("Tamanho max. : %d", d->maxLength);
	println("Tamanho atual: %d", d->length);
	println("Esquerda: %d", d->left);
	println("Direita: %d", d->right);

	printf("\n|");
	int count = 0;
	each(count, d->maxLength) {
		printf(" %d |", d->data[count]);
	}

	println("\n=========================");
};


void executeTests(int dequeSize) {
	Deque *d = initDeque(dequeSize);
	printDequeInfos(d);

	removeFromLeft(d);
	removeFromRight(d);


	while (!isDequeFull(d))
	{
		insertOnLeft(d, rand());
		insertOnRight(d, rand());
		printDequeInfos(d);
	}

	system("pause && cls");

	while (!isDequeEmpty(d))
	{
		removeFromLeft(d);
		removeFromRight(d);
		printDequeInfos(d);
	}

	system("pause && cls");

	while (!isDequeFull(d))
	{
		insertOnLeft(d, rand());
		insertOnRight(d, rand());
		printDequeInfos(d);
	}


};

//TODO escrever os testes
int main(int argc, char * argv[]) {
	srand(time(NULL));
	executeTests(10);
	return 0;
}
