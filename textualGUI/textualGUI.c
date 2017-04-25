#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "textualGUI.h"
#include "specifics.h"
#include "../utils.h"
#include "../chainedList/chainedList.h"

#define TOP_PADDING 1
#define BOTTOM_PADDING 1
#define LEFT_PADDING 2
#define RIGHT_PADDING 2

int drawList(ChainedList * options) {
	ensureScreenSize();

	//2 lines more for height margin
	int boxHeight = getChainedListLength(options) + TOP_PADDING + BOTTOM_PADDING;
	int index = 0;
	int longestWord = 0;
	int wordLen = 0;

	//Get the longest word
	each(index, getChainedListLength(options)) {
		wordLen = strlen((char *) getFromChainedList(options, index));
		if (longestWord < wordLen) {
			longestWord = wordLen;
		}
	}

	int boxInitialX = ((getScreenWidth() / 2) - ((longestWord) / 2));
	int boxInitialY = ((getScreenHeight() / 2) - (boxHeight / 2));
	int actualLine = boxInitialY + TOP_PADDING;

	system("cls");
	drawBox(
		longestWord + LEFT_PADDING + RIGHT_PADDING,
		boxHeight,
		boxInitialX - LEFT_PADDING,
		boxInitialY
	);


	//Draw the box
	index = 0;
	each(index, getChainedListLength(options)) {
		mgotoxy(boxInitialX, actualLine);
		printf((char *) getFromChainedList(options, index));
		actualLine++;
	}

	//Just for system pause
	mgotoxy(0, getScreenHeight() - 2);

	return longestWord;
}


int drawSelectableList(ChainedList *options, bool circularSelection) {
	if (kbhit()) {
		getch(); //prevent acidental enters
	}

	setTextColor(BLACK_WHITE);

	int longestWord = drawList(options);
	int boxHeight = getChainedListLength(options);
	int initialX = ((getScreenWidth() / 2) - ((longestWord) / 2));
	int initialY = ((getScreenHeight() / 2) - (boxHeight / 2));
	int selectedOption = 0;

	//Select first item
	setTextColor(WHITE_BLACK);
	mgotoxy(initialX, initialY);
	printf((char *) getFromChainedList(options, selectedOption));

	char key;
	hidecursor();
	do {
		key = getch();
		if (key == -32) { //if its a arrow key
			key = getch();
			setTextColor(BLACK_WHITE);
			mgotoxy(initialX, initialY + selectedOption);
			printf((char *) getFromChainedList(options, selectedOption));

			switch (key) {
				case UP:
					if (selectedOption < 1) {
						selectedOption = circularSelection ? boxHeight-1 : 0;
					} else {
						selectedOption--;
					}

					break;
				case DOWN:
					if (selectedOption >= boxHeight-1) {
						selectedOption = circularSelection ? 0 : selectedOption;
					} else {
						selectedOption++;
					}

					break;
			}
			setTextColor(WHITE_BLACK);
			mgotoxy(initialX, initialY + selectedOption);
			printf((char *) getFromChainedList(options, selectedOption));
		}
	} while (key != 13); //Enter key.

	setTextColor(BLACK_WHITE);
	mgotoxy(0, getScreenHeight() - 2);

	return selectedOption;
}

void drawBox(int width, int height, int x, int y) {
	int actualY = 0;

	//Top
	mgotoxy(x, y + actualY);
	actualY++;

	printf("%c", 201);
	repeat((width) - 2) {
		printf("%c", 205);
	}
	println("%c", 187);
	
	//Middle
	repeat(height - 2) {
		mgotoxy(x, y + actualY);
		actualY++;

		printf("%c", 186);
		repeat((width) - 2) {
			printf("%c", ' ');
		}
		println("%c", 186);
	}
	
	//Bottom
	mgotoxy(x, y + actualY);
	printf("%c", 200);
	
	repeat((width) - 2) {
		printf("%c", 205);
	}
	println("%c", 188);
}
