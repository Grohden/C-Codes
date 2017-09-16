CC=gcc

build: MAIN CHAINED_LIST SO
	$(CC) *.o -o chained

debug: MAIN CHAINED_LIST SO
	$(CC) -g *.o -o chained

MAIN:
	$(CC) -g -c testChainedList.c

CHAINED_LIST:
	$(CC) -c chainedList.c

SO: 
	$(CC) -c ../SO/specifics.c

