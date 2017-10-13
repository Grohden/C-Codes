#include "quickSort.h"
#include "../../libs/random/random.h"

int comparer(void *t, void *f) {
    int x = (int) f;
    int y = (int) t;
    return y >= x;
}

//TODO escrever os testes
int main(int argc, char * argv[]) {

	int len = 10;
	int i = 0;
    void **array;

	while(i++ < len){

        array = (void **) generateRandomArray(len);

        quickSortIntArray(array, len, &comparer);
        printIntArray((int *) array, len);
	}

	return 0;
}
