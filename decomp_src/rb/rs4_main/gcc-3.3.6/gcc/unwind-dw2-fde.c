/* upstream: libgcc unwind-dw2-fde.c (unwind-dw2-fde.o), tree: 1.9.2 */
/* cflags: -O2 -fexceptions */
#include <unwind-dw2-fde.c>  /* the tree's, not this file */

/* the module's asm .eh_frame refers to these static functions by name */
__asm__(".globl frame_heapsort\n.globl search_object\n.globl init_object\n.globl fde_split");
