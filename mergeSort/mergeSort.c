#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "mergeSort.h"


void merge(int vetor[], int start, int middle, int end, SortData* sortDataStruct){
	int startOne = start;
	int startTwo = middle + 1;
	int comAux = 0;
	int tempArray[end - start + 1];

	while (startOne <= middle && startTwo <= end)
	{
		if (vetor[startOne] <= vetor[startTwo])
		{
			tempArray[comAux] = vetor[startOne];
			startOne++;
		}
		else
		{
			tempArray[comAux] = vetor[startTwo];
			startTwo++;
		}
		comAux++;
	}

	//Caso ainda haja elementos na primeira metade
	while (startOne <= middle){
		tempArray[comAux] = vetor[startOne];
		comAux++;
		startOne++;
	}

	//Caso ainda haja elementos na segunda metade
	while (startTwo <= end){ 
		tempArray[comAux] = vetor[startTwo];
		comAux++;
		startTwo++;
	}
	
	//Move os elementos de volta para o vetor original
	for (comAux = start; comAux <= end; comAux++){ 
		vetor[comAux] = tempArray[comAux - start];
	}
}

void delegatedMergeSort(int array[],int start, int end, SortData *sortDataStruct){
	if (start < end)
	{
		int middle = (start + end) / 2;

		delegatedMergeSort(array, start, middle, sortDataStruct);
		delegatedMergeSort(array, middle + 1, end, sortDataStruct);
		merge(array, start, middle, end, sortDataStruct);
	}
}

SortData *mergeSortIntArray(int array[], int size)
{
	SortData *sortData = initSortData();

	delegatedMergeSort(array, 0, size-1, sortData);

	return sortData;
}
