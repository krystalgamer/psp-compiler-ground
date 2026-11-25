#ifndef _LOADEXEC_H
#define _LOADEXEC_H
/* SDK prototypes as used by the decompiled code */
#include <kerneltypes.h>
int sceKernelLoadExec(const char *file, void *param);
void sceKernelExitGame(void);
int sceKernelRegisterExitCallback(SceUID cbid);
#endif
