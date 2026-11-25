#ifndef MPEGBASE_H
#define MPEGBASE_H

typedef struct {
	short c[11];
} CscParam;

typedef struct {
	CscParam param;
	short pad16;
	int unk18;
	int unk1C;
	int sema;
} CscCtx;

extern CscCtx D_00001740;
typedef struct {
	unsigned int src;
	unsigned int dst;
	unsigned int next;
	unsigned int ctrl;
} PesDesc;

typedef struct {
	PesDesc desc[100];
	int unk640[4];
	int sema;
} PesCtx;

extern PesCtx D_00001780;

typedef struct {
	unsigned int src;
	unsigned int dst;
	unsigned int next;
	unsigned int size;
} PesPacket;

typedef struct {
	int width;
	int height;
	int unk8;
	int unkC;
	unsigned int buf[8];
} CscAvcParam;

typedef struct {
	int width;
	int height;
	int unk8;
	int unkC;
	unsigned int buf[6];
} CscVmeParam;
extern int D_00001E00;

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSignalSema(int id, int n);
int sceKernelWaitSema(int id, int n, unsigned int *timeout);
int sceKernelPollSema(int id, int n);
void sceKernelDcacheWritebackInvalidateAll(void);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
int sceDmacplus_driver_B2EFA681(int a, int b, void *c);
int sceDmacplus_driver_1D73DDA8(void *a, void *b, void *c);
int sceDmacplus_driver_74323807(void *a, void *b, void *c);
int sceDmacplus_driver_3A98EE05(int a, int b);
int sceDmacplus_driver_3438DA0B();
int sceDmacplus_driver_58DE4914();
int sceDmacplus_driver_BE693828(void *dst, void *src, int n);
int sceDmacplus_driver_AB49D2CB(int a, void *b);
int sceSysregGetTachyonVersion(void);
int sceMeCore_driver_3D5F109C(int cmd, ...);

int func_00000828(void);
int func_00000878(void);
int func_000008A0(void);
int func_000008C8(void);
int func_000008EC(void);
int func_00000BA0(void);
int func_00000BE0(void);
int func_00000C08(void);
int func_00000C30(void);
int func_00000C54(void);
int func_00001278(void);
int func_000012B4(void);
int func_000012DC(void);
int func_00001304(void);
int func_00001328(void);

static inline unsigned int pspShiftK1(void)
{
	unsigned int k1;
	asm volatile("move %0, $27\n\tsrl $27, $27, 16" : "=r"(k1));
	return k1;
}

static inline void pspSetK1(unsigned int k1)
{
	asm volatile("move $27, %0" : : "r"(k1));
}


static inline int pspK1IsUserMode(void)
{
	int r;
	asm volatile("andi %0, $27, 0x18" : "=r"(r));
	return r;
}

#define K1_USER() pspK1IsUserMode()

static inline int dynBufOk(unsigned int addr, unsigned int size)
{
	return ((addr | size | (addr + size)) >> 31) ^ 1;
}

static inline int staBufOk(unsigned int addr, unsigned int size)
{
	return ((addr | (addr + size)) >> 31) ^ 1;
}

static inline int dynBufBad(unsigned int addr, unsigned int size)
{
	if (K1_USER() && !dynBufOk(addr, size))
		return 1;
	return 0;
}

static inline int staBufBad(unsigned int addr, unsigned int size)
{
	if (K1_USER() && !staBufOk(addr, size))
		return 1;
	return 0;
}

#define K1_SAVE(old) ((old) = pspShiftK1())
#define K1_RESTORE(old) pspSetK1(old)

#endif
