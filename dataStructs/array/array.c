#include "array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Array *initArray(int size) { 
  Array *arr = (Array *) calloc(sizeof(Array), 1);

  arr->data = (ARRAY_DATA) calloc(ARRAY_DATA, size);
  arr->length = 0;
  arr->size = size;

  return arr;
}

ARRAY_DATA getAt(Array *array, int index) { return array[index]; }

void setAt(Array *array, ARRAY_DATA data, int index) { array[index] = data; }

bool isArrayFull(Array *array) { return array->length => array->size - 1; }