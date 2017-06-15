#include "insertionSort.h"
#include "../utils.h"
#include "../SO/specifics.h" //pause
#include "../random/random.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void printIntArray(int array[], int size){
	int index = 0;
	each(index, size){
		println(" index - %2d | nr - %d", index, array[index]);
	}
}

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 30;
	int * array = generateRandomArray(len);

	insertionSortIntArray(array, len);
	
	printIntArray(array,len);

	pause();

	return 0;
}
