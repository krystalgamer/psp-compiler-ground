/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

int I3sRoot__CheckIdString(char *r);
int I3dHierarchy__RecursivePack();
int I3dHierarchy__RecursiveUnpack();
int I3sRoot__PackSub(char *r, int mode)
{
	if (I3sRoot__CheckIdString(r) != 0) return 3;
	if (*(int *)(r + 8) != 0x100001) return 4;
	if (*(int *)(r + 0xC) == mode) return 0;
	switch (mode) {
	case 0:
		I3dHierarchy__RecursivePack(r + 0x10, r + 0x10);
		*(int *)(r + 0xC) = 0;
		break;
	case 1:
		I3dHierarchy__RecursiveUnpack(r + 0x10, r + 0x10);
		*(int *)(r + 0xC) = 1;
		break;
	}
	return 0;
}

int I3sRoot__PackSub();
int I3sRoot__Unpack(void *r)
{
	I3sRoot__PackSub(r, 1);
	return 0;
}

int I3sRoot__PackSub();
int I3sRoot__Pack(void *r)
{
	I3sRoot__PackSub(r, 0);
	return 0;
}
