#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetIRegisterObjectStart(void);
int NetIRegisterRemoteObjectCallback(unsigned int, void *, void *, void *);
int rt_memory_allocate_init_zero(void **, unsigned int);

extern char *gObjectInterfacePtr;
extern int GlobalObjectFieldCount; extern void *GlobalObjectFieldList;
int NetMapRtError();
int NetIRegisterObjectStart(void)
{
    if (*(unsigned int *)(gObjectInterfacePtr + 0x110) < *(unsigned int *)(gObjectInterfacePtr + 0xF8)) {
        int sz = *(int *)(gObjectInterfacePtr + 0xFC) * 4;
        GlobalObjectFieldCount = 0;
        return NetMapRtError(rt_memory_allocate_init_zero(&GlobalObjectFieldList, sz));
    }
    return 8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIObjectField);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", RegisterChildStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterStructure);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterObjectFilter);

extern char *gObjectInterfacePtr;
int NetIRegisterRemoteObjectCallback(unsigned int idx, void *a, void *b, void *c)
{
    char *o = gObjectInterfacePtr;
    if (idx >= *(unsigned int *)(o + 0xF8)) return 0x17;
    (*(void ***)(o + 0x158))[idx] = a;
    (*(void ***)(o + 0x15C))[idx] = b;
    (*(void ***)(o + 0x160))[idx] = c;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", NetIRegisterDataStream);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_object/src/DmeObjectRegister", rcsid_10DDD4);
