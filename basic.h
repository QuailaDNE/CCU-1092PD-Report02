#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>

#define  DEFMAXHASH 	1<<20
#define  int32 			unsigned int

struct timeval start, end, diff;