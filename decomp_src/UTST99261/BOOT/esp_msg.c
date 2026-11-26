/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
void *MEM_malloc(M2C_UNK, int);                     /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);

void *cnvExtSchemeSelected(void *arg0) {
    void *temp_s1;
    void *temp_v0;
    void *var_v0;

    temp_s1 = M2C_FIELD(arg0, void **, 0x1C);
    temp_v0 = MEM_malloc(0, M2C_FIELD(temp_s1, unsigned int *, 0) + 1);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, M2C_FIELD(temp_s1, unsigned int *, 0) + 1);
        memcpy(temp_v0, M2C_FIELD(temp_s1, void **, 4), M2C_FIELD(temp_s1, unsigned int *, 0));
        MEM_free(0, temp_s1);
        M2C_FIELD(arg0, void **, 0x1C) = temp_v0;
        var_v0 = arg0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_msgThread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_setupPointerDeviceMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_setupKeyDeviceMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgQuit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgLoadPage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgSubmitForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgRepaint);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgDeviceEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgStop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgFindString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgDataAttr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgSaveURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgTitle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgConfigChanged);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgFreeScroll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgEditMenu);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgDeleteCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", esp_postMsgInputData);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133C84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133C94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133CFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cfg_names);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133DE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cv_code);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", D_00133E40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/esp_msg", cv_fsize);
