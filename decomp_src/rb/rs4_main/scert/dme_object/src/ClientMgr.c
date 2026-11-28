#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void * DMEmalloc(int);
void DmeFree(void **);
void NetFreeAllClients(void);
void NetFreeClientPointers(void);
void NetFreeClients(void *);
void * NetGetConnInfo(unsigned int);
void * NetIGetClient(void *, unsigned int);
void NetInitializeClients(void);

extern void **NetClientPointerList;
extern void *gObjectInterfacePtr;

void *memset(void *s, int c, unsigned int n);
void NetInitializeClients(void) {
    NetClientPointerList = DMEmalloc(0x400);
    if (gObjectInterfacePtr != NULL) {
        M2C_FIELD(gObjectInterfacePtr, int *, 0x128) = 0;
    }
    memset(NetClientPointerList, 0, 0x400U);
}

void *NetIGetClient(void *o, unsigned int idx)
{
    if (gObjectInterfacePtr != NULL && o != NULL && o == *(void **)((char *)gObjectInterfacePtr + 0x138) && idx < 256 && NetClientPointerList != NULL)
        return NetClientPointerList[idx];
    return NULL;
}

void *NetGetClientInfo();
int NetIGetClientStatus(int *st, void *o, unsigned int idx)
{
    char *ci;

    if (st == NULL) return 0x17;
    *st = 0;
    if (idx >= 256) return 8;
    ci = NetGetClientInfo(o, idx);
    if (ci != NULL)
        *st = *(int *)(ci + 0xC);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetCreateClient);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", NetFreeClient);

void NetFreeClient();
void NetFreeClients(void *c)
{
    int i;
    if (c != NULL && NetClientPointerList != NULL)
        for (i = 0; i < 256; i++) NetFreeClient(c, i);
    if (gObjectInterfacePtr != NULL) *(int *)((char *)gObjectInterfacePtr + 0x128) = 0;
}

void NetFreeAllClients(void)
{
    unsigned int i;
    if (NetClientPointerList != NULL)
        for (i = 0; i < 4; i++) NetFreeClients(NetGetConnInfo(i));
    if (gObjectInterfacePtr != NULL) *(int *)((char *)gObjectInterfacePtr + 0x128) = 0;
}

void NetFreeClientPointers(void) {
    DmeFree(&NetClientPointerList);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", rcsid_10DB6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/ClientMgr", headerfile_rcsid_10DBCC);
