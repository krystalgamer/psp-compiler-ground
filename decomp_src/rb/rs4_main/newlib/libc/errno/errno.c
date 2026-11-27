/* upstream: newlib-1.12.0/newlib/libc/errno/errno.c (Sony's psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include "libc/errno/errno.c"
