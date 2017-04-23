#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textualGUI.h"
#include "specifics.h"
#include "../utils.h"
#include "../chainedList/chainedList.h"

void drawList(ChainedList * options) {
	//2 lines more for height margin
	int boxHeight = getChainedListLength(options) + 2;

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
	int actualLine = boxInitialY + 1;

	system("cls");
	drawBox(
		longestWord+4,
		boxHeight,
		boxInitialX-2,
		boxInitialY
	);


	//Draw the box
	index = 0;
	each(index, getChainedListLength(options)) {
		mgotoxy(boxInitialX, actualLine);
		printf("%s",(char *) getFromChainedList(options, index));
		actualLine++;
	}

	mgotoxy(0, getScreenHeight() - 2);
}

/*
int selectableList(char * options[], int numberOfOptions, int sizeOfOptions) {
	if (kbhit()) {
		getch(); //prevent acidental enters
	}
	list(options, numberOfOptions, sizeOfOptions);
	int boxCols = SCREEN_WIDTH / 2;
	int boxLines = SCREEN_HEIGHT / 2;
	char halfOpts = (numberOfOptions) / 2;
	char itemsSize = (sizeOfOptions);
	int selectedOption = -halfOpts;
	//Select first item
	setTextColor(WHITE_BLACK);
	mgotoxy(boxCols - (itemsSize / 2), boxLines + selectedOption);
	printf(options[selectedOption + halfOpts]);

	char key;
	hidecursor();
	do {
		key = getch();
		if (key == -32) { //if its a arrow key
			key = getch();
			setTextColor(BLACK_WHITE);
			mgotoxy(boxCols - (itemsSize / 2), boxLines + selectedOption);
			printf(options[selectedOption + halfOpts]);

			switch (key) {
			case UP:
				selectedOption = selectedOption <= -halfOpts ? halfOpts : selectedOption - 1; //Infinite scroll
				break;
			case DOWN:
				selectedOption = selectedOption >= halfOpts ? -halfOpts : selectedOption + 1; //Infinite scroll
				break;
			}
			setTextColor(WHITE_BLACK);
			mgotoxy(boxCols - (itemsSize / 2), boxLines + selectedOption);
			printf("%s", options[selectedOption + halfOpts]);
		}
	} while (key != 13); //Enter key.
	return selectedOption + halfOpts;
}
*/

void drawBox(int width, int height, int x, int y) {
	int index = 0;
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
