/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_release);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_data_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_set_error);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_get_error);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_seq_data_copy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_check_str);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", checkAP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_set_APInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", MakeSendSeqID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_StatusExclusion);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", aoss_get_bin);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetSecurityData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetSecurityType);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", crc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", update_crc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", make_crc_table);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", CryptSeqNo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", MakeKey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AddKey);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", Rotate);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *malloc(unsigned int size);
void AOSS_Malloc(unsigned int arg0) {
    malloc(arg0);
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
void AOSS_Memcmp(void *arg0, void *arg1, unsigned int arg2) {
    memcmp(arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memcpy(void *d, const void *s, unsigned int n);
void *AOSS_Memcpy(void *arg0, void *arg1, unsigned int arg2) {
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_Htons);

#ifndef NULL
#define NULL ((void *)0)
#endif
int AOSS_Ntohl(int arg0) {
    return __builtin_allegrex_wsbw(arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_Ntohs);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);
void AOSS_Strlen(signed char *arg0) {
    strlen(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int rand(void);
void AOSS_Rand(void) {
    rand();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_FD_ZERO);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_FD_SET);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", AOSS_version);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetWEPData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", GetWPAData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", _NecApGetTickCount);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", necApConfigStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", necApConfigEnd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", necApConfigGetState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aoss", necApConfigGetResult);

#ifndef NULL
#define NULL ((void *)0)
#endif
int necApConfigGetVersion(void) {
    return 0x100;
}
