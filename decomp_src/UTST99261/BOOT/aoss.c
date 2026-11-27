/* cflags: -O2 -frename-registers */
#include "common.h"
#include "m2c_macros.h"
typedef struct AossApInfo {
    int ssidlen;
    char ssid[0x20];                  /* 0x4 */
    int f24;                          /* 0x24 */
    int keylen;                       /* 0x28 */
    char key[0x10];                   /* 0x2C */
} AossApInfo;
typedef struct AossSockaddr {
    unsigned char len;
    unsigned char family;             /* 0x1 */
    unsigned short port;              /* 0x2 */
    unsigned int addr;                /* 0x4 */
    char zero[8];
} AossSockaddr;
extern char D_00141138[];
extern char D_00141144[];
unsigned int AOSS_Strlen(const char *s);
unsigned short AOSS_Ntohs(unsigned short v);
int AOSS_Htonl(int v);
int AOSS_Sendto(int s, void *buf, int len, int flags, void *to, int tolen);
int CryptSeqNo(unsigned char *buf, int len, unsigned char *key, int keylen);
int EncodeRC4(unsigned char *in, unsigned char *out, int len, unsigned char *crcp, unsigned char *iv, unsigned char *key, int keylen);
int AstsSetInitReq(int a, int b, int c);
int AstsSetSecureReq(int a, int b, int c);
int AstsRestartReq(int a, int b, int c);
unsigned short AOSS_Htons(unsigned short v);
typedef struct RC4Ctx {
    unsigned int x;
    unsigned int y;                   /* 0x4 */
    unsigned char *state;             /* 0x8 */
    unsigned int n;                   /* 0xC */
} RC4Ctx;
extern unsigned char TANE[];
void RC4init(RC4Ctx *ctx, unsigned char *key, unsigned int keylen, unsigned int n);
void RC4encrypt(RC4Ctx *ctx, unsigned char *out, unsigned char *in, unsigned int n);
unsigned char arcfour_byte(RC4Ctx *ctx);
void MakeKey(int seed, unsigned char *out, int len, unsigned char *key, int keylen);
void Rotate(unsigned char *buf, int len, unsigned char *tmp);
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
int sceNetInetRecvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen);
int sceNetInetSelect(int n, void *r, void *w, void *e, void *t);
int sceNetInetSendto(int s, void *buf, int len, int flags, void *to, int tolen);
int sceNetInetSetsockopt(int s, int level, int name, void *val, int len);
int sceNetInetSocket(int domain, int type, int proto);
int sceNetInetBind(int s, void *addr, int len);
int sceNetInetClose(int s);


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141118);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_Init_old);

unsigned int aoss_IP_sta(unsigned int a, unsigned int mask)
{
    unsigned int x;
    volatile unsigned int tmp;
    void *p;

    x = (a & mask) | ((a & ~mask) + 1);
    if (!(x < ((a & mask) | ~mask)))
        x = (a & mask) | 1;
    p = AOSS_Malloc(100);
    tmp = x;
    AOSS_Free(p);
    return x;
}

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

int checkAP(int *list)
{
    int n;
    int i;
    int cnt = 0;
    int r = 0;
    unsigned char *e;

    if (list[0] == 0)
        return 5;
    n = list[0];
    if ((unsigned int)n > 64)
        n = 64;
    if (n > 0) {
        for (e = (unsigned char *)list, i = n; i != 0; i--, e += 0x54) {
            if ((*(int *)(e + 0x54) & 1) && *(int *)(e + 4) == AOSS_Strlen(D_00141138))
                cnt += AOSS_Memcmp(e + 8, D_00141138, AOSS_Strlen(D_00141138)) == 0;
        }
        if (cnt >= 2)
            r = 4;
        if (cnt != 0)
            goto out;
    }
    r = 5;
out:
    return r;
}

int AOSS_set_APInfo(AossApInfo *info)
{
    info->ssidlen = AOSS_Strlen(D_00141138);
    AOSS_Memcpy(info->ssid, D_00141138, info->ssidlen);
    info->f24 = 1;
    info->keylen = AOSS_Strlen(D_00141144);
    if ((unsigned int)info->keylen >= 14)
        return -1;
    AOSS_Memcpy(info->key, D_00141144, info->keylen);
    return 0;
}

void MakeSendSeqID(int n, unsigned char *p, unsigned char *mac)
{
    int i;
    short r;

    for (i = 0; i < n; i++) {
        AOSS_Memcpy(&p[i * 8], mac, 6);
        r = AOSS_Rand();
        *(short *)&p[i * 8 + 6] = r;
        *(short *)&p[i * 8 + 6] = AOSS_Htons(r);
    }
}

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

int CheckSeqID(unsigned short id, unsigned char *seq)
{
    int r = 0;
    int i;
    int set = 0;

    for (i = 0; i < 6; i++) {
        if (gSeqID[i] != 0) {
            set = 1;
            break;
        }
    }
    if (set != 0) {
        if (AOSS_Memcmp(gSeqID, seq, 6) != 0)
            r = 1;
    } else if (id != 0x1000)
        r = 2;
    return r;
}

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

int SendMessage(int type, int a, int b, int c)
{
    switch (type) {
    case 0:
        AOSS_StatusExclusion(2);
        return AstsSetInitReq(a, b, c);
    case 1:
        AOSS_StatusExclusion(3);
        return AstsSetSecureReq(a, b, c);
    case 2:
        AOSS_StatusExclusion(5);
        return AstsRestartReq(a, b, c);
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetInitReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetSecureReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsRestartReq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", SetStaData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", PacketDataSet);

void SetPacketHeader(short *hdr, short a, short b, short c, char d, char e, unsigned char *key)
{
    hdr[0] = AOSS_Htons(1);
    hdr[1] = 0;
    hdr[2] = 0;
    hdr[3] = AOSS_Htons(a);
    hdr[4] = 0;
    hdr[5] = AOSS_Htons(b);
    hdr[6] = AOSS_Htons(c);
    ((char *)hdr)[14] = d;
    ((char *)hdr)[15] = e;
    AOSS_Memcpy(hdr + 8, key, 8);
}

int SendPacketUDP(void *buf, int len, unsigned char bcast, int sock)
{
    AossSockaddr sa;

    AOSS_Memset(&sa, 0, 16);
    sa.family = 2;
    sa.port = AOSS_Htons(0x5790);
    sa.addr = AOSS_Htonl(gData.ip);
    if (bcast == 0xFF || (signed char)gData.f18 == 0)
        sa.addr = -1;
    return AOSS_Sendto(sock, buf, len, 0, &sa, 16);
}

int EncodeRC4(unsigned char *in, unsigned char *out, int len, unsigned char *crcp, unsigned char *iv, unsigned char *key, int keylen)
{
    RC4Ctx ctx;
    short r;

    *crcp = crc(in, len);
    ctx.state = AOSS_Malloc(len);
    if (ctx.state == NULL)
        return -1;
    r = AOSS_Rand();
    AOSS_Memcpy(iv, &r, 2);
    AOSS_Memcpy(TANE, iv, 2);
    AOSS_Memcpy(TANE + 2, key, keylen);
    RC4init(&ctx, TANE, keylen + 2, len);
    RC4encrypt(&ctx, out, in, len);
    AOSS_Free(ctx.state);
    return 0;
}

int DecodeRC4(unsigned char *in, unsigned char *out, int len, unsigned char c, unsigned char *iv, unsigned char *key, int keylen)
{
    RC4Ctx ctx;

    ctx.state = AOSS_Malloc(len);
    if (ctx.state == NULL) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memcpy(TANE, iv, 2);
    AOSS_Memcpy(TANE + 2, key, keylen);
    RC4init(&ctx, TANE, keylen + 2, len);
    RC4encrypt(&ctx, out, in, len);
    if (crc(out, len) != c) {
        aoss_set_error(0x12);
        AOSS_Free(ctx.state);
        return -1;
    }
    AOSS_Free(ctx.state);
    return 0;
}

void RC4init(RC4Ctx *ctx, unsigned char *key, unsigned int keylen, unsigned int n)
{
    unsigned char *s;
    unsigned int i, j, k;
    unsigned char t, u;

    ctx->y = 0;
    ctx->x = 0;
    ctx->n = n;
    s = ctx->state;
    for (i = 0; i < n; i++)
        s[i] = i;
    j = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        t = s[i];
        j = (j + key[k] + t) % ctx->n;
        if (++k >= keylen)
            k = 0;
        u = s[j];
        s[j] = t;
        s[i] = u;
    }
}

void RC4encrypt(RC4Ctx *ctx, unsigned char *out, unsigned char *in, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        out[i] = arcfour_byte(ctx) ^ in[i];
}

unsigned char arcfour_byte(RC4Ctx *ctx)
{
    unsigned char x, y, sx, sy;
    unsigned char *s = ctx->state;

    x = (ctx->x + 1) % ctx->n;
    sx = s[x];
    y = (sx + ctx->y) % ctx->n;
    sy = s[y];
    ctx->x = x;
    ctx->y = y;
    s[y] = sx;
    s[x] = sy;
    return s[(sx + sy) % ctx->n];
}

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

int CryptSeqNo(unsigned char *buf, int len, unsigned char *key, int keylen)
{
    unsigned char *a;
    unsigned char *b;
    int i;

    a = AOSS_Malloc(len / 2);
    if (a == NULL)
        return -1;
    b = AOSS_Malloc(len);
    if (b == NULL) {
        AOSS_Free(a);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        MakeKey(i, a, len, key, keylen);
        AddKey(a, buf, len);
        Rotate(buf, len, b);
    }
    AOSS_Free(a);
    AOSS_Free(b);
    return 0;
}

void MakeKey(int seed, unsigned char *out, int len, unsigned char *key, int keylen)
{
    int i;
    int k = seed % keylen;
    int half = len / 2;

    for (i = 0; i < half; i++) {
        out[i] = i;
        out[i] ^= key[k];
        if (++k >= keylen)
            k = 0;
    }
}

void AddKey(unsigned char *key, unsigned char *buf, int len)
{
    int i;
    int half = len / 2;

    for (i = 0; i < half; i++)
        buf[half + i] ^= key[i];
}

void Rotate(unsigned char *buf, int len, unsigned char *tmp)
{
    int half = len / 2;

    AOSS_Memcpy(tmp, buf + half, half);
    AOSS_Memcpy(tmp + half, buf, half);
    AOSS_Memcpy(buf, tmp, len);
}

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

int AOSS_Recvfrom(int s, void *buf, int len, int flags, void *from, int *fromlen) {
    return sceNetInetRecvfrom(s, buf, len, flags, from, fromlen);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Select(int n, void *r, void *w, void *e, void *t) {
    return sceNetInetSelect(n, r, w, e, t);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Sendto(int s, void *buf, int len, int flags, void *to, int tolen) {
    return sceNetInetSendto(s, buf, len, flags, to, tolen);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Setsockopt(int s, int level, int name, void *val, int len) {
    return sceNetInetSetsockopt(s, level, name, val, len);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Socket(int domain, int type, int proto) {
    return sceNetInetSocket(domain, type, proto);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Bind(int s, void *addr, int len) {
    return sceNetInetBind(s, addr, len);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int AOSS_Close(int s) {
    return sceNetInetClose(s);
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
