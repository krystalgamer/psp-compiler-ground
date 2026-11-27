#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", sceGimPictureLoadCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", sceGimPictureLoadCacheEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", sceGimPictureUnloadCache);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGimPictureUnloadCacheEx(void *arg0, int arg1) {
    int var_s0;
    void *temp_v0;

    var_s0 = arg1;
    if (arg0 != NULL) {
        if (arg1 & 2) {
            temp_v0 = M2C_FIELD(arg0, void **, 0x18);
            var_s0 = (temp_v0 != NULL) ? (arg1 | 1) : var_s0;
            sceGimPictureFreeMemory3(temp_v0);
            M2C_FIELD(arg0, void **, 0x18) = NULL;
        }
        if (var_s0 & 1) {
            sceGimPictureFreeMemory2(M2C_FIELD(arg0, void **, 0x14));
            M2C_FIELD(arg0, void **, 0x14) = NULL;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", sceGimPictureActivateEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", set_null);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", set_texture);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", set_renderstate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_activate", copy_image);
