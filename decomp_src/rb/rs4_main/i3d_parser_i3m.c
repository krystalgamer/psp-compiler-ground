/* cflags: -O2 -fno-strict-aliasing */
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

int I3mRoot__Unpack(char *r)
{
	int ret, i, n;
	if ((ret = I3mRoot__CheckIdString(r)) != 0) return ret;
	if (!CheckVersion(r)) return 4;
	if (*(unsigned short *)(r + 0x16) == 0) return 0;
	n = *(unsigned short *)(r + 0x14);
	AddOfs_((int *)(r + 0x1C), (int)r);
	AddOfs_((int *)(r + 0x20), (int)r);
	AddOfs_((int *)(r + 0x24), (int)r);
	AddOfs_((int *)(r + 0x28), (int)r);
	for (i = 0; i < n; i++) {
		AddOfs_((int *)(*(char **)(r + 0x1C) + i * 12), (int)r);
		AddOfs_((int *)(*(char **)(r + 0x1C) + i * 12 + 8), (int)r);
	}
	*(unsigned short *)(r + 0x16) = 0;
	return 0;
}

int I3mRoot__Pack(char *r)
{
	int ret, i, n;
	if ((ret = I3mRoot__CheckIdString(r)) != 0) return ret;
	if (!CheckVersion(r)) return 4;
	if (*(unsigned short *)(r + 0x16) == 1) return 0;
	n = *(unsigned short *)(r + 0x14);
	for (i = 0; i < n; i++) {
		AddOfs_((int *)(*(char **)(r + 0x1C) + i * 12), -(int)r);
		AddOfs_((int *)(*(char **)(r + 0x1C) + i * 12 + 8), -(int)r);
	}
	AddOfs_((int *)(r + 0x20), -(int)r);
	AddOfs_((int *)(r + 0x24), -(int)r);
	AddOfs_((int *)(r + 0x28), -(int)r);
	AddOfs_((int *)(r + 0x1C), -(int)r);
	*(unsigned short *)(r + 0x16) = 1;
	return 0;
}

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

float I3mRoot__GetKeyTime(char *r, unsigned short node, unsigned short key)
{
	char *na;
	if (I3mRoot__CheckIdString(r) != 0) return 0.0f;
	if (node >= *(unsigned short *)(r + 0x14)) return 0.0f;
	na = (char *)(node * 12 + *(int *)(r + 0x1C));
	if (key >= *(unsigned short *)(na + 6)) return 0.0f;
	return (*(float **)(r + 0x24))[(*(unsigned short **)(na + 8))[*(unsigned short *)(r + 0x12) * key]];
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3m", I3mRoot__GetKeyTimeTable);
