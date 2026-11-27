/* cflags: -Os */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/save", GameAnmInit);

void taskKill();
void GameAnmTerm(int a, int *p)
{
	if (p) {
		int t = *p;
		*p = 0;
		if (t)
			taskKill(t, 0, 0);
	}
}
