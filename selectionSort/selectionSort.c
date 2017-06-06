#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "selectionSort.h"


void selectionSortIntArray(int array[], int size){
	int timesFoundMinor = 0;
	int minorIndex;
	int temp;
	int i = 0;
	int j = 0;

	while(i < size){
		minorIndex = i;
		j = i;
		while(j < size){
			if(array[j] < array[minorIndex]){
				minorIndex = j;
				timesFoundMinor++;
			}
			j++;
		}

		temp = array[i];
		array[i] = array[minorIndex];
		array[minorIndex] = temp;
		i++;
	}

	println("Times found minor for selection: %d", timesFoundMinor);
}