/* upstream: newlib-1.12.0/newlib/libc/stdlib/malign.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/malign.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/utility_font_basho/nonmatchings/newlib/libc/stdlib/malign", D_000142A8);
