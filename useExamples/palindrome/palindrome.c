#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../utils.h"
#include "../../stack/stack.h"
#include "palindrome.h"

//Diz se a frase é palindrome
bool isPalindrome(char * phrase, bool trim) {
	char * safePhrase = malloc(sizeof(char) * strlen(phrase));
	strcpy(safePhrase, phrase); //Copia para evitar manipulacoes indesejadas.

	if (trim) {
		safePhrase = trimPhrase(safePhrase);
	}

	//Coloca a frase numa pilha
	Stack * phraseStack = putPhraseOnStack(safePhrase);

	int index = 0;
	int phraseLen = strlen(safePhrase);
	bool isValid = true;
	
	//Nao sei se uma letra é considerada palindrome, entao vou retornar falso.
	if (phraseLen < 1) {
		return false;
	}

	do {
		isValid = getAndPopTopValue(phraseStack) == safePhrase[index];	
	} while (index++ < phraseLen && isValid);

	return isValid;
};

//Remove espaços de uma frase
char * trimPhrase(char * phrase) {
	int phraseLen = strlen(phrase);
	int newPhraseLen = 0;
	int index = 0;

	char * newPhrase = malloc(sizeof(char) * phraseLen);

	each(index, phraseLen) {
		if (phrase[index] != ' ') {
			newPhrase[newPhraseLen] = phrase[index];
			newPhraseLen += 1;
		}
	}
	
	newPhrase[newPhraseLen] = 0; //Finaliza a string

	return newPhrase;
};

//Coloca a frase numa pilha
Stack * putPhraseOnStack(char * phrase) {
	int phraseLen = strlen(phrase);
	int index = 0;
	Stack *stack = initStack(phraseLen + 1); //+ o \0

	push(stack, 0); //Coloca o final da string.
	each(index, phraseLen) {
		push(stack, phrase[index]);
	}

	return stack;
};