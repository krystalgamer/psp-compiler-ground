#include "common.h"
#include <kerneltypes.h>
#include <kernelutils.h>
#include <pspnet.h>
#include <pspnet_inet.h>
#include <pspnet_apctl.h>
#include <stdio.h>

typedef struct {
	int code[4];
} PATCH_WORK;

extern PATCH_WORK localNetInitWork;
extern PATCH_WORK localNetTermWork;
extern PATCH_WORK localNetInetInitWork;
extern PATCH_WORK localNetInetTermWork;
extern PATCH_WORK localNetApctlInitWork;
extern PATCH_WORK localNetApctlTermWork;

static void usrKernelIcacheInvalidate(const void *start)
{
	while (sceKernelIcacheProbe(start)) {
		__asm__ volatile ("cache 0x04, 0(%0)" : : "r"(start));
		__asm__ volatile ("cache 0x04, 0(%0)" : : "r"(start));
	}
}

static void usrKernelIcacheInvalidateRange(const void *start, unsigned int size)
{
	char *adrs = (char *)start;

	while (size != 0) {
		usrKernelIcacheInvalidate(adrs);
		size -= 4;
		adrs += 4;
	}
}

static void PatchAdrs(PATCH_WORK *p, int *orgcode, int *newcode)
{
	p->code[0] = orgcode[0];
	p->code[1] = orgcode[1];
	p->code[2] = 0x08000000 | ((int)(orgcode + 2) >> 2);
	p->code[3] = 0;
	orgcode[0] = 0x08000000 | ((int)newcode >> 2);
	orgcode[1] = 0;
	usrKernelIcacheInvalidateRange(p, sizeof(PATCH_WORK));
	sceKernelDcacheWritebackRange(p, sizeof(PATCH_WORK));
	usrKernelIcacheInvalidateRange(orgcode, 8);
	sceKernelDcacheWritebackRange(orgcode, 8);
}

static void UnpatchAdrs(PATCH_WORK *p)
{
	int *orgcode;

	orgcode = (int *)((p->code[2] - 0x08000000) << 2) - 2;
	orgcode[0] = p->code[0];
	orgcode[1] = p->code[1];
	usrKernelIcacheInvalidateRange(orgcode, 8);
	sceKernelDcacheWritebackRange(orgcode, 8);
}

static int localNetInit(SceSize poolsize, int callout_tpl, SceSize callout_stack, int netintr_tpl, SceSize netintr_stack)
{
	printf("localNetInit: %d, %d, %d, %d, %d\n", poolsize, callout_tpl, callout_stack, netintr_tpl, netintr_stack);
	return 0;
}

static int localNetTerm(void)
{
	puts("localNetTerm");
	return 0;
}

static int localNetInetInit(void)
{
	puts("localNetInetInit");
	return 0;
}

static int localNetInetTerm(void)
{
	puts("localNetInetTerm");
	return 0;
}

static int localNetApctlInit(SceSize stacksize, int prio)
{
	printf("localNetApctlInit: %d, %d\n", stacksize, prio);
	return 0;
}

static int localNetApctlTerm(void)
{
	puts("localNetApctlTerm");
	return 0;
}

void DevPatchInit(void)
{
	PatchAdrs(&localNetInitWork, (int *)sceNetInit, (int *)localNetInit);
	PatchAdrs(&localNetTermWork, (int *)sceNetTerm, (int *)localNetTerm);
	PatchAdrs(&localNetInetInitWork, (int *)sceNetInetInit, (int *)localNetInetInit);
	PatchAdrs(&localNetInetTermWork, (int *)sceNetInetTerm, (int *)localNetInetTerm);
	PatchAdrs(&localNetApctlInitWork, (int *)sceNetApctlInit, (int *)localNetApctlInit);
	PatchAdrs(&localNetApctlTermWork, (int *)sceNetApctlTerm, (int *)localNetApctlTerm);
}

void DevPatchTerm(void)
{
	UnpatchAdrs(&localNetInitWork);
	UnpatchAdrs(&localNetTermWork);
	UnpatchAdrs(&localNetInetInitWork);
	UnpatchAdrs(&localNetInetTermWork);
	UnpatchAdrs(&localNetApctlInitWork);
	UnpatchAdrs(&localNetApctlTermWork);
}
