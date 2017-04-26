#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "textualGUI.h"
#include "specifics.h"
#include "../utils.h"
#include "../chainedList/chainedList.h"


//Paddings for boxes
#define TOP_PADDING 1
#define BOTTOM_PADDING 1
#define LEFT_PADDING 2
#define RIGHT_PADDING 2

int drawList(ChainedList * options) {
	//Ensure that the screen size is right
	ensureScreenSize();

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

	//Defines the X & Y initial axys to draw the list
	int boxInitialX = ((getScreenWidth() / 2) - ((longestWord) / 2));
	int boxInitialY = ((getScreenHeight() / 2) - (boxHeight / 2));
	//X will not change, but the Y will, we need to keep track of the actual line.
	int actualLine = boxInitialY + TOP_PADDING;


	//Clear the console before drawing the box
	clearScreen();
	
	//Draw a Box empty on screen center
	drawBox(
		longestWord + LEFT_PADDING + RIGHT_PADDING,
		boxHeight,
		boxInitialX - LEFT_PADDING,
		boxInitialY
	);


	//Draw the options
	index = 0;
	each(index, getChainedListLength(options)) {
		//Put at the right Y axys
		putCursorAt(boxInitialX, actualLine);
		//Print the option
		printf((char *) getFromChainedList(options, index));
		//go to next line
		actualLine++;
	}

	//put cursor at bottom, just for system pause
	putCursorAt(0, getScreenHeight() - 2);

	//Need to review this, nonsense return the longest word length
	return longestWord;
}


int drawSelectableList(ChainedList *options, bool circularSelection) {
	if (kbhit()) {
		getch(); //prevent acidental enters
	}

	setTextColor(BLACK_WHITE);

	//Draw the options list, wich returns the longest word len
	int longestWord = drawList(options);

	int boxHeight = getChainedListLength(options);
	int initialX = ((getScreenWidth() / 2) - ((longestWord) / 2));
	int initialY = ((getScreenHeight() / 2) - (boxHeight / 2));
	
	//Initial selected option
	int selectedOption = 0;

	//print the first item selected
	setTextColor(WHITE_BLACK);
	putCursorAt(initialX, initialY);
	printf((char *) getFromChainedList(options, selectedOption));

	char key;
	hidecursor();
	do {
		//Arrow keys output two chars, the first tells us if it is an arrow key.
		key = getch();
		if (key == -32) {
			key = getch(); //The second tell wich arrow key it is
			//'Erase' the last selection
			setTextColor(BLACK_WHITE);
			putCursorAt(initialX, initialY + selectedOption);
			printf((char *) getFromChainedList(options, selectedOption));

			//Process the arrow key
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
			//Print the selected
			setTextColor(WHITE_BLACK);
			putCursorAt(initialX, initialY + selectedOption);
			printf((char *) getFromChainedList(options, selectedOption));
		}
	} while (key != 13); //Enter key.

	//Assure the next print will be white with bg white
	setTextColor(BLACK_WHITE);
	//Put the cursor at the bottom
	putCursorAt(0, getScreenHeight() - 2);

	//Return the selected option number
	return selectedOption;
}

void drawBox(int width, int height, int x, int y) {
	int actualY = 0;

	//Print Top
	putCursorAt(x, y + actualY);
	actualY++;

	printf("%c", 201);
	repeat((width) - 2) {
		printf("%c", 205);
	}
	println("%c", 187);
	
	//Print Middle
	repeat(height - 2) {
		putCursorAt(x, y + actualY);
		actualY++;

		printf("%c", 186);
		repeat((width) - 2) {
			printf("%c", ' ');
		}
		println("%c", 186);
	}
	
	//Print Bottom
	putCursorAt(x, y + actualY);
	printf("%c", 200);
	
	repeat((width) - 2) {
		printf("%c", 205);
	}
	println("%c", 188);
}
