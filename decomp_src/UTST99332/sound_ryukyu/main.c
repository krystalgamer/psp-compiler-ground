#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x14 */
    u_int32 x;
    u_int32 y;
    u_int32 dx;
    u_int32 dy;
    u_int32 col;
};
typedef struct _anon1 POS;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef int SceUID;
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

extern unsigned int starcolor[8];
extern unsigned int star16x16[64];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern long unsigned int pcmBuf[2][256];
extern char vagWork[2][16384];
extern int iVagSize[2];
extern volatile int iThreadExitFlag;
extern volatile unsigned int s_oldpadd;
extern volatile unsigned int s_padd;
extern volatile int s_updateFlag;
extern POS pos[256];
extern int maxnum;
extern char disp_list[131072];

static void draw_frame(void);
static void init_pos(void);
static int sas_thread(SceSize args, ScePVoid argp);
static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static void sas_setting(void);
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
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);


/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
int puts(const char *s);
int sceDisplayWaitVblankStart(void);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelDeleteThread(int thid);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

INCLUDE_ASM("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", draw_frame);

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x20000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0U, 0U);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuTexMode(4, 0, 0, 0);
    sceGuTexFilter(7, 0);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(1, 1);
    sceGuTexImage(0, 0x10, 0x10, 0x20, star16x16);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuClutLoad(1, starcolor);
    sceGuEnable(9);
    sceGuAlphaFunc(6, 0, 0xFF);
    sceGuEnable(0);
    sceGuBlendFunc(0, 2, 3, 0U, 0U);
    sceGuEnable(4);
    sceGuClearColor(0U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

int rand(void);
static void init_pos(void)
{
	int i;

	for (i = 0; i < 256; i++) {
		pos[i].x = rand() % 928;
		pos[i].y = rand() % 512;
		pos[i].dx = rand() % 4 + 2;
		pos[i].dy = rand() % 4 + 2;
		pos[i].col = ((rand() % 192 + 64) << 16) | ((rand() % 192 + 64) << 8) | (rand() % 192 + 64);
	}
}

int pad_read(void) {
    SceCtrlData buf;
    s_oldpadd = s_padd;
    sceCtrlReadBufferPositive(&buf, 1);
    s_padd = buf.Buttons;
    s_updateFlag = 1;
    if (s_padd & 1) {
        return 0;
    }
    return 1;
}

#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_START				(1<<3)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define SCE_CTRL_TRIANGLE			(1<<12)
#define SCE_CTRL_CROSS				(1<<14)
#define SCE_CTRL_SQUARE				(1<<15)
#define SCE_CTRL_CIRCLE				(1<<13)

static int sas_thread(SceSize args, ScePVoid argp)
{
	volatile int iSide = 0;
	int iPitch;

	while(iThreadExitFlag == 0){

		if (s_updateFlag != 0){
			s_updateFlag = 0;

			
			if (((s_padd & SCE_CTRL_UP) != 0) && ((s_oldpadd & SCE_CTRL_UP) == 0)){
				
				iPitch = 0x0800;
				sceSasSetPitch( 0,iPitch);
				sceSasSetPitch( 1,iPitch);
				sceSasSetKeyOff( 0);
				sceSasSetKeyOff( 1);
				sceSasSetKeyOn( 0);
				sceSasSetKeyOn( 1);
			}

			if (((s_padd & SCE_CTRL_START) != 0) && ((s_oldpadd & SCE_CTRL_START) == 0)){
				
				iPitch = 0x08fb;
				sceSasSetPitch(14,iPitch);
				sceSasSetPitch(15,iPitch);
				sceSasSetKeyOff(14);
				sceSasSetKeyOff(15);
				sceSasSetKeyOn(14);
				sceSasSetKeyOn(15);
			}

			if (((s_padd & SCE_CTRL_DOWN) != 0) && ((s_oldpadd & SCE_CTRL_DOWN) == 0)){
				
				iPitch = 0x0a14;
				sceSasSetPitch( 2,iPitch);
				sceSasSetPitch( 3,iPitch);
				sceSasSetKeyOff( 2);
				sceSasSetKeyOff( 3);
				sceSasSetKeyOn( 2);
				sceSasSetKeyOn( 3);
			}

			if (((s_padd & SCE_CTRL_LEFT) != 0) && ((s_oldpadd & SCE_CTRL_LEFT) == 0)){
				
				iPitch = 0x0aae;
				sceSasSetPitch( 4,iPitch);
				sceSasSetPitch( 5,iPitch);
				sceSasSetKeyOff( 4);
				sceSasSetKeyOff( 5);
				sceSasSetKeyOn( 4);
				sceSasSetKeyOn( 5);
			}

			if (((s_padd & SCE_CTRL_RIGHT) != 0) && ((s_oldpadd & SCE_CTRL_RIGHT) == 0)){
				
				iPitch = 0x0bfd;
				sceSasSetPitch( 6,iPitch);
				sceSasSetPitch( 7,iPitch);
				sceSasSetKeyOff( 6);
				sceSasSetKeyOff( 7);
				sceSasSetKeyOn( 6);
				sceSasSetKeyOn( 7);
			}

			if (((s_padd & SCE_CTRL_L1) != 0) && ((s_oldpadd & SCE_CTRL_L1) == 0)){
				
				iPitch = 0x0f1a;
				sceSasSetPitch( 8,iPitch);
				sceSasSetPitch( 9,iPitch);
				sceSasSetKeyOff( 8);
				sceSasSetKeyOff( 9);
				sceSasSetKeyOn( 8);
				sceSasSetKeyOn( 9);
			}

			if (((s_padd & SCE_CTRL_R1) != 0) && ((s_oldpadd & SCE_CTRL_R1) == 0)){
				
				iPitch = 0x1000;
				sceSasSetPitch(10,iPitch);
				sceSasSetPitch(11,iPitch);
				sceSasSetKeyOff(10);
				sceSasSetKeyOff(11);
				sceSasSetKeyOn(10);
				sceSasSetKeyOn(11);
			}

			if (((s_padd & SCE_CTRL_TRIANGLE) != 0) && ((s_oldpadd & SCE_CTRL_TRIANGLE) == 0)){
				
				iPitch = 0x1429;
				sceSasSetPitch(12,iPitch);
				sceSasSetPitch(13,iPitch);
				sceSasSetKeyOff(12);
				sceSasSetKeyOff(13);
				sceSasSetKeyOn(12);
				sceSasSetKeyOn(13);
			}

			if (((s_padd & SCE_CTRL_CROSS) != 0) && ((s_oldpadd & SCE_CTRL_CROSS) == 0)){
				
				iPitch = 0x155c;
				sceSasSetPitch(14,iPitch);
				sceSasSetPitch(15,iPitch);
				sceSasSetKeyOff(14);
				sceSasSetKeyOff(15);
				sceSasSetKeyOn(14);
				sceSasSetKeyOn(15);
			}

			if (((s_padd & SCE_CTRL_SQUARE) != 0) && ((s_oldpadd & SCE_CTRL_SQUARE) == 0)){
				
				iPitch = 0x17f9;
				sceSasSetPitch( 0,iPitch);
				sceSasSetPitch( 1,iPitch);
				sceSasSetKeyOff( 0);
				sceSasSetKeyOff( 1);
				sceSasSetKeyOn( 0);
				sceSasSetKeyOn( 1);
			}

			if (((s_padd & SCE_CTRL_CIRCLE) != 0) && ((s_oldpadd & SCE_CTRL_CIRCLE) == 0)){
				
				iPitch = 0x1e34;
				sceSasSetPitch( 2,iPitch);
				sceSasSetPitch( 3,iPitch);
				sceSasSetKeyOff( 2);
				sceSasSetKeyOff( 3);
				sceSasSetKeyOn( 2);
				sceSasSetKeyOn( 3);
			}
		}

		
		sceSasCore((short*)pcmBuf[iSide]);

		sceWaveAudioWriteBlocking(0,0x8000,0x8000,pcmBuf[iSide]);
		iSide ^= 1;
	}

	sceKernelExitThread(0);
	return 0;
}

int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void sceKernelDcacheWritebackInvalidateAll(void);

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
	sceKernelDcacheWritebackInvalidateAll();

	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", D_00011C30);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", D_00011C64);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", D_00011C98);

INCLUDE_ASM("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", sas_setting);

INCLUDE_ASM("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/main", main);
