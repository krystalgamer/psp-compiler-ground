/* upstream: newlib-1.12.0/newlib/libc/locale/locale.c (unmodified) */
/* cflags: -O2 -fno-builtin */

/* The module's .data/.bss (asm) define the variables: declared first into
   .data.* sections, which the linker script discards (-fdata-sections would
   also move lconv out of .rodata), and weak in the assembler only.  charset
   is static: made global so that the module's label is the one used. */
#define DISCARD(n) __attribute__((section(".data." #n)))
extern int __mb_cur_max DISCARD(__mb_cur_max);
extern int __nlocale_changed DISCARD(__nlocale_changed);
extern int __mlocale_changed DISCARD(__mlocale_changed);
extern char *_PathLocale DISCARD(_PathLocale);
extern char *charset DISCARD(charset);
extern char __lc_ctype[12] DISCARD(__lc_ctype);
#undef DISCARD
#define static
#include "libc/locale/locale.c"
#undef static
__asm__(".weak __mb_cur_max\n.weak __nlocale_changed\n.weak __mlocale_changed\n"
        ".weak _PathLocale\n.weak charset\n.weak __lc_ctype");

/* labels the rest of the module's asm uses */
__asm__(".globl D_0000A760\nD_0000A760 = 0x0000A760");
