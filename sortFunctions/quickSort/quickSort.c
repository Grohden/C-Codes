#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../sortUtils.h"
#include "quickSort.h"

int partition(int array[], int size, int pivot, SortData *sortDataStruct)
{
	if (size <= 1)
	{
		return 0;
	}

	int pivotValue = array[pivot];
	int start = 0;
	int end = size - 1;

	while (start <= end)
	{

		while (array[start] <= pivotValue && start <= end)
		{
			sortDataStruct->comparisons++;
			start++;
		}

		while (array[end] > pivotValue && start <= end)
		{
			sortDataStruct->comparisons++;
			end--;
		}

		if (start <= end)
		{
			swapVariables(&array[start], &array[end]);
			sortDataStruct->swaps++;

			start++;
			end--;
		}
	}

	swapVariables(&array[pivot], &array[end]);
	sortDataStruct->swaps++;
			
	return end;
}

void delegatedQuickSort(int array[], int size, SortData *sortDataStruct){
	if (size <= 1)	{
		return;
	}

	int start = 0;
	int end = size - 1;

	if (start < end)
	{
		start = partition(array, size, 0, sortDataStruct);
		
		delegatedQuickSort(array, start, sortDataStruct);
		delegatedQuickSort(&array[start + 1], size - (start + 1), sortDataStruct);
	}
}


SortData* quickSortIntArray(int array[], int size){
	SortData *sortData = (SortData *) calloc(sizeof(SortData),1);
	sortData->comparisons = 0;
	sortData->swaps = 0;

	delegatedQuickSort(array, size, sortData);

	return sortData;
}
