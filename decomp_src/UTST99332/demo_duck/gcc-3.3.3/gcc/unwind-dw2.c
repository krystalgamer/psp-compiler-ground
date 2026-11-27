/* upstream: libgcc unwind-dw2.c, tree: 1.6.1 */
/* cflags: -O2 -fexceptions */
/* (spelled via config/ so that it does not include this file of the same name) */
#include "config/../unwind-dw2.c"
/* static in unwind-dw2.c; the module's .eh_frame (asm) refers to them */
__asm__(".globl _Unwind_ForcedUnwind_Phase2");
__asm__(".globl _Unwind_RaiseException_Phase2");
__asm__(".globl base_of_encoded_value");
__asm__(".globl execute_cfa_program");
__asm__(".globl extract_cie_info");
__asm__(".globl uw_frame_state_for");
__asm__(".globl uw_init_context_1");
__asm__(".globl uw_install_context_1");
