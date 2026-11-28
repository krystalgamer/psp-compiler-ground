/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int strcmp(const char *a, const char *b);
int I3cRoot__CheckIdString(signed char *arg0) {
    return (strcmp(arg0, "I3D_I3C") == 0) ? 0 : 3;
}


typedef struct { unsigned short num; short p2; int p4; unsigned int child; } I3cNodeP;
void UnpackNode_(I3cNodeP *node, unsigned int base)
{
	unsigned int c = node->child;
	int n = node->num;
	if (c < base) {
		if (c == 0xFFFFFFFF) {
			node->child = 0;
			c = 0;
		}
		if (c != 0)
			node->child = c + base;
	}
	if (n != 0 && !(n & 0x8000)) {
		I3cNodeP *ch = (I3cNodeP *)node->child;
		int i;
		for (i = 0; i < n; i++)
			UnpackNode_(&ch[i], base);
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", PackNode_);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__Unpack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3c", I3cRoot__Pack);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3cRoot__Get_nNode(void *arg0) {
    return M2C_FIELD(arg0, unsigned short *, 0x14);
}

void *I3cRoot__GetNodeName(char *r, unsigned short i)
{
	if (i < *(unsigned short *)(r + 0x14))
		return *(void **)(*(char **)(r + 0x18) + i * 12);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3cRoot__Get_nGroup(void *arg0) {
    return M2C_FIELD(arg0, unsigned short *, 0x16);
}

void *I3cRoot__GetGroupName(char *r, unsigned short i)
{
	if (i < *(unsigned short *)(r + 0x16))
		return (*(void ***)(r + 0x1C))[i];
	return 0;
}

int strcmp(const char *, const char *);
int I3cRoot__GetNodeIndexByName(char *r, char *name)
{
	int n = *(unsigned short *)(r + 0x14);
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, *(char **)(*(char **)(r + 0x18) + i * 12)) == 0)
			return i;
	}
	return -1;
}

int strcmp(const char *, const char *);
int I3cRoot__GetGroupIndexByName(char *r, char *name)
{
	int n = *(unsigned short *)(r + 0x16);
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, (*(char ***)(r + 0x1C))[i]) == 0)
			return i;
	}
	return -1;
}

unsigned short I3cRoot__GetNodeEnable(char *r, unsigned short i)
{
	if (i < *(unsigned short *)(r + 0x14))
		return *(unsigned short *)(*(char **)(r + 0x18) + i * 12 + 6);
	return 0xFFFF;
}

unsigned short I3cRoot__SetNodeEnable(char *r, unsigned short idx, unsigned short en)
{
	char *n;
	int old;
	if (idx >= *(unsigned short *)(r + 0x14))
		return 0xFFFF;
	n = (char *)(idx * 12 + *(int *)(r + 0x18));
	old = *(unsigned short *)(n + 6);
	*(unsigned short *)(n + 6) = en;
	return old;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3cRoot__GetBothFaceEnable(void *arg0) {
    return M2C_FIELD(arg0, unsigned char *, 0x12) == 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3cRoot__SetBothFaceEnable(void *arg0, int arg1) {
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, unsigned char *, 0x12) == 1;
    M2C_FIELD(arg0, unsigned char *, 0x12) = (unsigned char) ((arg1 & 0xFF) != 0);
    return temp_v0;
}
