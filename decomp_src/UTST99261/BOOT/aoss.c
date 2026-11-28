/* cflags: -O2 -frename-registers */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char *s_buf;
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


int AstsSetInitRes(int state, unsigned char *pkt, int *cnt, unsigned char *ctx);
int AstsSetSecureRes(int state, unsigned char *pkt, int *cnt, unsigned char *ctx);
int AstsRestartRes(int state, unsigned char *pkt, int *cnt, unsigned char *ctx);
int DecodePacket(unsigned char *p);
extern unsigned char ProductInfo[];
extern unsigned char SecurityInfo[];
int GetSecurityData(int a, unsigned char *p, int len, unsigned char *info, unsigned char *prod);
int aoss_get_bin(unsigned char *p, int n);
int DecodeRC4(unsigned char *in, unsigned char *out, int len, unsigned char c, unsigned char *iv, unsigned char *key, int keylen);
typedef struct AossTlv { unsigned char type; unsigned char f1; unsigned short len; unsigned int val; } AossTlv;
extern unsigned int D_002DC6D4;
extern int SecurityType;
int PacketDataSet(int type, unsigned char *out, AossTlv *tlv, short *len, short *x, char *c);
int SetStaData(unsigned char *p);
typedef struct { int f0; int len; char ssid[0x28]; char key[4][0x40]; } AossWep;
typedef struct { int f0; int len; char ssid[0x28]; char key[0x40]; } AossWpa;
typedef struct { AossWep w0; AossWep w1; AossWpa p0; AossWpa p1; } AossSec;
extern AossSec D_002DC6F0;
int aoss_check_str(unsigned char *s, int n);
int CheckRecvSeqID(unsigned char *a, unsigned char *b);
int AOSS_Ntohl(int arg0);
int CheckSeqID(unsigned short id, unsigned char *seq);
void SetPacketHeader(short *hdr, short a, short b, short c, char d, char e, unsigned char *key);
int SendPacketUDP(void *buf, int len, unsigned char bcast, int sock);
unsigned char crc(unsigned char *buf, int len);
void AddKey(unsigned char *key, unsigned char *buf, int len);
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

int AOSS_seq_data_copy(unsigned char *p)
{
    unsigned char *d = p + 0x117;
    AossWep *w0 = &D_002DC6F0.w0;
    AossWep *w1 = &D_002DC6F0.w1;
    AossWpa *p0 = &D_002DC6F0.p0;
    AossWpa *p1 = &D_002DC6F0.p1;

    if (d == NULL)
        return -1;
    *(unsigned short *)p = gData.f8 & gData.fC;
    AOSS_Memset(d, 0, 0x154);
    if (*(unsigned short *)p & 1) {
        AOSS_Memcpy(d, w0->key[0], w0->len);
        AOSS_Memcpy(p + 0x11D, w0->key[1], w0->len);
        AOSS_Memcpy(p + 0x123, w0->key[2], w0->len);
        AOSS_Memcpy(p + 0x129, w0->key[3], w0->len);
        if (aoss_check_str((unsigned char *)w0->ssid, AOSS_Strlen(w0->ssid)))
            goto err;
        AOSS_Memcpy(p + 0x12F, w0->ssid, AOSS_Strlen(w0->ssid));
    }
    if (*(unsigned short *)p & 2) {
        AOSS_Memcpy(p + 0x150, w1->key[0], w1->len);
        AOSS_Memcpy(p + 0x15E, w1->key[1], w1->len);
        AOSS_Memcpy(p + 0x16C, w1->key[2], w1->len);
        AOSS_Memcpy(p + 0x17A, w1->key[3], w1->len);
        if (aoss_check_str((unsigned char *)w1->ssid, AOSS_Strlen(w1->ssid)))
            goto err;
        AOSS_Memcpy(p + 0x188, w1->ssid, AOSS_Strlen(w1->ssid));
    }
    if (*(unsigned short *)p & 4) {
        if (aoss_check_str((unsigned char *)p0->key, p0->len - 1))
            goto err;
        AOSS_Memcpy(p + 0x1A9, p0->key, p0->len);
        if (aoss_check_str((unsigned char *)p0->ssid, AOSS_Strlen(p0->ssid)))
            goto err;
        AOSS_Memcpy(p + 0x1E9, p0->ssid, AOSS_Strlen(p0->ssid));
    }
    if (*(unsigned short *)p & 8) {
        if (aoss_check_str((unsigned char *)p1->key, p1->len - 1))
            goto err;
        AOSS_Memcpy(p + 0x20A, p1->key, p1->len);
        if (aoss_check_str((unsigned char *)p1->ssid, AOSS_Strlen(p1->ssid)))
            goto err;
        AOSS_Memcpy(p + 0x24A, p1->ssid, AOSS_Strlen(p1->ssid));
    }
    p[0x116] = 0;
    return 0;
err:
    AOSS_Memset(d, 0, 0x154);
    return -1;
}

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

int RecvMessage(int state, unsigned char *pkt, int *cnt, unsigned char *ctx)
{
    unsigned char *p = pkt + 0xC;
    int ret = state;

    if (AOSS_Ntohs(*(unsigned short *)(pkt + 0xC)) == 0) {
        (*cnt)++;
        return ret;
    }
    if (p[0xF] != 0x11) {
        (*cnt)++;
        return ret;
    }
    if (DecodePacket(p) > 0) {
        (*cnt)++;
        return ret;
    }
    switch (AOSS_Ntohs(*(unsigned short *)(p + 6))) {
    case 0x1010:
        ret = AstsSetInitRes(ret, pkt, cnt, ctx);
        break;
    case 0x2010:
        ret = AstsSetSecureRes(ret, pkt, cnt, ctx);
        break;
    case 0x3010:
        ret = AstsRestartRes(ret, pkt, cnt, ctx);
        break;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsSetInitRes);

int AstsSetSecureRes(int state, unsigned char *pkt, int *cnt, unsigned char *ctx)
{
    unsigned char *hdr;
    unsigned char *body;
    int r;

    if (state != 1) {
        (*cnt)++;
        return state;
    }
    r = CheckRecvSeqID(ctx + 8, pkt + 0x1C);
    hdr = pkt + 0xC;
    body = pkt + 0x24;
    if (r < 0 || AOSS_Ntohs(*(unsigned short *)(body + 2)) == 0) {
        (*cnt)++;
        return 1;
    }
    if (pkt[0x24] == 7) {
        if (AOSS_Ntohl(*(int *)(body + 4)) == -2)
            aoss_set_error(0x14);
        else if (AOSS_Ntohl(*(int *)(body + 4)) == -3)
            aoss_set_error(0x15);
        else
            aoss_set_error(0x18);
        return -1;
    }
    AOSS_Memset(SecurityInfo, 0, 0x6A0);
    if (GetSecurityData(0, body, AOSS_Ntohs(*(unsigned short *)(hdr + 0xA)), SecurityInfo, ProductInfo) < 0) {
        (*cnt)++;
        return 1;
    }
    if (gData.fC & gData.f8) {
        *cnt = 0;
        return 2;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AstsRestartRes);

int DecodePacket(unsigned char *p)
{
    unsigned char seq[8];
    unsigned char *body = p + 0x18;
    int r;
    int len;
    unsigned char *buf;

    AOSS_Memcpy(seq, p + 0x10, 8);
    if (CryptSeqNo(seq, 8, D_00141144, AOSS_Strlen(D_00141144)) == -1) {
        aoss_set_error(2);
        return -100;
    }
    r = CheckSeqID(AOSS_Ntohs(*(unsigned short *)(p + 6)), seq);
    if (r != 0)
        return r;
    if (AOSS_Ntohs(*(unsigned short *)(p + 6)) == 0x1000)
        AOSS_Memcpy(gSeqID, seq, 8);
    if ((AOSS_Ntohs(*(unsigned short *)(p + 0xC)) & 0xF) == 0)
        return 0;
    len = AOSS_Ntohs(*(unsigned short *)(p + 0x18));
    buf = AOSS_Malloc(len);
    if (buf == NULL) {
        aoss_set_error(2);
        return 100;
    }
    if (DecodeRC4(p + 0x1C, buf, len, p[0xE], p + 0x1A, gSeqID, 8) < 0) {
        AOSS_Free(buf);
        return aoss_get_error() == 2 ? 100 : 200;
    }
    AOSS_Memcpy(body, buf, len);
    *(unsigned short *)(p + 0xA) = AOSS_Htons(len);
    AOSS_Free(buf);
    return 0;
}

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

int CheckRecvSeqID(unsigned char *a, unsigned char *b)
{
    int ret = 0;

    CryptSeqNo(b, 8, D_00141144, AOSS_Strlen(D_00141144));
    if (AOSS_Memcmp(a, b, 6) != 0)
        ret = -1;
    else if (AOSS_Ntohs(*(unsigned short *)(a + 6)) + 1 != AOSS_Ntohs(*(unsigned short *)(b + 6)))
        ret = -2;
    return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141138);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", D_00141144);

int GetProductInfo(unsigned char *buf, unsigned char *info)
{
    unsigned char *p;
    int len;
    int v;

    AOSS_Memset(info, 0, 0x104);
    p = buf;
    for (;;) {
        len = AOSS_Ntohs(*(unsigned short *)(p + 2));
        if (len <= 0)
            return -1;
        switch (p[0]) {
        case 0:
            AOSS_Memcpy(info, p + 6, len);
            break;
        case 1:
            AOSS_Memcpy(info + 0x80, p + 6, len);
            break;
        case 2:
            AOSS_Memcpy(info + 0x100, p + 6, len);
            break;
        case 3:
        case 4:
            v = AOSS_Ntohs(p[6]);
            if (v <= 0)
                return -2;
            break;
        case 5:
            gData.ip = AOSS_Ntohl(aoss_get_bin(p + 6, len));
            break;
        case 6:
            gData.f14 = AOSS_Ntohl(aoss_get_bin(p + 6, len));
            break;
        default:
            return -1;
        }
        if (*(unsigned short *)(p + 4) == 0)
            return 0;
        p = buf + AOSS_Ntohs(*(unsigned short *)(p + 4));
    }
}

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

int AstsSetInitReq(int a, int b, int c)
{
    unsigned char *buf = s_buf;
    unsigned char *data;
    char flag = 0;
    unsigned char seq[8];
    short len = 0;
    short x = 0;
    unsigned char *tlv;

    AOSS_Memset(buf, 0, 0x5DC);
    tlv = AOSS_Malloc(0x210);
    if (tlv == NULL) {
        aoss_set_error(2);
        return -1;
    }
    AOSS_Memset(tlv, 0, 0x210);
    AOSS_Memcpy(gSeqID, (unsigned char *)b, 8);
    AOSS_Memcpy(seq, gSeqID, 8);
    len = SetStaData(tlv + 4);
    data = buf + 0x18;
    if (len < 0) {
        aoss_set_error(3);
        AOSS_Free(tlv);
        return -1;
    }
    tlv[0] = 0;
    *(unsigned short *)(tlv + 2) = AOSS_Htons(len);
    len += 4;
    PacketDataSet(0, data, (AossTlv *)tlv, &len, &x, &flag);
    x |= 0x10;
    if (CryptSeqNo(seq, 8, (unsigned char *)D_00141144, 6) != 0) {
        aoss_set_error(2);
        AOSS_Free(tlv);
        return -1;
    }
    SetPacketHeader((short *)buf, 0x1000, len, x, flag, 0x11, seq);
    len += 0x18;
    SendPacketUDP(buf, len, 0xFF, c);
    AOSS_Free(tlv);
    return 0;
}

int AstsSetSecureReq(int a, int b, int c)
{
    unsigned char *buf = s_buf;
    unsigned char *data = buf + 0x18;
    char flag = 0;
    unsigned char seq[8];
    short len = 0;
    short x = 0;
    AossTlv tlv;

    AOSS_Memset(&tlv, 0, 8);
    AOSS_Memset(buf, 0, 0x5DC);
    tlv.type = 2;
    tlv.f1 = 0;
    tlv.len = AOSS_Htons(4);
    tlv.val = D_002DC6D4;
    tlv.val = AOSS_Htonl(tlv.val);
    len = 8;
    PacketDataSet(SecurityType, data, &tlv, &len, &x, &flag);
    AOSS_Memcpy(seq, (unsigned char *)b + 8, 8);
    if (CryptSeqNo(seq, 8, (unsigned char *)D_00141144, 6) != 0) {
        aoss_set_error(2);
        return -1;
    }
    SetPacketHeader((short *)buf, 0x2000, len, x, flag, 0x11, seq);
    len += 0x18;
    SendPacketUDP(buf, len, 0, c);
    return 0;
}

int AstsRestartReq(int a, int b, int c)
{
    unsigned char *buf = s_buf;
    unsigned char seq[8];

    AOSS_Memset(buf, 0, 0x5DC);
    AOSS_Memcpy(seq, (unsigned char *)b + 0x10, 8);
    CryptSeqNo(seq, 8, (unsigned char *)D_00141144, AOSS_Strlen(D_00141144));
    SetPacketHeader((short *)buf, 0x3000, 0, 0, 0, 0x11, seq);
    SendPacketUDP(buf, 0x18, 0, c);
    return 0;
}

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

int GetWEPData(unsigned char *buf, unsigned char *out)
{
    unsigned char *p;
    unsigned int len;

    p = buf + 6;
    for (;;) {
        len = AOSS_Ntohs(*(unsigned short *)(p + 2));
        switch (p[0]) {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            if (len > 5)
                return -1;
            break;
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
            if (len > 13)
                return -1;
            break;
        case 0x15:
        case 0x25:
            if (len > 0x21)
                return -1;
            break;
        }
        switch (p[0]) {
        case 0x10:
        case 0x20:
            AOSS_Memcpy(out + 0x30, p + 6, len);
            *(int *)(out + 4) = len;
            break;
        case 0x11:
        case 0x21:
            AOSS_Memcpy(out + 0x70, p + 6, len);
            *(int *)(out + 4) = len;
            break;
        case 0x12:
        case 0x22:
            AOSS_Memcpy(out + 0xB0, p + 6, len);
            *(int *)(out + 4) = len;
            break;
        case 0x13:
        case 0x23:
            AOSS_Memcpy(out + 0xF0, p + 6, len);
            *(int *)(out + 4) = len;
            break;
        case 0x15:
        case 0x25:
            if (len != 0 && ((unsigned char *)((int)len + (int)p))[5] != 0)
                return -1;
            AOSS_Memcpy(out + 8, p + 6, len);
            break;
        default:
            return -1;
        }
        if (*(unsigned short *)(p + 4) == 0)
            return 0;
        p = buf + AOSS_Ntohs(*(unsigned short *)(p + 4)) + 6;
    }
}

int GetWPAData(unsigned char *buf, unsigned char *out)
{
    unsigned char *p;
    unsigned int len;

    p = buf + 6;
    for (;;) {
        len = AOSS_Ntohs(*(unsigned short *)(p + 2));
        switch (p[0]) {
        case 0x30:
        case 0x40:
            if (len > 0x40)
                return -1;
            break;
        case 0x35:
        case 0x45:
            if (len > 0x21)
                return -1;
            break;
        }
        switch (p[0]) {
        case 0x30:
        case 0x40:
            AOSS_Memcpy(out + 0x30, p + 6, len);
            *(int *)(out + 4) = len;
            break;
        case 0x35:
        case 0x45:
            if (len != 0 && ((unsigned char *)((int)len + (int)p))[5] != 0)
                return -1;
            AOSS_Memcpy(out + 8, p + 6, len);
            break;
        default:
            return -1;
        }
        if (*(unsigned short *)(p + 4) == 0)
            return 0;
        p = buf + AOSS_Ntohs(*(unsigned short *)(p + 4)) + 6;
    }
}
