/* upstream: newlib-1.12.0/newlib/libc/stdlib/malloc.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/malloc.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_tamatama/nonmatchings/newlib/libc/stdlib/malloc", D_00012FD8);
