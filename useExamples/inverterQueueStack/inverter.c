#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../stack/stack.h"
#include "../../queue/queue.h"
#include "../../utils.h"
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