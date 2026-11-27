/* cflags: -O2 */
#include "common.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SendFrameViaInterface);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SendBroadcast);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", SendFrame);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", AsciiToHex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", StoreNetParam);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", _AutoConfigThreadEx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/autoex", _AutoConfigThread);
