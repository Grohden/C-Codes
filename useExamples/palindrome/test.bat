@echo off && (
	gcc -Wall *.h *.c ../../utils.h ../../stack/stack.h ../../stack/stack.c -o program
	program.exe
	pause
	del program.exe
)