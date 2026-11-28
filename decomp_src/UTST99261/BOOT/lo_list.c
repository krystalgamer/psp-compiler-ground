/* cflags: -O1 */
#include "common.h"
#include "iom_global.h"
#include "m2c_macros.h"
void iom_updateCache();
int iom_saveCache(void);
void iom_deleteCache(int);
unsigned int iom_preferenceCache(void);
void *UTL_peekqueue(void *q, int a1);
void iom_freeCache(void *c);
signed char *MEM_malloc(M2C_UNK, int);                       /* extern */
extern signed char D_0013F28C;
void UTL_initqueue(M2C_UNK *);                   /* extern */


int iom_addCache(int, int, int *);
signed char *getListNumCharAtAU(int n);
signed char *getListNumCharAtAL(int n);
signed char *getListNumCharAtIU(int n);
signed char *getListNumCharAtIL(int n);
extern char *roman_lc[4][9];
extern char D_0013F284[];
extern char D_0013F288[];
void *MEM_calloc(int, unsigned int);
char *strcat(char *d, const char *s);
char *strcpy(char *d, const char *s);
extern char *roman_uc[4][9];
void *memcpy(void *, const void *, unsigned int);
int iom_loadCache(void);
typedef struct IOMCINFO { int x0; char *url; int x8; int size1; int size2; int x14; int x18; void *file; } IOMCINFO;
typedef struct IOMCENT { void *next; void *prev; IOMCINFO *info; } IOMCENT;
typedef struct IOMCOUT { void *file; int size1; int size2; int x14; int x18; int x14b; } IOMCOUT;
void URL_splitURL(void **parts, char *url);
char *iom_malloc(int size);
int iom_mfree(char *p);
char *iom_strnmcat(char *dst, int n, ...);
void *iom_domainCache(char *name);
int strcasecmp(const char *a, const char *b);
void *UTL_mfilecreate(int size);
void UTL_mfiledelete(void *f);
void UTL_mfileseek(void *f, int pos);
int UTL_mfileread(void *f, void *buf, int len);
int UTL_mfilewrite(void *f, void *buf, int len);
signed char *getListNumCharAtIU(int n) {
    int d[4];
    int i;
    int size;
    int m;
    int r;
    char *s;

    m = n;
    size = 3;
    for (i = 3; i >= 0; i--) {
        r = n % 10;
        if (r != 0)
            size += 4;
        d[i] = r;
        n /= 10;
    }
    s = MEM_calloc(0, size);
    if (m < 0)
        memcpy(s, D_0013F284, 2);
    for (i = 0; i < 4; i++) {
        if (d[i] != 0)
            strcat(s, roman_uc[i][d[i] - 1]);
    }
    strcat(s, D_0013F288);
    return (signed char *)s;
}

signed char *getListNumCharAtIL(int n) {
    int d[4];
    int i;
    int size;
    int m;
    int r;
    char *s;

    m = n;
    size = 3;
    for (i = 3; i >= 0; i--) {
        r = n % 10;
        if (r != 0)
            size += 4;
        d[i] = r;
        n /= 10;
    }
    s = MEM_calloc(0, size);
    if (m < 0)
        memcpy(s, D_0013F284, 2);
    for (i = 0; i < 4; i++) {
        if (d[i] != 0)
            strcat(s, roman_lc[i][d[i] - 1]);
    }
    strcat(s, D_0013F288);
    return (signed char *)s;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", getListNumCharAtAU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", getListNumCharAtAL);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sprintf(char *buf, const char *fmt, ...);

signed char *getListNumCharAtL(int arg0) {
    int var_a1;
    int var_v1;
    signed char *temp_v0;

    var_a1 = 0;
    var_v1 = arg0;
    if (arg0 != 0) {
        do {
            var_v1 /= 0xA;
            var_a1 += 1;
        } while (var_v1 != 0);
    }
    temp_v0 = MEM_malloc(0, var_a1 + 3);
    sprintf(temp_v0, &D_0013F28C, arg0);
    return temp_v0;
}

signed char *getListNumChar(int n, int type) {
    switch (type) {
    case 0xC:
        return getListNumCharAtAU(n);
    case 0xD:
        return getListNumCharAtAL(n);
    case 0xE:
        if ((unsigned int)(n + 0xF9F) < 0x1F3F)
            return getListNumCharAtIU(n);
        break;
    case 0xF:
        if ((unsigned int)(n + 0xF9F) < 0x1F3F)
            return getListNumCharAtIL(n);
        break;
    }
    return getListNumCharAtL(n);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int iom_attachCache(void) {
    int temp_s0;

    UTL_initqueue(&iom.cacheList);
    UTL_initqueue(&iom.cacheList2);
    memset(iom.cache.ids, 0, 0x7EU);
    iom.x28 = 0;
    temp_s0 = iom_loadCache();
    iom_saveCache();
    return temp_s0;
}

int iom_detachCache(void) {
    void *e;
    int r = 0;
    iom_updateCache();
    if (iom.x28 != 0) {
        r = iom_saveCache();
    }
    while ((e = UTL_peekqueue(&iom.cacheList, 0)) != NULL) {
        iom_freeCache(M2C_FIELD(e, void **, 8));
    }
    return r;
}

int iom_setCache(int url, int *data) {
    int ret;

    if (url == 0 || data == NULL || *data == 0)
        return 0;
    if (iom_preferenceCache() == 0)
        return 0;
    iom_updateCache();
    ret = iom_addCache(url, -1, data);
    if (iom.x28 != 0)
        iom_saveCache();
    return ret;
}

int iom_getCache(char *url, IOMCOUT *out, int force) {
    void *parts[12];
    char buf[0x800];
    char *host;
    char *dom;
    IOMCENT *e;
    IOMCINFO *c;
    void *f;
    int n;
    int r;
    unsigned int total;

    out->file = NULL;
    out->size1 = 0;
    out->size2 = 0;
    out->x14b = 0;
    out->x14 = -1;
    out->x18 = -1;
    if (url == NULL) {
        return -0x12E;
    }
    if (iom_preferenceCache() == 0) {
        return 0;
    }
    iom_updateCache();
    if (iom.x28 != 0) {
        iom_saveCache();
    }
    URL_splitURL(parts, url);
    if (parts[1] == NULL || parts[3] == NULL) {
        return -0x12E;
    }
    host = iom_malloc((int)parts[3] + 1);
    if (host == NULL) {
        return -0x12D;
    }
    iom_strnmcat(host, 1, parts[3], parts[2]);
    dom = iom_domainCache(host);
    if (dom == NULL) {
        iom_mfree(host);
        return 0;
    }
    for (e = UTL_peekqueue(dom + 0xC, NULL); e != NULL; e = UTL_peekqueue(dom + 0xC, e)) {
        r = strcasecmp(e->info->url, url);
        if (r == 0) {
            break;
        }
        if (r > 0) {
            e = NULL;
            break;
        }
    }
    iom_mfree(host);
    if (e == NULL) {
        return 0;
    }
    if (!force && e->info->x14 == 0) {
        return 0;
    }
    c = e->info;
    if (c->file == NULL) {
        return -0x12D;
    }
    f = UTL_mfilecreate(0x800);
    if (f == NULL) {
        return -0x12D;
    }
    UTL_mfileseek(c->file, 0);
    n = c->size1 + c->size2;
    total = 0;
    while (n > 0) {
        if (n > sizeof(buf)) {
            n = sizeof(buf);
        }
        n = UTL_mfileread(c->file, buf, n);
        if (n <= 0) {
            break;
        }
        if (n != UTL_mfilewrite(f, buf, n)) {
            UTL_mfiledelete(f);
            return -0x12D;
        }
        total += n;
        n = c->size1 + c->size2 - total;
    }
    if (total < c->size1 + c->size2) {
        UTL_mfiledelete(f);
        return 0;
    }
    out->file = f;
    out->size1 = c->size1;
    out->size2 = c->size2;
    out->x14 = c->x14;
    out->x18 = c->x18;
    return 0;
}

void iom_capacityCache(void) {
    iom_updateCache();
    while (iom_preferenceCache() < iom.cache.size) {
        iom_deleteCache(0);
    }
    if (iom.x28 != 0) {
        iom_saveCache();
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F17C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F184);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F18C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F190);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F194);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F19C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F1FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F204);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F208);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F20C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F214);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F218);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F21C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F220);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F224);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F228);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F230);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F234);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F238);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F23C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F240);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F244);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F248);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F24C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F250);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F258);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F25C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F264);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F268);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F26C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F270);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F274);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F278);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F280);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F284);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F288);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F28C);
