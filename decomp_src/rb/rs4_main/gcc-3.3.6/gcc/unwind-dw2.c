/* upstream: libgcc unwind-dw2.c (unwind-dw2.o), tree: 1.9.2 */
/* cflags: -O2 -fexceptions */
#include <unwind-dw2.c>  /* the tree's, not this file */

/* the module's asm .eh_frame refers to these static functions by name */
__asm__(".globl _Unwind_ForcedUnwind_Phase2\n.globl _Unwind_RaiseException_Phase2\n.globl base_of_encoded_value\n.globl execute_cfa_program\n.globl extract_cie_info\n.globl uw_frame_state_for\n.globl uw_init_context_1\n.globl uw_install_context_1");
