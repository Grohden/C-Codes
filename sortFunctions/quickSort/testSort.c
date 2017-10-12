#include "quickSort.h"
#include "../../utils/utils.h"
#include "../../libs/random/random.h"

int comparer(void *t, void *f) {
    int x = (int) f;
    int y = (int) t;
    return y < x;
}

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 10;
	int i = 0;
    void **array;

	while(i++ < len){

        array = (void **) generateRandomArray(len);

        SortData *data = quickSortIntArray(array, len, &comparer);
		println("quickSort: Swaps %d, Comparisons: %d", data->swaps, data->comparisons);

        printIntArray((int *) array, len);
	}

	return 0;
}
