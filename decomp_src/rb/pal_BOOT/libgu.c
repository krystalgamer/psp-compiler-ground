#include "common.h"

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", callback_sig);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", callback_fin);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", send_commandi);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", send_commandi_stall);

static void send_commandf(int cmd, float argument)
{
	send_commandi(cmd, *((unsigned int *)&argument) >> 8);
}

static void draw_region(int x, int y, int w, int h)
{
	int ex = x + w - 1;
	int ey = y + h - 1;

	send_commandi(21, (y << 10) | x);
	send_commandi(22, (ey << 10) | ex);
}

int get_exp(int val)
{
	int i;

	i = 9;
	do {
		if ((val >> i) & 1)
			break;
		i--;
	} while (i > 0);
	return i;
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", reset_static_value);

void sceGuSendCommandf(int cmd, float argument)
{
	send_commandf(cmd, argument);
}

void sceGuSendCommandi(int cmd, int argument)
{
	send_commandi(cmd, argument);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuGetMemory);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_0001762C);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuInit);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTerm);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_00017658);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_00017698);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_000176AC);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_00017704);

INCLUDE_RODATA("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", D_0001775C);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuFinishId);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSignal);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuBreak);

void sceGuContinue(void)
{
	sceGeContinue();
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuCallList);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSendList);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuCheckList);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDisable);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuGetStatus);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuGetAllStatus);

void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuSetStatus(int state, int status);
void sceGuSetStatus(int state, int status)
{
	if (status == 0)
		sceGuDisable(state);
	else
		sceGuEnable(state);
}

void sceGuSetAllStatus(unsigned int status);
void sceGuSetAllStatus(unsigned int status)
{
	int i;

	for (i = 0; i < 22; i++) {
		if ((status >> i) & 1)
			sceGuEnable(i);
		else
			sceGuDisable(i);
	}
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSetMatrix);

void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices)
{
	if (vtype)
		send_commandi(18, vtype);
	if (indices) {
		send_commandi(16, (((unsigned int)indices) >> 8) & 0xf0000);
		send_commandi(2, ((unsigned int)indices) & 0xffffff);
	}
	if (vertices) {
		send_commandi(16, (((unsigned int)vertices) >> 8) & 0xf0000);
		send_commandi(1, ((unsigned int)vertices) & 0xffffff);
	}
	send_commandi_stall(4, (prim << 16) | count);
}

void sceGuDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGuDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices)
{
	if (vtype)
		send_commandi(18, vtype);
	if (indices) {
		send_commandi(16, (((unsigned int)indices) >> 8) & 0xf0000);
		send_commandi(2, ((unsigned int)indices) & 0xffffff);
	}
	if (vertices) {
		send_commandi(16, (((unsigned int)vertices) >> 8) & 0xf0000);
		send_commandi(1, ((unsigned int)vertices) & 0xffffff);
	}
	prim = (prim << 16) | count;
	{
		int i;

		for (i = 0; i < n - 1; i++)
			send_commandi(4, prim);
	}
	send_commandi_stall(4, prim);
}

void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices)
{
	if (vtype)
		send_commandi(18, vtype);
	if (indices) {
		send_commandi(16, (((unsigned int)indices) >> 8) & 0xf0000);
		send_commandi(2, ((unsigned int)indices) & 0xffffff);
	}
	if (vertices) {
		send_commandi(16, (((unsigned int)vertices) >> 8) & 0xf0000);
		send_commandi(1, ((unsigned int)vertices) & 0xffffff);
	}
	send_commandi_stall(5, (vcount << 8) | ucount);
}

void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices)
{
	if (vtype)
		send_commandi(18, vtype);
	if (indices) {
		send_commandi(16, (((unsigned int)indices) >> 8) & 0xf0000);
		send_commandi(2, ((unsigned int)indices) & 0xffffff);
	}
	if (vertices) {
		send_commandi(16, (((unsigned int)vertices) >> 8) & 0xf0000);
		send_commandi(1, ((unsigned int)vertices) & 0xffffff);
	}
	send_commandi_stall(6, (vedge << 18) | (uedge << 16) | (vcount << 8) | ucount);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSpriteMode);

void sceGuCopyImage(int psm, int sx, int sy, int width, int height, int srcw, void *src, int dx, int dy, int destw, void *dest);
void sceGuCopyImage(int psm, int sx, int sy, int width, int height, int srcw, void *src, int dx, int dy, int destw, void *dest)
{
	int is32 = (psm ^ 0x03) ? 0 : 1;

	send_commandi(178, ((unsigned int)src) & 0xffffff);
	send_commandi(179, ((((unsigned int)src) & 0xff000000) >> 8) | srcw);
	send_commandi(235, (sy << 10) | sx);
	send_commandi(180, ((unsigned int)dest) & 0xffffff);
	send_commandi(181, ((((unsigned int)dest) & 0xff000000) >> 8) | destw);
	send_commandi(236, (dy << 10) | dx);
	send_commandi(238, ((height - 1) << 10) | (width - 1));
	send_commandi(234, is32);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSwapBuffers);

void sceGuViewport(int cx, int cy, int width, int height);
void sceGuViewport(int cx, int cy, int width, int height)
{
	float sx = width / 2;
	float sy = -height / 2;
	float x = cx;
	float y = cy;

	send_commandf(66, sx);
	send_commandf(67, sy);
	send_commandf(69, x);
	send_commandf(70, y);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDepthRange);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDepthOffset);

void sceGuOffset(unsigned int x, unsigned int y);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuOffset(unsigned int x, unsigned int y)
{
	unsigned int ox = x << 4;
	unsigned int oy = y << 4;

	send_commandi(76, ox);
	send_commandi(77, oy);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuPatchDivide);

void sceGuPatchPrim(int prim);
void sceGuPatchPrim(int prim);
void sceGuPatchPrim(int prim)
{
	if (prim == 4)
		send_commandi(55, 0);
	else if (prim == 2)
		send_commandi(55, 1);
	else if (prim == 0)
		send_commandi(55, 2);
}

void sceGuAmbient(unsigned int color);
void sceGuAmbient(unsigned int color)
{
	send_commandi(92, color & 0xffffff);
	send_commandi(93, color >> 24);
}

void sceGuColor(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

void sceGuColorMaterial(int components);
void sceGuColorMaterial(int components)
{
	send_commandi(83, components);
}

void sceGuMaterial(int mode, unsigned int color)
{
	if (mode & 0x01) {
		send_commandi(85, color & 0xffffff);
		send_commandi(88, color >> 24);
	}
	if (mode & 0x02)
		send_commandi(86, color & 0xffffff);
	if (mode & 0x04)
		send_commandi(87, color & 0xffffff);
}

void sceGuAmbientColor(unsigned int color);
void sceGuAmbientColor(unsigned int color)
{
	send_commandi(85, color & 0xffffff);
	send_commandi(88, color >> 24);
}

void sceGuModelColor(unsigned int emissive, unsigned int ambient, unsigned int diffuse, unsigned int specular);
void sceGuModelColor(unsigned int emissive, unsigned int ambient, unsigned int diffuse, unsigned int specular)
{
	send_commandi(84, emissive & 0xffffff);
	send_commandi(86, diffuse & 0xffffff);
	send_commandi(85, ambient & 0xffffff);
	send_commandi(87, specular & 0xffffff);
}

void sceGuSpecular(float power);
void sceGuSpecular(float power)
{
	send_commandf(91, power);
}

void sceGuFrontFace(int order);
void sceGuFrontFace(int order)
{
	if (order)
		send_commandi(155, 0);
	else
		send_commandi(155, 1);
}

void sceGuPatchFrontFace(int arg0)
{
	send_commandi(56, arg0);
}

void sceGuShadeModel(int mode);
void sceGuShadeModel(int mode)
{
	if (mode != 1)
		send_commandi(80, 0);
	else
		send_commandi(80, 1);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuLight);

void sceGuLightMode(int mode);
void sceGuLightMode(int mode)
{
	send_commandi(94, mode & 1);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTexMode);

void sceGuTexFilter(int min, int mag);
void sceGuTexFilter(int min, int mag)
{
	send_commandi(198, ((mag << 8) | min));
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTexFunc);

void sceGuTexEnvColor(unsigned int color);
void sceGuTexEnvColor(unsigned int color)
{
	send_commandi(202, color & 0xffffff);
}

void sceGuTexWrap(int u, int v);
void sceGuTexWrap(int u, int v)
{
	send_commandi(199, ((v << 8) | u));
}

void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexLevelMode(unsigned int mode, float bias)
{
	int offset = (int)(bias * 16.0f);

	if (offset >= 128)
		offset = 127;
	else if (offset < -128)
		offset = -128;
	send_commandi(200, (((unsigned int)offset) << 16) | mode);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTexProjMapMode);

void sceGuTexSync(void);
void sceGuTexSync(void)
{
	send_commandi(204, 0x000000);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuTexImage);

void sceGuTexScale(float u, float v);
void sceGuTexScale(float u, float v)
{
	send_commandf(72, u);
	send_commandf(73, v);
}

void sceGuTexOffset(float u, float v);
void sceGuTexOffset(float u, float v);
void sceGuTexOffset(float u, float v)
{
	send_commandf(74, u);
	send_commandf(75, v);
}

void sceGuTexFlush(void);
void sceGuTexFlush(void)
{
	send_commandf(203, 0.0f);
}

void sceGuTexSlope(float slope);
void sceGuTexSlope(float slope)
{
	send_commandf(208, slope);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuClutMode);

void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutLoad(int num_blocks, const void *cbp)
{
	send_commandi(176, ((unsigned int)cbp) & 0xffffff);
	send_commandi(177, (((unsigned int)cbp) >> 8) & 0xf0000);
	send_commandi(196, num_blocks);
}

void sceGuFog(float near, float far, unsigned int color);
void sceGuFog(float near, float far, unsigned int color);
void sceGuFog(float near, float far, unsigned int color)
{
	float range = far - near;
	float distance = 0.0f;

	if (range != 0.0f)
		distance = 1.0f / range;
	send_commandi(207, color & 0xffffff);
	send_commandf(205, far);
	send_commandf(206, distance);
}

void sceGuColorFunc(int func, unsigned int color, unsigned int mask)
{
	send_commandi(216, func & 0x03);
	send_commandi(217, color & 0xffffff);
	send_commandi(218, mask & 0xffffff);
}

void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAlphaFunc(int a0, int a1, int a2)
{
	send_commandi(219, (((a2 & 0xFF) << 0x10) | ((a1 & 0xFF) << 8) | a0));
}

void sceGuDepthFunc(int function);
void sceGuDepthFunc(int function)
{
	send_commandi(222, function);
}

void sceGuDepthMask(int mask);
void sceGuDepthMask(int mask)
{
	send_commandi(231, mask);
}

void sceGuPixelMask(unsigned int mask);
void sceGuPixelMask(unsigned int mask)
{
	send_commandi(232, mask & 0xffffff);
	send_commandi(233, mask >> 24);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuScissor);

void sceGuStencilFunc(int func, int ref, int mask);
void sceGuStencilFunc(int func, int ref, int mask)
{
	send_commandi(220, (((mask & 0xFF) << 0x10) | ((ref & 0xFF) << 8) | func));
}

void sceGuLogicalOp(int op);
void sceGuLogicalOp(int op)
{
	send_commandi(230, op & 0x0f);
}

void sceGuStencilOp(int fail, int zfail, int zpass);
void sceGuStencilOp(int fail, int zfail, int zpass)
{
	send_commandi(221, ((zpass << 0x10) | (zfail << 8) | fail));
}

void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix)
{
	send_commandi(223, (op << 8) | (dest << 4) | src);
	send_commandi(224, srcfix & 0xffffff);
	send_commandi(225, destfix & 0xffffff);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuBoneMatrix);

void sceGuMorphWeight(int index, float weight);
void sceGuMorphWeight(int index, float weight)
{
	send_commandf(44 + index, weight);
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void);
void sceGuDebugFlush(void)
{
	flush_font();
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/libgu", sceGuSetCallback);
