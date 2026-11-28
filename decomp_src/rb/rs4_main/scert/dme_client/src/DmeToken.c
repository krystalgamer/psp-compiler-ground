#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetTokenCountGet(char *, int);
int NetTokenQuery(char *, unsigned int, int *);
int NetTokenRelease(char *, unsigned int);
int NetTokenRequest(char *, unsigned int);
int NetTokenSystemQuery(void *, int *);
int NetTokenTableSizeGet(char *, int);
void rt_token_check_ownership(unsigned int, int *, void *);
void rt_token_get_table_size(int *, int *);
void rt_token_get_token_count(int *, int *);
int rt_token_is_free(unsigned int, void *);
int rt_token_is_valid(unsigned int);
void rt_token_set_pending_state(unsigned int, void *);

extern void *gMsgClientInterfacePtr;
extern void *gP2PInterfacePtr;

int SendTokenMessage(char *ci, int tok, int arg)
{
    int r;
    int host;
    unsigned short idx;
    int a;
    int hidx;

    if (*(int *)(ci + 0x468) != 2) {
        r = (*(int (**)(int))((char *)gMsgClientInterfacePtr + 0x70))(*(int *)(ci + 0x470));
    } else {
        r = NetIsPeerToPeerHost(ci, &host);
        if (r != 0) return 0x25;
        if (host != 0) {
            idx = 0xFFFF;
            a = arg;
            if (*(int *)(ci + 0x4A0) != 0) {
                if (HostProcessTokenMessage(ci, tok, &idx, 0, 0, 0, 0, 0, &a, *(int *)(ci + 0x404)) != 0) return 0xD;
                TokenEvent(ci, idx, tok, 0, 0, 0, 0, 0, a);
            }
        } else {
            if (NetIGetPeerToPeerHostClientIndex(ci, &hidx) != 0) return 0x25;
            r = (*(int (**)(int, int, int, int, unsigned short))((char *)gP2PInterfacePtr + 0x7C))(*(int *)(ci + 0x474), tok, 0, arg, hidx);
        }
    }
    if (r != 0) return 0xD;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", SendTokenListMessage);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", rcsid_10E544);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", headerfile_rcsid_10E5A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", HostProcessTokenMessage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", TokenEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", TokenHostEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", TokenNotifyEvent);

int NetTokenQuery(char *c, unsigned int tok, int *owner)
{
    if (c == NULL) return 0x17;
    if (owner == NULL) return 0x17;
    if (*(int *)(c + 0x4A0) == 0) return 0x31;
    if (!(*(int *)(c + 0x450) & 1)) return 0x31;
    if (!rt_token_is_valid(tok)) return 0x17;
    rt_token_check_ownership(tok, owner, *(void **)(c + 0x40C));
    return 0;
}

int NetTokenSystemQuery(void *arg0, int *arg1) {
    int var_v1;

    var_v1 = 0x17;
    if (((arg0 == NULL) | (arg1 == NULL)) == 0) {
        var_v1 = 0x31;
        if (M2C_FIELD(arg0, int *, 0x4A0) != 0) {
            var_v1 = 0;
            *arg1 = M2C_FIELD(arg0, int *, 0x450) & 1;
        }
    }
    return var_v1;
}

int SendTokenMessage();
int NetTokenRequest(char *c, unsigned int tok)
{
    if (c == NULL) return 0x17;
    if (*(int *)(c + 0x4A0) == 0) return 0x31;
    if (!(*(int *)(c + 0x450) & 1)) return 0x31;
    if (!rt_token_is_valid(tok)) return 0x17;
    if (rt_token_is_free(tok, *(void **)(c + 0x40C)) != 1) return 0x31;
    rt_token_set_pending_state(tok, *(void **)(c + 0x40C));
    return SendTokenMessage(c, tok, 2);
}

int rt_token_is_mine();
int rt_token_is_pending();
int SendTokenMessage();
int NetTokenRelease(char *c, unsigned int tok)
{
    if (c == NULL) return 0x17;
    if (*(int *)(c + 0x4A0) == 0) return 0x31;
    if (!(*(int *)(c + 0x450) & 1)) return 0x31;
    if (!rt_token_is_valid(tok)) return 0x31;
    if (rt_token_is_mine(tok, *(int *)(c + 0x404), *(void **)(c + 0x40C)) != 1 &&
        rt_token_is_pending(tok, *(void **)(c + 0x40C)) != 1) return 0x31;
    return SendTokenMessage(c, tok, 3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", NetTokenListRequest);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", NetTokenListRelease);

int NetTokenCountGet(char *c, int a)
{
    if (*(int *)(c + 0x4A0) == 0) return 0x21;
    rt_token_get_token_count(a, *(int *)(c + 0x40C));
    return 0;
}

int NetTokenTableSizeGet(char *c, int a)
{
    if (*(int *)(c + 0x4A0) == 0) return 0x21;
    rt_token_get_table_size(a, *(int *)(c + 0x40C));
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", NetTokenTableGet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeToken", NetTokenTablePrint);
