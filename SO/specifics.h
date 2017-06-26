#include <stdlib.h>

#ifndef _SO_SPECIFICS_
#define _SO_SPECIFICS_

//These ones are specific for windows
#define BLACK_WHITE 07
#define WHITE_BLACK 240
#define SCREEN_WIDTH 150
#define SCREEN_HEIGHT 40

#define pause() system("pause")
//This should be a "macro"
#define clearScreen() system("cls")

//Keyboard numbers for arrows.
typedef enum { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 } direction;

int getScreenHeight();

int getScreenWidth();

void putCursorAt(int horizontalPosition, int verticalPosition);

void setTextColor(int k);

void setScreenSize(int cols, int lines);

void ensureScreenSize();

void hidecursor();
#endif // !_SO_SPECIFICS_
