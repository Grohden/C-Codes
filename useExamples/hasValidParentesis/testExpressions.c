#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils.h"
#include "hasValidParentesis.h"

void executeStackTests() {
	
	bool testOne = hasValidParentesis("(1+1)");
	println("====== Teste 1 %s =======", testOne ? "passou" : "falhou");

	bool testTwo= !hasValidParentesis("(1+1");
	println("====== Teste 2 %s =======", testTwo ? "passou" : "falhou");

	bool testTree = !hasValidParentesis("(156))");
	println("====== Teste 3 %s =======", testTree ? "passou" : "falhou");
	
	bool testFour = hasValidParentesis("(1+(2+0+(3+5(1+3))))"); 
	println("====== Teste 4 %s =======", testFour ? "passou" : "falhou");
}


void getTestFromUser() {
	char *str = (char *) malloc(sizeof(char) * 50);
	printf("\nDigite uma expressao:");
	gets(str);

	println("Expressao eh %s ", hasValidParentesis(str) ? "valida" : "invalida");
}

//TODO escrever os testes
int main(int argc, char * argv[]) {
	executeStackTests();

	getTestFromUser();
	return 0;
}
