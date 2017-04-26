#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

#ifndef _QUEUE_
#define _QUEUE_

typedef struct TypeQueue {
	//Index do ultimo a entrar (ultimo da fila)
	int last;
	//Index do primeiro a sair (primeiro da fila)
	int first;
	//Tamanho maximo
	int maxLength;
	//tamanho atual da fila
	int length;
	//Dados
	int * queueData;
} Queue;

Queue * initQueue(int maxLength);

int getFromQueue(Queue * queue);
void removeFromQueue(Queue * queue);
void insertOnQueue(Queue * queue, int value);

bool isQueueEmpty(Queue * queue);
bool isQueueFull(Queue * queue);
#endif //!_QUEUE_