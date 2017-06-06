#include "selectionSort.h"
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

	int array[] = {9,85,6,4,7,8,10,6,83,2,51,0,-1};
	int len = sizeof(array)/sizeof(int);

	selectionSortIntArray(array, len);
	
	printIntArray(array, len);

	pause();

	return 0;
}
