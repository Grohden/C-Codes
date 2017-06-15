#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "insertionSort.h"


int insertionSortIntArray(int array[], int size){
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

	println("insertionSort: Swaps %d, Comparisons: %d", swapCount, comparisons);
	return swapCount;
}
