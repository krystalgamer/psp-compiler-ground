#ifndef ATRAC_H
#define ATRAC_H

typedef struct {
	int codec;
	int channel;
	unsigned int sampleSize;
	unsigned int unkC;
	unsigned int unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
	int unk20;
	int loopNum;
	unsigned int unk28;
	unsigned int unk2C;
	unsigned int unk30;
	unsigned int state;
	int unk38;
	unsigned int unk3C;
	unsigned int unk40;
	unsigned int unk44;
	unsigned int unk48;
	unsigned int unk4C;
	unsigned int unk50;
	unsigned int unk54;
} AtracInfo;

typedef struct {
	int codec;
	unsigned int sampleSize;
	int bitrate;
} BitrateEnt;

extern BitrateEnt D_000038B4[10];

typedef struct {
	unsigned int d1;
	unsigned int d2;
	unsigned char d4[8];
} Guid;

typedef struct {
	unsigned short unk0;
	unsigned short nChannels;
	unsigned int unk4;
	unsigned int unk8;
	unsigned short nBlockAlign;
	unsigned short unkE;
	unsigned int unk10;
	unsigned int unk14;
	char pad18[0x2A - 0x18];
	unsigned char unk2A[2];
	char pad2C[0x40 - 0x2C];
} WaveFmt;

typedef struct {
	unsigned int buf;
	unsigned int unk4;
	unsigned int unk8;
	unsigned int unkC;
	unsigned int unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
} AtracBufInfo;

typedef struct {
	int inUse;
	char pad4[0x44 - 0x4];
	unsigned int codec[26];
	char padAC[0xF0 - 0xAC];
	AtracInfo info;
} AtracCtx;

static inline int frameSamples(AtracInfo *info)
{
	int n = 0x800;

	if (info->codec == 0x1001)
		n = 0x400;
	return n;
}

static inline unsigned int umin(unsigned int a, unsigned int b)
{
	if (b >= a)
		b = a;
	return b;
}

static inline int frameSkip(AtracInfo *info)
{
	int n = 0x170;

	if (info->codec == 0x1001)
		n = 0x45;
	return n;
}

extern AtracCtx D_00003930[4];

int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int intr);
int sceAudiocodecInit(unsigned int *codec, int type);

typedef struct {
	unsigned int value;
	unsigned int sampleSize;
	unsigned int key;
} ParamEnt;

extern ParamEnt D_00003890[3];

int func_00000D3C(AtracCtx *ctx, WaveFmt *fmt);
int func_00000E0C(AtracCtx *ctx);
int func_00000E90(unsigned int size, unsigned int key, unsigned int *out);
int func_00000EF8(AtracCtx *ctx, unsigned char *buf, int *a, int *b);

int func_000020B8(AtracInfo *info);
int func_000029E4(AtracInfo *info);
int func_0000220C(AtracInfo *info);
int func_00002180(AtracInfo *info);
int func_00001F7C(AtracInfo *info);
unsigned int func_000022B0(AtracInfo *info);
int func_00001F04(const unsigned char *a, const unsigned char *b, unsigned int n);
int func_0000201C(AtracInfo *info, unsigned int pos);
int func_0000222C(AtracInfo *info);
void func_00002884(AtracInfo *info);
void func_00002938(AtracInfo *info);
int func_00002CC8(AtracInfo *info);
int func_00002D18(AtracInfo *info);
int func_00002DD0(AtracInfo *info);
void func_000031CC(AtracInfo *info, unsigned int pos, AtracBufInfo *out);
void func_00003538(AtracInfo *info, unsigned int pos, unsigned int x, unsigned int y);
int func_000016E4(unsigned char *buf, unsigned int size, WaveFmt *fmt, unsigned int *a, unsigned int *c, unsigned int *d, int *e, int *f, int *g);
int func_00002408(AtracInfo *info, WaveFmt *fmt, unsigned char *buf, unsigned int a, unsigned int bufSize, unsigned int b, unsigned int c, unsigned int d, int e, int f, int g);
int func_00002504(AtracInfo *info, int type);
void func_00002550(AtracInfo *info, unsigned int x, WaveFmt *fmt);
void func_000025A4(AtracInfo *info, unsigned int endSample, unsigned int dataSize, int skip0, int loopStart, int loopEnd);
void func_00002690(AtracInfo *info, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);
int func_000026C0(AtracInfo *info);
int func_00002764(AtracInfo *info, unsigned int a, unsigned int b);
unsigned int func_00002F10(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
unsigned int func_00002F50(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
unsigned int func_00002F74(unsigned int a, unsigned int b, unsigned int start, unsigned int end, unsigned int lim);
unsigned int func_00002FC0(AtracInfo *info);
unsigned int func_0000303C(AtracInfo *info);
unsigned int func_00003064(AtracInfo *info);
unsigned int func_000030FC(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
unsigned int func_00001FAC(AtracInfo *info, unsigned int pos);
int func_00002064(AtracInfo *info, unsigned int pos);
unsigned int func_00002820(unsigned int a, unsigned int b, unsigned int c);

#endif
