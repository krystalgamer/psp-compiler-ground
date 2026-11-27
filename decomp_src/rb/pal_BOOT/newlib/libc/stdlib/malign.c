/* upstream: newlib-1.12.0/newlib/libc/stdlib/malign.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/malign.c"

/* impure.o's "C" (_impure_data's locale name; the struct itself is .data) */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/newlib/libc/stdlib/malign", D_00017850);
