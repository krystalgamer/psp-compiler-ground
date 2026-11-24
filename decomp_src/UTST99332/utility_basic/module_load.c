#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", LoadModule);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", LoadRequiredModules);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", StopDeleteLoadedModules);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/module_load", s_modules_path);
