@echo off && (
	gcc -Wall *.h *.c ../../utils.h ../../stack/stack.h ../../stack/stack.c ../../queue/queue.h ../../queue/queue.c -o program
	program.exe
	pause
	del program.exe
)