#include "palindrome.h"
#include "../utils.h"
#include <string.h>

bool testPhrase() {
	bool testOne = isPalindrome("ovo", false);
	println("======= (S/ Trim) Teste 1 - OVO ======= ");
	println("======= Teste 1 - %s", testOne ? "passou" : "falhou");
	system("pause && cls");

	bool testTwo  = isPalindrome("arara", false);
	println("======= (S/ Trim) Teste 2 - ARARA ======= ");
	println("======= Teste 2 - %s", testTwo ? "passou" : "falhou");
	system("pause && cls");

	bool testTree = !isPalindrome("galinha", false);
	println("======= (S/ Trim) Teste 3 - GALINHA ======= ");
	println("======= Teste 3 - %s", testTree ? "passou" : "falhou");
	system("pause && cls");

	bool testFour = !isPalindrome("a na", false);
	println("======= (S/ Trim) Teste 4 - A NA ======= ");
	println("======= Teste 4 - %s", testFour ? "passou" : "falhou");
	system("pause && cls");

	return testOne && testTwo && testTree && testFour;
};

bool testPhraseTrim() {
	bool testOne = isPalindrome("ovo", true);
	println("======= (C/ Trim) Teste 1 - OVO ======= ");
	println("======= Teste 1 - %s", testOne ? "passou" : "falhou");
	system("pause && cls");

	bool testTwo = !isPalindrome("arara arar", true);
	println("======= (C/ Trim) Teste 2 - arara arar ======= ");
	println("======= Teste 2 - %s", testTwo ? "passou" : "falhou");
	system("pause && cls");

	bool testTree = isPalindrome("AB BA", true);
	println("======= (C/ Trim) Teste 3 - AB BA ======= ");
	println("======= Teste 3 - %s", testTree ? "passou" : "falhou");
	system("pause && cls");

	bool testFour = isPalindrome("SOCORRAM ME SUBI NO ONIBUS EM MARROCOS", true);
	println("======= (C/ Trim) Teste 4 - SOCORRAM ME SUBI NO ONIBUS EM MARROCOS ======= ");
	println("======= Teste 4 - %s", testFour ? "passou" : "falhou");
	system("pause && cls");

	return testOne && testTwo && testTree && testFour;
}

void testTrim() {
	char testOneStr[] = "teste com alguns espacos";
	char * trimmedOneStr = trimPhrase(testOneStr);
	println("======= Teste 1 trim - %s - %s", trimmedOneStr, strcmp(trimmedOneStr, "testecomalgunsespacos") == 0 ? "passou" : "falhou");
	system("pause && cls");


	char testTwoStr[] = "a         e        a          e";
	char * trimmedTwoStr = trimPhrase(testTwoStr);
	println("======= Teste 2 trim %s - %s", trimmedTwoStr,strcmp(trimmedTwoStr, "aeae") == 0 ? "passou" : "falhou");
	system("pause && cls");


};

//TODO escrever os testes
int main(int argc, char * argv[]) {
	//testTrim();
	testPhrase();
	testPhraseTrim();
	return 0;
}
