CC = gcc

build: TEXTUAL_GUI
	$(CC) *.o -o demo

######### TEXTUAL GUI AND ITS DEPENDENCYS ########

TextualGUIBasePath = ./libs

TEXTUAL_GUI: UTILS SO CHAINED_LIST 
	$(CC) -c $(TextualGUIBasePath)/textualGUI/textualGUI.c

CHAINED_LIST:
	$(CC) -c $(TextualGUIBasePath)/chainedList/chainedList.c

UTILS:
	$(CC) -c $(TextualGUIBasePath)/random/random.c

SO: 
	$(CC) -c $(TextualGUIBasePath)/SO/specifics.c

######################## ########################