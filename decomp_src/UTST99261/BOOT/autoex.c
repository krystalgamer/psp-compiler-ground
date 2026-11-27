/* cflags: -O2 */
#include "common.h"
extern int _gNecApResult;
extern int _gNecApState;
extern int _gNecApTimeout;
int SendBroadcast(int s, void *buf, int len);
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
unsigned char *SetElementData(unsigned char *p, int a, int b, int c);

int SendFrameViaInterface(int s, void *to, int unused, void *buf, int len)
{
    int r = sceNetInetSendto(s, buf, len, 0, to, 16);

    if (r < 0) {
        printf("sceNetInetSendto() failed. ret = 0x%x\n", r);
        return -4;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SendBroadcast);

int SendFrame(int s, int unused, void *buf, int len)
{
    return SendBroadcast(s, buf, len);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", GetFrameData);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SetFrameData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SetElementData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SetSingleElement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", IsSearchCommand);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", GetCommandElement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SetSearchRes);

int GetAdapterMac(AEMac *out)
{
    AEMac mac;

    if (sceNetGetLocalEtherAddr(mac.b) != 0)
        return 0;
    *out = mac;
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", D_0014168C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", D_00141694);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", GetMacEncKey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", GetWLanSetElement);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", StoreNetParam);

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
