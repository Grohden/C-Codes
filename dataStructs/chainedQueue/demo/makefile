CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g

##################### TASKS #####################

build: CHAINED_QUEUE TEST
	$(CC) $(GCCFLAGS) *.o -o main.exe

TEST:
	$(CC) $(GCCFLAGS) -c cards.c

CHAINED_QUEUE:
	$(CC) $(GCCFLAGS) -c ../chainedQueue.c