#include "common.h"

void *__scee_param_recv(int *out, int a, char *p)
{
	*out = *(unsigned short *)(p + 0x32) + 0x34;
	return p;
}

int printf(const char *, ...);
int sceKernelLoadModule(const char *path, int flags, void *option);
int sceKernelStartModule(int modid, int args, void *argp, int *status, void *option);
int sceDemoStart(int args, void *argp)
{
	int len, status, mid, ret;
	char *path;

	path = __scee_param_recv(&len, args, *(char **)argp);
	printf("libpspdemo: argd=0x%x\n", path);
	printf("module to load is %s\n", path);
	mid = sceKernelLoadModule(path, 0, 0);
	if (mid < 0) return mid;
	ret = sceKernelStartModule(mid, len, path, &status, 0);
	printf("ret from startmodule is %i\n", ret);
	if (ret < 0) return ret;
	return status;
}
