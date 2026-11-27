#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", UnpackNode_);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", PackNode_);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__Unpack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__Pack);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3cRoot__Get_nNode(void *arg0) {
    return M2C_FIELD(arg0, unsigned short *, 0x14);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__GetNodeName);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3cRoot__Get_nGroup(void *arg0) {
    return M2C_FIELD(arg0, unsigned short *, 0x16);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__GetGroupName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__GetNodeIndexByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__GetGroupIndexByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__GetNodeEnable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__SetNodeEnable);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3cRoot__GetBothFaceEnable(void *arg0) {
    return M2C_FIELD(arg0, unsigned char *, 0x12) == 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3cRoot__SetBothFaceEnable(void *arg0, int arg1) {
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, unsigned char *, 0x12) == 1;
    M2C_FIELD(arg0, unsigned char *, 0x12) = (unsigned char) ((arg1 & 0xFF) != 0);
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3dTtyPrintf);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelDcacheWritebackAll(void);
int I3dWritebackDcache(void) {
    sceKernelDcacheWritebackAll();
    return 0;
}
