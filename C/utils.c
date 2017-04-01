
//Macros
#ifndef _ROHDEN_UTILS
#define _ROHDEN_UTILS 1

#define each(count, maxVal) for(count = 0; count < (maxVal); count++)
#define repeat(x) for(int i = 0; i < x; i++)
#define println(...) printf(__VA_ARGS__); printf("/n");

//Debug messages
#define _USE_DEBUG 1
#if _USE_DEBUG
#define debugMsg(...) println(__VA_ARGS__);)
#else
#define debugMsg(...) NULL;
#endif

#endif // _ROHDEN_UTILS
