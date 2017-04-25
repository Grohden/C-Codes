#include <stdbool.h>
#include "../chainedList/chainedList.h"

void drawBox(int width, int height, int x, int y);

int drawList(ChainedList * options);

int drawSelectableList(ChainedList *options, bool circularSelection);