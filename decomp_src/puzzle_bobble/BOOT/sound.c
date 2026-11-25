#include "common.h"
#include "m2c_macros.h"

M2C_UNK bgm_play(int);                              /* extern */
M2C_UNK printf(M2C_UNK *, int);                     /* extern */
extern int NextBgm;
extern int PlayFlag;


INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA74);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA80);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA8C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EAA4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EAB0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EABC);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", sound_init);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", vag_read);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", bgm_stop);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", bgm_play);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", se_play);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", snd_test);

void next_bgm(void) {
    if ((PlayFlag == 0) && (NextBgm >= 0)) {
        printf("NEXT PLAY = %d\n", NextBgm);
        bgm_play(NextBgm);
        NextBgm = -1;
    }
}
