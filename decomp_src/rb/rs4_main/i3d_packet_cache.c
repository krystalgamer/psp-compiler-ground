#include "common.h"

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", g_aTestFuncTbl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketCache__MakePresetPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketCache__InsertLruPrev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketCache__MoveLruPrev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dRenderStage__CreatePacketCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__InsertLruPrev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__MoveLruPrev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__GetTexEnv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntry__SetTofu);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_cache", I3dPacketEntryParam__Clear);

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
