#include <malloc.h>
#include <string.h>
#include "../utils.h"
#include "textualGUI.h"
#include "../SO/specifics.h"
#include "../chainedList/chainedList.h"

#define SCREEN_RATIO 40

void testSelectableList() {
	//First we need to set screen size
	setScreenSize(SCREEN_RATIO * 2, 40);

	//We init the chained list
	ChainedList * c = initChain();

	//Add the items
	addToChain(c, (void *) "Hello There!");
	addToChain(c, (void *) "Im a simple selectable list");
	addToChain(c, (void *) "Press enter here to add more options");

	//Draw the seletable list and wait for the response
	int selected = drawSelectableList(c, true);

	//TODO: get a ANSCI art of General Grevious
	if (!selected) {
		println("Ginirul kanub!");
		return;
	}
	else if (selected == 2) {
		int maxInputLen = (getScreenWidth()/2);
		char *userInput = NULL;

		while (selected == 2) {
			userInput = calloc(maxInputLen, sizeof(char));
			printf("Type a new option (limited to %d chars):", maxInputLen);
			fgets(userInput, maxInputLen, stdin);

			//Remove \n
			userInput[strlen(userInput) - 1] = '\0';

			addToChain(c, userInput);
			selected = drawSelectableList(c, true);

			if(getChainLength(c) == getScreenHeight()) {
				setScreenSize(getScreenWidth(), getScreenHeight() + 2);
			}
		}

	}

	println("Selected is '%s', wich is at position %d",(char *) getChainDataAt(c, selected), selected);
}



void testDrawList() {
	//First we need to set screen size
	setScreenSize(SCREEN_RATIO*2, SCREEN_RATIO);

	//We init a chained list
	ChainedList * c = initChain();

	//Add the items
	addToChain(c, (void *) "A simple test");
	addToChain(c, (void *) "For a simple box");
	addToChain(c, (void *) "With some items");
	addToChain(c, (void *) "or maybe");
	addToChain(c, (void *) "Is a complex box?");
	//Then we draw a LIST
	drawList(c);
}

int main(int argc, char **argv) {
	//testDrawList()
	testSelectableList();

	return 0;
}