#include "bubbleSort.h"
#include "../utils.h"
#include "../sortUtils.h"
#include "../SO/specifics.h"
#include "../random/random.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 30;
	int * array = generateRandomArray(len);

	bubbleSortIntArray(array, len);

	printIntArray(array, len);

	pause();

	return 0;
}
