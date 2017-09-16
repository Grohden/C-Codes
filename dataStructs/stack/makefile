CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g

##################### TASKS #####################

build: STACK UTILS TEST
	$(CC) $(GCCFLAGS) *.o -o main.exe

TEST:
	$(CC) $(GCCFLAGS) -c testStack.c

STACK:
	$(CC) $(GCCFLAGS) -c stack.c

UTILS:
	$(CC) $(GCCFLAGS) -c ../random/random.c
