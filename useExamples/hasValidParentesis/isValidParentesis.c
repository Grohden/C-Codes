#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils.h"
#include "../../stack/stack.h"
#include "hasValidParentesis.h"

bool hasValidParentesis(char  * expression) {
	int expressionLen = strlen(expression);
	int index = 0;
	Stack * validationStack = initStack(expressionLen);
	each(index, expressionLen) {
		
		if (expression[index] == '(') {
			push(validationStack, '(');
		}

		if (expression[index] == ')') {
			if (isStackEmpty(validationStack)) {
				return false;
			} else {
				pop(validationStack);
			}
		}
	}

	return isStackEmpty(validationStack);
};