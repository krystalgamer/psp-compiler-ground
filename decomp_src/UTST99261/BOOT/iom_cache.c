/* cflags: -O1 */
#include "common.h"
#include "iom_global.h"
#include "m2c_macros.h"
/* cache ids: a struct at 0x3C, so &iom.cache.ids[i] is iom + i + 0x30 with displacement 0x10 */
void *UTL_peekqueue(void *q, void *e);
int strcasecmp(const char *a, const char *b);
void iom_freeCache(void *c);
M2C_UNK UTL_mfiledelete(int);                       /* extern */
void UTL_relqueue(M2C_UNK *, void *);            /* extern */
int UTL_sizequeue(int);                             /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif
int CLIB_time(int *t);
int iom_diffexpire(int, int);
void iom_deleteCacheId(int id);
void iom_deleteDomainCache(void *arg0);
int iom_mfree(int arg0);
int iom_loadCache(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_saveCache(void) {
    return 0;
}

void iom_updateCache(void) {
    void *e;
    void *next;

    for (e = UTL_peekqueue(&iom.cacheList, NULL); e != NULL; e = next) {
        next = UTL_peekqueue(&iom.cacheList, e);
        e = M2C_FIELD(e, void **, 8);
        if ((unsigned int)(M2C_FIELD(e, int *, 0x14) + 1) >= 2 && iom_diffexpire(M2C_FIELD(e, int *, 0x14), CLIB_time(NULL)) < 0) {
            M2C_FIELD(e, int *, 0x14) = 0;
            iom.x28 = 1;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_cache", iom_addCache);

void iom_deleteCache(void *c) {
    void *e;
    if (c == NULL) {
        e = UTL_peekqueue(&iom.cacheList, NULL);
        if (e == NULL) {
            return;
        }
        c = M2C_FIELD(e, void **, 8);
    }
    if (M2C_FIELD(c, void **, 0x1C) != NULL) {
        UTL_mfiledelete(M2C_FIELD(c, int *, 0x1C));
        M2C_FIELD(c, void **, 0x1C) = NULL;
    }
    iom_deleteCacheId(M2C_FIELD(c, int *, 8));
    iom.cache.size -= M2C_FIELD(c, int *, 0xC) + M2C_FIELD(c, int *, 0x10);
    iom.x28 = 1;
    iom_freeCache(c);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_freeCache(void *arg0) {
    int temp_a0;

    UTL_relqueue(&iom.cacheList, arg0 + 0x20);
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
        UTL_relqueue(&iom.cacheList2, arg0);
        iom_mfree(M2C_FIELD(arg0, int *, 8));
        iom_mfree((int) arg0);
    }
}

void *iom_domainCache(char *name) {
    void *e;
    for (e = UTL_peekqueue(&iom.cacheList2, NULL); e != NULL; e = UTL_peekqueue(&iom.cacheList2, e)) {
        if (strcasecmp(M2C_FIELD(e, char **, 8), name) == 0) {
            return e;
        }
    }
    return NULL;
}

static inline unsigned char iom_isCacheId(int id) {
    return iom.cache.ids[id >> 3] & (1 << (id & 7));
}
int iom_newCacheId(void) {
    int i;

    for (i = 0; i < 1000; i += 8) {
        if (iom.cache.ids[i >> 3] != 0xFF)
            break;
    }
    for (; i < 1000; i++) {
        if (!iom_isCacheId(i))
            return i;
    }
    return i;
}

void iom_setCacheId(int id) {
    iom.cache.ids[id >> 3] |= 1 << (id & 7);
}

void iom_deleteCacheId(int id) {
    iom.cache.ids[id >> 3] &= ~(1 << (id & 7));
}
