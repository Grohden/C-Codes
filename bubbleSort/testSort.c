#include "bubbleSort.h"
#include "../utils.h"
#include "../SO/specifics.h"
#include <stdbool.h>
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

	int array[] = {2,2,4,87,4,64,4,55,15,37,68,6,48,6};
	int len = sizeof(array)/sizeof(int);

	bubbleSortIntArray(array, len);
	
	printIntArray(array,len);

	pause();

	return 0;
}
