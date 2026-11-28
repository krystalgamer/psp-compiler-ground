#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void randReSync(void);
unsigned int randomMT(void);
void randomMTSetCharArray(unsigned char *, unsigned int);
void reloadMT(void);
void seedMT();
void seedMTUsingArray();

extern unsigned int x1, x2, y;
typedef unsigned int uint32;
#define N              (624)
#define M              (397)
#define K              (0x9908B0DFU)
#define hiBit(u)       ((u) & 0x80000000U)
#define loBit(u)       ((u) & 0x00000001U)
#define loBits(u)      ((u) & 0x7FFFFFFFU)
#define mixBits(u, v)  (hiBit(u)|loBits(v))
typedef struct { uint32 state[N + 1]; int left; } MTState;
extern MTState gMT;
extern const char D_0010EBBC[];
void setNewSeed(uint32);

void seedMT(uint32 seed)
{
    register uint32 x = (seed | 1U) & 0xFFFFFFFFU, *s = gMT.state;
    register int j;

    for (gMT.left = N - 1, *s++ = x, j = N; --j; *s++ = (x *= 69069U) & 0xFFFFFFFFU);
}

void seedMTUsingArray(uint32 *seed, uint32 len)
{
    register uint32 x = 0xFFFFFFFFU, *s = gMT.state;
    register int j;

    if (len >= N)
        len = N - 1;
    gMT.left = N - 1;
    *s++ = x;
    for (j = N; j; ) {
        j--;
        if (len) {
            x ^= *seed++;
            len--;
        }
        x = (x >> 27) | (x << 5);
        *s++ = (x *= 69069U);
    }
}

void reloadMT(void)
{
    register uint32 *p0 = gMT.state, *p2 = gMT.state + 2, *pM = gMT.state + M, s0, s1;
    register int j;

    if (gMT.left > N)
        setNewSeed(0x3579ABCD);
    gMT.left = 0;
    for (s0 = gMT.state[0], s1 = gMT.state[1], j = N - M + 1; --j; s0 = s1, s1 = *p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
    for (pM = gMT.state, j = M; --j; s0 = s1, s1 = *p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
    s1 = gMT.state[0], *p0 = *pM ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
}

void randReSync(void) {
    x1 = 0x98765431;
    x2 = 0x12345679;
    y = 0x13579BDF;
}

uint32 randomMT(void)
{
    uint32 t, a, b;

    if (++gMT.left >= N)
        reloadMT();
    t = y ^ gMT.state[gMT.left];
    b = ((x1 >> 7) | (x1 << 25)) ^ t;
    a = ((t >> 25) | (t << 7)) ^ x2;
    x1 = b;
    x2 = a;
    y = (b & t) | (a & ~t);
    return y;
}

void randomMTSetCharArray(unsigned char *buf, unsigned int len)
{
    unsigned int i = 0;

    if (len) {
        for (; i < len - 1; i++)
            buf[i] = D_0010EBBC[randomMT() & 0x3F];
        buf[len - 1] = 0;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", setNewSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", ScrambleSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", setNewSeed_platform);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", rcsid_10EB04);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", header_rcsid_10EB60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mtrandgen", D_0010EBBC);
