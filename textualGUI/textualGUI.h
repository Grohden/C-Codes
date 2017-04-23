#include "../chainedList/chainedList.h"

/* This function draw a box and put in the middle of screen, and put the options on center
int list(char * options, int numberOfOptions, int sizeOfOptions);

/* This function uses the list function and implement arrow keys listening to navigate the options.
* it returns the number of chosed option.
int selectableList(char * options[], int numberOfOptions, int sizeOfOptions);

*/

void drawBox(int width, int height, int x, int y);

void drawList(ChainedList * options);