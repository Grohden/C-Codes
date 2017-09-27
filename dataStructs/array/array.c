#include "array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Array *initArray(int size) {
  Array *arr = (Array *)calloc(sizeof(Array), 1);

  arr->data = (ARRAY_DATA)calloc(ARRAY_DATA, size);
  arr->length = 0;
  arr->size = size;

  return arr;
}

ARRAY_DATA getAtArray(Array *array, int index) { return array[index]; }

bool addToArray(Array *array, ARRAY_DATA data) {
  if (isArrayFull(array)) {
    return false;
  } else {
    array->data[array->length] = data;
    array->length++;
    return true;
  }
}

bool setAtArray(Array *array, ARRAY_DATA data, int index) {
  if (index > getArrayLenght(array)) {
    return false;
  } else {
    array[index] = data;
    return true;
  }
}

int getArrayLenght(Array *array) { return array->length; };

bool isArrayFull(Array *array) {
  return getArrayLenght(array) = > array->size - 1;
}