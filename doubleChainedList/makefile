CC=gcc ##'C:/Program Files (x86)/Dev-Cpp/MinGW64/bin/gcc.exe'
GCCFLAGS=-Wall -std=c99 -g

##################### TASKS #####################

build: TEST DOUBLE_CHAINED_LIST TEXTUAL_GUI
	$(CC) $(GCCFLAGS) *.o -o testChain

debug: TEST DOUBLE_CHAINED_LIST TEXTUAL_GUI
	$(CC) $(GCCFLAGS) -g *.o -o testChain

TEST:
	$(CC) $(GCCFLAGS) -c testChain.c

DOUBLE_CHAINED_LIST:
	$(CC) $(GCCFLAGS) -c doubleChainedList.c

	
######### TEXTUAL GUI AND ITS DEPENDENCIES ########

TextualGUIBasePath = ..

TEXTUAL_GUI: UTILS SO CHAINED_LIST 
	$(CC) $(GCCFLAGS) -c $(TextualGUIBasePath)/textualGUI/textualGUI.c

CHAINED_LIST:
	$(CC) $(GCCFLAGS) -c $(TextualGUIBasePath)/chainedList/chainedList.c

UTILS:
	$(CC) $(GCCFLAGS) -c $(TextualGUIBasePath)/random/random.c

SO:
	$(CC) $(GCCFLAGS) -c $(TextualGUIBasePath)/SO/specifics.c

######################## ########################