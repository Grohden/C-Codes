#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "bubbleSort.h"


int bubbleSortIntArray(int array[], int size){
	int swapCount = 0;
	int index = 0;
	int n = 1;
	int tempValue;
	bool isOrdered = false;

	//Enquanto nao estiver ordenado
	while(!isOrdered){
		isOrdered = true;
		//Enquanto nao tiver ordenado todos
		while(index < size - n){
			//Se achou alguem para ordenar (Sempre garante que o maior vai para o final)
			if(array[index] > array[index + 1]){
				tempValue 		= array[index];
				array[index] 		= array[index + 1];
				array[index + 1	]	= tempValue;
				
				swapCount++;

				//Diz que nao esta ordenado
				isOrdered = false;
			}
			index++;
		}

		//Reseta o index
		index = 0;
		n++;
	}

	//println("Swap count for bubble: %d", swapCount);
	
	return swapCount;
}
