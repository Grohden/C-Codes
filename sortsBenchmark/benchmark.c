#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../SO/specifics.h"
#include "../random/random.h"
#include "../utils.h"
#include "../selectionSort/selectionSort.h"
#include "../quickSort/quickSort.h"
#include "../insertionSort/insertionSort.h"
#include "../bubbleSort/bubbleSort.h"

void sumToSortData(SortData *source, SortData *destionation){
	destionation->swaps += source->swaps;
	destionation->comparisons += source->comparisons;
	
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	
	SortData *quickData 	= initSortData();
	SortData *selectionData = initSortData();
	SortData *insertionData = initSortData();
	SortData *bubbleData 	= initSortData();

	int len = 10;
	int i = 0;
	int swapCount;
	int * array;
	int * tempArray = calloc(len,sizeof(int));

	while(i++ < len){

		array = generateRandomArray(len);

		memcpy(tempArray, array, len * sizeof(int));
		sumToSortData(quickSortIntArray(tempArray, len), 	quickData);

		memcpy(tempArray, array, len * sizeof(int));		
		sumToSortData(selectionSortIntArray(tempArray, len),selectionData);

		memcpy(tempArray, array, len * sizeof(int));		
		sumToSortData(insertionSortIntArray(tempArray, len),insertionData);
		
		memcpy(tempArray, array, len * sizeof(int));	
		sumToSortData(bubbleSortIntArray(tempArray, len),	bubbleData);

		free(array);
	}

	println("selectionSort: \t Media de trocas %d, Media de comparacoes: %d", (selectionData->swaps)/len, (selectionData->comparisons)/len);
	println("bubbleSort: \t Media de trocas %d, Media de comparacoes: %d", 	  (bubbleData->swaps)/len, (bubbleData->comparisons)/len);
	println("quickSort: \t Media de trocas %d, Media de comparacoes: %d", 	  (quickData->swaps)/len, (quickData->comparisons)/len);
	println("insertionSort: \t Media de trocas %d, Media de comparacoes: %d", (insertionData->swaps)/len, (insertionData->comparisons)/len);
	system("pause");
}
