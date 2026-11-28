#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int IsEqual(unsigned int *, unsigned int *);
int IsEven(int *);
int IsOne(int *);
int IsZero(int *);
int KM_SetUpdateCallback(int);
void MOD(unsigned int *, unsigned int *, unsigned int *);
void lintAdd(unsigned int *, unsigned int *, unsigned int *);
void lintAddIP(int, int);
void lintClearBit(int, unsigned int);
int lintGetBit(unsigned int *, unsigned int);
int lintGetBits(unsigned int *);
void lintIncrement(unsigned int *, unsigned int);
void lintSetBit(int, unsigned int);
void lintSetSmallValue(int *, int);
void lintSub(unsigned int *, unsigned int *, unsigned int *);

extern int gAppUpdateCallback;

typedef struct { unsigned int w[128]; } LInt;
void ShiftLeft(LInt *, unsigned int);
void ShiftRight(LInt *, unsigned int);
int IsNotSmaller();

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

void lintDecrement(unsigned int *a, unsigned int v)
{
    unsigned int i;
    unsigned int t;

    for (i = 0; i < 128; i++, a++) {
        if (i != 0) {
            if (*a != 0) { *a = *a - 1; return; }
            *a = 0xFFFFFFFF;
        } else {
            if (*a < v) *a = *a - v;
            else { *a = *a - v; return; }
        }
    }
}

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

void QUO(unsigned int *r, unsigned int *a, unsigned int *m)
{
    unsigned int x[128];
    unsigned int t[128];
    unsigned int q[128];
    unsigned int na, nt, nm;

    memcpy(x, a, 0x200);
    memcpy(t, m, 0x200);
    na = lintGetBits(x);
    nt = lintGetBits(t);
    nm = nt;
    lintSetSmallValue((int *)q, 0);
    if (nt < na) {
        ShiftLeft((LInt *)t, na - nt);
        nt = na;
    }
    for (;;) {
        if (na < nm) break;
        if (na < nt) {
            ShiftRight((LInt *)t, nt - na);
            nt = na;
        }
        if (IsNotSmaller(x, t)) {
            lintSubIP(x, t);
            na = lintGetBits(x);
            lintSetBit((int)q, nt - nm);
            continue;
        }
        if (nm >= nt) break;
        nt--;
        ShiftRight((LInt *)t, 1);
    }
    memcpy(r, q, 0x200);
}

void QRMOD(unsigned int *a, unsigned int *m, unsigned int *q, unsigned int *rem)
{
    unsigned int t[128];
    unsigned int na, nt, nm;

    memcpy(t, m, 0x200);
    memcpy(rem, a, 0x200);
    na = lintGetBits(rem);
    nt = lintGetBits(t);
    nm = nt;
    lintSetSmallValue((int *)q, 0);
    if (nt < na) {
        ShiftLeft((LInt *)t, na - nt);
        nt = na;
    }
    for (;;) {
        if (na < nm) return;
        if (na < nt) {
            ShiftRight((LInt *)t, nt - na);
            nt = na;
        }
        if (IsNotSmaller(rem, t)) {
            lintSubIP(rem, t);
            na = lintGetBits(rem);
            lintSetBit((int)q, nt - nm);
            continue;
        }
        if (nm >= nt) return;
        nt--;
        ShiftRight((LInt *)t, 1);
    }
}

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

void EMODM(); void XMOD();
int lintIsbSPRP(unsigned int *n, unsigned int *b)
{
    unsigned int nm1[128];
    unsigned int d[128];
    unsigned int y[128];
    unsigned int s;
    unsigned int j;

    memcpy(nm1, n, 0x200);
    lintDecrement(nm1, 1);
    memcpy(d, nm1, 0x200);
    s = 0;
    while (!lintGetBit(d, s)) s++;
    if (s != 0) ShiftRight((LInt *)d, s);
    EMODM(y, b, d, n);
    if (IsOne((int *)y) || IsEqual(y, nm1)) return 1;
    for (j = 1; j < s; j++) {
        XMOD(y, y, y, n);
        if (IsEqual(y, nm1)) return 1;
        if (IsOne((int *)y)) return 0;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintRandomize);

typedef struct PTree { struct PTree *l; struct PTree *r; int v; } PTree;
extern PTree gPTree;
extern unsigned char gPrimes[];
int MODW();
int lintTryDiv(unsigned int *a)
{
    unsigned int cnt = 0;
    unsigned int bits = 0;
    unsigned char *pp = gPrimes;
    PTree *n = &gPTree;
    unsigned int p = 1;
    unsigned int words;
    int ret;

    words = (lintGetBits(a) + 31U) >> 5;
    ret = 1;
    for (;;) {
        if (cnt == 0) {
            bits = *pp++;
            cnt = 8;
        }
        if (bits & 1) n = n->r;
        else n = n->l;
        bits >>= 1;
        cnt--;
        if (n->v == 0) break;
        if (n->v == -1) continue;
        p += n->v;
        ret = MODW(a, p, words);
        if (ret == 0) break;
    }
    return ret;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", PRIME_START);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", D_0010D37C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintPrime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", EMODM);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", lintGenerateKeyPair);

int lintGetBits(unsigned int *a)
{
    int i;
    int bits;
    unsigned int m;
    unsigned int *p;
    unsigned int w;

    m = 0x80000000;
    bits = 0x1000;
    i = 127;
    p = &a[127];
    do {
        w = *p--;
        i--;
        if (w != 0) {
            while ((m & w) != m) {
                m >>= 1;
                bits--;
            }
            break;
        }
        bits -= 32;
    } while (i != -1);
    return bits;
}

void ShiftRight(LInt *a, unsigned int n)
{
    LInt t;
    unsigned int w, s, d, carry, k, x;

    t = *a;
    w = n >> 5;
    n = n - (w << 5);
    s = w + 128;
    d = 128;
    if (n != 0) {
        k = 32 - n;
        carry = 0;
        while (s > 128) { s--; d--; t.w[d] = 0; }
        while (d != 0) {
            s--;
            x = a->w[s];
            d--;
            t.w[d] = carry | (x >> n);
            carry = x << k;
        }
    } else {
        while (s > 128) { s--; d--; t.w[d] = 0; }
        while (d != 0) {
            s--;
            d--;
            t.w[d] = a->w[s];
        }
    }
    *a = t;
}

void ShiftLeft(LInt *a, unsigned int n)
{
    LInt t;
    unsigned int w, d, carry, k, x;
    int s;

    t = *a;
    w = n >> 5;
    n = n - (w << 5);
    s = -w;
    d = 0;
    if (n != 0) {
        k = 32 - n;
        carry = 0;
        while (s != 0) { s++; t.w[d] = 0; d++; }
        while (d < 128) {
            x = a->w[s];
            t.w[d] = carry | (x << n);
            d++;
            carry = x >> k;
            s++;
        }
    } else {
        while (s != 0) { s++; t.w[d] = 0; d++; }
        while (d < 128) {
            t.w[d] = a->w[s];
            d++;
            s++;
        }
    }
    *a = t;
}

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

void MODIP(LInt *a, LInt *m)
{
    LInt t;
    unsigned int na, nt, nm;

    t = *m;
    na = lintGetBits((unsigned int *)a);
    nt = lintGetBits((unsigned int *)&t);
    nm = nt;
    if (nt < na) {
        ShiftLeft(&t, na - nt);
        nt = na;
    }
    for (;;) {
        if (na < nm) return;
        if (na < nt) {
            ShiftRight(&t, nt - na);
            nt = na;
        }
        if (IsNotSmaller(a, &t)) {
            lintSubIP(a, &t);
            na = lintGetBits((unsigned int *)a);
            continue;
        }
        if (nm >= nt) return;
        nt--;
        ShiftRight(&t, 1);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsNotGreater);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", IsNotSmaller);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MULT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", XMOD);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MODW);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", MontPro);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/LargeInt", D_0010D428);
