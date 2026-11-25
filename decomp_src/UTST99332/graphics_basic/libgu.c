#include "common.h"

typedef struct {
	unsigned int *start;
	unsigned int *current;
	int parent_context;
	int unk0C[5];
	int near_plane;
	int far_plane;
	int depth_offset;
	int unk2C[12];
} GuContext;

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawSpline);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuBeginObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuEndObject);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawSprite);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSpriteMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuCopyImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearStencil);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClearDepth);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuClear);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDrawBufferList);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDispBuffer);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDisplay);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSwapBuffers);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuViewport);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuDepthRange);

void sceGuDepthOffset(unsigned int offset)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->depth_offset = offset;
	sceGuDepthRange(context->near_plane, context->far_plane);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuOffset);

void sceGuPatchDivide(int ulevel, int vlevel)
{
	send_commandi(54, ((vlevel << 8) | ulevel));
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuPatchPrim);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuAmbient);

void sceGuColor(unsigned int color)
{
	sceGuMaterial(7, color);
}

void sceGuColorMaterial(int components)
{
	send_commandi(83, components);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuMaterial);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuAmbientColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuModelColor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuSpecular);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuFrontFace);

void sceGuPatchFrontFace(int arg0)
{
	send_commandi(56, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuShadeModel);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLight);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_basic/nonmatchings/libgu", sceGuLightMode);

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
