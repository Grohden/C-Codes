#include "insertionSort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../sortUtils.h"

SortData* insertionSortIntArray(int array[], int size) {
  SortData* sortData = initSortData();

  if (size <= 1) {
    return sortData;
  }

  int i = 0;
  int j = 0;

  while (i < size - 1) {
    j = i;

    while (j >= 0) {
      (sortData->comparisons)++;
      if (array[j] > array[j + 1]) {
        swapVariables(&array[j], &array[j + 1]);
        (sortData->swaps)++;
      } else {
        break;
      }

      j--;
    }

    i++;
  }

  return sortData;
}
