#include "textualGUI.h"
#include <malloc.h>

int main(int *argv, int argc) {

	//char * str = calloc(10 * 10, sizeof(char));
	//drawBox(10, 10, 20, 10);

	char *c = "Batata";
	char *e = "Batata";
	
	char ** b = calloc(2, sizeof(char));
	b[0] = c;
	b[1] = e;
	
	drawList(b, 2, 7);

	return 0;
}