#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
typedef unsigned int u_int32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef int SceInt32;
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
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;

extern ScePspFVector3 light_vec;
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern unsigned char vagbuf01[30000];
extern unsigned char vagbuf02[30000];
extern int ipitch;
extern int fxsw;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];
extern POS pos;

static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static int sound_init_all();
static void draw_frame(void);
static void init_pos(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuInit(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuAmbient(unsigned int color);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuFog(float near, float far, unsigned int color);
void sceGuShadeModel(int mode);
void sceGuDepthFunc(int function);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuStencilFunc(int func, int ref, int mask);
void sceGuStencilOp(int fail, int zfail, int zpass);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);


int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void sceKernelDcacheWritebackAll(void);

/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
int puts(const char *s);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceDisplayWaitVblankStart(void);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
int sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelDeleteThread(int thid);

static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset)
{
	SceUID fd;

	fd = sceIoOpen(pFile, 1, 0);
	if (fd < 0) {
		return -1;
	}

	*uSize = sceIoLseek(fd, 0, 2) - uOffset;
	if (*uSize > uBufSize) {
		*uSize = uBufSize;
	}

	sceIoLseek(fd, uOffset, 0);
	sceIoRead(fd, pBuf, *uSize);
	sceIoClose(fd);
	sceKernelDcacheWritebackAll();

	return 0;
}

static int sound_init_all(void)
{
	unsigned int size01, size02;


	

	
	if(sceSasInit() < 0){
		printf("Error:sceSasInit()\n");
		return -1;
	}

	
	if(file_read("host0:../../../data/sound/wave/fms.vag", vagbuf01, sizeof(vagbuf01), &size01, 0x30) < 0){
		printf("Error:read file\n");
		return -1;
	}
	if (size01 & 15) {
		printf("Error:invalid file size\n");
		return -1;
	}

	
	if(file_read("host0:../../../data/sound/wave/squ.vag", vagbuf02, sizeof(vagbuf02), &size02, 0x30) < 0){
		printf("Error:read file\n");
		return -1;
	}
	if (size02 & 15) {
		printf("Error:invalid file size\n");
		return -1;
	}

	
	fxsw = 0;
	sceSasSetEffectType(4);	
	sceSasSetEffect(1, fxsw);			
	
	sceSasSetEffectVolume(0x1000*3/4,
						  0x1000*3/4);

	
	sceKernelDcacheWritebackInvalidateAll();

	
	sceSasSetVoice(0, vagbuf01, size01, 0);	
	
	sceSasSetPitch(0, 0x1800);	
	
	sceSasSetADSR(0, 0xf, 0x40000000, 100, 100, 0x10000000);
	
	sceSasSetVolume(0, 2500, 1000, 2500, 1000);	

	
	sceSasSetVoice(1, vagbuf01, size01, 0);	
	
	sceSasSetPitch(1, 0x1000);	
	
	sceSasSetADSR(1, 0xf, 0x40000000, 100, 100, 0x10000000);
	
	sceSasSetVolume(1, 1000, 2500, 1000, 2500);	

	
	sceSasSetVoice(2, vagbuf02, size02, 1);	
	
	ipitch = 0x7f;
	
	sceSasSetADSR(2, 0xf, 0x40000000, 0, 0, 0x200000);
	
	sceSasSetVolume(2, 1000, 1000, 1000, 1000);	

	
	sceSasSetNoise(3, 0x30);
	
	sceSasSetADSR(3, 0xf, 0x40000000, 10, 10, 0x10000);
	
	sceSasSetVolume(3, 800, 800, 800, 800);	

	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_0001594C);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_00015964);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_00015970);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_000159AC);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_000159C4);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_000159E0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", D_00015A00);

void DrawData(void);

static void draw_frame(void)
{
	ScePspFVector3 vec;

	sceGuStart(0, disp_list, 0x10000);

	sceGuClear(7);

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	vec.x = pos.rot.x * 3.1415927f / 180.0f;
	vec.y = pos.rot.y * 3.1415927f / 180.0f;
	vec.z = pos.rot.z * 3.1415927f / 180.0f;
	sceGumRotateXYZ(&vec);

	DrawData();

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(0, 0);
}

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuViewport(0x800, 0x800, 0x1E0, 0x110);
    sceGuDepthRange(0xFFFF, 0);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDepthFunc(7);
    sceGuEnable(1);
    sceGuEnable(8);
    sceGuStencilFunc(2, 0, 0xFF);
    sceGuStencilOp(0, 0, 4);
    sceGuEnable(0x14);
    sceGuShadeModel(1);
    sceGuEnable(6);
    light_vec.x = 1.0f;
    light_vec.y = 0.0f;
    light_vec.z = 0.0f;
    sceGuLightColor(2, 2, -1U);
    sceGuLight(2, 0, 2, &light_vec);
    sceGuDisable(0xD);
    light_vec.y = 1.0f;
    light_vec.x = 0.0f;
    light_vec.z = 0.0f;
    sceGuLightColor(3, 2, -1U);
    sceGuLight(3, 0, 2, &light_vec);
    sceGuDisable(0xE);
    light_vec.y = 1.0f;
    light_vec.z = 1.0f;
    light_vec.x = 0.0f;
    sceGuLightColor(0, 2, -1U);
    sceGuLight(0, 0, 2, &light_vec);
    sceGuEnable(0xB);
    sceGuEnable(0xA);
    sceGuAmbient(0xFF7F7F7FU);
    sceGuBlendFunc(0, 2, 3, 0U, 0U);
    sceGuDisable(4);
    sceGuTexFilter(7, 1);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(0, 0);
    sceGuTexOffset(0.0f, 0.0f);
    sceGuTexScale(10.0f, 10.0f);
    sceGuTexMapMode(0, 0U, 1U);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuDisable(9);
    sceGuFog(20.0f, 30.0f, 0U);
    sceGuEnable(7);
    sceGumSetMatrixStack(matrix_stack, 4, 4, 8, 0);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(0.7853982f, 1.7647059f, 1.0f, 100.0f);
    sceGumMatrixMode(2);
    sceGuClearColor(0U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static void init_pos(void)
{
	pos.rot.x = 10.0f;
	pos.rot.y = 0.0f;
	pos.rot.z = 0.0f;
	pos.trans.x = 0.0f;
	pos.trans.y = -1.0f;
	pos.trans.z = -12.0f;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/main", main);
