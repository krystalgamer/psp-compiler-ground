#include "common.h"
#include "m2c_macros.h"

M2C_UNK SpriteInit();                               /* extern */
M2C_UNK SpriteKick();                               /* extern */
M2C_UNK PzlLoadFiles();                             /* extern */
M2C_UNK SpriteAllFreeImage();                       /* extern */
M2C_UNK SpriteSetFader(float);                        /* extern */
M2C_UNK bgm_play(M2C_UNK);                          /* extern */
M2C_UNK load_title_gim();                           /* extern */
extern int D_0015295C;
M2C_UNK LoadGimFile(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK MsLoad();                                   /* extern */
extern int D_00152968;
M2C_UNK se_play(M2C_UNK);                           /* extern */

/* cflags: -O2 -fno-merge-constants */
/* (while TitleDisp is asm: its constants are in .rodata, so the C ones go there too) */

int LogoDisp(void) {
    SpriteInit();
    SpriteKick();
    return 4;
}

int TitleInit(void) {
    SpriteAllFreeImage();
    load_title_gim();
    if (D_0015295C == 0) {
        D_0015295C = 1;
        PzlLoadFiles();
    }
    bgm_play(0);
    SpriteSetFader(1.0f);
    return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/Title", TitleDisp);

int SigInit(void) {
    SpriteAllFreeImage();
    LoadGimFile(0, 0x2AB);
    if (D_00152968 == 0) {
        MsLoad();
        D_00152968 = 1;
    }
    SpriteSetFader(1.0f);
    return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/Title", SigMain);

int EndCreditInit(void) {
    SpriteAllFreeImage();
    se_play(0xA);
    return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/Title", EndCreditMain);
