/* upstream: newlib-1.12.0/newlib/libc/stdlib/mallocr.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent(), 16-byte MALLOC_ALIGNMENT) */
/* cflags: -O2 -fno-builtin -fdata-sections */
#define __DYNAMIC_REENT__
#define INTERNAL_NEWLIB
#define DEFINE_MALLOC
#define MALLOC_ALIGNMENT 16
#include "libc/stdlib/mallocr.c"

/* The module's .data/.bss (asm) define these: -fdata-sections puts the C
   copies into .data.* sections the linker script discards, and they are
   made weak in the assembler only (#pragma weak would change the code). */
__asm__(".weak __malloc_av_\n.weak __malloc_trim_threshold\n.weak __malloc_top_pad\n"
        ".weak __malloc_sbrk_base\n.weak __malloc_max_sbrked_mem\n"
        ".weak __malloc_max_total_mem\n.weak __malloc_current_mallinfo");

/* "C" (the _current_locale of the module's _REENT_INIT data, no code of its own) */
__asm__(".pushsection .rodata\n.align 2\n.globl D_000F4398\nD_000F4398:\n.asciz \"C\"\n.align 2\n.popsection");
