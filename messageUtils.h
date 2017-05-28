#include <stdio.h>
#include "SO/specifics.h"

//Macros
#ifndef _ROHDEN_MSG_UTILS
#define _ROHDEN_MSG_UTILS 1

//Font colors (all bg black)
#define WHITE 7
#define RED 2
#define YELLOW 14

#define errorMsg(...); setTextColor(RED); println(__VA_ARGS__); setTextColor(WHITE);
#define warnMsg(...); setTextColor(YELLOW); println(__VA_ARGS__); setTextColor(WHITE);

#endif // !_ROHDEN_MSG_UTILS
