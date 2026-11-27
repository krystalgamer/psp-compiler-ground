#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef unsigned char *POINTER;
typedef struct {
    unsigned char state[16];
    unsigned char checksum[16];
    unsigned char buffer[16];
    unsigned int count;
} MD2_CTX;
void md2Init(MD2_CTX *);
void md2Update(MD2_CTX *, unsigned char *, unsigned int);
void md2Final(MD2_CTX *, unsigned char *);
static void md2Transform(MD2_CTX *, unsigned char *);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
extern unsigned char gS[256];
extern unsigned char *gPaddings_11529C[17];

void KM_MD2(unsigned char *data, unsigned int len, unsigned char *digest)
{
    MD2_CTX context;

    md2Init(&context);
    md2Update(&context, data, len);
    md2Final(&context, digest);
}

void md2Init(MD2_CTX *context)
{
    memset((POINTER)context, 0, sizeof(*context));
}

void md2Update(MD2_CTX *context, unsigned char *input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    index = context->count;
    context->count = (index + inputLen) & 0xf;
    partLen = 16 - index;
    if (inputLen >= partLen) {
        memcpy((POINTER)&context->buffer[index], (POINTER)input, partLen);
        md2Transform(context, context->buffer);
        for (i = partLen; i + 15 < inputLen; i += 16)
            md2Transform(context, &input[i]);
        index = 0;
    } else
        i = 0;
    memcpy((POINTER)&context->buffer[index], (POINTER)&input[i], inputLen - i);
}

void md2Final(MD2_CTX *context, unsigned char *digest)
{
    unsigned int index, padLen;

    index = context->count;
    padLen = 16 - index;
    md2Update(context, gPaddings_11529C[padLen], padLen);
    md2Update(context, context->checksum, 16);
    memcpy((POINTER)digest, (POINTER)context->state, 16);
    memset((POINTER)context, 0, sizeof(*context));
}

static void md2Transform(MD2_CTX *context, unsigned char *block)
{
    unsigned int i, j, t;
    unsigned char x[48];

    memcpy((POINTER)x, (POINTER)context->state, 16);
    memcpy((POINTER)x + 16, (POINTER)block, 16);
    for (i = 0; i < 16; i++)
        x[i + 32] = context->state[i] ^ block[i];
    t = 0;
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 48; j++)
            t = x[j] ^= gS[t];
        t = (t + i) & 0xff;
    }
    memcpy((POINTER)context->state, (POINTER)x, 16);
    t = context->checksum[15];
    for (i = 0; i < 16; i++)
        t = context->checksum[i] ^= gS[block[i] ^ t];
    memset((POINTER)x, 0, sizeof(x));
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", rcsid_10D704);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", md2_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", gS);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D8F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D900);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D90C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D918);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D928);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D938);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D948);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md2", D_0010D958);
