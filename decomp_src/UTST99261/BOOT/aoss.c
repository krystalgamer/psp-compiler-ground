/* cflags: -O2 -frename-registers */
#include "common.h"
#include "m2c_macros.h"
typedef struct AossData {
    unsigned char *mac;               /* 0x0 */
    int f4;
    int f8;
    int fC;
    unsigned int ip;                  /* 0x10 */
    int f14;
    unsigned char f18;
    unsigned char f19;
} AossData;
typedef struct NecApParam {
    int w[14];
} NecApParam;
extern int gError;
extern unsigned char gSeqID[8];
extern AossData gData;
extern unsigned int D_002DC2CC[256];
extern void *linkInfo;
extern void *bssList;
extern int D_00218824;
extern NecApParam _gNecApConfigParam;
extern int _gNecApState;
extern int _gNecApTimeout;
extern int _gNecApResult;
extern unsigned long long D_002DD080;
void *AOSS_Malloc(unsigned int n);
void AOSS_Free(void *p);
void AOSS_Memset(void *p, int c, unsigned int n);
void *AOSS_Memcpy(void *d, const void *s, unsigned int n);
int AOSS_Memcmp(const void *a, const void *b, unsigned int n);
int AOSS_Rand(void);
int AOSS_Status(int s);
unsigned int update_crc(unsigned int c, unsigned char *buf, int len, int init, unsigned int *table);
void make_crc_table(int a, unsigned int *table);
int sceRtcGetCurrentTick(unsigned long long *t);
M2C_UNK sceNetInetRecvfrom();                       /* extern */
M2C_UNK sceNetInetSelect();                         /* extern */
M2C_UNK sceNetInetSendto();                         /* extern */
M2C_UNK sceNetInetSetsockopt();                     /* extern */
M2C_UNK sceNetInetSocket();                         /* extern */
M2C_UNK sceNetInetBind();                           /* extern */
M2C_UNK sceNetInetClose();                          /* extern */


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141118);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_Init_old);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_IP_sta);

void aoss_release(void)
{
    if (linkInfo != NULL) {
        AOSS_Free(linkInfo);
        linkInfo = NULL;
    }
    if (bssList != NULL) {
        AOSS_Free(bssList);
        bssList = NULL;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_data_init);

void aoss_set_error(int e)
{
    gError = e;
}

int aoss_get_error(void)
{
    return gError;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_seq_data_copy);

int aoss_check_str(unsigned char *s, int n)
{
    int i;

    for (i = 0; i < n; i++, s++)
        if ((unsigned int)(*s - 0x20) >= 0x60)
            return -1;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", checkAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_set_APInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", MakeSendSeqID);

int AOSS_StatusExclusion(int s)
{
    int r = 0;

    if (s == -1)
        D_00218824 = s;
    else if (D_00218824 != s) {
        D_00218824 = s;
        r = AOSS_Status(s);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", RecvMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetInitRes);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetSecureRes);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsRestartRes);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", DecodePacket);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", CheckSeqID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", CheckRecvSeqID);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141138);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141144);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetProductInfo);

int aoss_get_bin(unsigned char *p, int n)
{
    int v = 0;
    int i;
    unsigned char *q = p + n - 1;

    for (i = 0; i < n; i++) {
        v <<= 8;
        v += *q--;
    }
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetSecurityData);

int GetSecurityType(int f)
{
    int t = 0;

    if (f & 0x10)
        t = 1;
    return t;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", SendMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetInitReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetSecureReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsRestartReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", SetStaData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", PacketDataSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", SetPacketHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", SendPacketUDP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", EncodeRC4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", DecodeRC4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", RC4init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", RC4encrypt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", arcfour_byte);

unsigned char crc(unsigned char *buf, int len)
{
    return ~update_crc(0xFFFFFFFF, buf, len, 0, D_002DC2CC);
}

unsigned int update_crc(unsigned int c, unsigned char *buf, int len, int init, unsigned int *table)
{
    int n;

    if (!init)
        make_crc_table(0, table);
    for (n = 0; n < len; n++)
        c = table[(c ^ buf[n]) & 0xFF] ^ (c >> 8);
    return c;
}

void make_crc_table(int unused, unsigned int *table)
{
    unsigned int c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = n;
        for (k = 0; k < 8; k++) {
            if (c & 1)
                c = 0xEDB88320 ^ (c >> 1);
            else
                c = c >> 1;
        }
        *table++ = c;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", CryptSeqNo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", MakeKey);

void AddKey(unsigned char *key, unsigned char *buf, int len)
{
    int i;
    int half = len / 2;

    for (i = 0; i < half; i++)
        buf[half + i] ^= key[i];
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", Rotate);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *malloc(unsigned int size);
void *AOSS_Malloc(unsigned int arg0) {
    return malloc(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void free(void *p);
void AOSS_Free(void *arg0) {
    free(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int memcmp(const void *a, const void *b, unsigned int n);
int AOSS_Memcmp(const void *arg0, const void *arg1, unsigned int arg2) {
    return memcmp(arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memcpy(void *d, const void *s, unsigned int n);
void *AOSS_Memcpy(void *arg0, const void *arg1, unsigned int arg2) {
    memcpy(arg0, arg1, arg2);
    return arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
void AOSS_Memset(void *arg0, int arg1, unsigned int arg2) {
    memset(arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Recvfrom(void) {
    sceNetInetRecvfrom();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Select(void) {
    sceNetInetSelect();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Sendto(void) {
    sceNetInetSendto();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Setsockopt(void) {
    sceNetInetSetsockopt();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Socket(void) {
    sceNetInetSocket();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Bind(void) {
    sceNetInetBind();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void AOSS_Close(void) {
    sceNetInetClose();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int AOSS_Htonl(int arg0) {
    return __builtin_allegrex_wsbw(arg0);
}

unsigned short AOSS_Htons(unsigned short v)
{
    return __builtin_allegrex_wsbh(v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int AOSS_Ntohl(int arg0) {
    return __builtin_allegrex_wsbw(arg0);
}

unsigned short AOSS_Ntohs(unsigned short v)
{
    return __builtin_allegrex_wsbh(v);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);
unsigned int AOSS_Strlen(const char *arg0) {
    return strlen(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int rand(void);
int AOSS_Rand(void) {
    return rand();
}

void AOSS_FD_ZERO(unsigned char *p)
{
    unsigned int i;

    for (i = 0; i < 32; i++)
        *p++ = 0;
}

void AOSS_FD_SET(unsigned int fd, unsigned int *set)
{
    set[fd >> 5] |= 1 << (fd & 0x1F);
}

int AOSS_version(void)
{
    return 0x2000767;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetWEPData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetWPAData);
