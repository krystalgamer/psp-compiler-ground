/* upstream: newlib-1.12.0/newlib/libc/stdlib/getenv_r.c (unmodified) */
/* cflags: -O2 -fno-builtin */

/* The module's .data (asm) defines p_environ: declared first into a .data.*
   section, which the linker script discards, and weak in the assembler only.
   It is static: made global so that the module's label is the one used. */
#define DISCARD(n) __attribute__((section(".data." #n)))
extern char ***p_environ DISCARD(p_environ);
#undef DISCARD
#define static
#include "libc/stdlib/getenv_r.c"
#undef static
__asm__(".weak p_environ");
