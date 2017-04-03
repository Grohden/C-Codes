#include "../utils.h"
#include "../stack/stack.h"
#include <string.h>

//Diz se a frase � palindrome
bool isPalindrome(char * phrase, bool trim);

//Remove espa�os de uma frase
char * trimPhrase(char * phrase);

//Coloca a frase numa pilha
Stack * putPhraseOnStack(char * phrase);
