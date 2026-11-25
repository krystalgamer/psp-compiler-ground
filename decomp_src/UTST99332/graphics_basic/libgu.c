#include "common.h"

typedef struct {
	unsigned int *start;
	unsigned int *current;
	int parent_context;
	int unk0C;
	int scissor_start[2];
	int scissor_end[2];
	int near_plane;
	int far_plane;
	int depth_offset;
	int unk2C[4];
	int sprite_mode[4];
	unsigned int clear_color;
	unsigned int clear_stencil;
	unsigned int clear_depth;
	int unk58;
} GuContext;

typedef struct {
	int pixel_size;
	int frame_width;
	void *frame_buffer;
	void *disp_buffer;
	void *depth_buffer;
	int depth_width;
	int width;
	int height;
} GuDrawBuffer;

extern GuDrawBuffer FBuf;

extern GuContext *pList;
extern GuContext _ctx[3];
extern int __aw_list_mode;
extern unsigned int __gu_status;

static __inline__ void send_commandi(int cmd, int argument)
{
	*(pList->current++) = (cmd << 24) | (argument & 0xffffff);
}

static __inline__ void send_commandf(int cmd, float argument)
{
	*(pList->current++) = (cmd << 24) | (*((unsigned int *)&argument) >> 8);
}

typedef struct ScePspFVector4 { float x, y, z, w; } ScePspFVector4;
typedef struct ScePspFMatrix4 { ScePspFVector4 x, y, z, w; } ScePspFMatrix4;

typedef struct {
	void (*signal_func)(int);
	void (*finish_func)(int);
	unsigned short signals[16];
	int index;
	int event;
} GuCallbackData;

extern GuCallbackData intrParam;
extern int queid[2];
extern int intrCode;
extern int call_mode;
extern int n_bbox;
extern int bParam[4];

int sceGeListUpdateStallAddr(int qid, void *stall);
int sceGeListEnQueue(const void *list, void *stall, int cbid, void *arg);
int sceGeListEnQueueHead(const void *list, void *stall, int cbid, void *arg);
int sceGeListSync(int qid, int syncType);
int sceGeDrawSync(int syncType);
int sceGeBreak(int mode, void *param);
int sceKernelSetEventFlag(int evid, unsigned int bits);
int sceKernelClearEventFlag(int evid, unsigned int bits);
int sceKernelWaitEventFlag(int evid, unsigned int bits, unsigned int wait, unsigned int *outBits, void *timeout);
void sceGuEnable(int state);
void sceGuDisable(int state);

extern void flush_font(void);
int sceGeUnsetCallback(int cbid);
int sceKernelDeleteEventFlag(int evid);
int sceGeContinue(void);
void sceGuDepthRange(int near, int far);
void sceGuMaterial(int mode, unsigned int color);

extern unsigned int *p_bbox[32];

typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;

typedef struct {
	unsigned char enable;
	unsigned char type;
	unsigned char xpos, ypos, zpos;
	unsigned char xdir, ydir, zdir;
	unsigned char ambient, diffuse, specular;
	unsigned char constant, linear, quadratic;
	unsigned char exponent, cutoff;
} GuLightSettings;

extern const GuLightSettings lcmd[4];
extern int disp_sw;
extern void *vram_top;
extern int aw_frame;

int sceDisplaySetMode(int mode, int width, int height);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);

void callback_sig(int id, void *arg)
{
	GuCallbackData *cb = (GuCallbackData *)arg;
	int sig = id & 0xffff;

	cb->signals[cb->index % 16] = sig;
	cb->index++;
	if (cb->signal_func)
		cb->signal_func(sig);
	sceKernelSetEventFlag(cb->event, 1);
}

void callback_fin(int id, void *arg)
{
	GuCallbackData *cb = (GuCallbackData *)arg;

	if (cb->finish_func)
		cb->finish_func(id & 0xffff);
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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", flush_font);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", reset_static_value);

void sceGuSendCommandf(int cmd, float argument)
{
	send_commandf(cmd, argument);
}

void sceGuSendCommandi(int cmd, int argument)
{
	send_commandi(cmd, argument);
}

void *sceGuGetMemory(int size)
{
	unsigned int *orig_ptr = pList->current;
	unsigned int *new_ptr = orig_ptr + (size + 3) / 4 + 2;
	unsigned int lo = (8 << 24) | (((unsigned int)new_ptr) & 0xffffff);
	unsigned int hi = (16 << 24) | ((((unsigned int)new_ptr) >> 8) & 0xf0000);

	*(orig_ptr++) = hi;
	*(orig_ptr++) = lo;
	pList->current = new_ptr;
	if (!__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], new_ptr);
	return orig_ptr;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", initList);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tbpcmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tbwcmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", tsizecmd_tbl);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", lcmd);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_000120E8);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuInit);

void sceGuTerm(void)
{
	sceKernelDeleteEventFlag(intrParam.event);
	sceGeUnsetCallback(intrCode);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012114);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012154);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012168);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_000121C0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", D_00012218);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuStart);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetDither);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFinish);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFinishId);

void sceGuCallMode(int mode)
{
	call_mode = mode;
}

void sceGuSignal(int signal, int behavior)
{
	send_commandi(14, (behavior & 0xffff) | ((signal & 0xff) << 16));
	send_commandi(12, 0);
	if (signal == 3) {
		send_commandi(15, 0);
		send_commandi(12, 0);
	}
	send_commandi(0, 0);
	if (!n_bbox && !__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], pList->current);
}

void sceGuBreak(int mode)
{
	sceGeBreak(mode, bParam);
}

void sceGuContinue(void)
{
	sceGeContinue();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuCallList);

void sceGuSendList(int mode, const void *list, void *context)
{
	struct {
		int size;
		void *context;
		int reserved[2];
	} args;

	intrParam.index = 0;
	args.size = 8;
	args.context = context;
	if (mode == 1)
		queid[1] = sceGeListEnQueueHead(list, 0, intrCode, &args);
	else
		queid[1] = sceGeListEnQueue(list, 0, intrCode, &args);
}

int sceGuCheckList(void)
{
	return (int)pList->current - (int)pList->start;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSignalSync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuEnable);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDisable);

int sceGuGetStatus(int state)
{
	if (state < 22)
		return (__gu_status >> state) & 1;
	return 0;
}

unsigned int sceGuGetAllStatus(void)
{
	return __gu_status;
}

void sceGuSetStatus(int state, int status)
{
	if (status == 0)
		sceGuDisable(state);
	else
		sceGuEnable(state);
}

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

void sceGuSetMatrix(int type, const ScePspFMatrix4 *matrix)
{
	const float *fmatrix = (const float *)matrix;

	switch (type) {
	case 0:
		send_commandi(62, 0);
		send_commandf(63, fmatrix[0]); send_commandf(63, fmatrix[1]); send_commandf(63, fmatrix[2]); send_commandf(63, fmatrix[3]);
		send_commandf(63, fmatrix[4]); send_commandf(63, fmatrix[5]); send_commandf(63, fmatrix[6]); send_commandf(63, fmatrix[7]);
		send_commandf(63, fmatrix[8]); send_commandf(63, fmatrix[9]); send_commandf(63, fmatrix[10]); send_commandf(63, fmatrix[11]);
		send_commandf(63, fmatrix[12]); send_commandf(63, fmatrix[13]); send_commandf(63, fmatrix[14]); send_commandf(63, fmatrix[15]);
		break;
	case 1:
		send_commandi(60, 0);
		send_commandf(61, fmatrix[0]); send_commandf(61, fmatrix[1]); send_commandf(61, fmatrix[2]);
		send_commandf(61, fmatrix[4]); send_commandf(61, fmatrix[5]); send_commandf(61, fmatrix[6]);
		send_commandf(61, fmatrix[8]); send_commandf(61, fmatrix[9]); send_commandf(61, fmatrix[10]);
		send_commandf(61, fmatrix[12]); send_commandf(61, fmatrix[13]); send_commandf(61, fmatrix[14]);
		break;
	case 2:
		send_commandi(58, 0);
		send_commandf(59, fmatrix[0]); send_commandf(59, fmatrix[1]); send_commandf(59, fmatrix[2]);
		send_commandf(59, fmatrix[4]); send_commandf(59, fmatrix[5]); send_commandf(59, fmatrix[6]);
		send_commandf(59, fmatrix[8]); send_commandf(59, fmatrix[9]); send_commandf(59, fmatrix[10]);
		send_commandf(59, fmatrix[12]); send_commandf(59, fmatrix[13]); send_commandf(59, fmatrix[14]);
		break;
	case 3:
		send_commandi(64, 0);
		send_commandf(65, fmatrix[0]); send_commandf(65, fmatrix[1]); send_commandf(65, fmatrix[2]);
		send_commandf(65, fmatrix[4]); send_commandf(65, fmatrix[5]); send_commandf(65, fmatrix[6]);
		send_commandf(65, fmatrix[8]); send_commandf(65, fmatrix[9]); send_commandf(65, fmatrix[10]);
		send_commandf(65, fmatrix[12]); send_commandf(65, fmatrix[13]); send_commandf(65, fmatrix[14]);
		break;
	}
}

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
	send_commandi(4, (prim << 16) | count);
	if (!n_bbox && !__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], pList->current);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawArrayN);

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
	send_commandi(5, (vcount << 8) | ucount);
	if (!n_bbox && !__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], pList->current);
}

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
	send_commandi(6, (vedge << 18) | (uedge << 16) | (vcount << 8) | ucount);
	if (!n_bbox && !__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], pList->current);
}

void sceGuBeginObject(int vtype, int count, const void *indices, const void *vertices)
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
	send_commandi(7, count);
	p_bbox[n_bbox++] = pList->current;
	send_commandi(16, 0);
	send_commandi(9, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawSprite);

void sceGuSpriteMode(int a0, int a1, int a2, int a3)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->sprite_mode[0] = a0;
	context->sprite_mode[1] = a1;
	context->sprite_mode[2] = a2;
	context->sprite_mode[3] = a3;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuCopyImage);

void sceGuClearColor(unsigned int color)
{
	_ctx[__aw_list_mode].clear_color = color;
}

void sceGuClearStencil(unsigned int stencil)
{
	_ctx[__aw_list_mode].clear_stencil = stencil;
}

void sceGuClearDepth(unsigned int depth)
{
	_ctx[__aw_list_mode].clear_depth = depth;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBuffer);

void sceGuDrawBufferList(int psm, void *fbp, int frame_width)
{
	send_commandi(210, psm);
	send_commandi(156, ((unsigned int)fbp) & 0xffffff);
	send_commandi(157, ((((unsigned int)fbp) & 0xff000000) >> 8) | frame_width);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthBuffer);

void sceGuDispBuffer(int width, int height, void *dbp, int frame_width)
{
	FBuf.width = width;
	FBuf.height = height;
	FBuf.disp_buffer = dbp;
	if (!FBuf.frame_width)
		FBuf.frame_width = frame_width;
	if (FBuf.frame_width != frame_width)
		FBuf.frame_width = frame_width;
	sceDisplaySetMode(0, FBuf.width, FBuf.height);
	if (disp_sw == 1)
		sceDisplaySetFrameBuf((char *)vram_top + (unsigned int)FBuf.disp_buffer, frame_width, FBuf.pixel_size, 1);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDisplay);

void *sceGuSwapBuffers(void)
{
	void *temp;

	flush_font();
	temp = FBuf.frame_buffer;
	FBuf.frame_buffer = FBuf.disp_buffer;
	FBuf.disp_buffer = temp;
	if (disp_sw == 1)
		sceDisplaySetFrameBuf((char *)vram_top + (unsigned int)temp, FBuf.frame_width, FBuf.pixel_size, 0);
	aw_frame = aw_frame == 0;
	return FBuf.frame_buffer;
}

void sceGuViewport(int cx, int cy, int width, int height)
{
	send_commandf(66, (float)(width / 2));
	send_commandf(67, (float)((-height) / 2));
	send_commandf(69, (float)cx);
	send_commandf(70, (float)cy);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthRange);

void sceGuDepthOffset(unsigned int offset)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->depth_offset = offset;
	sceGuDepthRange(context->near_plane, context->far_plane);
}

void sceGuOffset(unsigned int x, unsigned int y)
{
	send_commandi(76, x << 4);
	send_commandi(77, y << 4);
}

void sceGuPatchDivide(int ulevel, int vlevel)
{
	send_commandi(54, ((vlevel << 8) | ulevel));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPatchPrim);

void sceGuAmbient(unsigned int color)
{
	send_commandi(92, color & 0xffffff);
	send_commandi(93, color >> 24);
}

void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

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

void sceGuAmbientColor(unsigned int color)
{
	send_commandi(85, color & 0xffffff);
	send_commandi(88, color >> 24);
}

void sceGuModelColor(unsigned int emissive, unsigned int ambient, unsigned int diffuse, unsigned int specular)
{
	send_commandi(84, emissive & 0xffffff);
	send_commandi(86, diffuse & 0xffffff);
	send_commandi(85, ambient & 0xffffff);
	send_commandi(87, specular & 0xffffff);
}

void sceGuSpecular(float power)
{
	send_commandf(91, power);
}

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

void sceGuShadeModel(int mode)
{
	switch (mode) {
	case 1:
		send_commandi(80, 1);
		break;
	default:
		send_commandi(80, 0);
		break;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLight);

void sceGuLightMode(int mode)
{
	send_commandi(94, mode & 1);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightAtt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightSpot);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexMode);

void sceGuTexFilter(int min, int mag)
{
	send_commandi(198, ((mag << 8) | min));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexFunc);

void sceGuTexEnvColor(int color)
{
	send_commandi(202, color);
}

void sceGuTexWrap(int u, int v)
{
	send_commandi(199, ((v << 8) | u));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexLevelMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexMapMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexProjMapMode);

void sceGuTexSync(void)
{
	send_commandi(204, 0x000000);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexScale);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexOffset);

void sceGuTexFlush(void)
{
	send_commandi(203, 0x000000);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuTexSlope);

void sceGuClutMode(int cpsm, int shift, int mask, int a3)
{
	send_commandi(197, ((a3 << 0x10) | (mask << 8) | (shift * 4) | cpsm));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClutLoad);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFog);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuColorFunc);

void sceGuAlphaFunc(int a0, int a1, int a2)
{
	send_commandi(219, (((a2 & 0xFF) << 0x10) | ((a1 & 0xFF) << 8) | a0));
}

void sceGuDepthFunc(int function)
{
	send_commandi(222, function);
}

void sceGuDepthMask(int mask)
{
	send_commandi(231, mask);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPixelMask);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuScissor);

void sceGuStencilFunc(int func, int ref, int mask)
{
	send_commandi(220, (((mask & 0xFF) << 0x10) | ((ref & 0xFF) << 8) | func));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLogicalOp);

void sceGuStencilOp(int fail, int zfail, int zpass)
{
	send_commandi(221, ((zpass << 0x10) | (zfail << 8) | fail));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBlendFunc);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBoneMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuMorphWeight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDebugPrint);

void sceGuDebugFlush(void)
{
	flush_font();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSetCallback);
