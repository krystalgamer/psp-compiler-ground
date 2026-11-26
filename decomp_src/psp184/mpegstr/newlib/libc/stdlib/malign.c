/* upstream: newlib-1.12.0/newlib/libc/stdlib/malign.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin */
#define __DYNAMIC_REENT__
#include "libc/stdlib/malign.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/newlib/libc/stdlib/malign", D_00012964);
