#include "common.h"

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", LoadNetModules);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", UnloadNetModules);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", LoadRequiredModules);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", StopDeleteLoadedModules);
