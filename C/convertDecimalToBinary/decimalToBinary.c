#include "decimalToBinary.h"

char * convertDecimalToBinary(int number) {
	if ( number == 0 ) {
		return "0";
	}

	int stringCharCount = ceil(sqrt(number))+2;

	Stack * stack = initStack(stringCharCount);
	char * binaryString = calloc(stringCharCount + 1, sizeof(char));
	int divisionRest = 0;
	int count = 0;

	//Coloca no 
	while (number != 0) {
		divisionRest = number%2;
		number = number/2;

		push(stack, divisionRest);
	}


	while (!isStackEmpty(stack)) {
		binaryString[count] = numberToCharNumber(getAndPopTopValue(stack));
		count++;
	}

	return binaryString;
};


char numberToCharNumber(int number) {
	return 48 + number;
}