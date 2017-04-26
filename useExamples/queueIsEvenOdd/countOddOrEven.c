#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../queue/queue.h"
#include "../../utils.h"
#include "countOddOrEven.h"


void countEvenOdd(Queue *q) {
	int odd = 0;
	int even = 0;


	printf("|");
	while (!isQueueEmpty(q)) {
		
		if (getFromQueue(q)%2 == 0 ) {
			even++;
		} else {
			odd++;
		}

		printf(" %d |", getFromQueue(q));
		removeFromQueue(q);
	}

	println("\nImpares: %4d | Pares: %4d", odd, even);

}