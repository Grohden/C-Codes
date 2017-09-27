#include <stdbool.h>

//Support to define chain queue data.
#ifndef ARRAY_DATA
#define ARRAY_DATA int*
#endif  // !ARRAY_DATA

#ifndef _ARRAY_
#define _ARRAY_

typedef struct Array Array;

struct Array {
  ARRAY_DATA data;
  int length;
  int size;
};

Array *initArray(int size);

ARRAY_DATA getAt(Array *array, int index);

void setAt(Array *array, ARRAY_DATA data, int index);

bool isArrayFull(Array *array);

#endif  // !_ARRAY_
