@echo off && (
	gcc -Wall *.h *.c ../stack/stack.h ../stack/stack.c -o program
	program.exe
	pause
	del program.exe
)