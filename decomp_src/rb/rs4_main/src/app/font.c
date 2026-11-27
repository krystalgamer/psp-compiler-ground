/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceFontClose(int);                              /* extern */
int sceFontDoneLib(int);                            /* extern */
extern unsigned char D_000FC438;
extern int FontID;
extern int LibID;

#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FC3F8;
extern unsigned char D_000FC41C;
extern unsigned char D_000FC4EC;
extern int pFontDat;
extern int pMarkFontDat;
extern int pMarkTextDat;
extern unsigned char D_000FC524;
M2C_UNK _memFree(int *, M2C_UNK *, M2C_UNK);        /* extern */
extern unsigned char D_000FC544;
extern unsigned char D_000FC62C;

void *_memAlloc();

int copAddVec();

extern int D_00119780;
extern const float D_000FC670;

int fontImgPut();

int fontStrPut();

int _fontAlloc(int a, int size)
{
	int r = -1;
	if (size)
		r = (int)_memAlloc(size, &D_000FC3F8, 0x41);
	return r;
}

void _fontFree(int heap, int *p) {
    if (p != (int *)-1) {
        _memFree(p, &D_000FC3F8, 0x4C);
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC3F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC41C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC450);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC470);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC480);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC494);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC498);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "fontTerm";
    consPrintf("%s\n", temp_v0);
    if (sceFontClose(FontID) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xC9, temp_v0, &D_000FC438);
    }
    FontID = 0;
    if (sceFontDoneLib(LibID) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xCE, temp_v0, &D_000FC438);
    }
    LibID = 0x8046FFFF;
    return 0;
}

int fontSetPgfResource(int arg0) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xDA, "fontSetPgfResource", &D_000FC4EC);
    }
    pFontDat = arg0;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC4EC);

int fontSetPgfResourceExtra(int arg0, int arg1) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE4, "fontSetPgfResourceExtra", &D_000FC4EC);
    }
    if (arg1 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE5, "fontSetPgfResourceExtra", "pTextDat");
    }
    pMarkFontDat = arg0;
    pMarkTextDat = arg1;
    return 1;
}

int fontGetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xF4, "fontGetPos", &D_000FC524);
    }
    M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x10);
    M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x14);
    M2C_FIELD(arg1, int *, 8) = (int) M2C_FIELD(arg0, int *, 0x18);
    M2C_FIELD(arg1, int *, 0xC) = (int) M2C_FIELD(arg0, int *, 0x1C);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC524);

int fontSetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x102, "fontSetPos", &D_000FC524);
    }
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(arg1, int *, 0);
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(arg1, int *, 4);
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(arg1, int *, 8);
    M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(arg1, int *, 0xC);
    return 1;
}

int fontOfsPos(int *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x110, "fontOfsPos", &D_000FC524);
    }
    if (*arg0 != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x111, "fontOfsPos", &D_000FC544);
    }
    copAddVec((char *)arg0 + 0x10, arg1, (char *)arg0 + 0x10);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC544);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontIsMarkFont);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontGetCharWidth);

float fontGetCharHeight(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x145, "fontGetCharHeight", &D_000FC524);
    }
    return (float)((D_00119780 + 0x3F) & ~0x3F) * D_000FC670;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontGetStrWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontGetStrHeight);

void fontImgInit(int a)
{
	fontImgInitEx(a, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontImgInitEx);

int fontImgTerm(int *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E2, "fontImgTerm", &D_000FC524);
    }
    if (*arg0 != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E3, "fontImgTerm", &D_000FC544);
    }
    _memFree(arg0, &D_000FC3F8, 0x1E5);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontImgPut);

int fontImgStr(int f, int *str, int n) {
    int c;
    while (n != 0 && (c = *str) != 0) {
        fontImgPut(f, c);
        n--;
        str++;
    }
    return 1;
}

int fontImgDat(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x224, "fontImgDat", &D_000FC524);
    }
    if (M2C_FIELD(arg0, int *, 0) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x225, "fontImgDat", &D_000FC544);
    }
    return M2C_FIELD(arg0, int *, 0x50);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontStrInit);

int fontStrTerm(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *temp_s0_2;
    M2C_UNK *var_a0;
    M2C_UNK *var_a0_2;

    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24D, "fontStrTerm", &D_000FC524);
    }
    if (M2C_FIELD(arg0, M2C_UNK **, 0) != (M2C_UNK *)1) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24E, "fontStrTerm", &D_000FC62C);
    }
    var_a0 = M2C_FIELD(arg0, M2C_UNK **, 0x6C);
    if (var_a0 != NULL) {
        do {
            temp_s0 = *var_a0;
            _memFree(var_a0, &D_000FC3F8, 0x254);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
    var_a0_2 = M2C_FIELD(arg0, M2C_UNK **, 0x74);
    if (var_a0_2 != NULL) {
        do {
            temp_s0_2 = *var_a0_2;
            _memFree(var_a0_2, &D_000FC3F8, 0x25D);
            var_a0_2 = temp_s0_2;
        } while (temp_s0_2 != NULL);
    }
    _memFree(arg0, &D_000FC3F8, 0x262);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC62C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontStrPut);

int fontStrStr(int f, int *str, int n) {
    int c;
    while (n != 0 && (c = *str) != 0) {
        fontStrPut(f, c);
        n--;
        str++;
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC668);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC66C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC670);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC678);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontStrDraw);
