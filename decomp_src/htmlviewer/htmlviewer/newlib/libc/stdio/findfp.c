/* upstream: newlib-1.12.0/newlib/libc/stdio/findfp.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin -fdata-sections */
#define __DYNAMIC_REENT__
#include "libc/stdio/findfp.c"

/* its static lock (.data.lock.0) is discarded: the module's .data (asm) has it */
