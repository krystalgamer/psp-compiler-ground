#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
void AddOfs_(int *arg0, int arg1) {
    int temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        *arg0 = temp_v0 + arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CheckVersion(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) == 0x20001;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3m", I3mRoot__Unpack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3m", I3mRoot__Pack);

int I3mRoot__Get_nNode(char *r)
{
	if (I3mRoot__CheckIdString(r) != 0)
		return -1;
	return *(unsigned short *)(r + 0x14);
}

void *I3mRoot__GetNodeName(char *r, unsigned short i)
{
	if (I3mRoot__CheckIdString(r) != 0)
		return 0;
	if (i < *(unsigned short *)(r + 0x14))
		return *(void **)(*(char **)(r + 0x1C) + i * 12);
	return 0;
}

int strcmp(const char *, const char *);
int I3mRoot__GetNodeIndexByName(char *r, char *name)
{
	int n = *(unsigned short *)(r + 0x14);
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, *(char **)(*(char **)(r + 0x1C) + i * 12)) == 0)
			return i;
	}
	return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3mRoot__GetNodeAnim(signed char *arg0, int arg1) {
    int var_a0;
    unsigned int temp_s0;

    temp_s0 = arg1 & 0xFFFF;
    var_a0 = 0;
    if ((I3mRoot__CheckIdString(arg0) == 0) && (temp_s0 < (unsigned short) M2C_FIELD(arg0, unsigned short *, 0x14))) {
        var_a0 = M2C_FIELD(arg0, int *, 0x1C) + (temp_s0 * 0xC);
    }
    return var_a0;
}

unsigned short I3mRoot__Get_nSection(char *r, unsigned short i)
{
	if (I3mRoot__CheckIdString(r) != 0)
		return 0xFFFF;
	if (i < *(unsigned short *)(r + 0x14))
		return *(unsigned short *)(*(char **)(r + 0x1C) + i * 12 + 6);
	return 0xFFFF;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3m", I3mRoot__GetKeyTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3m", I3mRoot__GetKeyTimeTable);
