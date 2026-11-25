#include "common.h"
#include "m2c_macros.h"

M2C_UNK LoadRequiredModules();                      /* extern */
M2C_UNK loadModuleAt3plus();                        /* extern */
M2C_UNK puts(M2C_UNK *);                            /* extern */
M2C_UNK sceKernelExitDeleteThread(M2C_UNK);         /* extern */


INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9B8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9D8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002F9F4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA1C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA38);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA58);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA78);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FA9C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FAC0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FAE4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", D_0002FB04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", s_modules_path);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", LoadModule);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", LoadRequiredModules);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", StopDeleteLoadedModules);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", load_module);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/module_load", loadModuleAt3plus);

int sub_thread(void) {
    puts("module load-----------");
    loadModuleAt3plus();
    LoadRequiredModules();
    sceKernelExitDeleteThread(0);
    return 0;
}
