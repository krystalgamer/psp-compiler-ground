#include "common.h"
#include "m2c_macros.h"

M2C_UNK printf(M2C_UNK *, int);                     /* extern */
int sceKernelSetEventFlag(int, M2C_UNK);            /* extern */
extern unsigned char D_0002ED40;
int sceAtracReleaseAtracID(int);                    /* extern */
int sceIoClose(int);                                /* extern */
M2C_UNK sceKernelDeleteEventFlag(int);              /* extern */
extern unsigned char playArg;


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EBF8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC44);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC70);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EC98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002ECC4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", play_atrac3plus);

void finish_atrac3plus(void *arg0) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(M2C_FIELD(arg0, int *, 8), 2);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0002ED40, temp_v0);
    }
}

void restart_atrac3plus(void *arg0) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(M2C_FIELD(arg0, int *, 8), 1);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0002ED40, temp_v0);
    }
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002ED40);

void release_arg(void *arg0) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, int *, 0);
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x(in sceAtracReleaseID)\n", temp_v0_2);
    }
    if ((M2C_FIELD(arg0, int *, 4) < 0) || (temp_v0_3 = sceIoClose(M2C_FIELD(arg0, int *, 4)), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x(in sceIoClose)\n", temp_v0_3);
    }
    if (M2C_FIELD(arg0, int *, 8) >= 0) {
        sceKernelDeleteEventFlag(M2C_FIELD(arg0, int *, 8));
    }
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", at3plus_addData);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", at3plus_DisplayDecodePosition);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", reset_position);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", getPlayMode);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EEE0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF2C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF40);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", D_0002EF50);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", fadeoutOperation);

int at3_bgm_play_end(void) {
    finish_atrac3plus(&playArg);
    return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/at3plus", at3_bgm_play);
