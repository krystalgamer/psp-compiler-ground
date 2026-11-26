/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK saveDataInit(int, M2C_UNK);                 /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveDataInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE464);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveSetData);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE524);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE530);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE544);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveGetData);

#ifndef NULL
#define NULL ((void *)0)
#endif
int saveGetCurrentData(void) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s0, int *, 0xC) + (M2C_FIELD(gameGetCntx(), int *, 0x8C) * 0x14B0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int saveGetPlayerCurrentData(int arg0) {
    void *temp_s1;

    temp_s1 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s1, int *, 0xC) + (M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) * 0x14B0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveGetAccountData);

#ifndef NULL
#define NULL ((void *)0)
#endif
void saveSetAccount(int arg0, int arg1) {
    M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void saveCurrentDataInit(void) {
    saveDataInit(saveGetCurrentData(), 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveIsRemainCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE594);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE59C);
