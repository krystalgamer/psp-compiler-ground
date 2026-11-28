/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3s", I3sRoot__PackSub);

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
