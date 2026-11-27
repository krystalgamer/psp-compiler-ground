#include "common.h"
#include "m2c_macros.h"
int I3dPkDrawSphereMarkerA(int, int, int, int, float); /* extern */
int I3dPkDrawBoxMarkerA(int, int, int, int, int, int); /* extern */
int I3dPkDrawObbMarkerA(int, int, int, int, int);   /* extern */
M2C_UNK I3dSorter__ClosePacketAndClearStateUca(int); /* extern */
M2C_UNK I3dSorter__OpenPacketAndClearState_ByUint32(int, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK I3dSorter__OpenPacketAndClearStateUca_ByUint32(int, M2C_UNK, M2C_UNK); /* extern */


unsigned int *I3dPkSendViewStatus();
unsigned int *I3dPkSendFogStatus();
unsigned int *I3dPkSetPixelBlend();
unsigned int *SendDefaultStatus(unsigned int *p, void *st)
{
	p = I3dPkSendViewStatus(p, st);
	p = I3dPkSendFogStatus(p, st);
	p = I3dPkSetPixelBlend(p, 2);
	*p++ = 0x22000000;
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__DrawLineA);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawSphereMarkerA(int arg0, int arg1, int arg2, float fparg0) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry());
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawSphereMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, fparg0));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawBoxMarkerA(int arg0, int arg1, int arg2, int arg3, int arg4) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry());
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawBoxMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, arg3, arg4));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawObbMarkerA(int arg0, int arg1, int arg2, int arg3) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry());
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawObbMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, arg3));
    return 0;
}

int I3dRenderStage__SetCurrentPacketEntry(char *st, char *e)
{
	*(void **)(st + 0x828) = e;
	*(void **)(st + 0x818) = *(void **)(e + 0xC);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentLightStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x82C) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentFogStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x830) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentViewStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x834) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetDefaultPacketEntry(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x824);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentPacketEntry(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x828);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentLightStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x82C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentFogStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x830);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentViewStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x834);
}

int I3dSorter__OpenPacketAndClearState_ByUint32();
int I3dRenderStage__OpenPacket(char *st, float z)
{
	union { float f; int i; } u;
	u.f = z;
	return I3dSorter__OpenPacketAndClearState_ByUint32(*(void **)(st + 0x818), u.i ^ ((u.i >> 31) | 0x80000000), 0);
}

int I3dSorter__OpenPacketAndClearState_ByUint32();
int I3dRenderStage__OpenPacket_ByUint32(char *st, unsigned int n)
{
	return I3dSorter__OpenPacketAndClearState_ByUint32(*(void **)(st + 0x818), n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__ClosePacket(void *arg0) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x818));
}

int I3dSorter__OpenPacketAndClearStateUca_ByUint32();
int I3dRenderStage__OpenPacketUca(char *st, float z)
{
	union { float f; int i; } u;
	u.f = z;
	return I3dSorter__OpenPacketAndClearStateUca_ByUint32(*(void **)(st + 0x818), u.i ^ ((u.i >> 31) | 0x80000000), 0);
}

int I3dSorter__OpenPacketAndClearStateUca_ByUint32();
int I3dRenderStage__OpenPacketUca_ByUint32(char *st, unsigned int n)
{
	return I3dSorter__OpenPacketAndClearStateUca_ByUint32(*(void **)(st + 0x818), n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__ClosePacketUca(void *arg0) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x818));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenInitPacket(void *arg0) {
    I3dSorter__OpenPacketAndClearState_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseInitPacket(void *arg0) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x81C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenInitPacketUca(void *arg0) {
    I3dSorter__OpenPacketAndClearStateUca_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseInitPacketUca(void *arg0) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x81C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenTermPacket(void *arg0) {
    I3dSorter__OpenPacketAndClearState_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 2, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseTermPacket(void *arg0) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x81C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenTermPacketUca(void *arg0) {
    I3dSorter__OpenPacketAndClearStateUca_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 2, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseTermPacketUca(void *arg0) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x81C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetMasterRegValue(int arg0, int arg1, int arg2) {
    M2C_FIELD(((arg1 * 8) + arg0), int *, 0x838) = arg2;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetMasterRegMask(int arg0, int arg1, int arg2) {
    M2C_FIELD(((arg1 * 8) + arg0), int *, 0x83C) = arg2;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetMasterRegValue(int arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + arg0), int *, 0x838);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetMasterRegMask(int arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + arg0), int *, 0x83C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__CreatePacketEntry_FromMaterial);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__CreatePacketEntry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__CreateRenderStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__InitTexCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__DrawStrip);

void I3dSortTag__ConstructAsHead(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = (int)t;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacket_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__ClosePacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketUca_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__ClosePacketUca);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndChangeState_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__ClosePacketAndChangeState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndChangeStateUca_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__ClosePacketAndChangeStateUca);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndClearState_ByUint32);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dSorter__ClosePacketAndClearState(void *arg0, int arg1) {
    void *temp_a3;

    temp_a3 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_a3, int *, 0x18) = arg1;
    M2C_FIELD(arg0, int *, 0x28) = (int) (M2C_FIELD(arg0, int *, 0x28) + (arg1 - M2C_FIELD(temp_a3, int *, 0x14)));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0xF4) = (int) (((arg1 + 0x87) & 0x3FFFFF80) | 0x40000000);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndClearStateUca_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__ClosePacketAndClearStateUca);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__MergePacket);
