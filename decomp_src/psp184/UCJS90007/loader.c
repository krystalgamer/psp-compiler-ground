#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", fdgets_local);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", skipsp);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", skipnonsp);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", split);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", load_logfile_thread);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", load_boot_binary_thread);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/loader", D_0002DDE8);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", start_load);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", check_load_completed);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", check_loader_dialog_completed);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", loader_update);
