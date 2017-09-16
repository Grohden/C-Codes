CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g

##################### TASKS #####################

build: DOUBLE_CHAINED_LIST UTILS TEST
	$(CC) $(GCCFLAGS) *.o -o testChain

TEST:
	$(CC) $(GCCFLAGS) -c testChain.c

DOUBLE_CHAINED_LIST:
	$(CC) $(GCCFLAGS) -c doubleChainedList.c

UTILS:
	$(CC) $(GCCFLAGS) -c ../random/random.c
