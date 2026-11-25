#ifndef _THREAD_H
#define _THREAD_H
/* SDK prototypes as used by the decompiled code */
#include <kerneltypes.h>
SceUID sceKernelGetThreadId(void);
int sceKernelDelayThread(SceUInt delay);
int sceKernelChangeThreadPriority(SceUID thid, int priority);
typedef int (*SceKernelCallbackFunction)(int count, int arg1, int arg2);
SceUID sceKernelCreateCallback(const char *name, SceKernelCallbackFunction func, void *common);
int sceKernelDeleteCallback(SceUID cbid);
#endif
