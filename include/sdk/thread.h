#ifndef _THREAD_H
#define _THREAD_H
/* SDK prototypes as used by the decompiled code */
#include <psptypes.h>
#include <kerneltypes.h>
SceUID sceKernelGetThreadId(void);
int sceKernelDelayThread(SceUInt delay);
int sceKernelChangeThreadPriority(SceUID thid, int priority);
typedef int (*SceKernelCallbackFunction)(int count, int arg1, int arg2);
SceUID sceKernelCreateCallback(const char *name, SceKernelCallbackFunction func, void *common);
int sceKernelDeleteCallback(SceUID cbid);
typedef SceInt32 (*SceKernelThreadEntry)(SceSize args, ScePVoid argp);
SceUID sceKernelCreateThread(const char *name, SceKernelThreadEntry entry, int initPriority, SceSize stackSize, SceUInt attr, void *option);
int sceKernelStartThread(SceUID thid, SceSize arglen, void *argp);
int sceKernelTerminateDeleteThread(SceUID thid);
int sceKernelGetThreadCurrentPriority(void);
SceUID sceKernelCreateSema(const char *name, SceUInt attr, int initVal, int maxVal, void *option);
int sceKernelDeleteSema(SceUID semaid);
int sceKernelSignalSema(SceUID semaid, int signal);
int sceKernelWaitSema(SceUID semaid, int signal, SceUInt *timeout);
int sceKernelExitThread(int status);
#endif
