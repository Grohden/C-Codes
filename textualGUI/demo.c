#include "textualGUI.h"
#include <malloc.h>
#include "specifics.h"
#include "../chainedList/chainedList.h"

int main(int **argv, int argc) {
	setScreenSize(60, 40);
	//char * str = calloc(10 * 10, sizeof(char));
	//drawBox(10, 10, 20, 10);
	

	char *one = "Batatassss";
	
	ChainedList * c = initChainedList();

	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	addToChainedList(c, (void *) one);
	
	drawList(c);

	return 0;
}