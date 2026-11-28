#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { unsigned int state[4]; unsigned int count[2]; unsigned char buffer[64]; unsigned int pad[2]; } MD5_CTX;
void md5Init(MD5_CTX *);
void md5Update(MD5_CTX *, unsigned char *, unsigned int);
void md5Final(unsigned char *, MD5_CTX *);
void md5Transform(MD5_CTX *);
void md5Encode(unsigned char *, unsigned int *, unsigned int);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
extern unsigned char PADDING[64];

void KM_MD5(unsigned char *in, unsigned int len, unsigned char *out)
{
    MD5_CTX ctx;

    md5Init(&ctx);
    md5Update(&ctx, in, len);
    md5Final(out, &ctx);
}

void KM_Salted_MD5(unsigned char *salt, unsigned int saltlen, unsigned char *in, unsigned int len, unsigned char *out)
{
    MD5_CTX ctx;

    md5Init(&ctx);
    if (salt != NULL && saltlen != 0) md5Update(&ctx, salt, saltlen);
    md5Update(&ctx, in, len);
    md5Final(out, &ctx);
}

void md5Init(MD5_CTX *ctx)
{
    ctx->count[0] = ctx->count[1] = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
}

void md5Update(MD5_CTX *ctx, unsigned char *in, unsigned int len)
{
    unsigned int index, partLen;

    index = ctx->count[0] & 0x3F;
    if ((ctx->count[0] += len) < len) ctx->count[1]++;
    partLen = 64 - index;
    if (len >= partLen) {
        memcpy(&ctx->buffer[index], in, partLen);
        len -= partLen;
        in += partLen;
        md5Transform(ctx);
        index = 0;
        while (len >= 64) {
            memcpy(ctx->buffer, in, 64);
            len -= 64;
            in += 64;
            md5Transform(ctx);
        }
    }
    memcpy(&ctx->buffer[index], in, len);
}

void md5Final(unsigned char *digest, MD5_CTX *ctx)
{
    unsigned char bits[8];
    unsigned int count[2];
    unsigned int index, padLen;

    count[0] = ctx->count[0];
    count[1] = ctx->count[1];
    index = count[0] & 0x3F;
    padLen = (index < 56) ? (56 - index) : (120 - index);
    md5Update(ctx, PADDING, padLen);
    count[1] = (count[1] << 3) + (count[0] >> 29);
    count[0] <<= 3;
    md5Encode(bits, count, 8);
    md5Update(ctx, bits, 8);
    md5Encode(digest, ctx->state, 16);
    memset(ctx, 0, sizeof(*ctx));
}
