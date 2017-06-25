CC=gcc

build: MAIN TREE RANDOM
	$(CC) *.o -o tree

debug: MAIN TREE RANDOM
	$(CC) -g *.o -o tree

MAIN:
	$(CC) -g -c treeTest.c

TREE:
	$(CC) -c tree.c

RANDOM:
	$(CC) -c ../random/random.c