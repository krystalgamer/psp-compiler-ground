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
M2C_UNK UTL_initqueue(M2C_UNK *);                   /* extern */
extern unsigned char D_00585130;
extern unsigned char D_00585138;
extern unsigned char D_00585144;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", getListNumCharAtIU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", getListNumCharAtIL);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", getListNumChar);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", iom_setCache);

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F284);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F288);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F28C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F290);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F2F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F304);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F30C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F318);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F320);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F358);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F364);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F36C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F374);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F378);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F388);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F38C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_list", D_0013F3EC);
