#include "utils.h"
#include <stdio.h>

void swapVariables(int *i, int *j){
	if(i == j){
		return;
	}

    *i = (*i) + (*j);
    
    *j = (*i) - (*j);
    *i = (*i) - (*j);
}

void printIntArray(int array[], int size){
	int index = 0;
	each(index, size){
		printf("%d\t", array[index]);
	}
	printf("\n");
}