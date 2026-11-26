/* cflags: -O2 -frename-registers */
#include "common.h"

typedef struct {
	void *data;
	unsigned int size;
	int vol_l;
	int vol_r;
	int unk10;
	int unk14;
	int flags;
	int stat;
	int pos;
	int unk24;
	int unk28;
	int unk2C;
	int unk30;
	int unk34;
	int unk38;
	int unk3C;
	int unk40;
	int unk44;
	int unk48;
} SceWaveVoice;

typedef struct {
	int thid;
	int ch;
	int prio;
} SceWaveMain;

extern volatile int D_0001375C;
extern volatile int D_00013760;
extern char D_00013764[];
extern char D_000137D4[];
extern SceWaveVoice D_000145E4[8];
extern SceWaveVoice D_00014844[8];
extern SceWaveMain D_00014AA4;
extern void *D_00014AB0;
extern void *D_00014AB4;
extern int D_00014AB8[3];

int sceAudioChReserve(int channel, int samplecount, int format);
int sceAudioChRelease(int channel);
int sceAudioSetChannelDataLen(int channel, int samplecount);
int sceAudioChangeChannelVolume(int channel, int leftvol, int rightvol);

int sceWaveGetStat(unsigned int ch);
int sceWaveStop(unsigned int ch);
int sceAudioOutputPanned(int channel, int leftvol, int rightvol, void *buffer);
int sceAudioOutputPannedBlocking(int channel, int leftvol, int rightvol, void *buffer);
int sceAudioOutputBlocking(int channel, int vol, void *buffer);
int sceAudioChangeChannelConfig(int channel, int format);
int sceAudioGetChannelRestLength(int channel);
int sceKernelCreateThread(const char *name, void *entry, int initPriority, int stackSize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDelayThread(unsigned int delay);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int sceKernelDeleteThread(int thid);
int sceKernelExitThread(int status);
extern char D_000137E4[2][0x700];
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);
static int func_00005AEC(char *buf);
static int func_00005CD4(short *dst, unsigned char *src, int *h1, int *h2);
static void func_00005E18(int ch, void *dst);
static void func_000060C4(int ch, void *dst);
static void func_00006634(int ch, short *out, short *src);
static int func_000059D0(unsigned int args, void *argp);



