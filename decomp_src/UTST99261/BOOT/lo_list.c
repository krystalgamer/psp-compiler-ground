/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct { u8 pad[0x3C]; unsigned int x3C; } IOMC_T;
extern IOMC_T iom;
extern int D_0058512C;
void iom_updateCache();
int iom_saveCache(void);
void iom_deleteCache(int);
unsigned int iom_preferenceCache(void);
void *UTL_peekqueue(void *q, int a1);
void iom_freeCache(void *c);
signed char *MEM_malloc(M2C_UNK, int);                       /* extern */
extern signed char D_0013F28C;
void UTL_initqueue(M2C_UNK *);                   /* extern */
extern unsigned char D_00585130;
extern unsigned char D_00585138;
extern unsigned char D_00585144;


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

    UTL_initqueue(&D_00585130);
    UTL_initqueue(&D_00585138);
    memset(&D_00585144, 0, 0x7EU);
    M2C_FIELD(&D_00585144, int *, -0x18) = 0;
    temp_s0 = iom_loadCache();
    iom_saveCache();
    return temp_s0;
}

int iom_detachCache(void) {
    void *e;
    int r = 0;
    iom_updateCache();
    if (D_0058512C != 0) {
        r = iom_saveCache();
    }
    while ((e = UTL_peekqueue(&D_00585130, 0)) != NULL) {
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
    if (D_0058512C != 0)
        iom_saveCache();
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", iom_getCache);

void iom_capacityCache(void) {
    iom_updateCache();
    while (iom_preferenceCache() < iom.x3C) {
        iom_deleteCache(0);
    }
    if (D_0058512C != 0) {
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
