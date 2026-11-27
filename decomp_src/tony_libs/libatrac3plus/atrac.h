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
	unsigned char *unk40;
	unsigned int unk44;
	unsigned int unk48;
	unsigned char *unk4C;
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
	unsigned short tag;
	unsigned short nChannels;
	unsigned int rate;
	unsigned int bytesPerSec;
	unsigned short nBlockAlign;
	unsigned short bits;
	unsigned short cbSize;
	unsigned short validBits;
	unsigned int unk14;
	unsigned int guid1;
	unsigned short guid2[2];
	unsigned char guid4[8];
	unsigned short unk28;
	unsigned char unk2A[2];
	unsigned char unk2C[8];
	char pad34[0x40 - 0x34];
} WaveFmt;

typedef struct {
	unsigned char *buf;
	unsigned int unk4;
	unsigned int unk8;
	unsigned int unkC;
	unsigned char *unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
} AtracBufInfo;

typedef struct {
	int inUse;
	char pad4[0x44 - 0x4];
	unsigned int codec[26];
	unsigned int edram;
	char padB0[0xF0 - 0xB0];
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
int sceAudiocodecCheckNeedMem(unsigned int *codec, int type);
int sceAudiocodecGetEDRAM(unsigned int *codec, int type);
int sceAudiocodecReleaseEDRAM(unsigned int *codec);
void func_00001640(AtracCtx *ctx, int codec);
unsigned int func_0000114C(unsigned int base, unsigned int pos, unsigned int end, unsigned int size);
void func_00002288(unsigned char *dst, unsigned char *src, int n);
void func_00003148(AtracInfo *info, AtracBufInfo *out);
void func_00003160(AtracInfo *info, AtracBufInfo *out);
void func_00003178(AtracInfo *info, AtracBufInfo *out);
void func_0000340C(AtracInfo *info, unsigned int pos, AtracBufInfo *out);
unsigned int func_0000224C(unsigned int a, unsigned int b);

typedef struct {
	unsigned int value;
	unsigned int sampleSize;
	unsigned int key;
} ParamEnt;

extern ParamEnt D_00003890[3];

int func_00000D3C(AtracCtx *ctx, WaveFmt *fmt);
int sceAtracGetAtracID(int codec);
unsigned int func_00002AC0(AtracInfo *info);
unsigned int func_00002BA0(AtracInfo *info);
unsigned int func_00002C5C(AtracInfo *info);
int sceAtracReleaseAtracID(unsigned int id);
int func_00000E0C(AtracCtx *ctx);
int func_00000E90(unsigned int size, unsigned int key, unsigned int *out);
int func_00000EF8(AtracCtx *ctx, short *out, int *samples, int *finish);
int sceAudiocodecDecode(unsigned int *codec, int type);
unsigned int func_000010DC(AtracInfo *info);
unsigned int func_0000214C(AtracInfo *info);
void func_00002260(int *dst, int *src, int n);
int func_00002838(AtracInfo *info);

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
int func_00003334(AtracInfo *info, unsigned int pos, unsigned int x, unsigned int y);
int func_000016E4(unsigned char *buf, unsigned int size, WaveFmt *fmt, unsigned int *a, unsigned int *c, unsigned int *d, int *e, int *f, int *g);
int func_00001D94(Guid *a, Guid *b);
unsigned int func_00001DFC(const unsigned char *buf, unsigned int *pos, unsigned int size);
unsigned short func_00001E8C(const unsigned char *buf, unsigned int *pos, unsigned int size);
extern Guid D_00003834;
extern Guid D_00003844;
int func_000022F8(AtracInfo *info, unsigned char *buf, unsigned int bufSize, unsigned int b, WaveFmt *fmt);
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
