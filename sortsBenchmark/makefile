CC=gcc

build: MAIN SELECTION_SORT INSERTION_SORT QUICK_SORT MERGE_SORT BUBBLE_SORT UTILS
	$(CC) benchmark.o selectionSort.o insertionSort.o quickSort.o mergeSort.o bubbleSort.o sortUtils.o random.o -o benchmark

debug: MAIN SELECTION_SORT INSERTION_SORT QUICK_SORT MERGE_SORT BUBBLE_SORT UTILS
	$(CC) -g benchmark.o selectionSort.o insertionSort.o quickSort.o mergeSort.o bubbleSort.o sortUtils.o random.o -o benchmark

MAIN:
	$(CC) -c -g benchmark.c

SELECTION_SORT:
	$(CC) -c ../selectionSort/selectionSort.c

INSERTION_SORT:
	$(CC) -c ../insertionSort/insertionSort.c 

QUICK_SORT:
	$(CC) -c ../quickSort/quickSort.c

MERGE_SORT:
	$(CC) -c ../mergeSort/mergeSort.c

BUBBLE_SORT:
	$(CC) -c ../bubbleSort/bubbleSort.c

UTILS:
	$(CC) -c ../random/random.c ../sortUtils.c