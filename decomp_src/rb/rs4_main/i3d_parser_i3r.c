/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"


int strcmp(const char *, const char *);
int I3dSearchName(char **tbl, unsigned int n, char *name)
{
	unsigned int i;
	for (i = 0; i < n; i++) {
		if (strcmp(tbl[i], name) == 0)
			return i;
	}
	return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int strcmp(const char *a, const char *b);
int I3rRoot__CheckIdString(signed char *arg0) {
    int var_a0;

    var_a0 = 0;
    if ((strcmp(arg0, "I3D_BIN") != 0) || (__builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0x14), 0x18, 7) != 0x52)) {
        var_a0 = 3;
    }
    return var_a0;
}

int I3dHierarchy__RecursivePack();
int I3dHierarchy__RecursiveUnpack();
int I3rRoot__MakePresetPacket();
int I3rRoot__ClearPresetPacket();
int I3rRoot__PackSub(char *r, int mode)
{
	int ret;
	if (I3rRoot__CheckIdString(r) != 0) return 3;
	if (*(int *)(r + 8) != 0x100001) return 4;
	if (*(int *)(r + 0xC) == mode) return 0;
	switch (mode) {
	case 0:
		I3rRoot__ClearPresetPacket(r);
		I3dHierarchy__RecursivePack(r + 0x10, r + 0x10);
		*(int *)(r + 0xC) = 0;
		break;
	case 1:
		ret = I3dHierarchy__RecursiveUnpack(r + 0x10, r + 0x10);
		if (ret != 0) return ret;
		*(int *)(r + 0xC) = 1;
		I3rRoot__MakePresetPacket(r);
		break;
	}
	return 0;
}

int I3rRoot__PackSub();
int I3rRoot__Unpack(void *r)
{
	I3rRoot__PackSub(r, 1);
	return 0;
}

int I3rRoot__PackSub();
int I3rRoot__Pack(void *r)
{
	I3rRoot__PackSub(r, 0);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__Get_nNode(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), int *, 0x34), 0, 0x18);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__GetNodeName);

int I3dSearchName();
int I3rRoot__GetNodeIndexByName(char *r, char *name)
{
	char *h = *(char **)(r + 0x10);
	int i = I3dSearchName(*(void **)(h + 0x20), *(unsigned short *)(h + 0x2E), name);
	if (i < 0)
		return -1;
	return (*(unsigned short **)(h + 0x1C))[i];
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3rRoot__Get_nTex(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), unsigned short *, 0x2C);
}

int I3rRoot__GetTexName(char *r, int i)
{
	return (*(int **)(*(char **)(r + 0x10) + 0x18))[i];
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rRoot__GetTexIndexByName(void *arg0, int arg1) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    I3dSearchName(M2C_FIELD(temp_v0, int *, 0x18), M2C_FIELD(temp_v0, unsigned short *, 0x2C), arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__CalcTotalStrip(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__GetLocalBasicTransformA(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x10) + (arg1 << 6);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__GetModelBasicTransformA(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x14) + (arg1 << 6);
}

