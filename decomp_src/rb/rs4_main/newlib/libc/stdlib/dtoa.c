/* upstream: newlib-1.12.0/newlib/libc/stdlib/dtoa.c (Sony's psp-newlib build: _REENT is __getreent(); its doubles in .rodata between the strings and the jump table: -fno-merge-constants) */
/* cflags: -O2 -fno-builtin -fno-merge-constants */
/* data-align: 8 */
#define __DYNAMIC_REENT__
#include "libc/stdlib/dtoa.c"
