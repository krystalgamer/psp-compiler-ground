#include "common.h"

/* declarations recovered from DWARF */


extern char *boot_path;

static int LoadNetModules(void);
static int UnloadNetModules(void);


INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", LoadNetModules);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/module_load", UnloadNetModules);

int LoadRequiredModules(void) {
    return __builtin_allegrex_min(LoadNetModules(), 0);
}

void StopDeleteLoadedModules(void) {
    UnloadNetModules();
}
