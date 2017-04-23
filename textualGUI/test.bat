@echo off && (
	gcc -Wall *.h *.c ../utils.h ../chainedList/chainedList.h ../chainedList/chainedList.c -o program
	program.exe
	pause
	del program.exe
)