/* upstream: newlib-1.12.0/newlib/libc/stdlib/mallocr.c (Sony's psp-newlib build: 16-byte MALLOC_ALIGNMENT) */
/* cflags: -O2 -fno-builtin */
#define INTERNAL_NEWLIB
#define DEFINE_REALLOC
#define MALLOC_ALIGNMENT 16
#include "libc/stdlib/mallocr.c"
