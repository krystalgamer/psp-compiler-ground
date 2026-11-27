#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
struct _anon1 { /* size 0x80 */
    int buffer[32];
};
typedef struct _anon1 SceGumContext;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef unsigned int u_int32;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
struct _anon2;
struct _anon2 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon2 POS;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct SceGeContext;
struct SceGeContext { /* size 0x800 */
    unsigned int buffer[512];
};
typedef struct SceGeContext SceGeContext;
typedef SceGeContext SceGuContext;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern volatile int vcnt;
extern int num;
extern int step;
extern int cdb;
extern POS pos;
extern int frame;
extern int prev_vcnt;
extern int cur_vcnt;
extern float fps;
extern void *edram_addr;
extern int list_size;
extern u_int32 packet[2][1024];
extern char disp_list[1048576];
extern ScePspFMatrix4 matrix_stack[16];
extern SceGuContext context;
extern float triangle[9];

static void mk_pkt(void);
static void cbvsync(int idx, void *cookie);
static void frame_update(void);
static void draw_debug(void);
static void draw_frame(void);
static void init_all(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);


/* SDK prototypes (tools/sdk_protos.h) */
int sceDisplayGetVcount(void);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuCopyImage(int psm, int sx, int sy, int width, int height, int srcw, void *src, int dx, int dy, int destw, void *dest);
void sceGuDebugFlush(void);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDrawBufferList(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSendList(int mode, const void *list, void *context);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateXYZ(const ScePspFVector3 *v);
void sceGumRotateY(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumUpdateMatrix(void);
int sprintf(char *buf, const char *fmt, ...);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011DF8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E04);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E10);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E18);

extern const ScePspFVector3 D_00011DF8;
void sceGumStoreContext(SceGumContext *ctx);
void sceGumLoadContext(const SceGumContext *ctx);
static void mk_pkt(void)
{
	ScePspFVector3 vec = D_00011DF8;
	SceGumContext ctx;

	cdb ^= 1;
	sceGuStart(2, packet[cdb], 4096);
	sceGuDrawBufferList(3, (void *)0, 512);
	sceGuOffset(2048 - 420, 2048 - 238);
	sceGuDepthRange(50000, 10000);
	sceGuViewport(2048, 2048, 120, 68);
	sceGuScissor(360, 204, 120, 68);
	sceGuEnable(2);
	sceGuClearColor(0);
	sceGuClearStencil(0);
	sceGuClearDepth(0xffff);
	sceGuClear(7);
	sceGuDisable(9);
	sceGuDisable(4);
	sceGuDisable(0);
	sceGuDisable(1);
	sceGuDisable(10);
	sceGuColor(0xffffffff);

	sceGumStoreContext(&ctx);

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&vec);
	sceGumRotateY(((vcnt * 2) % 360) * 3.1415927f / 180.0f);
	sceGumDrawArray(3, 0x180, 3, 0, triangle);
	sceGumPopMatrix();

	sceGumLoadContext(&ctx);

	sceGuCopyImage(3, 360, 204, 120, 68, 512, edram_addr, 360, 204, 512, (char *)edram_addr + 0x88000);

	sceGuFinish();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", cbvsync);

static void frame_update(void)
{
	float angle;

	angle = ((frame * 2) % 360) * 3.1415927f / 180.0f;
	pos.rot.x = angle;
	pos.rot.y = angle;
	pos.rot.z = angle;
	frame++;
	num += step;
	if (num < 0) {
		step = 1;
		num = 0;
	} else if (num > 19) {
		num = 19;
		step = -1;
	}
}

extern const char D_00011E04[];
extern const char D_00011E10[];
extern const char D_00011E18[];
static void draw_debug(void)
{
	char str[64];

	sprintf(str, D_00011E04, fps);
	sceGuDebugPrint(8, 8, 0xffffffff, str);
	sprintf(str, D_00011E10, vcnt);
	sceGuDebugPrint(8, 16, 0xffffffff, str);
	sprintf(str, D_00011E18, list_size);
	sceGuDebugPrint(8, 24, 0xffffffff, str);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", draw_frame);

static void init_all(void)
{
	ScePspFVector3 vec;

	sceGuInit();
	sceGuStart(0, disp_list, 0x100000);

	sceGuDrawBuffer(3, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x88000, 512);

	sceGuDepthBuffer((void *)0x110000, 512);

	sceGuOffset(2048 - 240, 2048 - 136);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(50000, 10000);

	sceGuDisable(4);
	sceGuEnable(8);

	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);

	sceGuDepthFunc(7);
	sceGuEnable(1);

	sceGuFrontFace(0);

	sceGuDisable(9);
	sceGuShadeModel(1);

	vec.x = 1.0f;
	vec.y = 1.0f;
	vec.z = 1.0f;

	sceGuLightColor(0, 2, 0xffc0c0c0);
	sceGuLightColor(0, 4, 0xffffffff);
	sceGuLight(0, 0, 6, &vec);
	sceGuEnable(11);
	sceGuEnable(10);

	sceGuSpecular(20.0f);

	sceGuAmbient(0x404040);
	sceGuColor(0xa0a0a0);

	sceGuTexMode(1, 1, 0, 0);
	sceGuTexFilter(5, 1);
	sceGuTexFunc(0, 0);
	sceGuTexWrap(0, 0);

	sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(45.0f * 3.1415927f / 180.0f, 480.0f / 272.0f, 1.0f, 100.0f);

	sceGumMatrixMode(2);
	sceGumUpdateMatrix();

	sceGuClearColor(0x402020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(0, 0);

	edram_addr = sceGeEdramGetAddr();
	mk_pkt();

	sceDisplaySetVblankCallback(0, cbvsync, 0);
	sceDisplayWaitVblankStart();

	pos.rot.x = 0.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = 0.0f;
	pos.trans.z = -10.0f;

	sceGuDisplay(1);
}

int pad_read(void) {
    SceCtrlData buf;
    sceCtrlReadBufferPositive(&buf, 1);
    if (buf.Buttons & 1) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E60);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E64);
