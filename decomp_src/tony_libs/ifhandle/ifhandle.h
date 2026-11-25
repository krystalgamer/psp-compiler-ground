#ifndef IFHANDLE_H
#define IFHANDLE_H

#define K1_SAVE(old) asm volatile(".set noreorder\n\tmove %0, $27\n\tsrl $27, $27, 16\n\t.set reorder" : "=r"(old))
#define K1_RESTORE(old) asm volatile("move $27, %0" : : "r"(old))
#define K1_USER() ({ unsigned int _u; asm volatile("andi %0, $27, 0x18" : "=r"(_u)); _u; })

typedef struct {
	int size;
	char name[32];
	unsigned int attr;
	int poolSize;
	int freeSize;
	int numWaitThreads;
} SceKernelVplInfo;

int sceKernelCreateVpl(const char *name, int part, unsigned int attr, unsigned int size, void *opt);
int sceKernelDeleteVpl(int uid);
int sceKernelTryAllocateVpl(int uid, unsigned int size, void **data);
int sceKernelFreeVpl(int uid, void *data);
int sceKernelReferVplStatus(int uid, SceKernelVplInfo *info);
int Kprintf(const char *fmt, ...);

extern int D_00003B28;
extern int D_00003B2C;

#endif
