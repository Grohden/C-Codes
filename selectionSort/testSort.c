#include "selectionSort.h"
#include "../utils.h"
#include "../sortUtils.h"
#include "../SO/specifics.h"
#include "../random/random.h"
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 10;
	int * array = generateRandomArray(len);	
	
	SortData *data = selectionSortIntArray(array, len);

	println("selectionSort: Swaps %d, Comparisons: %d", data->swaps, data->comparisons);
	printIntArray(array, len);

	pause();

	return 0;
}
