#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../utils.h"
#include "../SO/specifics.h"
#include "../random/random.h"
#include "../quickSort/quickSort.h"
#include "../mergeSort/mergeSort.h"
#include "../bubbleSort/bubbleSort.h"
#include "../insertionSort/insertionSort.h"
#include "../selectionSort/selectionSort.h"

void sumToSortData(SortData *source, SortData *destionation){
	destionation->swaps += source->swaps;
	destionation->comparisons += source->comparisons;
	
}

int main(int argc, char * argv[]) {

	int len = 10;
	int i = 0;
	int swapCount;
	int * array;
	int * tempArray = calloc(len,sizeof(int));
	
	SortData *quickData 	= initSortData();

	SortData *selectionData = initSortData();
	
	SortData *insertionData = initSortData();
	
	SortData *bubbleData 	= initSortData();
	
	SortData *mergeData 	= initSortData();

	while(i++ < len){

		array = generateRandomArray(len);

		memcpy(tempArray, array, len * sizeof(int));

		sumToSortData(
			quickSortIntArray(tempArray, len),
			quickData
		);

		memcpy(tempArray, array, len * sizeof(int));		
		
		sumToSortData(
			selectionSortIntArray(tempArray, len),
			selectionData
		);

		memcpy(tempArray, array, len * sizeof(int));		
		
		sumToSortData(
			insertionSortIntArray(tempArray, len),
			insertionData
		);

		memcpy(tempArray, array, len * sizeof(int));		
		
		sumToSortData(
			mergeSortIntArray(tempArray, len),
			mergeData
		);

		memcpy(tempArray, array, len * sizeof(int));	
		sumToSortData(
			bubbleSortIntArray(tempArray, len),
			bubbleData
		);

		free(array);
	}

	println("bubbleSort: \t Media de trocas %d, Media de comparacoes: %d", 	  (bubbleData->swaps)/len, (bubbleData->comparisons)/len);
	println("mergeSort: \t Media de trocas %d, Media de comparacoes: %d", 	  (mergeData->swaps)/len, (mergeData->comparisons)/len);
	println("quickSort: \t Media de trocas %d, Media de comparacoes: %d", 	  (quickData->swaps)/len, (quickData->comparisons)/len);
	println("selectionSort: \t Media de trocas %d, Media de comparacoes: %d", (selectionData->swaps)/len, (selectionData->comparisons)/len);
	println("insertionSort: \t Media de trocas %d, Media de comparacoes: %d", (insertionData->swaps)/len, (insertionData->comparisons)/len);
	system("pause");
}
