CC=gcc

build: MAIN TREE TEXTUAL_GUI CHAINED_LIST SO
	$(CC) *.o -o tree

debug: MAIN TREE TEXTUAL_GUI CHAINED_LIST SO
	$(CC) -g *.o -o tree

MAIN:
	$(CC) -g -c treeTest.c

TREE:
	$(CC) -c tree.c

CHAINED_LIST:
	$(CC) -c ../chainedList/chainedList.c

TEXTUAL_GUI: 
	$(CC) -c ../textualGUI/textualGUI.c 

SO: 
	$(CC) -c ../SO/specifics.c