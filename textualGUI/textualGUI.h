#include <stdbool.h>
#include "../chainedList/chainedList.h"

void drawBox(int width, int height, int x, int y);

int getLongestWordLen(ChainedList * chainedList);

void drawList(ChainedList * options);

int drawSelectableList(ChainedList *options, bool circularSelection);