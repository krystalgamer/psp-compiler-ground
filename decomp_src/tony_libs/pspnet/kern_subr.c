#include "common.h"

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_microtime);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_uiomove);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_hashinit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_hashdone);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_selrecord);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_selwakeup);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/kern_subr", _sce_pspnet_get_selwait_addr);
