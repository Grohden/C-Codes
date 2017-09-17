#include "sortUtils.h"
#include <stdio.h>
#include <stdlib.h>

void swapVariables(int *i, int *j) {
  if (i == j) {
    return;
  }

  *i = (*i) + (*j);

  *j = (*i) - (*j);
  *i = (*i) - (*j);
}

SortData *initSortData() {
  SortData *sortData = (SortData *)calloc(1, sizeof(SortData));
  sortData->swaps = 0;
  sortData->comparisons = 0;
  return sortData;
}

void printIntArray(int array[], int size) {
  int index = 0;

  for (index = 0; index < size; index++) {
    printf("%d\t", array[index]);
  }
  printf("\n");
}