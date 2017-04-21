#include <windows.h>
#include <stdio.h>

//These ones are specific for windows
#define BLACK_WHITE 07
#define WHITE_BLACK 240
#define SCREEN_WIDTH 150
#define SCREEN_HEIGHT 40

typedef enum { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 } direction;

void mgotoxy(int x, int y);

void setTextColor(int k);

void setScreenSize(int cols, int lines);

void hidecursor();