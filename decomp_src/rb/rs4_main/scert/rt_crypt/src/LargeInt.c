#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int IsEven(int *arg0);
int IsZero(int *arg0);
int KM_SetUpdateCallback(int arg0);
void lintAddIP(int arg0, int arg1);
void lintClearBit(int arg0, unsigned int arg1);
void lintSetBit(int arg0, unsigned int arg1);
void lintSetSmallValue(int *arg0, int arg1);
extern int gAppUpdateCallback;

int KM_SetUpdateCallback(int arg0) {
    int temp_v0;

    temp_v0 = gAppUpdateCallback;
    gAppUpdateCallback = arg0;
    return temp_v0;
}

void *memset(void *s, int c, unsigned int n);
void lintSetSmallValue(int *arg0, int arg1) {
    memset(arg0, 0, 0x200U);
    *arg0 = arg1;
}

int IsEven(int *arg0) {
    return (*arg0 ^ 1) & 1;
}

int IsZero(int *arg0) {
    int *var_a0;
    int temp_v0;
    int var_a1;
    int var_a2;

    var_a0 = arg0;
    var_a1 = 0;
loop_1:
    temp_v0 = *var_a0;
    var_a1 += 1;
    var_a0 += 1;
    var_a2 = 0;
    if (temp_v0 == 0) {
        if (var_a1 >= 0x80) {
            var_a2 = 1;
        } else {
            goto loop_1;
        }
    }
    return var_a2;
}

int IsOne(int *a)
{
    int i;
    if (a[0] != 1) return 0;
    for (i = 1; i < 128; i++)
        if (a[i] != 0) return 0;
    return 1;
}

int IsEqual(unsigned int *a, unsigned int *b)
{
    unsigned int i;
    for (i = 0; i < 128; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

void *memcpy(void *, const void *, unsigned long);

int lintGetBit(unsigned int *a, unsigned int bit)
{
    unsigned int w = bit >> 5;
    return ((1 << (bit - (w << 5))) & a[w]) ? 1 : 0;
}

void lintSetBit(int arg0, unsigned int arg1) {
    int *temp_a2;
    unsigned int temp_v1;

    temp_v1 = arg1 >> 5;
    temp_a2 = (temp_v1 * 4) + arg0;
    *temp_a2 |= 1 << (arg1 - (temp_v1 << 5));
}

void lintClearBit(int arg0, unsigned int arg1) {
    int *temp_a2;
    unsigned int temp_v0;

    temp_v0 = arg1 >> 5;
    temp_a2 = (temp_v0 * 4) + arg0;
    *temp_a2 &= ~(1 << (arg1 - (temp_v0 << 5)));
}

void lintIncrement(unsigned int *a, unsigned int v)
{
    unsigned int i;
    unsigned int t;

    for (i = 0; i < 128; i++, a++) {
        if (i != 0) {
            t = *a + 1;
            *a = t;
            if (t != 0) return;
        } else {
            t = *a + v;
            *a = t;
            if (t >= v) return;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintDecrement);

void lintAdd(unsigned int *r, unsigned int *a, unsigned int *b)
{
    unsigned int t[128];
    memcpy(t, a, 0x200);
    lintAddIP(t, b);
    memcpy(r, t, 0x200);
}

void lintSubIP();
void lintSub(unsigned int *r, unsigned int *a, unsigned int *b)
{
    unsigned int t[128];
    memcpy(t, a, 0x200);
    lintSubIP(t, b);
    memcpy(r, t, 0x200);
}

void MODIP();
void MOD(unsigned int *r, unsigned int *a, unsigned int *b)
{
    unsigned int t[128];
    memcpy(t, a, 0x200);
    MODIP(t, b);
    memcpy(r, t, 0x200);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", QUO);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", QRMOD);

typedef struct { unsigned int w[128]; } LInt;
void MODIP();
void GCD(LInt *r, LInt *a, LInt *b)
{
    LInt x, y;

    memcpy(&x, a, sizeof(LInt));
    memcpy(&y, b, sizeof(LInt));
    for (;;) {
        MODIP(&x, &y);
        if (IsZero((int *)&x)) {
            memcpy(r, &y, sizeof(LInt));
            return;
        }
        MODIP(&y, &x);
        if (IsZero((int *)&y)) {
            memcpy(r, &x, sizeof(LInt));
            return;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", EMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintIsbSPRP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintRandomize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintTryDiv);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", PRIME_START);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", D_0010D37C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintPrime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", EMODM);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintGenerateKeyPair);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintGetBits);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", ShiftRight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", ShiftLeft);

void lintAddIP(int arg0, int arg1) {
    int temp_v0;
    int var_a4;
    unsigned int *temp_a2;
    unsigned int *temp_v0_2;
    unsigned int temp_v1;
    unsigned int var_a3;

    var_a4 = 0;
    var_a3 = 0;
    do {
        temp_v0 = var_a3 * 4;
        temp_a2 = temp_v0 + arg1;
        temp_v0_2 = temp_v0 + arg0;
        temp_v1 = *temp_v0_2 + (*temp_a2 + var_a4);
        *temp_v0_2 = temp_v1;
        if (var_a4 != 0) {
            var_a4 = (unsigned int) *temp_a2 >= temp_v1;
        } else {
            var_a4 = temp_v1 < (unsigned int) *temp_a2;
        }
        var_a3 += 1;
    } while (var_a3 < 0x80U);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintSubIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MODIP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsNotGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsNotSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MULT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", XMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MODW);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MontPro);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", D_0010D428);
