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

extern volatile int D_0069F1B4;
extern volatile int D_0069F1B8;
extern char D_0069F1BC[];
extern char D_0069F22C[];
extern SceWaveVoice D_006A003C[8];
extern SceWaveVoice D_006A029C[8];
extern SceWaveMain D_006A04FC;
extern void *D_006A0508;
extern void *D_006A050C;
extern int D_006A0510[3];

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
extern char D_0069F23C[2][0x700];
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);
static int func_00006440(char *buf);
static int func_00006628(short *dst, unsigned char *src, int *h1, int *h2);
static void func_0000676C(int ch, void *dst);
static void func_00006A18(int ch, void *dst);
static void func_00006F88(int ch, void *buf, void *src);
static int func_00006324(unsigned int args, void *argp);



