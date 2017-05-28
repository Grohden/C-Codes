#include <stdbool.h>
#include "../chainedList/chainedList.h"


#ifndef _TEXTUAL_GUI_
#define _TEXTUAL_GUI_

void drawBox(int width, int height, int x, int y);

int getLongestWordLen(ChainedList * chainedList);

void drawList(ChainedList * options);

int drawSelectableList(ChainedList *options, bool circularSelection);

#endif //!_TEXTUAL_GUI_