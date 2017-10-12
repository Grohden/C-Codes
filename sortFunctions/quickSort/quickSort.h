#include <stdbool.h>
#include "../sortUtils.h"

#ifndef _QUICK_SORT_
#define _QUICK_SORT_

SortData *quickSortIntArray(void **array, int size, int ((*predicate)(void *, void *)));

#endif // !_QUICK_SORT_
