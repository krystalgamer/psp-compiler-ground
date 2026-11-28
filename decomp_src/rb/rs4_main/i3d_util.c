/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

int sceKernelDcacheWritebackAll(void);
int I3dWritebackDcache(void) {
    sceKernelDcacheWritebackAll();
    return 0;
}
