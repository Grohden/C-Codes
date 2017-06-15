#include "selectionSort.h"
#include "../utils.h"
#include "../SO/specifics.h"
#include "../random/random.h"
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

	int len = 10;
	int * array = generateRandomArray(len);	
	
	selectionSortIntArray(array, len);
	
	printIntArray(array, len);

	pause();

	return 0;
}
