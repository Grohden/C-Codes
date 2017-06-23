#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
#include "../utils.h"
#include "../sortUtils.h"
#include "mergeSort.h"

void delegatedMergeSort(int array[], int size, SortData *sortDataStruct){
	println("size %d",size);
	if(size <= 1){
		printIntArray(array,size);
		return;
	} else {
		int middle = floor(size/2);
		delegatedMergeSort(array, middle,sortDataStruct);
		delegatedMergeSort(&array[middle], size - (middle),sortDataStruct);
	}
}


SortData* mergeSortIntArray(int array[], int size){
	SortData *sortData = initSortData();


 	delegatedMergeSort(array, size, sortData);

	return sortData;
}
