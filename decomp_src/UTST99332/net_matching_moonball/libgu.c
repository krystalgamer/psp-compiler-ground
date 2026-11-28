#include "common.h"
#define gu_init gu_init_D35E4

typedef struct {
	unsigned int *start;
	unsigned int *current;
	int parent_context;
	int scissor_enable;
	int scissor_start[2];
	int scissor_end[2];
	int near_plane;
	int far_plane;
	int depth_offset;
	int fragment_2x;
	int texture_function;
	int texture_proj_map_mode;
	int texture_map_mode;
	int sprite_mode[4];
	unsigned int clear_color;
	unsigned int clear_stencil;
	unsigned int clear_depth;
	int texture_mode;
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

/* a macro: the argument is copied into a float before the command is evaluated */
#define send_commandf(cmd, argument) do { \
	float f_ = (argument); \
	unsigned int v_ = *(unsigned int *)&f_; \
\
	v_ >>= 8; \
	v_ &= 0xffffff; \
	send_commandi(cmd, v_); \
} while (0)

static __inline__ unsigned int float_bits(float f)
{
	union { float f; unsigned int i; } t;

	t.f = f;
	return t.i;
}

static __inline__ void send_commandf_u(int cmd, float argument)
{
	*(pList->current++) = (cmd << 24) | (float_bits(argument) >> 8);
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

static const GuLightSettings lcmd[4];
extern int disp_sw;
extern void *vram_top;
extern int aw_frame;

int sceDisplaySetMode(int mode, int width, int height);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);

static const unsigned int tbpcmd_tbl[8];
static const unsigned int tbwcmd_tbl[8];
static const unsigned int tsizecmd_tbl[8];
void sceGuTexFlush(void);
int get_exp(int val);

extern int gu_init;
extern const GuDrawBuffer D_0001AB64;

extern const unsigned int initList[221];
typedef struct { int m[16]; } GuDitherInit;
extern const GuDitherInit D_0001AB90;
int sceGeSetCallback(void *cb);
void *sceGeEdramGetAddr(void);
int sceKernelCreateEventFlag(const char *name, int attr, int bits, void *opt);
void sceGuSetDither(const int *matrix);
void sceGuPatchDivide(int a0, int a1);
void sceGuColorMaterial(int a0);

static __inline__ void send_commandi_stall(int cmd, int argument)
{
	send_commandi(cmd, argument);
	if (!n_bbox && !__aw_list_mode)
		sceGeListUpdateStallAddr(queid[0], pList->current);
}
void sceGuSpecular(float power);
void sceGuTexScale(float u, float v);
extern const float D_0001ACB0;

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

typedef struct {
	int x;
	int y;
	unsigned int color;
	char c;
} GuDebugChar;

extern int aw_fontcnt[2];
extern GuDebugChar aw_fontbuf[2][1024];

extern const unsigned int fonttex[];

void flush_font(void)
{
	unsigned short *fp, *p16, *p32;
	unsigned int data;
	unsigned int mask;
	int code;
	int off;
	int u, v;
	int col;
	int fx, fy;
	int fontcnt;
	GuDebugChar *fontbuf;
	GuDrawBuffer *fbuf = &FBuf;

	fontbuf = aw_fontbuf[aw_frame];
	fontcnt = aw_fontcnt[aw_frame];
	if (fontcnt == 0) {
		return;
	}

	data = 0;
	mask = 0;
	while (fontcnt) {
		fx = fontbuf->x;
		fy = fontbuf->y;
		if (((unsigned int)(fy + 7) < (unsigned int)fbuf->height) && ((unsigned int)(fx + 7) < (unsigned int)fbuf->width) && (fy >= 0) && (fx >= 0)) {
			const unsigned int *glyph;
			int psm;
			unsigned int fb;
			int fw;
			code = fontbuf->c;
			col = fontbuf->color;
			glyph = &fonttex[code * 2];
			psm = fbuf->pixel_size;
			fb = (unsigned int)fbuf->frame_buffer;
			fw = fbuf->frame_width;
			for (v = 0; v < 8; v++) {
				if (v == 0) {
					data = glyph[0];
					mask = 1;
				} else if (v == 4) {
					data = glyph[1];
					mask = 1;
				}

				off = fx + (fy + v) * fw;
				p16 = (unsigned short *)(off * 2 + (unsigned int)vram_top + fb);
				p32 = (unsigned short *)(off * 4 + (unsigned int)vram_top + fb);
				for (u = 0; u < 8; u++) {
					if (psm == 3) {
						fp = (unsigned short *)((unsigned int)p32 + 0x40000000);
						if (data & mask) {
							fp[0] = col;
							fp[1] = col >> 16;
						}
					} else {
						fp = (unsigned short *)((unsigned int)p16 + 0x40000000);
						if (data & mask) {
							*fp = col;
						}
					}
					mask = mask << 1;
					p32 += 2;
					p16++;
				}
			}
		}
		fontbuf++;
		fontcnt--;
	}
	aw_fontcnt[aw_frame] = 0;
}

static void reset_static_value(void)
{
	GuDrawBuffer init = D_0001AB64;
	int i;

	gu_init = 0;
	__gu_status = 0;
	FBuf = init;
	aw_frame = 0;
	n_bbox = 0;
	disp_sw = 0;
	call_mode = 0;
	for (i = 0; i < 3; i++) {
		GuContext *context = &_ctx[i];

		context->scissor_enable = 0;
		context->scissor_start[0] = 0;
		context->scissor_start[1] = 0;
		context->scissor_end[0] = 0;
		context->scissor_end[1] = 0;
		context->near_plane = 0;
		context->far_plane = 1;
		context->depth_offset = 0;
		context->sprite_mode[0] = 0;
		context->sprite_mode[1] = 0;
		context->sprite_mode[2] = 0;
		context->sprite_mode[3] = 0;
		context->clear_color = 0;
		context->clear_stencil = 0;
		context->clear_depth = 0xffff;
		context->texture_mode = 0;
		context->fragment_2x = 0;
		context->texture_function = 0;
		context->texture_proj_map_mode = 0;
		context->texture_map_mode = 0;
	}
	intrParam.signal_func = 0;
	intrParam.finish_func = 0;
}

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

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", fonttex);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", initList);

static const unsigned int tbpcmd_tbl[8] = { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7 };

static const unsigned int tbwcmd_tbl[8] = { 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF };

static const unsigned int tsizecmd_tbl[8] = { 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF };

static const GuLightSettings lcmd[4] = {
	{ 0x18, 0x5F, 0x63, 0x64, 0x65, 0x6F, 0x70, 0x71, 0x8F, 0x90, 0x91, 0x7B, 0x7C, 0x7D, 0x87, 0x8B },
	{ 0x19, 0x60, 0x66, 0x67, 0x68, 0x72, 0x73, 0x74, 0x92, 0x93, 0x94, 0x7E, 0x7F, 0x80, 0x88, 0x8C },
	{ 0x1A, 0x61, 0x69, 0x6A, 0x6B, 0x75, 0x76, 0x77, 0x95, 0x96, 0x97, 0x81, 0x82, 0x83, 0x89, 0x8D },
	{ 0x1B, 0x62, 0x6C, 0x6D, 0x6E, 0x78, 0x79, 0x7A, 0x98, 0x99, 0x9A, 0x84, 0x85, 0x86, 0x8A, 0x8E },
};

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", color_material);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", D_0001AB64);

void sceGuInit(void);
void sceGuInit(void)
{
	struct {
		void (*signal_func)(int, void *);
		void *signal_arg;
		void (*finish_func)(int, void *);
		void *finish_arg;
	} callback;

	callback.signal_func = callback_sig;
	callback.signal_arg = &intrParam;
	callback.finish_func = callback_fin;
	callback.finish_arg = &intrParam;
	intrCode = sceGeSetCallback(&callback);
	vram_top = sceGeEdramGetAddr();
	queid[0] = sceGeListEnQueue((void *)((unsigned int)initList & 0x1fffffff), 0, intrCode, 0);
	reset_static_value();
	intrParam.event = sceKernelCreateEventFlag("SceGuSignal", 0x200, 3, 0);
	sceGeListSync(queid[0], 0);
}

void sceGuTerm(void)
{
	sceKernelDeleteEventFlag(intrParam.event);
	sceGeUnsetCallback(intrCode);
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", D_0001AB90);

void sceGuStart(int type, void *list, int size)
{
	GuContext *context = &_ctx[type];
	GuDrawBuffer *fb = &FBuf;
	unsigned int *local_list = (unsigned int *)(((unsigned int)list) | 0x40000000);

	context->parent_context = __aw_list_mode;
	context->start = local_list;
	context->current = local_list;
	pList = context;
	__aw_list_mode = type;
	if (!type) {
		intrParam.index = 0;
		queid[0] = sceGeListEnQueue(local_list, local_list, intrCode, 0);
	}
	if (!gu_init) {
		GuDitherInit dither_matrix = D_0001AB90;
		float one;

		sceGuSetDither(dither_matrix.m);
		sceGuPatchDivide(16, 16);
		sceGuColorMaterial(7);
		one = D_0001ACB0;
		sceGuSpecular(one);
		sceGuTexScale(one, one);
		gu_init = 1;
	}
	if (!__aw_list_mode) {
		int width = fb->frame_width;

		if (width) {
			send_commandi(156, *(unsigned int *)&fb->frame_buffer & 0xffffff);
			send_commandi(157, ((*(unsigned int *)&fb->frame_buffer & 0xff000000) >> 8) | width);
		}
	}
}

void sceGuSetDither(const int *matrix)
{
	unsigned int dither[4];

	dither[0] = (matrix[0] & 0x0f) | ((matrix[1] & 0x0f) << 4) | ((matrix[2] & 0x0f) << 8) | ((matrix[3] & 0x0f) << 12);
	dither[1] = (matrix[4] & 0x0f) | ((matrix[5] & 0x0f) << 4) | ((matrix[6] & 0x0f) << 8) | ((matrix[7] & 0x0f) << 12);
	dither[2] = (matrix[8] & 0x0f) | ((matrix[9] & 0x0f) << 4) | ((matrix[10] & 0x0f) << 8) | ((matrix[11] & 0x0f) << 12);
	dither[3] = (matrix[12] & 0x0f) | ((matrix[13] & 0x0f) << 4) | ((matrix[14] & 0x0f) << 8) | ((matrix[15] & 0x0f) << 12);
	send_commandi(226, dither[0]);
	send_commandi(227, dither[1]);
	send_commandi(228, dither[2]);
	send_commandi(229, dither[3]);
}

int sceGuFinish(void)
{
	GuContext *context;
	int size;

	if (__aw_list_mode == 0 || __aw_list_mode == 2) {
		send_commandi(15, 0);
		send_commandi_stall(12, 0);
	} else if (call_mode == 1) {
		send_commandi(14, 0x120000);
		send_commandi(12, 0);
		send_commandi_stall(0, 0);
	} else {
		send_commandi(11, 0);
	}
	context = pList;
	size = (unsigned int)context->current - (unsigned int)context->start;
	__aw_list_mode = context->parent_context;
	pList = &_ctx[__aw_list_mode];
	return size;
}

int sceGuFinishId(unsigned int id)
{
	GuContext *context;
	int size;

	if (__aw_list_mode == 0 || __aw_list_mode == 2) {
		send_commandi(15, id & 0xffff);
		send_commandi_stall(12, 0);
	} else if (call_mode == 1) {
		send_commandi(14, 0x120000);
		send_commandi(12, 0);
		send_commandi_stall(0, 0);
	} else {
		send_commandi(11, 0);
	}
	context = pList;
	size = (unsigned int)context->current - (unsigned int)context->start;
	__aw_list_mode = context->parent_context;
	pList = &_ctx[__aw_list_mode];
	return size;
}

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

void sceGuCallList(const void *list)
{
	unsigned int list_addr = (unsigned int)list;

	if (call_mode == 1) {
		send_commandi(14, (list_addr >> 16) | 0x110000);
		send_commandi(12, list_addr & 0xffff);
		send_commandi_stall(0, 0);
	} else {
		send_commandi(16, (list_addr >> 8) & 0xf0000);
		send_commandi_stall(10, list_addr & 0xffffff);
	}
}

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

int sceGuSync(int mode, int what)
{
	switch (mode) {
	case 0:
		return sceGeDrawSync(what);
	case 1:
	case 2:
	default:
		return 0;
	case 3:
		return sceGeListSync(queid[0], what);
	case 4:
		return sceGeListSync(queid[1], what);
	}
}

void sceGuSignalSync(int signal)
{
	int i;

	for (;;) {
		for (i = 0; i < 16; i++) {
			if (i >= intrParam.index)
				break;
			if (intrParam.signals[i] == (unsigned short)signal)
				return;
		}
		sceKernelWaitEventFlag(intrParam.event, 1, 0, 0, 0);
		sceKernelClearEventFlag(intrParam.event, ~1);
	}
}

void sceGuEnable(int state)
{
	switch (state) {
	case 0:
		send_commandi(34, 1);
		break;
	case 1:
		send_commandi(35, 1);
		break;
	case 2:
		_ctx[__aw_list_mode].scissor_enable = 1;
		send_commandi(212, 0xffffff & ((_ctx[__aw_list_mode].scissor_start[1] << 10) | _ctx[__aw_list_mode].scissor_start[0]));
		send_commandi(213, (_ctx[__aw_list_mode].scissor_end[1] << 10) | _ctx[__aw_list_mode].scissor_end[0]);
		send_commandi(21, 0);
		send_commandi(22, (_ctx[__aw_list_mode].scissor_end[1] << 10) | _ctx[__aw_list_mode].scissor_end[0]);
		break;
	case 3:
		send_commandi(36, 1);
		break;
	case 4:
		send_commandi(33, 1);
		break;
	case 5:
		send_commandi(29, 1);
		break;
	case 6:
		send_commandi(32, 1);
		break;
	case 7:
		send_commandi(31, 1);
		break;
	case 8:
		send_commandi(28, 1);
		break;
	case 9:
		send_commandi(30, 1);
		break;
	case 10:
		send_commandi(23, 1);
		break;
	case 11:
		send_commandi(24, 1);
		break;
	case 12:
		send_commandi(25, 1);
		break;
	case 13:
		send_commandi(26, 1);
		break;
	case 14:
		send_commandi(27, 1);
		break;
	case 15:
		send_commandi(37, 1);
		break;
	case 16:
		send_commandi(38, 1);
		break;
	case 17:
		send_commandi(39, 1);
		break;
	case 18:
		send_commandi(40, 1);
		break;
	case 19:
		send_commandi(81, 1);
		break;
	case 20:
		send_commandi(56, 1);
		break;
	case 21:
		_ctx[__aw_list_mode].fragment_2x = 0x10000;
		send_commandi(201, 0x10000 | _ctx[__aw_list_mode].texture_function);
		break;
	}
	if (state < 22)
		__gu_status |= (1 << state);
}

void sceGuDisable(int state)
{
	GuDrawBuffer *fb = &FBuf;

	switch (state) {
	case 0:
		send_commandi(34, 0);
		break;
	case 1:
		send_commandi(35, 0);
		break;
	case 2:
		{
			int w = fb->width - 1;
			int h = fb->height - 1;
			_ctx[__aw_list_mode].scissor_enable = 0;
			send_commandi(212, 0);
			send_commandi(213, (h << 10) | w);
			send_commandi(21, 0);
			send_commandi(22, (h << 10) | w);
		}
		break;
	case 3:
		send_commandi(36, 0);
		break;
	case 4:
		send_commandi(33, 0);
		break;
	case 5:
		send_commandi(29, 0);
		break;
	case 6:
		send_commandi(32, 0);
		break;
	case 7:
		send_commandi(31, 0);
		break;
	case 8:
		send_commandi(28, 0);
		break;
	case 9:
		send_commandi(30, 0);
		break;
	case 10:
		send_commandi(23, 0);
		break;
	case 11:
		send_commandi(24, 0);
		break;
	case 12:
		send_commandi(25, 0);
		break;
	case 13:
		send_commandi(26, 0);
		break;
	case 14:
		send_commandi(27, 0);
		break;
	case 15:
		send_commandi(37, 0);
		break;
	case 16:
		send_commandi(38, 0);
		break;
	case 17:
		send_commandi(39, 0);
		break;
	case 18:
		send_commandi(40, 0);
		break;
	case 19:
		send_commandi(81, 0);
		break;
	case 20:
		send_commandi(56, 0);
		break;
	case 21:
		_ctx[__aw_list_mode].fragment_2x = 0;
		send_commandi(201, _ctx[__aw_list_mode].texture_function);
		break;
	}
	if (state < 22)
		__gu_status &= ~(1 << state);
}

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

void sceGuEndObject(void)
{
	unsigned int *current = pList->current;

	pList->current = p_bbox[n_bbox - 1];
	send_commandi(16, (((unsigned int)current) >> 8) & 0xf0000);
	send_commandi(9, ((unsigned int)current) & 0xffffff);
	pList->current = current;
	sceGeListUpdateStallAddr(queid[0], current);
	n_bbox--;
}

typedef struct __attribute__((packed)) {
	unsigned short u, v;
	short x, y, z;
} GuSpriteVertex;

void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate)
{
	GuSpriteVertex *vtx = (GuSpriteVertex *)sceGuGetMemory(2 * sizeof(GuSpriteVertex));
	GuSpriteVertex tmp;

	vtx[0].u = u;
	vtx[0].v = v;
	vtx[0].x = x;
	vtx[0].y = y;
	vtx[0].z = z;
	vtx[1].u = _ctx[__aw_list_mode].sprite_mode[0] + u;
	vtx[1].v = _ctx[__aw_list_mode].sprite_mode[1] + v;
	vtx[1].x = _ctx[__aw_list_mode].sprite_mode[2] + x;
	vtx[1].y = _ctx[__aw_list_mode].sprite_mode[3] + y;
	vtx[1].z = z;

	switch (flip) {
	case 0:
		break;
	case 1:
		tmp.u = vtx[0].u;
		vtx[0].u = vtx[1].u;
		vtx[1].u = tmp.u;
		break;
	case 2:
		tmp.v = vtx[0].v;
		vtx[0].v = vtx[1].v;
		vtx[1].v = tmp.v;
		break;
	case 3:
		tmp.u = vtx[0].u;
		tmp.v = vtx[0].v;
		vtx[0].u = vtx[1].u;
		vtx[0].v = vtx[1].v;
		vtx[1].u = tmp.u;
		vtx[1].v = tmp.v;
		break;
	}
	switch (rotate) {
	case 0:
		break;
	case 1:
		tmp.y = vtx[0].y;
		vtx[0].y = vtx[1].y;
		vtx[1].y = tmp.y;
		break;
	case 2:
		tmp.x = vtx[0].x;
		tmp.y = vtx[0].y;
		vtx[0].x = vtx[1].x;
		vtx[0].y = vtx[1].y;
		vtx[1].x = tmp.x;
		vtx[1].y = tmp.y;
		break;
	case 3:
		tmp.x = vtx[0].x;
		vtx[0].x = vtx[1].x;
		vtx[1].x = tmp.x;
		break;
	}
	sceGuDrawArray(6, 0x800102, 2, 0, vtx);
}

void sceGuSpriteMode(int a0, int a1, int a2, int a3)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->sprite_mode[0] = a0;
	context->sprite_mode[1] = a1;
	context->sprite_mode[2] = a2;
	context->sprite_mode[3] = a3;
}

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

typedef struct {
	unsigned int color;
	unsigned short x, y, z;
	unsigned short pad;
} GuClearVertex;

void sceGuClear(int flags)
{
	unsigned int filter;
	GuClearVertex *vertices;
	int count;
	GuDrawBuffer *fbuf = &FBuf;

	if (fbuf->pixel_size == 3)
		filter = (_ctx[__aw_list_mode].clear_stencil << 24) | (_ctx[__aw_list_mode].clear_color & 0xffffff);
	else if (fbuf->pixel_size == 1)
		filter = (_ctx[__aw_list_mode].clear_stencil << 31) | (_ctx[__aw_list_mode].clear_color & 0xffffff);
	else if (fbuf->pixel_size == 2)
		filter = (_ctx[__aw_list_mode].clear_stencil << 28) | (_ctx[__aw_list_mode].clear_color & 0xffffff);
	else if (fbuf->pixel_size == 0)
		filter = _ctx[__aw_list_mode].clear_color & 0xffffff;
	else
		filter = 0;

	if (flags & 0x10) {
		GuClearVertex *curr;
		int i;

		count = 16;
		vertices = (GuClearVertex *)sceGuGetMemory(count * sizeof(GuClearVertex));
		for (i = 0, curr = vertices; i < count; i++, curr++) {
			int j = i / 2;
			int k = i - j * 2;
			curr->color = filter;
			curr->x = (j + k) * 64;
			curr->y = k * fbuf->height;
			curr->z = _ctx[__aw_list_mode].clear_depth;
		}
	} else {
		vertices = (GuClearVertex *)sceGuGetMemory(2 * sizeof(GuClearVertex));
		count = 2;
		vertices[0].color = filter;
		vertices[0].x = _ctx[__aw_list_mode].scissor_start[0];
		vertices[0].y = _ctx[__aw_list_mode].scissor_start[1];
		vertices[0].z = _ctx[__aw_list_mode].clear_depth;
		vertices[1].color = filter;
		vertices[1].x = _ctx[__aw_list_mode].scissor_end[0] + 1;
		vertices[1].y = _ctx[__aw_list_mode].scissor_end[1] + 1;
		vertices[1].z = _ctx[__aw_list_mode].clear_depth;
	}
	send_commandi(211, ((flags & 7) << 8) | 1);
	sceGuDrawArray(6, 0x80011C, count, 0, vertices);
	send_commandi(211, 0);
}

void sceGuDrawBuffer(int psm, void *fbp, int frame_width)
{
	GuDrawBuffer *fb = &FBuf;

	fb->pixel_size = psm;
	fb->frame_buffer = fbp;
	fb->frame_width = frame_width;
	if (!fb->depth_buffer && fb->height) fb->depth_buffer = (char *)fbp + fb->height * frame_width * 4;
	if (!fb->depth_width) fb->depth_width = frame_width;
	send_commandi(210, fb->pixel_size);
	send_commandi(156, *(unsigned int *)&fb->frame_buffer & 0xffffff);
	send_commandi(157, ((*(unsigned int *)&fb->frame_buffer & 0xff000000) >> 8) | frame_width);
	send_commandi(158, *(unsigned int *)&fb->depth_buffer & 0xffffff);
	send_commandi(159, ((*(unsigned int *)&fb->depth_buffer & 0xff000000) >> 8) | fb->depth_width);
}

void sceGuDrawBufferList(int psm, void *fbp, int frame_width)
{
	send_commandi(210, psm);
	send_commandi(156, ((unsigned int)fbp) & 0xffffff);
	send_commandi(157, ((((unsigned int)fbp) & 0xff000000) >> 8) | frame_width);
}

void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width)
{
	FBuf.depth_buffer = zbp;
	if (!FBuf.depth_width)
		FBuf.depth_width = frame_width;
	if (FBuf.depth_width != frame_width)
		FBuf.depth_width = frame_width;
	send_commandi(158, (*(unsigned int *)&FBuf.depth_buffer) & 0xffffff);
	send_commandi(159, (((*(unsigned int *)&FBuf.depth_buffer) & 0xff000000) >> 8) | FBuf.depth_width);
}

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

int sceGuDisplay(int state)
{
	int old;
	GuDrawBuffer *fb = &FBuf;

	if (!state)
		sceDisplaySetFrameBuf(0, 0, 0, 1);
	else
		sceDisplaySetFrameBuf((char *)vram_top + (unsigned int)fb->disp_buffer, fb->frame_width, fb->pixel_size, 1);
	old = disp_sw;
	disp_sw = state;
	return old;
}

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

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/libgu", sceGuDepthRange);

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

void sceGuLight(int light, int type, int components, const ScePspFVector3 *position)
{
	int c;

	send_commandf(lcmd[light].xpos, position->x);
	send_commandf(lcmd[light].ypos, position->y);
	send_commandf(lcmd[light].zpos, position->z);
	if (components == 8) {
		c = 2;
	} else if (components == 6) {
		c = 1;
	} else {
		c = 0;
	}
	send_commandi(lcmd[light].type, ((type & 3) << 8) | c);
}

void sceGuLightMode(int mode)
{
	send_commandi(94, mode & 1);
}

void sceGuLightAtt(int light, float atten0, float atten1, float atten2)
{
	send_commandf(lcmd[light].constant, atten0);
	send_commandf(lcmd[light].linear, atten1);
	send_commandf(lcmd[light].quadratic, atten2);
}

void sceGuLightSpot(int light, float exponent, float cutoff, const ScePspFVector3 *direction)
{
	send_commandf(lcmd[light].exponent, exponent);
	send_commandf(lcmd[light].cutoff, cutoff);
	send_commandf(lcmd[light].xdir, direction->x);
	send_commandf(lcmd[light].ydir, direction->y);
	send_commandf(lcmd[light].zdir, direction->z);
}


void sceGuLightColor(int light, int component, unsigned int color)
{
	color &= 0xffffff;
	switch (component) {
	case 1:
		send_commandi(lcmd[light].ambient, color);
		break;
	case 2:
		send_commandi(lcmd[light].diffuse, color);
		break;
	case 3: {
		int cmd = lcmd[light].diffuse;

		send_commandi(lcmd[light].ambient, color);
		send_commandi(cmd, color);
		break;
	}
	case 4:
		send_commandi(lcmd[light].specular, color);
		break;
	case 6: {
		int cmd = lcmd[light].specular;

		send_commandi(lcmd[light].diffuse, color);
		send_commandi(cmd, color);
		break;
	}
	}
}

void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle)
{
	_ctx[__aw_list_mode].texture_mode = tpsm;
	send_commandi(194, (maxmips << 16) | (a2 << 8) | swizzle);
	send_commandi(195, tpsm);
	sceGuTexFlush();
}

void sceGuTexFilter(int min, int mag)
{
	send_commandi(198, ((mag << 8) | min));
}

void sceGuTexFunc(int tfx, int tcc)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->texture_function = (tcc << 8) | tfx;
	send_commandi(201, context->fragment_2x | ((tcc << 8) | tfx));
}

void sceGuTexEnvColor(int color)
{
	send_commandi(202, color);
}

void sceGuTexWrap(int u, int v)
{
	send_commandi(199, ((v << 8) | u));
}

const float D_0001ACB0 = 1.0f;

void sceGuTexLevelMode(unsigned int mode, float bias)
{
	int offset = (int)(bias * 16.0f);

	if (offset >= 128)
		offset = 127;
	else if (offset < -128)
		offset = -128;
	send_commandi(200, (((unsigned int)offset) << 16) | mode);
}

void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->texture_map_mode = mode & 0x03;
	send_commandi(192, context->texture_proj_map_mode | (mode & 0x03));
	send_commandi(193, ((a2 & 0x03) << 8) | (a1 & 0x03));
}

void sceGuTexProjMapMode(int mode)
{
	GuContext *context = &_ctx[__aw_list_mode];

	context->texture_proj_map_mode = ((mode & 0x03) << 8);
	send_commandi(192, ((mode & 0x03) << 8) | context->texture_map_mode);
}

void sceGuTexSync(void)
{
	send_commandi(204, 0x000000);
}

void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp)
{
	int w = get_exp(width);
	int h = get_exp(height);
	unsigned int hi = (((unsigned int)tbp) >> 8) & 0x0f0000;

	send_commandi((unsigned char)tbpcmd_tbl[mipmap], ((unsigned int)tbp) & 0xffffff);
	send_commandi((unsigned char)tbwcmd_tbl[mipmap], hi | tbw);
	send_commandi((unsigned char)tsizecmd_tbl[mipmap], (h << 8) | w);
	sceGuTexFlush();
}

void sceGuTexScale(float u, float v)
{
	send_commandf(72, u);
	send_commandf(73, v);
}

void sceGuTexOffset(float u, float v)
{
	send_commandf(74, u);
	send_commandf(75, v);
}

void sceGuTexFlush(void)
{
	send_commandi(203, 0x000000);
}

void sceGuTexSlope(float slope)
{
	send_commandf(208, slope);
}

void sceGuClutMode(int cpsm, int shift, int mask, int a3)
{
	send_commandi(197, ((a3 << 0x10) | (mask << 8) | (shift * 4) | cpsm));
}

void sceGuClutLoad(int num_blocks, const void *cbp)
{
	send_commandi(176, ((unsigned int)cbp) & 0xffffff);
	send_commandi(177, (((unsigned int)cbp) >> 8) & 0xf0000);
	send_commandi(196, num_blocks);
}

void sceGuFog(float near, float far, unsigned int color)
{
	float range = far - near;
	float distance = 0.0f;

	if (range != 0.0f)
		distance = 1.0f / range;
	send_commandi(207, color & 0xffffff);
	send_commandi(205, (*(unsigned int *)&far) >> 8);
	send_commandi(206, (*(unsigned int *)&distance) >> 8);
}

void sceGuColorFunc(int func, unsigned int color, unsigned int mask)
{
	send_commandi(216, func & 0x03);
	send_commandi(217, color);
	send_commandi(218, mask);
}

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

void sceGuPixelMask(unsigned int mask)
{
	send_commandi(232, mask);
	*(pList->current++) = (233 << 24) | (mask >> 24);
}

void sceGuScissor(int x, int y, int w, int h)
{
	GuContext *context = &_ctx[__aw_list_mode];

	int ex = x + w - 1;
	int ey = y + h - 1;

	context->scissor_start[0] = x;
	context->scissor_start[1] = y;
	context->scissor_end[0] = ex;
	context->scissor_end[1] = ey;
	if (context->scissor_enable) {
		send_commandi(212, (y << 10) | x);
		send_commandi(213, (ey << 10) | ex);
		send_commandi(21, 0);
		send_commandi(22, (ey << 10) | ex);
	}
}

void sceGuStencilFunc(int func, int ref, int mask)
{
	send_commandi(220, (((mask & 0xFF) << 0x10) | ((ref & 0xFF) << 8) | func));
}

void sceGuLogicalOp(int op)
{
	send_commandi(230, op & 0x0f);
}

void sceGuStencilOp(int fail, int zfail, int zpass)
{
	send_commandi(221, ((zpass << 0x10) | (zfail << 8) | fail));
}

void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix)
{
	send_commandi(223, (op << 8) | (dest << 4) | src);
	send_commandi(224, srcfix & 0xffffff);
	send_commandi(225, destfix & 0xffffff);
}

void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix)
{
	send_commandi(255, 0);
	send_commandi(42, index * 12);
	send_commandi(43, float_bits(matrix->x.x) >> 8);
	send_commandi(43, float_bits(matrix->x.y) >> 8);
	send_commandi(43, float_bits(matrix->x.z) >> 8);
	send_commandi(43, float_bits(matrix->y.x) >> 8);
	send_commandi(43, float_bits(matrix->y.y) >> 8);
	send_commandi(43, float_bits(matrix->y.z) >> 8);
	send_commandi(43, float_bits(matrix->z.x) >> 8);
	send_commandi(43, float_bits(matrix->z.y) >> 8);
	send_commandi(43, float_bits(matrix->z.z) >> 8);
	send_commandi(43, float_bits(matrix->w.x) >> 8);
	send_commandi(43, float_bits(matrix->w.y) >> 8);
	send_commandi(43, float_bits(matrix->w.z) >> 8);
}

void sceGuMorphWeight(int index, float weight)
{
	int cmd = 44 + index;

	send_commandi(255, 0);
	send_commandf(cmd, weight);
}

void sceGuDebugPrint(int x, int y, unsigned int color, const char *str)
{
	int r, g, b, a;
	int fx, fy;
	int code;
	int fontcnt;
	GuDebugChar *fontbuf;

	fontbuf = aw_fontbuf[aw_frame];
	fontcnt = aw_fontcnt[aw_frame];
	fontbuf = &fontbuf[fontcnt];
	if (fontcnt >= 1024)
		return;

	fx = x;
	fy = y;

	r = (color >> 0) & 0xff;
	g = (color >> 8) & 0xff;
	b = (color >> 16) & 0xff;
	a = (color >> 24) & 0xff;

	if (FBuf.pixel_size == 0) {
		r = r >> 3;
		g = g >> 2;
		b = b >> 3;
		color = (b << 11) | (g << 5) | r;
	} else if (FBuf.pixel_size == 1) {
		r = r >> 3;
		g = g >> 3;
		b = b >> 3;
		a = a >> 7;
		color = (a << 15) | (b << 10) | (g << 5) | r;
	} else if (FBuf.pixel_size == 2) {
		r = r >> 4;
		g = g >> 4;
		b = b >> 4;
		a = a >> 4;
		color = (a << 12) | (b << 8) | (g << 4) | r;
	}

	while (*str) {
		if (*str == '\n') {
			fx = x;
			fy += 8;
			str++;
			continue;
		}
		code = *str - '!' + 1;

		fontbuf->x = fx;
		fontbuf->y = fy;
		fontbuf->color = color;
		fontbuf->c = code++;

		fx += 8;

		str++;
		fontcnt++;
		fontbuf++;
	}
	aw_fontcnt[aw_frame] = fontcnt;
}

void sceGuDebugFlush(void)
{
	flush_font();
}

void *sceGuSetCallback(int signal, void (*callback)(int))
{
	void (*old)(int) = 0;

	switch (signal) {
	case 1:
		old = intrParam.signal_func;
		intrParam.signal_func = callback;
		break;
	case 4:
		old = intrParam.finish_func;
		intrParam.finish_func = callback;
		break;
	}
	return old;
}
