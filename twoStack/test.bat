@echo off && (
	gcc -Wall *.h *.c ../utils.h -o program
	program.exe
	pause
	del program.exe
)