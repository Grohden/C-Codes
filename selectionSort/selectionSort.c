#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "selectionSort.h"



void printItArray(int array[], int size){
	int index = 0;
	each(index, size){
		printf(" %d ", array[index]);
	}

	printf("\n size %d", size);
	printf("\n");
	printf("\n");
	printf("\n");
}

void selectionSortIntArray(int array[], int size){
	int timesFoundMinor = 0;
	int minorIndex;
	int temp;
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
				timesFoundMinor++;
			}
			j++;
		}

		//Se realmente precisa trocar
		if(i != minorIndex){
			//Troca o atual pelo menor
			temp = array[i];
			array[i] = array[minorIndex];
			array[minorIndex] = temp;
		}

		printItArray(array,size);
		i++;
	}

	println("Times found minor for selection: %d", timesFoundMinor);
}