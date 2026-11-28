#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int ClientLeavesPacketHandler(int, int, int);
int DeleteNetObjectPacketHandler(int, int, int, unsigned short *);
int NetFreeRemoteObject(int);
int NetClientLeaves();

int DeleteNetObjectPacketHandler(int a, int b, int c, unsigned short *msg)
{
    NetFreeRemoteObject(*msg);
    return 2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", ElectSessionMaster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", NetObjectFullUpdatePacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", FieldUpdatePacketHandler);

extern void *gObjectInterfacePtr;
char *NetIGetDataStream();
int FindFreeDataStreamBlock(unsigned int n)
{
    unsigned int i;
    int j, found;
    unsigned char *ds;

    if (n >= *(unsigned int *)((char *)gObjectInterfacePtr + 0x10C)) return -1;
    for (i = 0; i < *(unsigned int *)((char *)gObjectInterfacePtr + 0x10C) - n; i++) {
        ds = NetIGetDataStream(i);
        if (ds == NULL || ds[0] != 0) continue;
        found = 1;
        for (j = i + 1; j < (int)(i + n); j++) {
            ds = NetIGetDataStream(j);
            if (ds[0] != 0) {
                found = 0;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", RequestOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", GrantOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", ReleaseOwnershipPacketHandler);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", DataStreamUpdatePacketHandler);

unsigned char *NetGetStreamChannel();
int NetIGetSessionMasterClientIndex();
void DmeFree();
int rt_circ_buf_destroy();
int DataStreamEndPacketHandler(char *o, int a1, int c, unsigned char *msg)
{
    int sm = 0x100;
    unsigned char *s;
    void (*cb)(int, int);

    if (o == NULL) return -1;
    s = NetGetStreamChannel(msg[0]);
    if (s == NULL) return 1;
    if (s[0] == 2) {
        cb = (*(void (***)(int, int))((char *)gObjectInterfacePtr + 0x174))[s[3]];
        if (cb != NULL) cb(c, msg[0]);
        NetIGetSessionMasterClientIndex(&sm, o);
        if (*(int *)(o + 0x404) == sm && s[5] != 0 && (*(int **)((char *)gObjectInterfacePtr + 0x178))[s[3]] != 0) {
            s[4] = 1;
        } else {
            s[0] = 1;
            if (s[2] != 0) {
                DmeFree(s + 0x10);
                rt_circ_buf_destroy(s + 0x2C);
                *(int *)(s + 0x10) = 0;
                *(int *)(s + 0x14) = 0;
            }
        }
    }
    return 1;
}

void *NetGetClientInfo();
void SendMyClientStatus();
void AcceptClientIntoGame();
int ArbitrateJoinPacketHandler(char *o, int a1, unsigned int idx, unsigned char *msg)
{
    char *ci;
    int me;

    if (o == NULL) return -1;
    if (idx >= 256) return -1;
    ci = NetGetClientInfo(o, msg[1]);
    if (ci == NULL) return -1;
    if (*(int *)(ci + 0x20) == 0) return -1;
    *(int *)(ci + 0xC) = msg[0];
    me = *(long *)(o + 0x404); /* a long field (alias set differs from int): its load is scheduled before the store */
    if (me == 0x100) return -1;
    SendMyClientStatus(o, msg[1]);
    if (*(int *)(((char **)o)[me] + 0xC) == 5)
        AcceptClientIntoGame(o, msg[1], msg[2], msg[3]);
    return 4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", SMMigrateOrderPacketHandler);

extern void *gObjectInterfacePtr;
void *NetIGetClient();
int GetFreeNetObjectBlock(unsigned int n)
{
    char *self;
    int i, c, ok;
    char *cl;

    if (n >= *(unsigned int *)((char *)gObjectInterfacePtr + 0x100)) return -1;
    self = *(char **)((char *)gObjectInterfacePtr + 0x138);
    if (self == NULL) return -1;
    for (i = 0; i < *(unsigned int *)((char *)gObjectInterfacePtr + 0x100) - n; i++) {
        ok = 1;
        for (c = 0; c < *(int *)(self + 0x460); c++) {
            cl = NetIGetClient(self, c);
            if (cl == NULL) continue;
            if (i >= *(int *)(cl + 8) && i < *(int *)(cl + 8) + *(int *)(cl + 0xC)) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        if ((*(int **)((char *)gObjectInterfacePtr + 0x17C))[i] != 0) continue;
        for (c = i + 1; c < (int)(i + n); c++) {
            if ((*(int **)((char *)gObjectInterfacePtr + 0x17C))[c] != 0) {
                ok = 0;
                break;
            }
        }
        if (ok) return i;
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", AcceptClientIntoGame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", AcceptClientPacketHandler);

int ClientLeavesPacketHandler(int a, int b, int c)
{
    NetClientLeaves(a, c);
    return 1;
}

void *NetIGetClient();
void *NetCreateClient();
void NetClientJoins();
char *strcpy(char *, const char *);
typedef struct { unsigned char idx; char pad[7]; unsigned short a, b, c, d, e; char pad2[4]; char name[1]; } DmeClientUpd;
int ClientUpdatePacketHandler(char *o, int a1, int a2, DmeClientUpd *m)
{
    unsigned int idx;
    int *c;

    if (o == NULL) return 0x24;
    if (*(char **)(o + 0x400) == NULL) return 0x24;
    if ((unsigned)(*(int *)(*(char **)(o + 0x400) + 0xC) - 4) >= 2) return 0x24;
    idx = m->idx;
    if (idx >= 256) return 0x24;
    c = NetIGetClient(o, idx);
    if (c == NULL) c = NetCreateClient(o, idx);
    if (c == NULL) return 0x24;
    c[1] = m->a;
    c[2] = m->b;
    c[3] = m->c;
    c[4] = m->d;
    c[5] = m->e;
    strcpy((char *)&c[6], m->name);
    if (c[0] == 0)
        NetClientJoins(o, idx);
    return 0x24;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", rcsid_10DD00);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectMessage", header_rcsid_10DD6C);
