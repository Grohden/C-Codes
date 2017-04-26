#include <time.h>
#include <math.h>
#include "countOddOrEven.h"
#include "../../utils.h"


void fillQueue(Queue * q) {
	while (!isQueueFull(q)) {
		insertOnQueue(q, round(rand()/1000));
	}
}

void executeTests(int size) {
	Queue *q = initQueue(size);

	fillQueue(q);

	countEvenOdd(q);
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	srand(time(NULL));
	executeTests(15);
	return 0;
}
