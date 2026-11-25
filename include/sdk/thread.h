#ifndef _THREAD_H
#define _THREAD_H
/* SDK prototypes as used by the decompiled code */
#include <kerneltypes.h>
SceUID sceKernelGetThreadId(void);
int sceKernelDelayThread(SceUInt delay);
#endif
