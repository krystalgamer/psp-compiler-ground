#include "common.h"
#include "m2c_macros.h"

M2C_UNK memalign(M2C_UNK, int);                     /* extern */
M2C_UNK free();                                     /* extern */
int sceDisplayGetVcount();                          /* extern */
extern int frameCount;
extern int VCount;
M2C_UNK sceGuDisable(M2C_UNK);                      /* extern */
M2C_UNK sceGuFinish();                              /* extern */


void malloc16(int arg0) {
    memalign(0x10, arg0);
}

void free16(void) {
    free();
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", exit_func);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", main);

void vsyncCountInit(void) {
    frameCount = sceDisplayGetVcount();
}

int vsyncGetCount(void) {
    int temp_a0;
    int temp_v0;
    int temp_v1;

    temp_v0 = sceDisplayGetVcount();
    temp_v1 = frameCount;
    frameCount = temp_v0;
    temp_a0 = temp_v0 - temp_v1;
    VCount = temp_a0;
    return temp_a0;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBB8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBC4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBDC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBEC);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", begin_scene);

void end_scene(void) {
    sceGuDisable(9);
    sceGuDisable(1);
    sceGuFinish();
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", swap_buffers);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", dummy_swap);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", draw_rect);
