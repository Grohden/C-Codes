CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -g

##################### TASKS #####################

build: VALIDATE_ENCLOSING UTILS TEST
	$(CC) $(GCCFLAGS) *.o -o main.exe

TEST:
	$(CC) $(GCCFLAGS) -c testExpressions.c

VALIDATE_ENCLOSING: STACK
	$(CC) $(GCCFLAGS) -c isValidStructure.c

STACK:
	$(CC) $(GCCFLAGS) -c ../stack.c

UTILS:
	$(CC) $(GCCFLAGS) -c ../../random/random.c
