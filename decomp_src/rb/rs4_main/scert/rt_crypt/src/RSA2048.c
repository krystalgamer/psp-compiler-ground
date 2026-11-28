#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { unsigned int w[128]; } LInt;
void *memset(void *, int, unsigned long);
void EMODM(LInt *, LInt *, LInt *, LInt *);
void lintGenerateKeyPair(LInt *, LInt *, int, unsigned int);

void RSA2048Encrypt(unsigned char *mod, unsigned int modlen, unsigned int e, unsigned char *buf, unsigned int len)
{
    LInt E, N, M, C;
    unsigned int i;
    unsigned char *d, *q;

    memset(&E, 0, sizeof(LInt));
    memset(&N, 0, sizeof(LInt));
    memset(&M, 0, sizeof(LInt));
    memset(&C, 0, sizeof(LInt));
    E.w[0] = e;
    d = (unsigned char *)&N + modlen;
    for (i = 0; i < modlen; i++)
        *--d = *mod++;
    q = buf;
    d = (unsigned char *)&M + len;
    for (i = 0; i < len; i++)
        *--d = *q++;
    EMODM(&C, &M, &E, &N);
    q = buf;
    d = (unsigned char *)&C + len;
    for (i = 0; i < len; i++)
        *q++ = *--d;
}

void RSA2048Decrypt(unsigned char *mod, unsigned char *key, unsigned int modlen, unsigned char *buf, unsigned int len)
{
    LInt D, N, M, C;
    unsigned int i;
    unsigned char *d, *q;

    memset(&D, 0, sizeof(LInt));
    memset(&N, 0, sizeof(LInt));
    memset(&M, 0, sizeof(LInt));
    memset(&C, 0, sizeof(LInt));
    d = (unsigned char *)&N + modlen;
    for (i = 0; i < modlen; i++)
        *--d = *mod++;
    mod = key;
    d = (unsigned char *)&D + modlen;
    for (i = 0; i < modlen; i++)
        *--d = *mod++;
    q = buf;
    d = (unsigned char *)&M + len;
    for (i = 0; i < len; i++)
        *--d = *q++;
    EMODM(&C, &M, &D, &N);
    q = buf;
    d = (unsigned char *)&C + len;
    for (i = 0; i < len; i++)
        *q++ = *--d;
}

void RSA2048GenerateKeyPair(unsigned char *pub, unsigned char *priv, int x, unsigned int bits)
{
    LInt A, B;
    unsigned int n = (bits + 7) >> 3;
    unsigned int i;
    unsigned char *a, *b;

    lintGenerateKeyPair(&A, &B, x, bits);
    a = (unsigned char *)&A;
    b = (unsigned char *)&B;
    pub += n;
    priv += n;
    for (i = 0; i < n; i++) {
        *--pub = *a++;
        *--priv = *b++;
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA2048", rcsid_10D590);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA2048", rsa2048_header_rcsid);
