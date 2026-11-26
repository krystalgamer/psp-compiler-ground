/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK UTL_mfiledelete(int);                       /* extern */
M2C_UNK UTL_relqueue(M2C_UNK *, void *);            /* extern */
extern unsigned char D_00585130;
int UTL_sizequeue(int);                             /* extern */
extern unsigned char D_00585138;



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

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_freeCache(void *arg0) {
    int temp_a0;

    UTL_relqueue(&D_00585130, arg0 + 0x20);
    UTL_relqueue(M2C_FIELD(arg0, int *, 0) + 0xC, arg0 + 0x2C);
    iom_deleteDomainCache(M2C_FIELD(arg0, int *, 0));
    temp_a0 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_a0 != 0) {
        UTL_mfiledelete(temp_a0);
        M2C_FIELD(arg0, int *, 0x1C) = 0;
    }
    iom_mfree(M2C_FIELD(arg0, int *, 4));
    iom_mfree((int) arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_deleteDomainCache(void *arg0) {
    if (UTL_sizequeue(arg0 + 0xC) <= 0) {
        UTL_relqueue(&D_00585138, arg0);
        iom_mfree(M2C_FIELD(arg0, int *, 8));
        iom_mfree((int) arg0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_domainCache);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_newCacheId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_setCacheId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_deleteCacheId);
