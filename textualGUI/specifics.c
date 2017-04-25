#include "specifics.h"
#include <windows.h>
#include <stdio.h>

int _screenHeight_ = 0;
int _screenWidth_ = 0;
char *screenSizeCommand;


void mgotoxy(int x, int y) {
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
};

void setTextColor(int k) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void setScreenSize(int cols, int lines) {
	//Command string format
	char format[] = "mode con:cols=%d lines=%d";
	char command[1];
	sprintf(command, format, cols, lines);
	system(command);

	screenSizeCommand = &command;

	_screenHeight_ = lines;
	_screenWidth_ = cols;
};

void ensureScreenSize() {
	if (screenSizeCommand) {
		system(screenSizeCommand);
	}
}


int getScreenHeight() {
	return _screenHeight_;
}

int getScreenWidth() {
	return _screenWidth_;
}

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}