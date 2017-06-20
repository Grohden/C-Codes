#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "insertionSort.h"

SortData* insertionSortIntArray(int array[], int size){
	SortData *sortData = (SortData *) calloc(sizeof(SortData),1);
	sortData->comparisons = 0;
	sortData->swaps = 0;

	if(size <= 1){
		return sortData;
	}

	int swapCount = 0;
	int comparisons = 0;

	int i = 0;
	int j = 0;
	
	while(i < size - 1){
		j = i;

		while(j >= 0){
			comparisons++;
			if(array[j] > array[j + 1]){
				swapVariables(&array[j],&array[j+1]);
				swapCount++;
			} else {
				break;
			}
			
			j--;
		}

		i++;
	}

	sortData->comparisons = comparisons;
	sortData->swaps = swapCount;
	return sortData;
}
