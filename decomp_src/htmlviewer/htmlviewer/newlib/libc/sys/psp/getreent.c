/* upstream: newlib-1.12.0/newlib/libc/sys/psp/getreent.c (Sony's psp-newlib 1.8.x; not in newlib 1.12.0) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include <stddef.h>
#include <reent.h>

struct _reent *
__getreent(void)
{
	register struct _reent **tsd __asm__("$26");
	struct _reent *reentp;

	if (tsd != NULL && (reentp = tsd[1]) != NULL)
		return reentp;
	return _impure_ptr;
}
