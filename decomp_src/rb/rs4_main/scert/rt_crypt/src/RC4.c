#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void RC4Init(unsigned char *s, unsigned char *key, unsigned int len)
{
    unsigned int i;
    unsigned char j, k, t;

    for (i = 0; i < 256; i++) s[i] = i;
    s[0x100] = 0;
    s[0x101] = 0;
    k = 0;
    j = 0;
    for (i = 0; i < 256; i++) {
        t = s[i];
        j += t + key[k];
        s[i] = s[j];
        s[j] = t;
        k = (k + 1) % len;
    }
}

void RC4Code(unsigned char *s, unsigned char *buf, unsigned int len)
{
    unsigned int i;
    unsigned char x, y, t;

    x = s[0x100];
    y = s[0x101];
    for (i = 0; i < len; i++) {
        x = x + 1;
        y = y + s[x];
        t = s[x] + s[y];
        s[x] = t - s[x];
        s[y] = t - s[y];
        buf[i] ^= s[t];
    }
    s[0x100] = x;
    s[0x101] = y;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4", rcsid_10D42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4", rc4_header_rcsid);
