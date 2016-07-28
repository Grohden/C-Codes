#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <windows.h>

#define BLACK_WHITE 07
#define WHITE_BLACK 240
#define and &&
#define or ||
#define is ==
#define ln(); puts("");
#define out printf
#define ARR_SIZE 46

int printArr(int * arr, int size, int posOne,int posTwo){
	int x=0;
	for(x=0;x<size;x++){
		if(x==posOne or x==posTwo ){
			setTextColor(WHITE_BLACK);
		} 
		printf("%i" ,arr[x]);
		setTextColor(BLACK_WHITE);
		printf(" "); //make space have normal color.
	}
	setTextColor(BLACK_WHITE);
};

void sort(int * arr,int size){
	printArr(arr,size,-1,-1);	
	ln();
	
	int x=0;
	int loopCount=0;
	bool headChanged=false;
	bool tailChanged=false;
	int temp;
	do {
		headChanged=false;
		tailChanged=false;
		if(arr[x]>arr[x+1]){
			headChanged=true;
			temp=arr[x];
			arr[x]=arr[x+1];
			arr[x+1]=temp;
		}
		
		if(arr[size-x-1]>arr[size-x] and x>=1){
			tailChanged=true;
			temp=arr[size-x];
			arr[size-x]=arr[size-x-1];
			arr[size-x-1]=temp;
		}
		
		if(tailChanged or headChanged){
			ln();
			int tail=-1;
			int head=-1;
			if (tailChanged){
				tail=size-x;
			}
			if (headChanged) {
				head=x;
			}
			printArr(arr,size,tail,head);
			x=0;
		} else {
			x++;
		}
		loopCount++;
	} while((tailChanged or headChanged) or x<size-1);
	ln();
	out("Number of iterations: %i",loopCount);
}

int list[ARR_SIZE]={90, 89, 87, 86, 85, 84, 83, 82, 81,15,4,84,84,1,51,5,44,84,984,984,984,8,7,8,4,84,498,984,151,654,80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};



void mgotoxy(int x,int y){	
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
};

void setTextColor(int k){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}


int main(){
	sort(list,ARR_SIZE);	
}
