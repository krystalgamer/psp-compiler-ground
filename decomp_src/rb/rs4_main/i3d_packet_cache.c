/* cflags: -O2 -fno-strict-aliasing */
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

int I3dPacketEntry__GetTexEnv(int *e, int i)
{
	((int *)e[5])[i]++;
	return ((int *)e[4])[i];
}

int I3dTexEnv__SetErrorTex();
int I3dPacketEntry__SetTofu(int *e)
{
	unsigned int n = e[10];
	unsigned int i;
	for (i = 0; i < n; i++) {
		if (((int *)e[5])[i] != 0)
			I3dTexEnv__SetErrorTex(((int *)e[4])[i]);
	}
	return 0;
}

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

unsigned int *I3dPkSetPixelBlend();
unsigned int *I3dPkResetDrawState(unsigned int *p)
{
	p = I3dPkSetPixelBlend(p, 0x10);
	p[0] = 0x21000001;
	p[1] = 0x22000001;
	p[2] = 0xDBFF0006;
	p[3] = 0x23000001;
	p[4] = 0xDE000007;
	p[5] = 0x24000000;
	p[6] = 0x1D000000;
	p[7] = 0x1F000000;
	p[8] = 0x27000000;
	p[9] = 0x28000000;
	p[10] = 0x1E000000;
	p[11] = 0xD4000000;
	p[12] = 0xD5043DDF;
	return p + 13;
}

unsigned int *I3dPk2dPrim_DrawSpriteF();
extern unsigned char D_00109200, D_00109210, D_00109220;
unsigned int *I3dPkClearZBuffer(unsigned int *p)
{
	*p++ = 0xD3000401;
	p = I3dPk2dPrim_DrawSpriteF(p, &D_00109210, &D_00109220, &D_00109200);
	*p++ = 0xD3000700;
	return p;
}
