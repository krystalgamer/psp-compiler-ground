#include "common.h"
#include "m2c_macros.h"

M2C_UNK sceGimPictureFreeMemory(int *);             /* extern */
M2C_UNK sceGimPictureUnload();                      /* extern */


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureCreate);

void sceGimPictureDelete(int *arg0) {
    int temp_v0;

    if ((arg0 == NULL) || (temp_v0 = *arg0 - 1, *arg0 = temp_v0, (temp_v0 != 0))) {

    } else {
        sceGimPictureUnload();
        sceGimPictureFreeMemory(arg0);
    }
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureDuplicate);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureLoadFile);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureLoad);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureUnload);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureAnimate);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureActivate);

void sceGimPictureSetEnableBits(void *arg0, int arg1, int arg2) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x2C) = (int) ((M2C_FIELD(arg0, int *, 0x2C) & ~arg1) | (arg1 & arg2));
    }
}

int sceGimPictureGetEnableBits(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x2C);
    }
    return var_v0;
}

int sceGimPictureGetImage(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 8);
    }
    return var_v0;
}

int sceGimPictureGetPalette(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0xC);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureGetImagePixels);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureGetPalettePixels);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureSetImagePixels);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureSetPalettePixels);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureReallocImage);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureReallocPalette);

int sceGimPictureHasAnimation(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = ((unsigned int) M2C_FIELD(arg0, unsigned int *, 4) >> 4) & 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureSetFrameLoop);

int sceGimPictureGetFrameLoop(int arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = arg0 + 0x1C;
    }
    return var_v0;
}

void sceGimPictureSetFrameRate(void *arg0, float fparg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, float *, 0x24) = fparg0;
    }
}

float sceGimPictureGetFrameRate(void *arg0) {
    float var_f0;

    var_f0 = 0.0f;
    if (arg0 != NULL) {
        var_f0 = M2C_FIELD(arg0, float *, 0x24);
    }
    return var_f0;
}

void sceGimPictureSetFrame(void *arg0, float fparg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, float *, 0x28) = fparg0;
    }
}

float sceGimPictureGetFrame(void *arg0) {
    float var_f0;

    var_f0 = 0.0f;
    if (arg0 != NULL) {
        var_f0 = M2C_FIELD(arg0, float *, 0x28);
    }
    return var_f0;
}

void sceGimPictureSetImageFrame(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x30) = arg1;
    }
}

int sceGimPictureGetImageFrame(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x30);
    }
    return var_v0;
}

void sceGimPictureSetImageFrame2(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x34) = arg1;
    }
}

int sceGimPictureGetImageFrame2(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x34);
    }
    return var_v0;
}

void sceGimPictureSetPaletteFrame(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x38) = arg1;
    }
}

int sceGimPictureGetPaletteFrame(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x38);
    }
    return var_v0;
}

void sceGimPictureSetPaletteFrame2(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x38) = arg1;
    }
}

int sceGimPictureGetPaletteFrame2(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x38);
    }
    return var_v0;
}

void sceGimPictureSetDissolve(void *arg0, float fparg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, float *, 0x40) = fparg0;
    }
}

float sceGimPictureGetDissolve(void *arg0) {
    float var_f0;

    var_f0 = 0.0f;
    if (arg0 != NULL) {
        var_f0 = M2C_FIELD(arg0, float *, 0x40);
    }
    return var_f0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", sceGimPictureSetImageCrop);

void *sceGimPictureGetImageCrop(void *arg0) {
    void *var_v1;

    var_v1 = NULL;
    if ((arg0 != NULL) && (M2C_FIELD(arg0, int *, 4) & 0x20)) {
        var_v1 = arg0 + 0x44;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_picture", reconfigure_picture);
