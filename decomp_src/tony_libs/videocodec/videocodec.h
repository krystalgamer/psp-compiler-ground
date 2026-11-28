#ifndef VIDEOCODEC_H
#define VIDEOCODEC_H

register unsigned int k1 asm("$27");

#define K1_SAVE(old) asm volatile(".set noreorder\n\tmove %0, $27\n\tsrl $27, $27, 16\n\t.set reorder" : "=r"(old))
#define K1_RESTORE(old) asm volatile("move $27, %0" : : "r"(old))
#define K1_USER() ({ unsigned int _u; asm volatile("andi %0, $27, 0x18" : "=r"(_u)); _u; })

static inline int k1StaBufOk(const void *p, unsigned int size)
{
	if (!K1_USER())
		return 1;
	return (((unsigned int)p | ((unsigned int)p + size)) >> 31) ^ 1;
}

static inline int k1DynBufOk(unsigned int p, unsigned int size)
{
	if (!K1_USER())
		return 1;
	return ((p | size | (p + size)) >> 31) ^ 1;
}

static inline int isMeAddr(unsigned int p)
{
	return __builtin_allegrex_ext(p, 0, 29) <= 0x1FFFFF;
}

typedef struct {
	unsigned int unk0;
	unsigned int unk4;
	unsigned int unk8;
	int unkC;
	unsigned int unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
	unsigned int unk20;
	unsigned int unk24;
	unsigned int unk28;
	unsigned int unk2C;
	unsigned int unk30;
	unsigned int unk34;
	unsigned int unk38;
	unsigned int unk3C;
	unsigned int unk40[4];
	unsigned int mem;
} VideocodecCtx;

int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);

static inline void wbInvNotMe(unsigned int p, unsigned int size)
{
	if (!isMeAddr(p))
		sceKernelDcacheWritebackInvalidateRange((void *)p, size);
}
int sceKernelDcacheInvalidateRange(const void *p, unsigned int size);
void *sceMeCalloc(unsigned int size, unsigned int n);
void sceMeFree(void *p);
int sceMeVideo_driver_B655AD4E(int type, VideocodecCtx *ctx);
int sceMeVideo_driver_06F0236A(int type, VideocodecCtx *ctx);
int sceMeVideo_driver_176BBE07(int type, VideocodecCtx *ctx);
int sceMeVideo_driver_DE2E7E89(int type, VideocodecCtx *ctx);
int sceMeVideo_driver_E67F4E0A(int type, VideocodecCtx *ctx);
int sceMeVideo_driver_1C6A60E1(int type, int func, VideocodecCtx *ctx);
int sceMePower_driver_B6FE3E62(int on);
int sceMePowerControlAvcPower(int on);

int func_00000A80(VideocodecCtx *ctx, unsigned int type);
int func_00000AE8(VideocodecCtx *ctx, unsigned int type);
int func_00000BB8(VideocodecCtx *ctx, unsigned int type);
void func_00000D84(VideocodecCtx *ctx, unsigned int type);
int func_00000E1C(VideocodecCtx *ctx, unsigned int type);

static inline int convErr(int r)
{
	int ret = 0x80628002;

	switch (r) {
	case 0:
		ret = 0;
		break;
	case -1:
		ret = 0x806201FE;
		break;
	case -2:
		ret = 0x80620002;
		break;
	case -3:
		ret = 0x80628001;
		break;
	case -4:
		ret = 0x80628002;
		break;
	}
	return ret;
}

#endif
