/* cflags: -Os */
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/core", coreFunc);
