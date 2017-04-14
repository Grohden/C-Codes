@echo off && (
	gcc -Wall *.h *.c ../utils.h ../queue/queue.c ../queue/queue.h -o program
	program.exe
	pause
	del program.exe
)