#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "queue.h"


Queue * initQueue(int maxLength) {
	Queue *q = malloc(sizeof(Queue));
	q->first = -1;
	q->last = -1;
	q->length = 0;
	q->maxLength = maxLength;
	q->queueData = calloc(maxLength, sizeof(int));

	return q;
};

int getFromQueue(Queue * queue) {
	if (isQueueEmpty(queue)) {
		println("Can't get value, queue is empty");
		return 0;
	}
	
	return queue->queueData[queue->first+1];
};

void removeFromQueue(Queue * queue) {
	if (isQueueEmpty(queue)) {
		println("Can't remove value, queue is empty");
		return;
	}

	if ((queue->maxLength-1) == queue->first) {
		queue->first = 0;
	}
	else {
		queue->first++;
	}

	queue->queueData[queue->first] = -1;


	queue->length--;
};
void insertOnQueue(Queue * queue, int value) {
	if (isQueueFull(queue)) {
		println("Can't insert value, queue is full");
		return;
	}

	if ((queue->maxLength - 1) == queue->last) {
		queue->last = 0;
	}
	else {
		queue->last++;
	}

	queue->queueData[queue->last] = value;

	queue->length++;
};

bool isQueueEmpty(Queue * queue) {
	return !queue->length;
};

bool isQueueFull(Queue * queue) {
	return queue->length == queue->maxLength;
};