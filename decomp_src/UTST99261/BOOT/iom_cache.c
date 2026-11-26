#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_loadCache(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_saveCache(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_updateCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_addCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_deleteCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_freeCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_deleteDomainCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_domainCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_newCacheId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_setCacheId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_deleteCacheId);
