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