/* upstream: newlib-1.12.0/newlib/libc/sys/psp/mlock.c (Sony's psp-newlib 1.8.x; not in newlib 1.12.0) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include <reent.h>

int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int);

/* the module's .bss (asm) has them */
#define static extern
static int locks;
static int saved_status;
#undef static

void
__malloc_lock(struct _reent *ptr)
{
	int oldst;

	oldst = sceKernelCpuSuspendIntr();
	if (locks == 0)
		saved_status = oldst;
	locks++;
}

void
__malloc_unlock(struct _reent *ptr)
{
	if (--locks == 0)
		sceKernelCpuResumeIntr(saved_status);
}
