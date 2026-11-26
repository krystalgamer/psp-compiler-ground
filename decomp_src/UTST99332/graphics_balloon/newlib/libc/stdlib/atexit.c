/* upstream: newlib-1.12.0/newlib/libc/stdlib/atexit.c (unmodified) */
/* cflags: -O2 -fno-builtin -fdata-sections */
#include "libc/stdlib/atexit.c"

/* its static lock (.data.lock.0) is discarded: the module's .data (asm) has it */
