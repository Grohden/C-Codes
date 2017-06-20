CC=gcc

build: SELECTION_SORT INSERTION_SORT QUICK_SORT BUBBLE_SORT UTILS
	$(CC) benchmark.c selectionSort.o insertionSort.o quickSort.o bubbleSort.o sortUtils.o random.o -o benchmark

debug: SELECTION_SORT INSERTION_SORT QUICK_SORT BUBBLE_SORT UTILS
	$(CC) -g benchmark.c selectionSort.o insertionSort.o quickSort.o bubbleSort.o sortUtils.o random.o -o benchmark

SELECTION_SORT:
	$(CC) -c ../selectionSort/selectionSort.c

INSERTION_SORT:
	$(CC) -c ../insertionSort/insertionSort.c 

QUICK_SORT:
	$(CC) -c ../quickSort/quickSort.c

BUBBLE_SORT:
	$(CC) -c ../bubbleSort/bubbleSort.c

UTILS:
	$(CC) -c ../random/random.c ../sortUtils.c