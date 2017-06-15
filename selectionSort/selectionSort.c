#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "selectionSort.h"

int selectionSortIntArray(int array[], int size){
	//Contadores
	int comparisons = 0;
	int swapCount = 0;

	int minorIndex;
	int i = 0;
	int j = 0;

	//index do atual elemento a ser trocado
	while(i < size){
		minorIndex = i;
		j = i;
		
		//Index da procura
		while(j < size){
			// Registra o index do menor valor
			if(array[j] < array[minorIndex]){
				minorIndex = j;
			}

			comparisons++;
			j++;
		}

		//Se realmente precisa trocar
		if(i != minorIndex){
			//Troca o atual pelo menor
			swapVariables(&array[i],&array[minorIndex]);
			swapCount++;
		}

		i++;
	}

	println("selectionSort: Swaps %d, Comparisons: %d", swapCount, comparisons);
	return swapCount;
}