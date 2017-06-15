#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "bubbleSort.h"


int bubbleSortIntArray(int array[], int size){
	bool isOrdered = false;
	int swapCount = 0;
	int comparisons = 0;
	int index = 0;
	int n = 1;

	//Enquanto nao estiver ordenado
	while(!isOrdered){
		isOrdered = true;
		//Enquanto nao tiver ordenado todos
		while(index < size - n){
			//Se achou alguem para ordenar (Sempre garante que o maior vai para o final)
			if(array[index] > array[index + 1]){
				swapVariables(&array[index],&array[index+1]);				
				swapCount++;

				//Diz que nao esta ordenado
				isOrdered = false;
			}
			comparisons++;
			index++;
		}

		//Reseta o index
		index = 0;
		n++;
	}

	println("bubbleSort: Swaps %d, Comparisons: %d", swapCount, comparisons);
	
	return swapCount;
}
