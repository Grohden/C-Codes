#include <malloc.h>
#include <string.h>
#include "../utils.h"
#include "textualGUI.h"
#include "specifics.h"
#include "../chainedList/chainedList.h"

#define SCREEN_RATIO 40

void testSelectableList() {
	//First we need to set screen size
	setScreenSize(SCREEN_RATIO * 2, 40);

	//We init the chained list
	ChainedList * c = initChainedList();

	//Add the items
	addToChainedList(c, (void *) "Hello There :D");
	addToChainedList(c, (void *) "Im a simple selectable list");
	addToChainedList(c, (void *) "Press enter");
	addToChainedList(c, (void *) "To select one option");

	//Draw the seletable list and wait for the response
	int selected = drawSelectableList(c, true);

	//TODO: get a ANSCI art of General Grevious
	if (!selected) {
		println("Ginirul kanub!");
		return;
	}

	println("Selected : %d", selected);
}

void testDrawList() {
	//First we need to set screen size
	setScreenSize(SCREEN_RATIO*2, SCREEN_RATIO);

	//We init a chained list
	ChainedList * c = initChainedList();

	//Add the items
	addToChainedList(c, (void *) "A simple test");
	addToChainedList(c, (void *) "For a simple box");
	addToChainedList(c, (void *) "With some items");
	addToChainedList(c, (void *) "or maybe");
	addToChainedList(c, (void *) "Is a complex box?");
	//Then we draw a LIST
	drawList(c);
}

int main(int argc, char **argv) {
	//testDrawList()
	testSelectableList();

	return 0;
}