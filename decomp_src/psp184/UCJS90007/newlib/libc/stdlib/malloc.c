/* upstream: newlib-1.12.0/newlib/libc/stdlib/malloc.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include "libc/stdlib/malloc.c"
