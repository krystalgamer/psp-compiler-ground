/* upstream: newlib-1.12.0/newlib/libc/stdlib/mallocr.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#define INTERNAL_NEWLIB
#define DEFINE_REALLOC
#define MALLOC_ALIGNMENT 16
#include "libc/stdlib/mallocr.c"
