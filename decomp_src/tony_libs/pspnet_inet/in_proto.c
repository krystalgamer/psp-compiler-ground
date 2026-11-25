/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

const char D_0002DB14[] = "internet";

extern int D_0002E794, D_0002E798, D_0002E79C, D_0002E7A0, D_0002E7A4, D_0002E7A8;
extern char D_0002F648[];

void
func_00014824(void)
{
	D_0002E794 = 0x125;
	D_0002E798 = 0x280F;
	D_0002E79C = 0x69;
	memset(D_0002F648, 0, 0x928);
	D_0002E7A0 = 1;
	D_0002E7A8 = D_0002E7A4 = 100;
}
