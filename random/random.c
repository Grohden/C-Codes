#include "random.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int CALLED_SEED = 0;

void makeSureSeed(){
	if(!CALLED_SEED){
		srand(time(NULL));
		CALLED_SEED = 1;
	}
}

int getRandomNumber(){
    makeSureSeed();
	return rand();
};


int * generateRandomArray(int size){
	int arrayLen = -1;
	int * randomArray = (int *) calloc(size, sizeof(int));

	while(arrayLen++ <  size - 1){
		randomArray[arrayLen] = getRandomNumber()/100;
		//printf("%d \t", randomArray[arrayLen]);
	}

	return randomArray;
};