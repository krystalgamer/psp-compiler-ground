/* Sony's psp-newlib libc/sys/psp/mlock.c (not in newlib 1.12.0) */
/* cflags: -O2 -fno-builtin */
#include "common.h"

struct _reent;

int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int intr);

/* static in the original; defined by the module's .bss (asm) */
extern int locks;
extern int saved_status;

void __malloc_lock(struct _reent *ptr)
{
	int intr = sceKernelCpuSuspendIntr();

	if (locks == 0)
		saved_status = intr;
	locks++;
}

void __malloc_unlock(struct _reent *ptr)
{
	if (--locks == 0)
		sceKernelCpuResumeIntr(saved_status);
}
