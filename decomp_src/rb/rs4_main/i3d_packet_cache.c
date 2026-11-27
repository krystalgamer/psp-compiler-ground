#include "common.h"
#include "m2c_macros.h"


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", g_aTestFuncTbl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketCache__MakePresetPacket);

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dPacketCache__InsertLruPrev(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg1, void **, 4);
    M2C_FIELD(arg0, void **, 4) = temp_v0;
    M2C_FIELD(temp_v0, void **, 8) = arg0;
    M2C_FIELD(arg1, void **, 4) = arg0;
    M2C_FIELD(arg0, void **, 8) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dPacketCache__MoveLruPrev(void *arg0, void *arg1) {
    void *temp_a2;
    void *temp_v0;
    void *temp_v1;

    temp_a2 = M2C_FIELD(arg0, void **, 4);
    temp_v1 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(temp_v1, void **, 4) = temp_a2;
    temp_v0 = M2C_FIELD(arg1, void **, 4);
    M2C_FIELD(temp_a2, void **, 8) = temp_v1;
    M2C_FIELD(arg0, void **, 4) = temp_v0;
    M2C_FIELD(temp_v0, void **, 8) = arg0;
    M2C_FIELD(arg1, void **, 4) = arg0;
    M2C_FIELD(arg0, void **, 8) = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dRenderStage__CreatePacketCache);

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dPacketEntry__InsertLruPrev(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg1, void **, 4);
    M2C_FIELD(arg0, void **, 4) = temp_v0;
    M2C_FIELD(temp_v0, void **, 8) = arg0;
    M2C_FIELD(arg1, void **, 4) = arg0;
    M2C_FIELD(arg0, void **, 8) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dPacketEntry__MoveLruPrev(void *arg0, void *arg1) {
    void *temp_a2;
    void *temp_v0;
    void *temp_v1;

    temp_a2 = M2C_FIELD(arg0, void **, 4);
    temp_v1 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(temp_v1, void **, 4) = temp_a2;
    temp_v0 = M2C_FIELD(arg1, void **, 4);
    M2C_FIELD(temp_a2, void **, 8) = temp_v1;
    M2C_FIELD(arg0, void **, 4) = temp_v0;
    M2C_FIELD(temp_v0, void **, 8) = arg0;
    M2C_FIELD(arg1, void **, 4) = arg0;
    M2C_FIELD(arg0, void **, 8) = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__GetTexEnv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__SetTofu);

void I3dPacketEntryParam__Clear(int *p)
{
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0;
	p[4] = 0;
	p[5] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSetPicture);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSetClut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSelectTex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSendFogStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSendLightStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSendAmbientLight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSendViewStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkSetPixelBlend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkResetDrawState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPkClearZBuffer);
