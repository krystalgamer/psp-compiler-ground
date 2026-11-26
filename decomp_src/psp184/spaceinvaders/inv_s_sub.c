/* cflags: -O2 */
#include "common.h"

void Sys_AssertMes(void *a, int b, void *c, void *d);
void Sys_Assert(void *a, int b, void *c)
{
	Sys_AssertMes(a, b, c, 0);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sub", Sys_AssertMes);
