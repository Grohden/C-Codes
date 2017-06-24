CC=gcc

build: MAIN TREE
	$(CC) *.o -o tree

debug: MAIN TREE
	$(CC) -g *.o -o tree

MAIN:
	$(CC) -c treeTest.c

TREE:
	$(CC) -c tree.c