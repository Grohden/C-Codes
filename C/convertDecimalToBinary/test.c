#include "decimalToBinary.h"
#include <string.h>

bool testConversion();

bool testConversion() {
	
	//1
	printf("\nExecutando teste 1, 1 - 1\n");
	bool testOne = strcmp("1", convertDecimalToBinary(1)) == 0;
	printf("\nTeste 1 %s\n", testOne ? "passou" : "falhou");

	system("pause && cls");
	
	//2
	printf("\nExecutando teste 2, 2 - 10\n");
	bool testTwo = strcmp("10", convertDecimalToBinary(2)) == 0;
	printf("\nTeste 2 %s\n", testTwo ? "passou" : "falhou");

	system("pause && cls");

	//4
	printf("\nExecutando teste 3, 4 - 100\n");
	bool testTree = strcmp("100", convertDecimalToBinary(4)) == 0;
	printf("\nTeste 3 %s\n", testTree ? "passou" : "falhou");
	
	system("pause && cls");

	//8
	printf("\nExecutando teste 4, 8 - 1000\n");
	bool testFour = strcmp("1000", convertDecimalToBinary(8)) == 0;
	printf("\nTeste 4 %s\n", testFour ? "passou" : "falhou");
	
	system("pause && cls");

	//255
	printf("\nExecutando teste 5, 255 - 11111111\n");
	bool testFive = strcmp("11111111", convertDecimalToBinary(255)) == 0;
	printf("\nTeste 5 %s\n", testFive ? "passou" : "falhou");

	system("pause && cls");

	//256
	printf("\nExecutando teste 6, 256 - 100000000\n");
	bool testSix = strcmp("100000000", convertDecimalToBinary(256)) == 0;
	printf("\nTeste 6 %s\n", testFive ? "passou" : "falhou");

	return testOne && testTwo && testTree && testFour && testFive && testSix;
};

//TODO escrever os testes
int main(int argc, char * argv[]) {
	testConversion();
	return 0;
}
