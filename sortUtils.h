//Macros
#ifndef _SORT_UTILS_
#define _SORT_UTILS_ 1

typedef struct TypeSortData {
    int comparisons;
    int swaps;
} SortData;

void swapVariables(int *i, int *j);

void printIntArray(int array[], int size);

#endif // _SORT_UTILS_
