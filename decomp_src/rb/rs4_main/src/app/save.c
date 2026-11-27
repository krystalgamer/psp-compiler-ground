/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */
extern signed char D_000FE460;
extern unsigned char D_000FE498;
extern unsigned char D_000FE4A0;
extern unsigned char D_000FE4BC;
extern unsigned char D_000FE4C8;
extern unsigned char D_000FE4D4;
extern unsigned char D_000FE4E8;

void consPrintf(const char *, ...);
extern unsigned char D_000FE464;
extern unsigned char D_000FE474;

M2C_UNK saveDataInit(int, M2C_UNK);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveDataInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE464);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4A0);

#ifndef NULL
#define NULL ((void *)0)
#endif

int saveTerm(void *arg0) {
    M2C_UNK *temp_v0;

    temp_v0 = "saveTerm";
    consPrintf(&D_000FE460, temp_v0);
    if (arg0 == NULL) {
        consPrintf(&D_000FE474, &D_000FE464, 0x60, temp_v0, &D_000FE498);
    }
    if (M2C_FIELD(arg0, int *, 0) == 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x61, temp_v0, &D_000FE4BC);
    }
    if (M2C_FIELD(arg0, int *, 4) == 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x62, temp_v0, &D_000FE4C8);
    }
    if (M2C_FIELD(arg0, int *, 8) != 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x63, temp_v0, &D_000FE4D4);
    }
    if (M2C_FIELD(arg0, void **, 0xC) == NULL) {
        consPrintf(&D_000FE474, &D_000FE464, 0x64, temp_v0, &D_000FE4A0);
    }
    if (M2C_FIELD(arg0, int *, 4) != (M2C_FIELD(arg0, int *, 0) * 0x14B0)) {
        consPrintf(&D_000FE474, &D_000FE464, 0x65, temp_v0, &D_000FE4E8);
    }
    _memFree(M2C_FIELD(arg0, void **, 0xC), &D_000FE464, 0x67);
    _memFree(arg0, &D_000FE464, 0x68);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveSetData);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE524);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE530);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE544);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveGetData);

int saveGetCurrentData(void) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s0, int *, 0xC) + (M2C_FIELD(gameGetCntx(), int *, 0x8C) * 0x14B0);
}

int saveGetPlayerCurrentData(int arg0) {
    void *temp_s1;

    temp_s1 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s1, int *, 0xC) + (M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) * 0x14B0);
}

int saveGetAccountData(int arg0) {
    if (arg0 >= 3) {
        consPrintf(&D_000FE474, &D_000FE464, 0xBE, "saveGetAccountData", "Account < SaveData_Account_Num");
    }
    return M2C_FIELD(M2C_FIELD(gameGetCntx(), void **, 0x88), int *, 0xC) + (arg0 * 0x14B0);
}

void saveSetAccount(int arg0, int arg1) {
    M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) = arg1;
}

void saveCurrentDataInit(void) {
    saveDataInit(saveGetCurrentData(), 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveIsRemainCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE594);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE59C);
