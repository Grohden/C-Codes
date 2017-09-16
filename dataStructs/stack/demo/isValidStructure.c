#include "isValidStructure.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../stack/stack.h"
#include "../../utils.h"

char getOpenerFor(char closer) {
  switch (closer) {
    case '}':
      return '{';
    case ']':
      return '[';
    case ')':
      return '(';
  }

  return 0;
}

char getEnclosingFor(char opener) {
  switch (opener) {
    case '{':
      return '}';
    case '[':
      return ']';
    case '(':
      return ')';
  }
  return 0;
}

bool hasValidParentesis(char* expression) {
  int expressionLen = strlen(expression);
  int index = 0;

  Stack* closersStack = initStack(expressionLen);

  char indexChar;
  for (index = 0; index < expressionLen; index++) {
    indexChar = expression[index];

    if (getEnclosingFor(indexChar)) {
      push(closersStack, getEnclosingFor(indexChar));
    } else if (getOpenerFor(indexChar)) {
      if((char) peek(closersStack) != indexChar){
        println("Expected %c at column %d but found was %c", indexChar, index,
                (char)peek(closersStack));
        return false;
      } else {
        pop(closersStack);
      }
    }
  }

  return isStackEmpty(closersStack);
}

