/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int (*l_pfnUtil)();
extern int (*l_pfnUtil)();

int UtilityLink(int arg0) {
    int var_v1;

    var_v1 = 0;
    if (l_pfnUtil == 0) {
        l_pfnUtil = arg0;
        var_v1 = 1;
    }
    return var_v1;
}

void UtilityUnlink(void) {
    l_pfnUtil = 0;
}

int UtilityUpdate(void) {
    int var_v0;

    var_v0 = -1;
    if (l_pfnUtil != NULL) {
        var_v0 = l_pfnUtil();
    }
    return var_v0;
}

int UtilityState(void) {
    return l_pfnUtil != 0;
}
