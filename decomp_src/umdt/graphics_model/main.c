/* cflags: -O0 */
#include "common.h"

typedef struct {
	float x, y, z;
} Vec3;

typedef struct {
	int fpl;
	void *addr;
} MemPool;

void *memset(void *s, int c, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);
int sceKernelCreateFpl(const char *name, int part, int attr, unsigned int size, unsigned int blocks, void *opt);
int sceKernelTryAllocateFpl(int fpl, void **data);
int sceKernelDeleteFpl(int fpl);

extern MemPool _mempool[200];
extern int g_menu_select;
extern int g_menu_model;
extern int g_menu_vertex;
extern int g_menu_texture;
extern int g_menu_packet;
extern int g_menu_count;
extern int g_menu_cache;
extern Vec3 g_translate;
extern Vec3 g_rotate;
extern unsigned char g_running;
extern unsigned char g_reload;

typedef struct ScePspFVector3 ScePspFVector3;
typedef struct ScePspFVector4 ScePspFVector4;
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFVector3 { float x, y, z; };
struct ScePspFVector4 { float x, y, z, w; };
struct ScePspFMatrix4 { ScePspFVector4 x, y, z, w; };
typedef struct SceGmoModel SceGmoModel;
typedef struct SceGmoMotion SceGmoMotion;

extern SceGmoModel *g_model;
extern int g_frame;
extern int g_vbl_count;
extern int g_vbl_step;
extern int g_vbl_time;
extern int g_cpu_load;
extern int g_gpu_load;
extern char g_cache_buf[1024 * 1024];
extern char *g_cache_top;
extern char *g_cache_packets[50];
extern char *g_cache_packet;
extern float g_cache_loop[2];
extern float g_cache_fps;
extern float g_cache_frame;
extern ScePspFVector3 g_scale;

void sceGmoModelDelete(SceGmoModel *model);
int sceGmoModelGetCurrentMotion(SceGmoModel *model);
SceGmoMotion *sceGmoModelGetMotion(SceGmoModel *model, int index);
const float *sceGmoMotionGetFrameLoop(SceGmoMotion *motion);
float sceGmoMotionGetFrameRate(SceGmoMotion *motion);
float sceGmoMotionGetFrame(SceGmoMotion *motion);
void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
unsigned int sceKernelGetSystemTimeLow(void);
int sceGuSync(int mode, int what);
int sceDisplayWaitVblankStart(void);
void *sceGuSwapBuffers(void);
unsigned int sceDisplayGetVcount(void);
void sceGumMatrixMode(int mode);
typedef struct { unsigned int low; unsigned int hi; } SceKernelSysClock;
extern unsigned char _productMode;
extern int _timerid;
extern int g_packet;
extern char g_launch_buf[4096];
extern char g_packet_buf[2][0x100000];
extern ScePspFMatrix4 g_matrix_buf[16];
typedef struct { unsigned int uiMake; unsigned int uiBreak; unsigned int uiPress; unsigned int uiRelease; } SceCtrlLatch;
typedef struct { unsigned int TimeStamp; unsigned int Buttons; unsigned char Lx; unsigned char Ly; unsigned char Rsrv[6]; } SceCtrlData;
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlReadLatch(SceCtrlLatch *latch);
int sceKernelGetVTimerTime(int uid, SceKernelSysClock *clock);
void LcdDrawSetBackColor(unsigned int color);
void LcdDrawClr(void);
void LcdDrawReset(void);
int sceCtrlSetSamplingCycle(unsigned int cycle);
int sceCtrlSetSamplingMode(unsigned int mode);
int sceKernelCreateVTimer(const char *name, void *opt);
int sceKernelStartVTimer(int uid);
int sceKernelSetVTimerTime(int uid, SceKernelSysClock *clock);
int sceKernelDeleteVTimer(int uid);
void sceGuInit(void);
void sceGuTerm(void);
void sceGuDrawBuffer(int format, void *fbp, int fbw);
void sceGuDispBuffer(int w, int h, void *dbp, int dbw);
void sceGuDepthBuffer(void *zbp, int zbw);
void sceGuOffset(unsigned int x, unsigned int y);
int sceGuDisplay(int state);
int sceGumSetMatrixStack(ScePspFMatrix4 *m, int p, int v, int w, int t);
void myHeapTerm(void);
static void _GlobalInit(void);
static void begin_scene();
static void end_scene();
static void swap_buffers();
static void move_objects();
static void draw_objects();
static void clear_cache();
static void update_cache();
static void draw_cache();
static unsigned char load_objects();
static void unload_objects();
void sceGimPictureSetMemoryManager(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGmoModelSetMemoryManager(void *(*alloc)(unsigned int), void (*free)(void *));
void sceGmoModelSetMemoryManager2(void *(*alloc)(unsigned int), void (*free)(void *));
int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
void myHeapInit(void *addr, int size);
void *myHeapAlloc(unsigned int size);
void myHeapFree(void *addr);
SceGmoModel *sceGmoModelCreate(int type);
int sceGmoModelLoadFile(SceGmoModel *model, const void *buf, int size, int flags);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int index, float frame);
void sceGmoModelSetEnableBits(SceGmoModel *model, int mask, int bits);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int bits);
const ScePspFVector3 *sceGmoModelGetBoundingBox(SceGmoModel *model);
static unsigned char load_file(const char *filename, int **buf, int *size, int *fpl);
void free(void *addr);
void *malloc(unsigned int size);
unsigned int strlen(const char *s);
int sceIoWrite(int fd, const void *buf, unsigned int size);
int sceIoOpen(const char *path, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *buf, unsigned int size);
int sceIoClose(int fd);
int UtilityFileAssign(const char *path, int mode);
int UtilityFileUnassign(const char *path);
extern const char **g_model_names;
extern int g_model_size;
extern int g_model_count;
/* end_scene's static VertexModes, TextureModes, PacketModes (.data) */
extern const char *D_00017AD8[2];
extern const char *D_00017AE0[2];
extern const char *D_00017AE8[3];
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDisable(int state);
void draw_rect(int x, int y, int w, int h, int color);
void sceGuViewport(int cx, int cy, int w, int h);
void sceGuDepthRange(int near, int far);
void sceGuEnable(int state);
void sceGuScissor(int x, int y, int w, int h);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuClear(int flags);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGuFog(float near, float far, unsigned int color);
void sceGuAmbient(unsigned int color);
void sceGuLight(int light, int type, int comp, const ScePspFVector3 *pos);
void sceGuLightColor(int light, int comp, unsigned int color);
void sceGuColorMaterial(int comp);
void sceGuFrontFace(int order);
void sceGuShadeModel(int mode);
void sceGuAlphaFunc(int func, int ref, int mask);
void sceGuBlendFunc(int op, int src, int dst, unsigned int srcfix, unsigned int dstfix);
void sceGuDepthFunc(int func);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int func, int comp);
void sceGuTexWrap(int u, int v);
void sceGuPatchDivide(int s, int t);
void sceGumMultMatrix(const ScePspFMatrix4 *m);
void sceGuCallList(const void *list);
static ScePspFMatrix4 *inverse_orthonormal(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1);
static ScePspFVector3 *rotate_vector3(ScePspFVector3 *v0, const ScePspFMatrix4 *m1, const ScePspFVector3 *v2);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
void sceGumUpdateMatrix(void);
void sceGmoMotionSetFrame(SceGmoMotion *motion, float frame);
void sceGumLoadIdentity(void);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumRotateY(float a);
void sceGumRotateX(float a);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumStoreMatrix(ScePspFMatrix4 *m);

void *malloc(unsigned int size)
{
	int i;
	int ret;
	void *p = 0;

	for (i = 0; i < 200; i++) {
		if (_mempool[i].addr == 0) {
			_mempool[i].fpl = sceKernelCreateFpl("ModelTestFpl", 2, 256, size + 16, 1, 0);
			if (_mempool[i].fpl < 0) {
				_mempool[i].fpl = 0;
				break;
			}
			ret = sceKernelTryAllocateFpl(_mempool[i].fpl, &p);
			if (ret < 0) {
				p = 0;
				break;
			}
			p = (void *)(((unsigned int)p + 15) & ~15);
			_mempool[i].addr = p;
			break;
		}
	}
	return p;
}

void free(void *addr)
{
	int i;

	for (i = 0; i < 200; i++) {
		if (_mempool[i].addr == addr) {
			sceKernelDeleteFpl(_mempool[i].fpl);
			_mempool[i].fpl = 0;
			_mempool[i].addr = 0;
			break;
		}
	}
}

static void MemPoolCheck(void)
{
	int i;

	for (i = 0; i < 200; i++)
		;
}

int *__errno(void)
{
}

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016250);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016260);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016270);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016280);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016290);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162A0);

static void _GlobalInit(void)
{
	Vec3 v;
	static const Vec3 t0 = { -8.609375f, -0.957031012f, 10.5f };
	static const Vec3 r0 = { 0.0f, -0.942f, 0.0f };

	g_menu_select = 0;
	g_menu_model = 0;
	g_menu_vertex = 1;
	g_menu_texture = 1;
	g_menu_packet = 2;
	g_menu_count = 10;
	g_menu_cache = 40;
	v = t0;
	g_translate = v;
	v = r0;
	g_rotate = v;
	g_running = 1;
	g_reload = 1;
}

int GraphicsModelEntry(int a, int b)
{
	memset(_mempool, 0, sizeof(_mempool));
	return 0;
}







int GraphicsModelMain(int mode)
{
	int ret = 0;
	SceKernelSysClock clock = { 0, 0 };

	if (mode)
		_productMode = 1;
	else
		_productMode = 0;
	LcdDrawSetBackColor(0);
	LcdDrawClr();
	_GlobalInit();
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(1);
	_timerid = sceKernelCreateVTimer("model timer", 0);
	sceKernelStartVTimer(_timerid);
	sceGuInit();
	sceGuStart(0, g_packet_buf[0], 0x100000);
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuFinish();
	sceGuSync(0, 0);
	sceGumSetMatrixStack(g_matrix_buf, 4, 4, 8, 0);
	sceGimPictureSetMemoryManager(malloc, free);
	sceGimPictureSetMemoryManager2(malloc, free);
	sceGmoModelSetMemoryManager(malloc, free);
	sceGmoModelSetMemoryManager2(malloc, free);
	sceGuDisplay(1);
	while (g_running) {
		if (g_reload) {
			if (!load_objects()) {
				ret = -1;
				break;
			}
			sceKernelSetVTimerTime(_timerid, &clock);
			clear_cache();
			g_packet = -1;
			g_vbl_count = -1;
		}
		if (g_menu_packet == 0) {
			sceGuStart(0, g_packet_buf[0], 0x100000);
			begin_scene();
			move_objects();
			draw_objects();
			end_scene();
			sceGuFinish();
		} else if (g_menu_packet == 1) {
			sceGuStart(0, g_launch_buf, 4096);
			begin_scene();
			if (g_packet >= 0)
				sceGuCallList(g_packet_buf[g_packet]);
			end_scene();
			sceGuFinish();
			g_packet = (g_packet != 0) ? 0 : 1;
			sceGuStart(1, g_packet_buf[g_packet], 0x100000);
			move_objects();
			draw_objects();
			sceGuFinish();
		} else {
			sceGuStart(0, g_packet_buf[0], 0x100000);
			begin_scene();
			move_objects();
			update_cache();
			draw_cache();
			end_scene();
			sceGuFinish();
		}
		swap_buffers();
	}
	unload_objects();
	myHeapTerm();
	sceGuTerm();
	LcdDrawReset();
	LcdDrawSetBackColor(0);
	LcdDrawClr();
	sceKernelDeleteVTimer(_timerid);
	return ret;
}

static void begin_scene()
{
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(0xe000, 0x1000);
	sceGuEnable(2);
	sceGuScissor(0, 0, 480, 272);
	sceGuClearColor(0xff800000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuClear(7);
	sceGumMatrixMode(1);
	sceGumLoadIdentity();
	sceGumLookAt(&(ScePspFVector3){ 0, 0, 50 }, &(ScePspFVector3){ 0, 0, 0 }, &(ScePspFVector3){ 0, 1, 0 });
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(30.0f * 3.14f / 180.0f, 480.0f / 272.0f, 10.0f, 1000000.0f);
	sceGumMatrixMode(2);
	sceGuEnable(7);
	sceGuFog(40, 100, 0xff800000);
	sceGuEnable(10);
	sceGuAmbient(0xff404040);
	sceGuEnable(11);
	sceGuLight(0, 0, 6, &(ScePspFVector3){ -5, 10, 5 });
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuLight(2, 0, 2, &(ScePspFVector3){ 1, 0, 0 });
	sceGuLight(3, 0, 2, &(ScePspFVector3){ 0, 1, 0 });
	sceGuColorMaterial(3);
	sceGuEnable(0);
	sceGuEnable(1);
	sceGuEnable(4);
	sceGuEnable(6);
	sceGuEnable(9);
	sceGuEnable(5);
	sceGuEnable(8);
	sceGuEnable(16);
	sceGuEnable(20);
	sceGuFrontFace(1);
	sceGuShadeModel(1);
	sceGuAlphaFunc(7, 0, 255);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuDepthFunc(7);
	sceGuTexFilter(7, 1);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(0, 0);
	sceGuPatchDivide(4, 4);
}

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_0001631C);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016320);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016328);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_0001632C);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016330);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016338);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016340);

static void end_scene()
{
	char buf[64];

	if (g_frame * g_vbl_step % 30 < 15)
		sceGuDebugPrint(0, g_menu_select * 10 + 10, 0xffffffff, ">");
	sprintf(buf, "MODEL   %s %dKB", g_model_names[g_menu_model], (g_model_size + 1023) / 1024);
	sceGuDebugPrint(10, 10, 0xffffffff, buf);
	sprintf(buf, "VERTEX  %s", D_00017AD8[g_menu_vertex]);
	sceGuDebugPrint(10, 20, 0xffffffff, buf);
	sprintf(buf, "TEXTURE %s", D_00017AE0[g_menu_texture]);
	sceGuDebugPrint(10, 30, 0xffffffff, buf);
	sprintf(buf, "PACKET  %s", D_00017AE8[g_menu_packet]);
	sceGuDebugPrint(10, 40, 0xffffffff, buf);
	sprintf(buf, "COUNT   %d", g_menu_count);
	sceGuDebugPrint(10, 50, 0xffffffff, buf);
	if (g_menu_select == 5) {
		sprintf(buf, "CACHE   %d / %d KB", g_menu_cache, (g_cache_top - g_cache_buf + 1023) / 1024);
		sceGuDebugPrint(10, 60, 0xffffffff, buf);
	}
	sprintf(buf, "CPU %d%%", g_cpu_load);
	sceGuDebugPrint(10, 240, 0xffffffff, buf);
	sprintf(buf, "GPU %d%%", g_gpu_load);
	sceGuDebugPrint(10, 250, 0xffffffff, buf);
	if (g_reload)
		sceGuDebugPrint(400, 10, 0xffffffff, "LOADING");
	sceGuDisable(9);
	sceGuDisable(1);
	draw_rect(82, 241, g_cpu_load, 7, 0x8f00);
	draw_rect(82, 251, g_gpu_load, 7, 0x800f);
}

static void swap_buffers()
{
	int cpu_time = sceKernelGetSystemTimeLow();
	int gpu_time;
	int vbl_time;
	int vbl_count;

	sceGuSync(0, 0);
	gpu_time = sceKernelGetSystemTimeLow();
	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
	g_frame++;
	vbl_time = sceKernelGetSystemTimeLow();
	vbl_count = sceDisplayGetVcount();
	if (g_vbl_count >= 0) {
		g_vbl_step = vbl_count - g_vbl_count;
		if (g_frame % 6 == 0) {
			g_cpu_load = (cpu_time - g_vbl_time) * 100 / 16667;
			g_gpu_load = (gpu_time - g_vbl_time) * 100 / 16667;
		}
	}
	g_vbl_time = vbl_time;
	g_vbl_count = vbl_count;
}

static void move_objects()
{
	float move = g_vbl_step * 0.5f;
	float turn = g_vbl_step * (2.0f * 3.14f / 180.0f);
	SceKernelSysClock clock = { 0, 0 };
	SceCtrlLatch latch;
	SceCtrlData buf;
	char msg1[112];
	char msg2[112];

	sceCtrlReadBufferPositive(&buf, 1);
	if (sceCtrlReadLatch(&latch)) {
		if ((latch.uiBreak & 0x2000) && _productMode == 1) {
			sceKernelGetVTimerTime(_timerid, &clock);
			sprintf(msg1, "%08X %08X\n", clock.hi, clock.low);
			sceIoWrite(0, msg1, strlen(msg1));
			if (clock.low > 1500000) {
				g_running = 0;
				return;
			}
		}
		if (latch.uiBreak & 0x4000) {
			sprintf(msg1, "g_translate %f,%f,%f\n", g_translate.x, g_translate.y, g_translate.z);
			sceIoWrite(0, msg1, strlen(msg1));
			sprintf(msg2, "g_rotate %f,%f,%f\n", g_rotate.x, g_rotate.y, g_rotate.z);
			sceIoWrite(0, msg2, strlen(msg2));
			if (_productMode == 0) {
				g_running = 0;
				return;
			}
		}
		if (latch.uiPress & 0x80)
			g_rotate.y -= turn;
		if (latch.uiPress & 0x20)
			g_rotate.y += turn;
		if (latch.uiPress & 0x100)
			g_translate.z -= move;
		if (latch.uiPress & 0x200)
			g_translate.z += move;
		float dx = (buf.Lx - 128) / 128.0f;
		float dy = (buf.Ly - 128) / 128.0f;
		if (dx > -0.75f && dx < 0.75f)
			dx = 0.0f;
		if (dy > -0.75f && dy < 0.75f)
			dy = 0.0f;
		g_translate.x += move * dx;
		g_translate.y -= move * dy;

		if (latch.uiBreak & 0x10) {
			if (g_menu_select > 0)
				g_menu_select -= 1;
		}
		if (latch.uiBreak & 0x40) {
			if (g_menu_select < 5)
				g_menu_select += 1;
		}

		switch (g_menu_select) {
		case 0: {
			if (latch.uiBreak & 0x8) {
				if (g_menu_model < g_model_count - 1) {
					g_menu_model += 1;
					g_reload = 1;
				}
			}
			if (latch.uiBreak & 0x1) {
				if (g_menu_model > 0) {
					g_menu_model -= 1;
					g_reload = 1;
				}
			}
			break;
		}
		case 1: {
			if (latch.uiBreak & 0x9) {
				g_menu_vertex = !g_menu_vertex;
				g_reload = 1;
			}
			break;
		}
		case 2: {
			if (latch.uiBreak & 0x9) {
				g_menu_texture = !g_menu_texture;
				int bits = g_menu_texture ? -1 : 0;
				SceGmoModel *model = g_model;
				sceGmoModelSetEnableMask(model, 4, ~bits);
				sceGmoModelSetEnableBits(model, 4, bits);
				if (g_menu_packet == 2)
					clear_cache();
			}
			break;
		}
		case 3: {
			if (latch.uiBreak & 0x8) {
				if (g_menu_packet < 2) {
					g_menu_packet += 1;
					g_packet = -1;
					g_frame %= 2;
					clear_cache();
				}
			}
			if (latch.uiBreak & 0x1) {
				if (g_menu_packet > 0) {
					g_menu_packet -= 1;
					g_packet = -1;
					g_frame %= 2;
					clear_cache();
				}
			}
			break;
		}
		case 4: {
			if (latch.uiBreak & 0x8) {
				if (g_menu_count < 10)
					g_menu_count += 1;
			}
			if (latch.uiBreak & 0x1) {
				if (g_menu_count > 0)
					g_menu_count -= 1;
			}
			break;
		}
		case 5: {
			if (latch.uiBreak & 0x8) {
				if (g_menu_cache < 50) {
					g_menu_cache += 1;
					clear_cache();
				}
			}
			if (latch.uiBreak & 0x1) {
				if (g_menu_cache > 1) {
					g_menu_cache -= 1;
					clear_cache();
				}
			}
			break;
		}
		}
	}
}

static void draw_objects()
{
	int i;
	float step = g_vbl_step * (1.0f / 60.0f);
	ScePspFMatrix4 m;

	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	sceGumTranslate((ScePspFVector3 *)&g_translate);
	sceGumRotateY(g_rotate.y);
	sceGumRotateX(g_rotate.x);
	for (i = 0; i < g_menu_count; i++) {
		ScePspFVector3 move = { ((i % 2 == 0) ? i : -i) * 6, 0, 0 };
		SceGmoModel *model;

		sceGumTranslate(&move);
		sceGumPushMatrix();
		sceGumScale(&g_scale);
		sceGumStoreMatrix(&m);
		model = g_model;
		sceGmoModelSetWorldMatrix(model, &m);
		sceGmoModelAnimate(model, step);
		sceGmoModelUpdate(model);
		sceGmoModelDraw(model);
		sceGumPopMatrix();
		step = 0.0f;
	}
}

static void clear_cache()
{
	SceGmoModel *model = g_model;
	int current = sceGmoModelGetCurrentMotion(model);
	SceGmoMotion *motion = sceGmoModelGetMotion(model, current);
	const float *loop = sceGmoMotionGetFrameLoop(motion);

	g_cache_loop[0] = (loop == 0) ? 0.0f : loop[0];
	g_cache_loop[1] = (loop == 0) ? 0.0f : loop[1];
	g_cache_fps = sceGmoMotionGetFrameRate(motion);
	g_cache_frame = sceGmoMotionGetFrame(motion);
	memset(g_cache_packets, 0, sizeof(g_cache_packets));
	g_cache_top = g_cache_buf;
	g_cache_packet = 0;
}

static void update_cache()
{
	float step;
	float f;
	float f0;
	float f1;
	int index;

	if (g_menu_cache == 0)
		return;
	step = g_vbl_step * (1.0f / 60.0f);
	f = g_cache_frame + g_cache_fps * step;
	f0 = g_cache_loop[0];
	f1 = g_cache_loop[1];
	if (f >= f1)
		f = f0;
	if (f < f0)
		f = f1;
	g_cache_frame = f;
	f = (f0 == f1) ? 0.0f : (f - f0) / (f1 - f0);
	index = (int)((g_menu_cache - 1) * f + 0.5f);
	g_cache_packet = g_cache_packets[index];
	if (g_cache_packet == 0) {
		int size = (char *)g_cache_packets - g_cache_top;
		SceGmoModel *model;
		int current;
		SceGmoMotion *motion;

		sceGuStart(1, g_cache_top, size);
		sceGumUpdateMatrix();
		sceGuFinish();
		sceGuStart(1, g_cache_top, size);
		model = g_model;
		current = sceGmoModelGetCurrentMotion(model);
		motion = sceGmoModelGetMotion(model, current);
		sceGmoMotionSetFrame(motion, g_cache_frame);
		sceGmoModelSetWorldMatrix(model, 0);
		sceGmoModelAnimate(model, 0.0f);
		sceGmoModelUpdate(model);
		sceGmoModelDraw(model);
		size = sceGuFinish();
		size = (size + 63) / 64 * 64;
		g_cache_packets[index] = g_cache_top;
		g_cache_packet = g_cache_top;
		g_cache_top += size;
	}
}

static void draw_cache()
{
	int i;
	float step = g_vbl_step * (1.0f / 60.0f);
	ScePspFMatrix4 m;

	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	sceGumTranslate((ScePspFVector3 *)&g_translate);
	sceGumRotateY(g_rotate.y);
	sceGumRotateX(g_rotate.x);
	for (i = 0; i < g_menu_count; i++) {
		ScePspFVector3 move = { ((i % 2 == 0) ? i : -i) * 6, 0, 0 };
		ScePspFMatrix4 m2;
		ScePspFVector3 v2;

		sceGumTranslate(&move);
		sceGumPushMatrix();
		sceGumScale(&g_scale);
		sceGumStoreMatrix(&m);
		sceGumPopMatrix();
		sceGumMatrixMode(1);
		sceGumPushMatrix();
		sceGumMultMatrix(&m);
		sceGumMatrixMode(2);
		inverse_orthonormal(&m2, &m);
		rotate_vector3(&v2, &m2, &(ScePspFVector3){ -5, 10, 5 });
		sceGuLight(0, 0, 6, &v2);
		if (g_cache_packet != 0) {
			sceGumUpdateMatrix();
			sceGuCallList(g_cache_packet);
		} else {
			SceGmoModel *model = g_model;

			sceGmoModelSetWorldMatrix(model, 0);
			sceGmoModelAnimate(model, step);
			sceGmoModelUpdate(model);
			sceGmoModelDraw(model);
		}
		sceGumMatrixMode(1);
		sceGumPopMatrix();
		sceGumMatrixMode(2);
		step = 0.0f;
	}
}

static unsigned char load_objects()
{
	int fpl = 0;

	unload_objects();
	if (g_menu_vertex == 0) {
		sceGimPictureSetMemoryManager(malloc, free);
		sceGimPictureSetMemoryManager2(malloc, free);
		sceGmoModelSetMemoryManager(malloc, free);
		sceGmoModelSetMemoryManager2(malloc, free);
	} else {
		int usage = 0x154000;
		int size = sceGeEdramGetSize();
		char *base = (char *)sceGeEdramGetAddr();
		myHeapInit(base + usage, size - usage);
		sceGimPictureSetMemoryManager(malloc, free);
		sceGimPictureSetMemoryManager2(malloc, free);
		sceGmoModelSetMemoryManager(malloc, free);
		sceGmoModelSetMemoryManager2(myHeapAlloc, myHeapFree);
	}
	g_model_size = 0;
	int *data, size;
	const char *filename = g_model_names[g_menu_model];
	if (!load_file(filename, &data, &size, &fpl))
		return 0;
	g_model_size = size;
	SceGmoModel *model = g_model = sceGmoModelCreate(0);
	sceGmoModelLoadFile(model, data, size, 0);
	sceGmoModelSetCurrentMotion(model, 0, 0.0f);
	sceGmoModelSetEnableBits(model, 2, 0);
	if (!g_menu_texture) {
		sceGmoModelSetEnableMask(model, 4, -1);
		sceGmoModelSetEnableBits(model, 4, 0);
	}
	g_scale = (ScePspFVector3){ 1, 1, 1 };
	const ScePspFVector3 *box = sceGmoModelGetBoundingBox(model);
	if (box != 0) {
		float s = box[1].x - box[0].x;
		float s2 = box[1].y - box[0].y;
		if (s2 > s)
			s = s2;
		s2 = box[1].z - box[0].z;
		if (s2 > s)
			s = s2;
		if (s > 0.0f) {
			s = 10.0f / s;
			g_scale = (ScePspFVector3){ s, s, s };
		}
	}
	if (fpl)
		sceKernelDeleteFpl(fpl);
	g_reload = 0;
	return (model != 0);
}

static void unload_objects()
{
	sceGmoModelDelete(g_model);
	g_model = 0;
}

static unsigned char load_file(const char *filename, int **buf, int *size, int *fpl)
{
	char fullpath[256];
	int fd;
	unsigned char ret = 0;
	int err;
	char msg1[112];
	char msg2[112];

	sprintf(fullpath, "%s%s", "disc0:/PSP_GAME/USRDIR/GMO/", filename);
	sprintf(msg1, "%s\n", fullpath);
	sceIoWrite(0, msg1, strlen(msg1));
	if (UtilityFileAssign(fullpath, 1) < 0) {
		sprintf(msg2, "fatal error : strFileAssign()\n");
		sceIoWrite(0, msg2, strlen(msg2));
		goto end;
	}
	fd = sceIoOpen(fullpath, 1, 644);
	if (fd < 0) {
		sprintf(msg2, "fatal error : strFileOpen()\n");
		sceIoWrite(0, msg2, strlen(msg2));
		goto end;
	}
	*size = sceIoLseek(fd, 0, 2);
	if (*size <= 0) {
		sceIoClose(fd);
		goto end;
	}
	sceIoLseek(fd, 0, 0);
	*fpl = sceKernelCreateFpl("modelTest", 2, 256, *size, 1, 0);
	if (*fpl < 0) {
		*fpl = 0;
		goto end;
	}
	err = sceKernelTryAllocateFpl(*fpl, (void **)buf);
	if (err < 0)
		goto end;
	sceIoRead(fd, *buf, *size);
	sceIoClose(fd);
	ret = 1;
end:
	UtilityFileUnassign(fullpath);
	return ret;
}

void *sceGuGetMemory(int size);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void draw_rect(int x, int y, int w, int h, int color)
{
	int format = 0x800118;
	short *vertex = sceGuGetMemory(16);

	vertex[0] = color;
	vertex[1] = x;
	vertex[2] = y;
	vertex[3] = 0;
	vertex[4] = color;
	vertex[5] = x + w;
	vertex[6] = y + h;
	vertex[7] = 0;
	sceGuDrawArray(6, format, 2, 0, vertex);
}

static ScePspFMatrix4 *inverse_orthonormal(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1)
{
	float x = -m1->w.x;
	float y = -m1->w.y;
	float z = -m1->w.z;

	m0->x = (ScePspFVector4){ m1->x.x, m1->y.x, m1->z.x, 0 };
	m0->y = (ScePspFVector4){ m1->x.y, m1->y.y, m1->z.y, 0 };
	m0->z = (ScePspFVector4){ m1->x.z, m1->y.z, m1->z.z, 0 };
	m0->w = (ScePspFVector4){ m1->x.x * x + m1->x.y * y + m1->x.z * z,
	                          m1->y.x * x + m1->y.y * y + m1->y.z * z,
	                          m1->z.x * x + m1->z.y * y + m1->z.z * z, 1 };
	return m0;
}

static ScePspFVector3 *rotate_vector3(ScePspFVector3 *v0, const ScePspFMatrix4 *m1, const ScePspFVector3 *v2)
{
	float x = v2->x;
	float y = v2->y;
	float z = v2->z;

	v0->x = m1->x.x * x + m1->y.x * y + m1->z.x * z;
	v0->y = m1->x.y * x + m1->y.y * y + m1->z.y * z;
	v0->z = m1->x.z * x + m1->y.z * y + m1->z.z * z;
	return v0;
}

void GraphicsModelTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041027_2");
}
