/* upstream: newlib-1.12.0/newlib/libc/sys/psp/atexit.c (Sony's psp-newlib 1.8.x; not in newlib 1.12.0) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include <stddef.h>
#include <stdlib.h>
#include <reent.h>

int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int);

int
atexit(void (*fn)(void))
{
	register struct _atexit *p;
	struct _reent *ptr;
	int oldst;

	oldst = sceKernelCpuSuspendIntr();
	ptr = (struct _reent *)_getmodreent();
	if ((p = ptr->_atexit) == NULL)
		ptr->_atexit = p = &ptr->_atexit0;
	if (p->_ind >= _ATEXIT_SIZE) {
		sceKernelCpuResumeIntr(oldst);
		if ((p = (struct _atexit *)_malloc_r(ptr, sizeof(*p))) == NULL)
			return -1;
		oldst = sceKernelCpuSuspendIntr();
		p->_ind = 0;
		p->_next = ptr->_atexit;
		p->_on_exit_args._fntypes = 0;
		ptr->_atexit = p;
	}
	p->_fns[p->_ind++] = fn;
	sceKernelCpuResumeIntr(oldst);
	return 0;
}
