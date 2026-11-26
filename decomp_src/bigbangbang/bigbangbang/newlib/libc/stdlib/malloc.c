/* upstream: newlib-1.12.0/newlib/libc/stdlib/malloc.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/malloc.c"

/* impure.o's "C" (_impure_data's locale name; the struct itself is .data) */
__asm__(".include \"include/labels.inc\"");
__asm__(".section .rodata\n.include \"tmp/asm/bigbangbang/bigbangbang/nonmatchings/newlib/libc/stdlib/malloc/D_0000C54C.s\"\n.section .text");
