#include <stdbool.h>


#ifndef ARRAY_DATA
#define ARRAY_DATA int*
#endif  // !ARRAY_DATA

#ifndef _ARRAY_
#define _ARRAY_

typedef struct TypeArray {
  ARRAY_DATA data;
  int length;
  int size;
} Array;

ARRAY_DATA getAtArray(Array *array, int index);

bool addToArray(Array *array, ARRAY_DATA data);

bool setAtArray(Array *array, ARRAY_DATA data, int index);

int getArrayLenght(Array *array);

bool isArrayFull(Array *array);

#endif  // !_ARRAY_
