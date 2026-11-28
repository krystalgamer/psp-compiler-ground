#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned char BYTE;
typedef unsigned int UINT4;
#define SHS_DATASIZE 64
#define SHS_DIGESTSIZE 20
typedef struct {
    UINT4 data[16];
    UINT4 digest[5];
    int Endianness;
    UINT4 countLo, countHi;
} SHA_CTX;
void SHAInit(SHA_CTX *);
void SHAUpdate(SHA_CTX *, BYTE *, unsigned int);
void SHAFinal(SHA_CTX *, BYTE *, unsigned int);
void endianTest(int *);
void SHSTransform(SHA_CTX *);
void longReverse(UINT4 *, int, int);
void SHAtoByte(BYTE *, UINT4 *, unsigned int);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
extern SHA_CTX D_0011523C;

void SHAInit(SHA_CTX *shsInfo)
{
    *shsInfo = D_0011523C;
    endianTest(&shsInfo->Endianness);
}

void SHAUpdate(SHA_CTX *shsInfo, BYTE *buffer, unsigned int count)
{
    UINT4 tmp;
    unsigned int dataCount;

    tmp = shsInfo->countLo;
    if ((shsInfo->countLo = tmp + ((UINT4)count << 3)) < tmp)
        shsInfo->countHi++;
    shsInfo->countHi += count >> 29;
    dataCount = (tmp >> 3) & 0x3F;
    if (dataCount) {
        BYTE *p = (BYTE *)shsInfo->data + dataCount;

        dataCount = SHS_DATASIZE - dataCount;
        if (count < dataCount) {
            memcpy(p, buffer, count);
            return;
        }
        memcpy(p, buffer, dataCount);
        longReverse(shsInfo->data, SHS_DATASIZE, shsInfo->Endianness);
        SHSTransform(shsInfo);
        buffer += dataCount;
        count -= dataCount;
    }
    while (count >= SHS_DATASIZE) {
        memcpy((void *)shsInfo->data, (void *)buffer, SHS_DATASIZE);
        longReverse(shsInfo->data, SHS_DATASIZE, shsInfo->Endianness);
        SHSTransform(shsInfo);
        buffer += SHS_DATASIZE;
        count -= SHS_DATASIZE;
    }
    memcpy((void *)shsInfo->data, (void *)buffer, count);
}

void SHAFinal(SHA_CTX *shsInfo, BYTE *output, unsigned int len)
{
    int count;
    BYTE *dataPtr;

    count = (int)shsInfo->countLo;
    count = (count >> 3) & 0x3F;
    dataPtr = (BYTE *)shsInfo->data + count;
    *dataPtr++ = 0x80;
    count = SHS_DATASIZE - 1 - count;
    if (count < 8) {
        memset(dataPtr, 0, count);
        longReverse(shsInfo->data, SHS_DATASIZE, shsInfo->Endianness);
        SHSTransform(shsInfo);
        memset((void *)shsInfo->data, 0, SHS_DATASIZE - 8);
    } else
        memset(dataPtr, 0, count - 8);
    shsInfo->data[14] = shsInfo->countHi;
    shsInfo->data[15] = shsInfo->countLo;
    longReverse(shsInfo->data, SHS_DATASIZE - 8, shsInfo->Endianness);
    SHSTransform(shsInfo);
    if (len > SHS_DIGESTSIZE) {
        memset(output + SHS_DIGESTSIZE, 0, len - SHS_DIGESTSIZE);
        len = SHS_DIGESTSIZE;
    }
    SHAtoByte(output, shsInfo->digest, len);
    memset((void *)shsInfo, 0, sizeof(shsInfo));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
extern unsigned short D_0010D700;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", endianTest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", SHSTransform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", longReverse);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", SHAtoByte);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", rcsid_10D64C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", sha1_header_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/SHA1", D_0010D700);
