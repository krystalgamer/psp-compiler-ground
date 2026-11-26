#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
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
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef int SceInt32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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
extern POS pos[256];
extern int maxnum;
extern char disp_list[131072];
extern short int pcmBuf[2][512];
extern unsigned char vagbuf01[30000];
extern unsigned char vagbuf02[30000];
extern int ipitch;
extern int thread_on;
extern int fxsw;

static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static void draw_frame(void);
static void init_pos(void);
static int sound_init_all();
static SceInt32 sound_idle(SceSize args, ScePVoid argp);
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
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelDeleteThread(int thid);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

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

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_TEXTURE                      9
#define SCEGU_SCR_WIDTH       480
#define WALL_X			(SCEGU_SCR_WIDTH-SIZE)
#define SCEGU_SCR_HEIGHT      272
#define SIZE			16
#define WALL_Y			(SCEGU_SCR_HEIGHT-SIZE)
#define MAXOBJ			8
#define SCEGU_NOFLIP                       0
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	POS	*p = pos;
	int	x, y, px, py;
	int	i, j;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuEnable(SCEGU_TEXTURE);
	sceGuSpriteMode(SIZE, SIZE, SIZE, SIZE);
	for (j = 0; j < maxnum; j++, p++) {	
		if ((x = ((p->x+=p->dx) % (WALL_X*2))) >= WALL_X) {
			px = WALL_X*2 - x;
		} else {
			px = x;
		}
		if ((y = ((p->y+=p->dy) % (WALL_Y*2))) >= WALL_Y) {
			py = WALL_Y*2 - y;
		} else {
			py = y;
		}
		for (i = 1; i < MAXOBJ; i++) {
			if ((x = ((x+p->dx*2) % (WALL_X*2))) >= WALL_X) {
				px = WALL_X*2 - x;
			} else {
				px = x;
			}
			if ((y = ((y+p->dy*2) % (WALL_Y*2))) >= WALL_Y) {
				py = WALL_Y*2 - y;
			} else {
				py = y;
			}

			sceGuColor(p->col + ((0xff/(MAXOBJ-i)) << 24));
			sceGuDrawSprite(px, py, 0, 0, 0, SCEGU_NOFLIP, 0);
		}
	}
	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

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

static int sound_init_all(void)
{
	unsigned int size01, size02;


	
	sceWaveInit();
	sceWaveAudioSetSample(0, 256);

	
	if(sceSasInit() != 0){
		printf("Error:sceSasInit()\n");
		return -1;
	}

	
	if(file_read("disc0:/PSP_GAME/USRDIR/DATA/sound/wave/fms.vag", vagbuf01, sizeof(vagbuf01), &size01, 0x30) < 0){
		printf("Error:read file\n");
		return -1;
	}
	if (size01 & 15) {
		printf("Error:invalid file size\n");
		return -1;
	}

	
	if(file_read("disc0:/PSP_GAME/USRDIR/DATA/sound/wave/squ.vag", vagbuf02, sizeof(vagbuf02), &size02, 0x30) < 0){
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
	
	ipitch = 0x0080;
	sceSasSetPitch(2, ipitch);
	
	sceSasSetADSR(2, 0xf, 0x40000000, 0, 0, 0x20000000);
	
	sceSasSetVolume(2, 1000, 1000, 1000, 1000);	

	
	sceSasSetNoise(3, 0x30);
	
	sceSasSetADSR(3, 0xf, 0x40000000, 10, 10, 0x10000);
	
	sceSasSetVolume(3, 800, 800, 800, 800);	

	return 0;
}

static SceInt32 sound_idle(SceSize args, ScePVoid argp)
{
	volatile int iSide;

	iSide = 0;
	sceSasSetKeyOn(2);

	while (thread_on) {
		sceSasCore(pcmBuf[iSide]);

		sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, pcmBuf[iSide]);
		iSide ^= 1;
	}

	sceSasSetKeyOff(2);
	sceKernelExitThread(0);

	return 0;
}

void sound_end(void) {
    sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, 0);
    sceWaveExit();
}

#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define MAXNUM			256
#define SCE_CTRL_SELECT				(1<<0)
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define SCE_CTRL_TRIANGLE			(1<<12)
#define V2 ((0)+2)
#define SCE_CTRL_CIRCLE				(1<<13)
#define V1 ((0)+1)
#define SCE_CTRL_SQUARE				(1<<15)
#define V0 (0)
#define SCE_CTRL_CROSS				(1<<14)
#define V3 ((0)+3)

static int pad_read(void)
{
	extern u_int32 D_00013440;
	extern u_int32 D_00013444;
	SceCtrlData		buf;

	D_00013440 = D_00013444;
	sceCtrlReadBufferPositive(&buf, 1);
	D_00013444 = buf.Buttons;

	
	if (D_00013444 & SCE_CTRL_LEFT) {
		maxnum--;
		if (maxnum <= 1) {
			maxnum = 1;
		}
	}
	
	if (D_00013444 & SCE_CTRL_RIGHT) {
		maxnum++;
		if (maxnum >= MAXNUM) {
			maxnum = MAXNUM;
		}
	}
	
	if (D_00013444 & SCE_CTRL_SELECT) {
		return 0;	
	}
	
	if (((D_00013444 & SCE_CTRL_R1) != 0) && ((D_00013440 & SCE_CTRL_R1) == 0)){
		fxsw ^= 1;	
		sceSasSetEffect(1, fxsw);		
		printf("Effect %s\n",(fxsw)? "ON":"OFF");
	}

	
	if((D_00013444 & SCE_CTRL_TRIANGLE) !=0){
		
		if(ipitch < 0x4000){
			ipitch += 30;	
			if(ipitch > 0x4000) ipitch = 0x4000;	
			sceSasSetPitch(V2, ipitch);
		}
	}else
	{
		
		
		if(ipitch > 0x0080){
			ipitch -= 30;	
			if(ipitch < 0x0080) ipitch = 0x0080;
			sceSasSetPitch(V2, ipitch);
		}
	}

	
	if (((D_00013444 & SCE_CTRL_CIRCLE) != 0) && ((D_00013440 & SCE_CTRL_CIRCLE) == 0)){
		sceSasSetKeyOff(V1);
		sceSasSetKeyOn(V1);
	}
	
	if (((D_00013444 & SCE_CTRL_SQUARE) != 0) && ((D_00013440 & SCE_CTRL_SQUARE) == 0)){
		sceSasSetKeyOff(V0);
		sceSasSetKeyOn(V0);
	}
	
	if ((D_00013444 & SCE_CTRL_CROSS) != 0){
		if((D_00013440 & SCE_CTRL_CROSS) ==0){
			sceSasSetKeyOn(V3);
		}
	}else{
		if ((D_00013440 & SCE_CTRL_CROSS) != 0){
			sceSasSetKeyOff(V3);
		}
	}
	return 1;
}

#define SCE_KERNEL_USER_HIGHEST_PRIORITY        16
#define STACKSIZE	(1024 * 64)
#define SCE_KERNEL_ERROR_OK    0x0

int main(void)
{
	SceUID thread_id;
	SceInt32 thread_status;
	int ret = 0;

	menuInit();
	if (sasload() < 0) {
		return -1;
	}
	if (sound_init_all() < 0) {
		ret = -1;
		goto unload;
	}
	thread_on = 1;
	thread_id = sceKernelCreateThread("thread 1", sound_idle, SCE_KERNEL_USER_HIGHEST_PRIORITY, STACKSIZE, 0, NULL);
	if (thread_id < 0) {
		printf("sceKernelCreateThread:%08X\n", thread_id);
		ret = -1;
		goto end;
	}
	thread_status = sceKernelStartThread(thread_id, 0, 0);
	if (thread_status != SCE_KERNEL_ERROR_OK) {
		printf("sceKernelStartThread:%08X\n", thread_status);
		ret = -1;
		goto end;
	}
	init_all();
	init_pos();
	while (pad_read()) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
	sceGuTerm();
	thread_on = 0;
	thread_status = sceKernelWaitThreadEnd(thread_id, NULL);
	thread_status = sceKernelDeleteThread(thread_id);
	if (thread_status != SCE_KERNEL_ERROR_OK) {
		printf("sceKernelDeleteThread: %08X\n", thread_status);
		ret = -1;
	}
end:
	sound_end();
unload:
	sasunload();
	menuTerm(4, 6);
	return ret;
}
