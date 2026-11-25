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
	unsigned int codec[26];
	char pad68[0xF0 - 0x68];
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
