#ifndef AUDIOCODEC_H
#define AUDIOCODEC_H

register unsigned int k1 asm("$27");

#define K1_SAVE(old) asm volatile("move %0, $27\n\tsrl $27, $27, 16" : "=r"(old))
#define K1_RESTORE(old) asm volatile("move $27, %0" : : "r"(old))
#define K1_USER() ({ unsigned int _u; asm volatile("andi %0, $27, 0x18" : "=r"(_u)); _u; })

static inline int k1StaBufOk(const void *p, unsigned int size)
{
	return !K1_USER() || (int)((unsigned int)p | ((unsigned int)p + size)) >= 0;
}

static inline int k1DynBufOk(unsigned int p, unsigned int size)
{
	return !K1_USER() || (int)(p | size | (p + size)) >= 0;
}

typedef struct {
	unsigned int unk0;
	unsigned int unk4;
	int err;
	unsigned int edram;
	unsigned int neededMem;
	unsigned int unk14;
	unsigned int inBuf;
	unsigned int unk1C;
	unsigned int outBuf;
	unsigned int unk24;
	unsigned int unk28;
	unsigned int unk2C;
	unsigned int unk30;
	unsigned int unk34;
	unsigned int unk38;
	unsigned int unk3C;
	unsigned int unk40;
	unsigned int unk44;
	unsigned int unk48;
	unsigned int unk4C;
	unsigned int unk50[6];
	unsigned int allocMem;
} AudiocodecCtx;

int sceMeAudio_driver_C00D873B(int codec, AudiocodecCtx *ctx);
int sceMeAudio_driver_FEE0A97D(int codec, AudiocodecCtx *ctx);
int sceMeAudio_driver_BAC7C2BE(int codec, AudiocodecCtx *ctx);
int sceMeAudio_driver_39F06790(int codec, int what, AudiocodecCtx *ctx);
void *sceMeMalloc(unsigned int size);
void sceMeFree(void *p);
int sceKernelDcacheWritebackRange(const void *p, unsigned int size);
int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);

int sceAudiocodecGetInfo(AudiocodecCtx *ctx, int codec);
int func_000007B4(AudiocodecCtx *ctx, int codec);
int func_00000894(AudiocodecCtx *ctx, int codec);
int func_00000958(int a, int b, int c, int d, unsigned int *out);
int func_00000A40(int a, int b);
int func_00000A94(int a, int b);

extern const int D_00000D1C[2][15];
extern const int D_00000D94[3][4];

static inline int convErr(int r)
{
	int e;

	switch (r) {
	case -2:
		e = 0x80000000;
		break;
	case -1:
		return 0x807F0001;
	case -3:
	default:
		e = 0x807F0000;
		break;
	}
	return e | 2;
}

#endif
