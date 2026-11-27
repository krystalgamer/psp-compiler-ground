/* upstream: libgcc unwind-dw2-fde.c, tree: 1.6.1 */
/* cflags: -O2 -fexceptions */
/* (spelled via config/ so that it does not include this file of the same name) */
#include "config/../unwind-dw2-fde.c"
/* static in unwind-dw2-fde.c; the module's .eh_frame (asm) refers to them */
__asm__(".globl fde_split");
__asm__(".globl frame_heapsort");
__asm__(".globl init_object");
__asm__(".globl search_object");
