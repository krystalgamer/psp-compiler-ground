/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern int sprbuf;
extern int SprNum;
extern int spr_head;
extern int spr_root;
M2C_UNK SprLinkDelete();                            /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif



void SprInit_Psp(void) {
    sprbuf = psp_malloc(0xA000U);
}

void psp_free(void *p);
void SprInit_PspFree(void)
{
	psp_free((void *)sprbuf);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void SprInit(void) {
    memset(sprbuf, 0, 0xA000U);
    spr_head = 0;
    spr_root = 0;
    SprNum = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SprNumGet(void) {
    return SprNum;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SprHeadGet(void) {
    return spr_head;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprLinkAdd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprLinkDelete);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void SprFree(void *arg0) {
    if (arg0 != NULL) {
        SprLinkDelete();
        memset(arg0, 0, 0xA0U);
        SprNum -= 1;
    }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprAlloc);

#ifndef NULL
#define NULL ((void *)0)
#endif

void SprAllDispSetSub(int arg0) {
    void *var_v1;

    var_v1 = spr_head;
    if (var_v1 != NULL) {
        do {
            if (M2C_FIELD(var_v1, int *, 0xC) != 0) {
                if (M2C_FIELD(var_v1, int *, 0x14) == arg0) {
                    M2C_FIELD(var_v1, int *, 0x30) = (int) (M2C_FIELD(var_v1, int *, 0x30) + 1);
                }
            }
            var_v1 = M2C_FIELD(var_v1, void **, 0x94);
        } while (var_v1 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SprAllDispSet(void) {
    SprAllDispSetSub(0);
    SprAllDispSetSub(1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprDraw4Psp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_spr", SprAnm4Psp);
