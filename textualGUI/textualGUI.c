#include "textualGUI.h"

/*Creates a message box with one option (i know, it is useless since we have list(), may i change this to a pop-up with timer*/

/* This function draw a box and put in the middle of screen, and put the options on center */
int drawList(char ** options, int numberOfOptions, int sizeOfOptions) {
	int cols = 20;
	int lines = 20;
	int boxCols = cols / 2;
	int boxLines = lines / 2;
	int index = 0;
	system("cls");

	drawBox(boxCols, boxLines, boxCols, boxLines);

	char halfOpts = (numberOfOptions) / 2;
	char itemsSize = (sizeOfOptions);

	each(index, numberOfOptions) {
		mgotoxy(boxCols*1.5+2, boxLines*1.5 - 1);
		printf(options[index]);
	}
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
	repeat((width * 2) - 2) {
		printf("%c", 205);
	}
	println("%c", 187);
	
	//Middle
	repeat(height - 2) {
		mgotoxy(x, y + actualY);
		actualY++;

		printf("%c", 186);
		repeat((width * 2) - 2) {
			printf("%c", ' ');
		}
		println("%c", 186);
	}
	
	//Bottom
	mgotoxy(x, y + actualY);
	printf("%c", 200);
	
	repeat((width * 2) - 2) {
		printf("%c", 205);
	}
	println("%c", 188);
}
