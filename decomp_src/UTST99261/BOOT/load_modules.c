#include "common.h"

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", s_modules_path);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", LoadModule_AFC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", LoadRequiredModules);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/load_modules", StopDeleteLoadedModules);
