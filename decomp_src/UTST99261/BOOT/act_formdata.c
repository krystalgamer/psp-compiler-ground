/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
extern unsigned char search;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", URLencode);

#ifndef NULL
#define NULL ((void *)0)
#endif
int newFormCollect(int arg0, int arg1, void *arg2) {
    M2C_FIELD(arg2, int *, 4) = arg0;
    M2C_FIELD(arg2, int *, 8) = arg1;
    M2C_FIELD(arg2, int *, 0xC) = 0;
    M2C_FIELD(arg2, int *, 0x10) = 0;
    M2C_FIELD(arg2, int *, 0x14) = 0;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteFormCollect(void *arg0) {
    int temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s1;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x10);
    if (var_s0 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_s0, void **, 0);
            temp_s1 = M2C_FIELD(var_s0, void **, 0xC);
            if (temp_a1 != NULL) {
                MEM_free(0, temp_a1);
            }
            temp_a1_2 = M2C_FIELD(var_s0, void **, 4);
            if (temp_a1_2 != NULL) {
                MEM_free(0, temp_a1_2);
            }
            temp_a0 = M2C_FIELD(var_s0, int *, 8);
            if (temp_a0 != 0) {
                deleteFileData(temp_a0);
            }
            MEM_free(0, var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", getFormCollectData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", addFormCollectSymbol);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", fileContentType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", newFileData);

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteFileData(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    if (temp_a1 != NULL) {
        MEM_free(0, temp_a1);
    }
    MEM_free(0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", memstr);

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearSearchStrings(void) {
    M2C_FIELD(&search, int *, 0) = 0;
    M2C_FIELD(&search, int *, 4) = 0;
    M2C_FIELD(&search, int *, 0xC) = 0;
    M2C_FIELD(&search, int *, 8) = 0;
    M2C_FIELD(&search, int *, 0x10) = 0;
    if (M2C_FIELD(&search, int *, 0x14) != 0) {
        MEM_free(0, M2C_FIELD(&search, int *, 0x14));
        M2C_FIELD(&search, int *, 0x14) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", searchStrings);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F030);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F038);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F040);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F044);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F05C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F060);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F068);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F06C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F070);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F078);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F080);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F088);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F08C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F094);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F09C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F0D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F104);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F10C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F114);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F11C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F124);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F12C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F13C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F140);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F148);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F14C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F154);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F15C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F168);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F170);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F17C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F184);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F18C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F190);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F194);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F19C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F1FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F204);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F208);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F20C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F214);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F218);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F21C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F220);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F224);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F228);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F230);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F234);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F238);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F23C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F240);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F244);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F248);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F24C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F250);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F258);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F25C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F264);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F268);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F26C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F270);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F274);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F278);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/act_formdata", D_0013F280);
