/* Stand-in for the SDK's kernel.h, which libstdc++'s bits/gthr-default.h
   (psp-gcc's gthr-psp.h) includes: the kernel calls it uses. */
#ifndef CXX_KERNEL_H
#define CXX_KERNEL_H

#define SCE_KERNEL_SA_THPRI 0x0100U

#ifdef __cplusplus
extern "C" {
#endif

extern int sceKernelCpuSuspendIntr(void);
extern int sceKernelCpuResumeIntr(int oldstat);
extern int sceKernelGetThreadId(void);
extern int sceKernelCreateSema(const char *s, int flg, int val, int max, const void *p);
extern int sceKernelDeleteSema(int id);
extern int sceKernelWaitSema(int id, int count, void *p);
extern int sceKernelPollSema(int id, int count);
extern int sceKernelSignalSema(int id, int count);

#ifdef __cplusplus
}
#endif

#endif
