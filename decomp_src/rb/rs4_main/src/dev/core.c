/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int coreInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int coreTerm(void) {
    return 1;
}

unsigned int coreFunc(unsigned int *p)
{
	unsigned int x = *p;
	if ((x >> 26) == 2)
		return (x & 0xF0000000) | ((x & 0x3FFFFFF) << 2);
	return (unsigned int)p;
}
