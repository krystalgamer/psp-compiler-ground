#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetSetDefaultBitMask(void *);

int NetSetDefaultBitMask(void *arg0) {
    int var_v0;

    var_v0 = 0x17;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
        M2C_FIELD(arg0, int *, 0xC) = 0;
        M2C_FIELD(arg0, int *, 0x10) = 0;
        M2C_FIELD(arg0, int *, 0x14) = 0;
        M2C_FIELD(arg0, int *, 0x18) = 0;
        M2C_FIELD(arg0, int *, 0x1C) = 0;
        M2C_FIELD(arg0, int *, 0x20) = 0;
        M2C_FIELD(arg0, int *, 0x24) = 0x100;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeList", NetBitMaskIsSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeList", NetBitMaskSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeList", NetBitMaskUnSet);

typedef struct { unsigned int bits[8]; int base; int end; } DmeBitMaskL;
typedef struct { int max; DmeBitMaskL mask; } DmeClientList;
int NetBitMaskSet();
int NetGenerateClientList(char *ci, DmeClientList *l)
{
    int i;
    char *c;

    if (ci == NULL) return 0x17;
    if (l == NULL) return 0x17;
    memset(l, 0, sizeof *l);
    l->max = 0x100;
    l->mask.end = *(int *)(ci + 0x460);
    for (i = 0; i < *(int *)(ci + 0x460); i++) {
        c = ((char **)ci)[i];
        if (c != NULL && c != *(char **)(ci + 0x400) && *(int *)(c + 0x20) != 0)
            NetBitMaskSet(&l->mask, i);
    }
    return 0;
}

int NetGenerateJoinedClientList(char *ci, DmeClientList *l)
{
    int i;
    char *c;

    if (ci == NULL) return 0x17;
    if (l == NULL) return 0x17;
    memset(l, 0, sizeof *l);
    l->max = 0x100;
    l->mask.end = *(int *)(ci + 0x460);
    for (i = 0; i < *(int *)(ci + 0x460); i++) {
        c = ((char **)ci)[i];
        if (c != *(char **)(ci + 0x400))
            if (c != NULL)
                if (*(int *)(c + 0x20) != 0)
                    if ((unsigned int)(*(int *)(c + 0xC) - 4) < 2)
                        NetBitMaskSet(&l->mask, i);
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeList", rcsid_10E144);
