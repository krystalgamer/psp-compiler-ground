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
struct _anon2;
struct _anon2 { /* size 0x20 */
    unsigned int setMask;
    unsigned int type;
    unsigned int delayTime;
    unsigned int feedBack;
    unsigned int effectVolume_l;
    unsigned int effectVolume_r;
    unsigned int drySwitch;
    unsigned int wetSwitch;
};
typedef struct _anon2 SceSsEffectParam;
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
struct _anon3;
struct _anon3 { /* size 0x8 */
    char system[8];
};
typedef struct _anon3 SceSsSndpCtx;
struct _anon4;
struct _anon4 { /* size 0x140 */
    char system[320];
};
typedef struct _anon4 SceSsSmfCtx;

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
extern volatile int iThreadExitFlag;
extern volatile unsigned int s_oldpadd;
extern volatile unsigned int s_padd;
extern volatile int s_updateFlag;
extern char phdWork[34760];
extern char pbdWork[857680];
extern char smfWork[44466];
extern int iPhdSize;
extern int iPbdSize;
extern int iSmfSize;
extern int phdID;
extern int smfID;
extern SceSsSndpCtx sndpCtx;
extern SceSsSmfCtx smfCtx;
extern POS pos[256];
extern int maxnum;
extern char disp_list[131072];

static void draw_frame(void);
static void init_pos(void);
static int sndp_thread(SceSize args, ScePVoid argp);
static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static int sndp_setting(void);
static int file_setting(void);
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

void sound_end(void) {
    sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, 0);
    sceWaveExit();
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

extern unsigned int D_00018574; /* static unsigned int playVelocity in sndp_thread */
extern unsigned int D_00018578; /* static unsigned int playPanpot in sndp_thread */
extern int D_00018F10; /* static int playStartFlag in sndp_thread */
int sceSsSynthesis(void *pBuf);
int sceSsSMFGetPlayStatus(int id);
int sceSsSMFSetPlayVelocity(int id, unsigned int vel);
int sceSsSMFSetPlaySendVelocity(int id, unsigned int vel);
int sceSsSMFSetPlayPanpot(int id, unsigned int pan);
int sceSsSMFSetPlaySendPanpot(int id, unsigned int pan);
int sceSsSMFSetChannelMute(int id, int ch);
int sceSsSMFResetChannelMute(int id);
int sceSsSMFPlay(int id, int a, int b, int c, int d, int e);
int sceSsSMFStop(int id);
int sceSsSMFPause(int id);
int sceSsSMFResume(int id);
int sceKernelExitThread(int status);

static int sndp_thread(SceSize args, ScePVoid argp)
{
	volatile int iSide = 0;

	while (iThreadExitFlag == 0) {
		if (s_updateFlag) {
			s_updateFlag = 0;

			if ((s_padd & 0x10) && !(s_oldpadd & 0x10)) {
				if (D_00018574 < 127) {
					D_00018574++;
					printf("@SET PLAY VELOCITY : %d\n", D_00018574);
					sceSsSMFSetPlayVelocity(smfID, D_00018574);
					sceSsSMFSetPlaySendVelocity(smfID, D_00018574);
				}
			}

			if ((s_padd & 0x8) && !(s_oldpadd & 0x8)) {
				printf("PLAY STATUS : %d\n", sceSsSMFGetPlayStatus(smfID));
			}

			if ((s_padd & 0x40) && !(s_oldpadd & 0x40)) {
				if (D_00018574 > 0) {
					D_00018574--;
					printf("@SET PLAY VELOCITY : %d\n", D_00018574);
					sceSsSMFSetPlayVelocity(smfID, D_00018574);
					sceSsSMFSetPlaySendVelocity(smfID, D_00018574);
				}
			}

			if ((s_padd & 0x80) && !(s_oldpadd & 0x80)) {
				if (D_00018578 > 0) {
					D_00018578--;
					printf("@SET PLAY PANPOT : %d\n", D_00018578);
					sceSsSMFSetPlayPanpot(smfID, D_00018578);
					sceSsSMFSetPlaySendPanpot(smfID, D_00018578);
				}
			}

			if ((s_padd & 0x20) && !(s_oldpadd & 0x20)) {
				if (D_00018578 < 127) {
					D_00018578++;
					printf("@SET PLAY PANPOT : %d\n", D_00018578);
					sceSsSMFSetPlayPanpot(smfID, D_00018578);
					sceSsSMFSetPlaySendPanpot(smfID, D_00018578);
				}
			}

			if ((s_padd & 0x100) && !(s_oldpadd & 0x100)) {
				printf("@CHANNEL 0 MUTE\n");
				sceSsSMFSetChannelMute(smfID, 0);
			}

			if ((s_padd & 0x200) && !(s_oldpadd & 0x200)) {
				printf("@RESET CHANNEL MUTE\n");
				sceSsSMFResetChannelMute(smfID);
			}

			if ((s_padd & 0x1000) && !(s_oldpadd & 0x1000)) {
				printf("@SMF PLAY START\n");
				D_00018F10 = 1;
				sceSsSMFPlay(smfID, 48, 64, 48, 64, 1);
			}

			if ((s_padd & 0x4000) && !(s_oldpadd & 0x4000)) {
				printf("@SMF PLAY STOP\n");
				sceSsSMFStop(smfID);
			}

			if ((s_padd & 0x8000) && !(s_oldpadd & 0x8000)) {
				printf("@SMF PLAY PAUSE\n");
				sceSsSMFPause(smfID);
			}

			if ((s_padd & 0x2000) && !(s_oldpadd & 0x2000)) {
				printf("@SMF PLAY RESUME\n");
				sceSsSMFResume(smfID);
			}
		}

		sceSsSynthesis(pcmBuf[iSide]);

		sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, pcmBuf[iSide]);
		iSide ^= 1;

		if (D_00018F10) {
			if (sceSsSMFGetPlayStatus(smfID) == 0) {
				D_00018F10 = 0;
				printf("@SMF PLAY FINISH\n");
			}
		}
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

int sceSsBindSoundData(SceSsSndpCtx *pCtx, void *pHd, void *pBd);
int sceSsSMFBind(SceSsSmfCtx *pCtx, void *pSmf, int hdID);
int sceSsSetEffectParam(SceSsEffectParam *pParam);
int puts(const char *s);

static int sndp_setting(void)
{
	SceSsEffectParam effectParam;

	phdID = sceSsBindSoundData(&sndpCtx, phdWork, pbdWork);
	if (phdID < 0) {
		printf("sceSsBindSoundData() error\n");
		return -1;
	}

	smfID = sceSsSMFBind(&smfCtx, smfWork, phdID);
	if (smfID < 0) {
		printf("sceSsSMFBind() error\n");
		return -1;
	}

	effectParam.setMask = 0xFFFFFFFF;
	effectParam.type = 3;
	effectParam.delayTime = 0;
	effectParam.feedBack = 0;
	effectParam.effectVolume_l = 0x1000;
	effectParam.effectVolume_r = 0x1000;
	effectParam.drySwitch = 1;
	effectParam.wetSwitch = 1;

	if (sceSsSetEffectParam(&effectParam) != 0) {
		printf("sceSsSetEffectParam() error\n");
		return -1;
	}

	return 0;
}

static int file_setting(void)
{
	const char *phdFile, *pbdFile, *smfFile;
	int iRc;

	phdFile = "disc0:/PSP_GAME/USRDIR/DATA/sound/sndp/Impression.phd";
	pbdFile = "disc0:/PSP_GAME/USRDIR/DATA/sound/sndp/Impression.pbd";
	smfFile = "disc0:/PSP_GAME/USRDIR/DATA/sound/sndp/Impression.mid";

	iRc = file_read(phdFile, phdWork, sizeof(phdWork), &iPhdSize, 0);
	if (iRc < 0) {
		printf("phd file read error:%s\n", phdFile);
		return -1;
	}

	iRc = file_read(pbdFile, pbdWork, sizeof(pbdWork), &iPbdSize, 0);
	if (iRc < 0) {
		printf("pbd file read error:%s\n", pbdFile);
		return -1;
	}

	iRc = file_read(smfFile, smfWork, sizeof(smfWork), &iSmfSize, 0);
	if (iRc < 0) {
		printf("smf file read error:%s\n", smfFile);
		return -1;
	}

	return 0;
}

int main(void)
{
	SceUID thid;
	SceInt32 status;

	menuInit();

	if (sasload() < 0)
		return -1;

	if (sceWaveInit() != 0) {
		printf("sceWaveInit error\n");
		return -1;
	}

	sceWaveAudioSetSample(0, 256);

	if (sceSsInit(32) != 0) {
		printf("sceSsInit error\n");
		return -1;
	}

	if (file_setting() != 0)
		return -1;

	if (sndp_setting() != 0)
		return -1;

	thid = sceKernelCreateThread("sndp thread", sndp_thread, 16, 0x1000, 0, NULL);
	if (thid < 0) {
		printf("sceKernelCreateThread:%08X\n", thid);
		return -1;
	}

	status = sceKernelStartThread(thid, 0, NULL);
	if (status != 0) {
		printf("sceKernelStartThread:%08X\n", status);
		return -1;
	}

	init_all();
	init_pos();

	while (pad_read() != 0) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}

	sceGuTerm();

	iThreadExitFlag = 1;
	sceKernelWaitThreadEnd(thid, NULL);
	status = sceKernelDeleteThread(thid);
	if (status != 0) {
		printf("sceKernelDeleteThread: %08X\n", status);
	}

	if (sceSsExit() != 0) {
		printf("sceSsExit() error\n");
	}

	if (sceWaveExit() != 0) {
		printf("sceWaveExit() error\n");
	}

	sound_end();
	if (sasunload() < 0)
		return -1;

	menuTerm(4, 3);
	return 0;
}
