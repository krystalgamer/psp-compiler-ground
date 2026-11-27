/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern unsigned char D_00103854;
extern unsigned char D_00103870;
extern unsigned char D_001038A4;
extern unsigned char D_001038B0;
M2C_UNK salbumCalcCardNumBySaveID(int, int, unsigned char, int); /* extern */
M2C_UNK salbumClearNewFlagBySaveID(int, int, unsigned char);   /* extern */

M2C_UNK taskDefaultMsg();                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcKinds);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcKindsContainLostCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103854);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103870);

#ifndef NULL
#define NULL ((void *)0)
#endif

int salbumGetCardDupBySaveID(int arg0, unsigned int arg1, int arg2, int *arg3, int *arg4) {
    int *temp_v1;
    int temp_a3;

    if (arg0 == 0) {
        consPrintf(&D_00103854, &D_00103870, 0x35, "salbumGetCardDupBySaveID", &D_001038A4);
    }
    if ((arg1 < 0x100U) & (arg2 < 3)) {
        temp_v1 = (((arg1 * 3) + arg2) * 4) + arg0;
        temp_a3 = *temp_v1 & 0x7F;
        if (arg3 != NULL) {
            *arg3 = temp_a3 == 0x7F;
        }
        if (arg4 != NULL) {
            *arg4 = __builtin_allegrex_ext(*temp_v1, 7, 1);
        }
        return ((temp_a3 ^ 0x7F) == 0) ? 0 : temp_a3;
    }
    if (arg3 != NULL) {
        *arg3 = 0;
    }
    if (arg4 != NULL) {
        *arg4 = 0;
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038B0);

#ifndef NULL
#define NULL ((void *)0)
#endif

void salbumGetCardDup(int arg0, void *arg1, int arg2, int arg3) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0x4E, "salbumGetCardDup", &D_001038B0);
    }
    salbumGetCardDupBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0), arg2, arg3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcCardNumBySaveID);

#ifndef NULL
#define NULL ((void *)0)
#endif

void salbumCalcCardNum(int arg0, void *arg1, int arg2) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0x87, "salbumCalcCardNum", &D_001038B0);
    }
    salbumCalcCardNumBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0), arg2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumClearNewFlagBySaveID);

#ifndef NULL
#define NULL ((void *)0)
#endif

void salbumClearNewFlag(int arg0, void *arg1) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0xA6, "salbumClearNewFlag", &D_001038B0);
    }
    salbumClearNewFlagBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int salbumTouchCardBySaveID(int arg0, unsigned int arg1, int arg2) {
    int *temp_v1;
    int temp_v0;
    int var_a1;

    if (arg0 == 0) {
        consPrintf(&D_00103854, &D_00103870, 0xB6, "salbumTouchCardBySaveID", &D_001038A4);
    }
    var_a1 = -1;
    temp_v1 = (((arg1 * 3) + arg2) * 4) + arg0;
    if (((arg1 >= 0x100U) | (arg2 >= 3)) == 0) {
        temp_v0 = *temp_v1;
        if (!(temp_v0 & 0x7F)) {
            *temp_v1 = temp_v0 | 0x7F;
        }
        var_a1 = *temp_v1 & 0x7F;
    }
    return var_a1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void salbumTouchCard(int arg0, void *arg1) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0xC7, "salbumTouchCard", &D_001038B0);
    }
    salbumTouchCardBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumGetAll);

#ifndef NULL
#define NULL ((void *)0)
#endif

void menuSaveTask(void) {
    taskDefaultMsg();
}
