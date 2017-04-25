#include <malloc.h>
#include <string.h>
#include "../utils.h"
#include "textualGUI.h"
#include "specifics.h"
#include "../chainedList/chainedList.h"

#define SCREEN_RATIO 40

void testDrawList() {
	setScreenSize(SCREEN_RATIO*2, SCREEN_RATIO);

	ChainedList * c = initChainedList();

	addToChainedList(c, (void *) "A simple test");
	addToChainedList(c, (void *) "For a simple box");
	addToChainedList(c, (void *) "With some items");
	addToChainedList(c, (void *) "or maybe");
	addToChainedList(c, (void *) "Is a complex box?");
	drawList(c);
}

void testSelectableList() {
	setScreenSize(SCREEN_RATIO * 2, 40);

	ChainedList * c = initChainedList();

	addToChainedList(c, (void *) "Hello There :D");
	addToChainedList(c, (void *) "Im a simple selectable list");
	addToChainedList(c, (void *) "Press enter");
	addToChainedList(c, (void *) "To select one option");

	int selected = drawSelectableList(c, true);
	
	if (!selected) {
		println("Ginirul kanub!");
		return;
	}

	println("Selected : %d", selected);
}

int main(int argc, char **argv) {
	//testDrawList()

	testSelectableList();

	return 0;
}