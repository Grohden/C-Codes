CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g


BUILD_ALL: DATA_STRUCTS SORT_FUNCTIONS LIBS

##################### DATA STRUCTS #####################

dataStructsBasePath = ./dataStructs

DATA_STRUCTS: CHAINED_LIST CHAINED_QUEUE STACK DOUBLE_CHAINED_LIST TREE DOUBLE_STACK DOUBLE_ENDED_QUEUE QUEUE

CHAINED_LIST:
	$(CC) -c $(dataStructsBasePath)/chainedList/chainedList.c

CHAINED_QUEUE:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/chainedQueue/chainedQueue.c

STACK:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/stack/stack.c

DOUBLE_CHAINED_LIST:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/doubleChainedList/doubleChainedList.c

TREE:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/tree/tree.c

DOUBLE_STACK:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/twoStack/twoStack.c
	
DOUBLE_ENDED_QUEUE:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/doubleEndedQueue/deque.c

QUEUE:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/queue/queue.c

################## SORT FUNCTIONS ######################

sortsBasePath = ./sortFunctions

SORT_FUNCTIONS: INSERTION_SORT QUICK_SORT MERGE_SORT SELECTION_SORT BUBBLE_SORT

INSERTION_SORT:SORT_UTILS
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/insertionSort/insertionSort.c

MERGE_SORT:SORT_UTILS
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/mergeSort/mergeSort.c

QUICK_SORT:SORT_UTILS
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/quickSort/quickSort.c

SELECTION_SORT:SORT_UTILS
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/selectionSort/selectionSort.c

BUBBLE_SORT:SORT_UTILS
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/bubbleSort/bubbleSort.c

SORT_UTILS:
	$(CC) $(GCCFLAGS) -c $(sortsBasePath)/sortUtils.c




######################### LIBS #########################

libsBasePath = ./libs

LIBS: RANDOM

RANDOM:
	$(CC) $(GCCFLAGS) -c $(libsBasePath)/random/random.c

