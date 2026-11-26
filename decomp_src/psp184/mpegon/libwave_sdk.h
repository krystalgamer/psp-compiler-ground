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

extern volatile int D_0001378C;
extern volatile int D_00013790;
extern char D_00013794[];
extern char D_00013804[];
extern SceWaveVoice D_00014614[8];
extern SceWaveVoice D_00014874[8];
extern SceWaveMain D_00014AD4;
extern void *D_00014AE0;
extern void *D_00014AE4;
extern int D_00014AE8[3];

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
extern char D_00013814[2][0x700];
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);
static int func_00005AF4(char *buf);
static int func_00005CDC(short *dst, unsigned char *src, int *h1, int *h2);
static void func_00005E20(int ch, void *dst);
static void func_000060CC(int ch, void *dst);
static void func_0000663C(int ch, void *buf, void *src);
static int func_000059D8(unsigned int args, void *argp);



