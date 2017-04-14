#include "inverter.h"

void invert(Queue *q) {
	Stack * s= initStack(q->maxLength);

	while (!isQueueEmpty(q)) {
		push(s, getFromQueue(q));
		removeFromQueue(q);
	}

	while (!isStackEmpty(s)) {
		insertOnQueue(q, getAndPopTopValue(s));
	}

};