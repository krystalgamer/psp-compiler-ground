#include "common.h"
#include "m2c_macros.h"

M2C_UNK sceGimPictureDelete(int);                   /* extern */
M2C_UNK sceGimPictureUnload(int);                   /* extern */
extern unsigned char Gims;
extern signed char isSkip;
extern int global_color;
extern float global_fader;


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", init_gims);

void release_gims(int arg0) {
    int *temp_s0;
    int temp_v1;

    temp_s0 = (arg0 * 4) + &Gims;
    temp_v1 = *temp_s0;
    if (temp_v1 != 0) {
        sceGimPictureUnload(temp_v1);
        sceGimPictureDelete(*temp_s0);
        *temp_s0 = 0;
    }
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", load_gims);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", set_gim);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", LoadGimFile);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteAllFreeImage);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", get_gims);

void SpriteSetSkipFrame(signed char arg0) {
    isSkip = arg0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", GetSpriteBuf);

void SpriteInit(void) {
}

void SpriteKick(void) {
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteInitExt);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteKickExt);

void SpriteSetColor(int arg0) {
    global_color = arg0;
}

void SpriteSetColorRGBA(int arg0, int arg1, int arg2, int arg3) {
    global_color = (arg0 & 0xFF) | ((arg1 & 0xFF) << 8) | ((arg2 & 0xFF) << 0x10) | (arg3 << 0x18);
}

int SpriteGetColor(void) {
    return global_color;
}

float SpriteGetFader(void) {
    return global_fader;
}

void SpriteSetFader(float fparg0) {
    global_fader = fparg0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", getFader);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", D_0002DC10);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDraw);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDrawEz);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDrawZoom);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDraw3D);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDrawC);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSprite);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSpriteEz);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSpriteZoom);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSpriteEx);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSpritePt4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", GetSpriteColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SetSpriteColor);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SetSpriteColorRGBA);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", draw_DrawSpritePt4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", draw_DrawSprite);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", draw_DrawSpriteEx);

int NullFunc(void) {
    return 1;
}
