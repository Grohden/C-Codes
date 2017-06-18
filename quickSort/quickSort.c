#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "quickSort.h"

int partition(int array[], int size, int pivot, int *swapCount)
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
			start++;
		}

		while (array[end] > pivotValue && start <= end)
		{
			end--;
		}

		if (start <= end)
		{
			swapVariables(&array[start], &array[end]);
			(*swapCount)++;

			start++;
			end--;
		}
	}

	swapVariables(&array[pivot], &array[end]);
	(*swapCount)++;
			
	return end;
}

int quickSortIntArray(int array[], int size)
{
	if (size <= 1)
	{
		return 0;
	}

	int swapCount = 0;

	int start = 0;
	int end = size - 1;

	if (start < end)
	{
		start = partition(array, size, 0, &swapCount);
		swapCount += quickSortIntArray(array, start);
		swapCount += quickSortIntArray(&array[start + 1], size - (start + 1));
	}

	return swapCount;
}
