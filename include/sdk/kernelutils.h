#ifndef _KERNELUTILS_H
#define _KERNELUTILS_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
void sceKernelDcacheWritebackAll(void);
void sceKernelDcacheWritebackInvalidateAll(void);
void sceKernelDcacheWritebackRange(const void *p, unsigned int size);
int sceKernelIcacheProbe(const void *p);
#endif
