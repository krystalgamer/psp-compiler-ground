/* upstream: newlib-1.12.0/newlib/libc/stdlib/malign.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/malign.c"

/* locale's "C" string, split into this object's rodata */
__asm__(".pushsection .rodata\n.align 2\n.globl D_000312A0\nD_000312A0:\n.asciz \"C\"\n.align 2\n.popsection");
