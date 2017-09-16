CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g

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

######################### LIBS #########################

RANDOM:
	$(CC) $(GCCFLAGS) -c $(dataStructsBasePath)/random/random.c

