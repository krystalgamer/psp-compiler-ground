#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { unsigned int w[128]; } LInt;
void *memcpy(void *, const void *, unsigned long);
void *memset(void *, int, unsigned long);
void lintSetSmallValue(LInt *, int);
void EMODM(LInt *, LInt *, LInt *, LInt *);
void RSAEncryptBlock(unsigned char *, int, unsigned char *, unsigned char *);
void RSADecryptBlock(unsigned char *, unsigned char *, unsigned char *, unsigned char *);

void RSAEncryptBlock(unsigned char *mod, int e, unsigned char *in, unsigned char *out)
{
    LInt E, N, M, C;

    lintSetSmallValue(&E, e);
    memcpy(&N, mod, 64);
    memset(&N.w[16], 0, 0x1C0);
    memcpy(&M, in, 64);
    memset(&M.w[16], 0, 0x1C0);
    EMODM(&C, &M, &E, &N);
    memcpy(out, &C, 64);
}

void RSADecryptBlock(unsigned char *mod, unsigned char *key, unsigned char *in, unsigned char *out)
{
    LInt D, N, M, C;

    memcpy(&D, key, 64);
    memset(&D.w[16], 0, 0x1C0);
    memcpy(&N, mod, 64);
    memset(&N.w[16], 0, 0x1C0);
    memcpy(&M, in, 64);
    memset(&M.w[16], 0, 0x1C0);
    EMODM(&C, &M, &D, &N);
    memcpy(out, &C, 64);
}

int RSAEncrypt(unsigned char *mod, unsigned char *in, unsigned char *out, int len)
{
    int done = 0;

    while (len >= 64) {
        RSAEncryptBlock(mod, 0x11, in, out);
        len -= 64;
        done += 64;
        out += 64;
        in += 64;
    }
    return done;
}

int RSADecrypt(unsigned char *mod, unsigned char *key, unsigned char *in, unsigned char *out, unsigned int len)
{
    int done = 0;

    while (len >= 64) {
        RSADecryptBlock(mod, key, in, out);
        len -= 64;
        done += 64;
        in += 64;
        out += 64;
    }
    return done;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", rcsid_10D4E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", header_rcsid_10D538);
