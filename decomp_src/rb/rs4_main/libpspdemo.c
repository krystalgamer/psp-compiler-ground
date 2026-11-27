#include "common.h"

void *__scee_param_recv(int *out, int a, char *p)
{
	*out = *(unsigned short *)(p + 0x32) + 0x34;
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libpspdemo", sceDemoStart);
