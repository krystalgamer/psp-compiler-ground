/* cflags: -O2 */
#include "common.h"
typedef struct AESockaddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;              /* 0x2 */
    int addr;                         /* 0x4 */
    char zero[8];
} AESockaddr;
extern int bDebug;
void *memcpy(void *d, const void *s, unsigned int n);
int sceNetApctlGetInfo(int code, void *info);
int _keywrap_decrypt(unsigned char *out, unsigned char *in, int len, unsigned char *key, int keylen);
unsigned char *GetFrameData(unsigned char *p, int *type, int *len);
int SendFrameViaInterface(int s, void *to, void *info, void *buf, int len);
extern int _gNecApResult;
extern int _gNecApState;
extern int _gNecApTimeout;
int SendBroadcast(int s, unsigned char *buf, int len);
int sceNetInetSendto(int s, void *buf, int len, int flags, void *to, int tolen);
int printf(const char *fmt, ...);
int _AutoConfigThreadEx(int a);
void _NecApDisconnectAP(void);
typedef struct AEMac {
    unsigned char b[6];
} AEMac;
int sceNetGetLocalEtherAddr(unsigned char *mac);
void *GetElementData(unsigned char **pp, unsigned char *end, int *type, int *len);
#define AE_NTOHS(x) ((unsigned short)__builtin_allegrex_wsbh(x))
typedef struct __attribute__((packed)) AEHdr {
    unsigned short type;
    unsigned short len;
} AEHdr;
typedef struct __attribute__((packed)) AEFrame {
    unsigned short len;
    unsigned short f2;
    unsigned int f4;
} AEFrame;
void *memset(void *d, int c, unsigned int n);
unsigned char *SetElementData(unsigned char *p, int type, void *data, int len);

int _keywrap_encrypt(unsigned char *out, unsigned char *in, int len, unsigned char *key, int keylen);
extern unsigned char *lpElementData;
extern unsigned char ElementData[];
extern unsigned char btAdapterMAC[];
extern int bDualCfg;
extern AEMac _gAPMac;
int memcmp(const void *a, const void *b, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);
int puts(const char *s);
int GetAdapterMac(AEMac *out);
typedef struct AEKey {
    AEMac a;
    AEMac b;
    char key[4];
} AEKey;
typedef struct AEWep { int type; int len; char key[32]; } AEWep;
typedef struct AEProfile { unsigned char x0[0x100]; char ssid[32]; unsigned char x120[0xC]; int f12C; int f130; unsigned char x134[0x28]; AEWep wep[4]; char x1FC[0x48]; unsigned char x244[0x10]; } AEProfile;
extern AEProfile AutoProfile;
typedef struct AENecParam { char ssid[0x24]; int wep; char key[32]; } AENecParam;
extern AENecParam _gNecApConfigParam;
char *strcpy(char *d, const char *s);
unsigned int strlen(const char *s);
int AsciiToHex(unsigned char *out, char *s, int n);
int SendFrameViaInterface(int s, void *to, void *info, void *buf, int len)
{
    int r = sceNetInetSendto(s, buf, len, 0, to, 16);

    if (r < 0) {
        printf("sceNetInetSendto() failed. ret = 0x%x\n", r);
        return -4;
    }
    return r;
}

int SendBroadcast(int s, unsigned char *buf, int len)
{
    AESockaddr sa;
    char info[0x80];
    int r;

    sa.len = 16;
    sa.family = 2;
    sa.port = AE_NTOHS(0xE601);
    sa.addr = -1;
    sceNetApctlGetInfo(8, info);
    r = SendFrameViaInterface(s, &sa, info, buf, len);
    if (bDebug)
        printf("AUTOCFG:Send Broadcast ID=%04X Size=%d (%d)\n", AE_NTOHS(((AEHdr *)buf)->type), AE_NTOHS(((AEHdr *)buf)->len), r);
    return r;
}

int SendFrame(int s, int unused, unsigned char *buf, int len)
{
    return SendBroadcast(s, buf, len);
}

unsigned char *GetFrameData(unsigned char *p, int *type, int *len)
{
    unsigned char *end;
    unsigned char *q;
    unsigned int sum = 0;
    unsigned int n;

    n = AE_NTOHS(((AEHdr *)p)->len);
    *type = AE_NTOHS(((AEHdr *)p)->type);
    *len = n;
    end = p + n + 6;
    for (q = p; q < end; q++)
        sum += *q;
    if ((unsigned short)sum != AE_NTOHS(*(unsigned short *)end)) {
        printf("AUTOCFG:Error Frame SUM %04X -> %04X\n", (unsigned short)sum, AE_NTOHS(*(unsigned short *)end));
        return 0;
    }
    if (bDebug)
        printf("AUTOCFG:Recv Frame ID=%04X Size=%d\n", *type, *len);
    return p + 6;
}

void *GetElementData(unsigned char **pp, unsigned char *end, int *type, int *len)
{
    unsigned char *p = *pp;
    unsigned int n;

    if (p < end) {
        n = AE_NTOHS(((AEHdr *)p)->len);
        *type = AE_NTOHS(((AEHdr *)p)->type);
        *pp = (unsigned char *)((int)((n + 0xB) >> 3 << 3) + (int)p);
        *len = n;
        return p + 4;
    }
    return 0;
}

void *GetFirstElement(AEFrame *f, int *type, int *len)
{
    unsigned char *p = (unsigned char *)f + 8;

    return GetElementData(&p, p + AE_NTOHS(f->len), type, len);
}

int SetFrameData(unsigned char *f, int type, unsigned char *elem, int len, unsigned char *key)
{
    unsigned char *end;
    unsigned char *q;
    unsigned char *d;
    unsigned int sum = 0;

    ((AEFrame *)elem)->f2 = 0;
    ((AEFrame *)elem)->f4 = 0;
    ((AEFrame *)elem)->len = AE_NTOHS((unsigned short)(len - 8));
    if (key != 0) {
        d = f + 6;
        _keywrap_encrypt(d, elem, len, key, 16);
        len += 8;
    } else {
        d = f + 6;
        memcpy(d, elem, len);
    }
    f[4] = 0;
    f[5] = 0;
    ((AEHdr *)f)->type = AE_NTOHS((unsigned short)type);
    ((AEHdr *)f)->len = AE_NTOHS((unsigned short)len);
    end = d + len;
    for (q = f; q < end; q++)
        sum += *q;
    *(unsigned short *)end = AE_NTOHS((unsigned short)sum);
    end += 2;
    return end - f;
}

unsigned char *SetElementData(unsigned char *p, int type, void *data, int len)
{
    unsigned int pad;

    ((AEHdr *)p)->type = AE_NTOHS((unsigned short)type);
    ((AEHdr *)p)->len = AE_NTOHS((unsigned short)len);
    pad = ((unsigned int)(len + 0xB) >> 3 << 3) - 4;
    p += 4;
    memset(p, 0, pad);
    memcpy(p, data, len);
    return p + pad;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SetSingleElement);

int IsSearchCommand(unsigned char *frame, int *out)
{
    int type;
    int len;
    unsigned char *p;
    int etype;
    int elen;
    unsigned char *end;
    unsigned char *e;
    int minor = 0;
    int major = 0;
    int dual = 0;
    int ret = 0;

    p = GetFrameData(frame, &type, &len);
    if (p != 0 && type == 1) {
        end = p + len;
        p += 8;
        while ((e = GetElementData(&p, end, &etype, &elen)) != 0) {
            switch (etype) {
            case 1:
                major = AE_NTOHS(*(unsigned short *)e);
                break;
            case 5:
                dual = AE_NTOHS(*(unsigned short *)e);
                break;
            case 2:
                minor = AE_NTOHS(*(unsigned short *)e);
                break;
            }
        }
        if (major != 1 || minor != 1) {
            if (bDebug)
                printf("AUTOCFG:Error Version Major=%d Minor=%d\n", major, minor);
            ret = 0;
        } else {
            if (dual > 0)
                *out = 1;
            else
                *out = 0;
            ret = 1;
        }
    }
    return ret;
}

int GetCommandElement(unsigned char *frame, int cmd, unsigned char *out, unsigned char *key)
{
    int type, len;
    unsigned char *p = GetFrameData(frame, &type, &len);

    if (p == NULL || type != cmd)
        return 0;
    if (key != NULL) {
        _keywrap_decrypt(out, p, len, key, 16);
        len -= 8;
    } else
        memcpy(out, p, len);
    return len;
}

int SetSearchRes(unsigned char *frame)
{
    unsigned short v;
    unsigned char *p;

    v = AE_NTOHS(1);
    {
    char ver[7] = { 6, 0, 1, 2, 3, 4, 5 };
    p = lpElementData;
    p = SetElementData(p, 1, &v, 2);
    p = SetElementData(p, 2, &v, 2);
    if (bDualCfg)
        p = SetElementData(p, 5, &v, 2);
    p = SetElementData(p, 3, ver, 7);
    if (bDualCfg)
        p = SetElementData(p, 4, btAdapterMAC, 6);
    }
    return SetFrameData(frame, 2, ElementData, p - lpElementData + 8, 0);
}

int GetAdapterMac(AEMac *out)
{
    AEMac mac;

    if (sceNetGetLocalEtherAddr(mac.b) != 0)
        return 0;
    *out = mac;
    return 1;
}




int GetMacEncKey(AEKey *out)
{
    AEMac ap;
    AEMac sta;
    char sSta[32];
    char sAp[32];

    memcpy(out->key, "WARP", 4);
    ap = _gAPMac;
    if (_gAPMac.b[0] & 1)
        puts("ApBSSID is XR-BSSID");
    ap.b[0] &= ~2;
    GetAdapterMac(&sta);
    *(AEMac *)btAdapterMAC = sta;
    if (memcmp(&ap, &sta, 6) > 0) {
        out->b = sta;
        out->a = ap;
    } else {
        out->b = ap;
        out->a = sta;
    }
    if (bDebug) {
        sprintf(sSta, "%02X:%02X:%02X:%02X:%02X:%02X", sta.b[0], sta.b[1], sta.b[2], sta.b[3], sta.b[4], sta.b[5]);
        sprintf(sAp, "%02X:%02X:%02X:%02X:%02X:%02X", ap.b[0], ap.b[1], ap.b[2], ap.b[3], ap.b[4], ap.b[5]);
        printf("AUTOCFG:Start AP:%s STA:%s\n", sAp, sSta);
    }
    return 1;
}

int GetWLanSetElement(AEFrame *f)
{
    unsigned char *p;
    int type;
    int len;
    unsigned char *end;
    unsigned char *e;
    int found = 0;
    int i;
    int v;
    char *d;

    p = (unsigned char *)f + 8;
    end = p + AE_NTOHS(f->len);
    while ((e = GetElementData(&p, end, &type, &len)) != 0) {
        switch (type) {
        case 0x201:
            memset(AutoProfile.ssid, 0, 32);
            found = 1;
            memcpy(AutoProfile.ssid, e, len);
            break;
        case 0x202:
            AutoProfile.f12C = AE_NTOHS(*(unsigned short *)e);
            break;
        case 0x203:
            v = AE_NTOHS(*(unsigned short *)e);
            for (i = 0; i < 4; i++)
                AutoProfile.wep[i].type = v;
            break;
        case 0x204:
            v = AE_NTOHS(*(unsigned short *)e);
            for (i = 0; i < 4; i++)
                AutoProfile.wep[i].len = v;
            break;
        case 0x205:
            AutoProfile.f130 = AE_NTOHS(*(unsigned short *)e);
            break;
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x209:
            memset(AutoProfile.wep[type - 0x206].key, 0, 32);
            if (AutoProfile.wep[0].type == 1) {
                d = AutoProfile.wep[type - 0x206].key;
                for (i = 0; i < len; i++)
                    d += sprintf(d, "%02X", *e++);
            } else {
                memcpy(AutoProfile.wep[type - 0x206].key, e, len);
            }
            break;
        case 0x20A:
            memset(AutoProfile.x1FC, 0, 0x48);
            memcpy(AutoProfile.x1FC, e, len);
            break;
        }
    }
    return found;
}

int AsciiToHex(unsigned char *out, char *s, int n)
{
    int v = 0;
    int i;
    char c;

    for (i = 0; i < n; i++) {
        c = s[i];
        switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            v = v + c - '0';
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            v = v + c - 'A' + 10;
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            v = v + c - 'a' + 10;
            break;
        default:
            return 0;
        }
        if (i % 2 == 0)
            v <<= 4;
        else {
            out[i / 2] = v;
            v = 0;
        }
    }
    return 1;
}

int StoreNetParam(void)
{
    int ret = 1;
    char *key;
    int i;

    strcpy(_gNecApConfigParam.ssid, AutoProfile.ssid);
    switch (AutoProfile.f12C) {
    case 0:
        _gNecApConfigParam.wep = 0;
        break;
    case 1:
        i = AutoProfile.f130;
        if (i > 0) {
            key = AutoProfile.wep[i - 1].key;
            switch (strlen(key)) {
            case 5:
                _gNecApConfigParam.wep = 1;
                memcpy(_gNecApConfigParam.key, key, 5);
                break;
            case 10:
                _gNecApConfigParam.wep = 1;
                AsciiToHex((unsigned char *)_gNecApConfigParam.key, key, 10);
                break;
            case 13:
                _gNecApConfigParam.wep = 2;
                memcpy(_gNecApConfigParam.key, key, 13);
                break;
            case 26:
                _gNecApConfigParam.wep = 2;
                AsciiToHex((unsigned char *)_gNecApConfigParam.key, key, 26);
                break;
            default:
                ret = -7;
                break;
            }
        }
        break;
    default:
        ret = -7;
        break;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", _AutoConfigThreadEx);

int _AutoConfigThread(int a)
{
    int r = _AutoConfigThreadEx(a);

    _gNecApResult = r;
    if (r == 1)
        _gNecApState = 4;
    else
        _gNecApState = 5;
    _NecApDisconnectAP();
    _gNecApTimeout = -1;
    return r;
}
