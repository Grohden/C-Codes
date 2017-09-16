#include "quickSort.h"
#include "../utils.h"
#include "../sortUtils.h"
#include "../SO/specifics.h" //pause
#include "../random/random.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 10;
	int i = 0;
	int swapCount;
	int * array;

	while(i++ < len){

		array = generateRandomArray(len);

		SortData *data = quickSortIntArray(array, len);
		println("quickSort: Swaps %d, Comparisons: %d", data->swaps, data->comparisons);

		printIntArray(array,len);
	}

	pause();

	return 0;
}
