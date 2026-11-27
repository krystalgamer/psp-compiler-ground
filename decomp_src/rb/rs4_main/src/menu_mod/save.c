/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
   /* extern */

M2C_UNK taskDefaultMsg();
void taskKill();

void menuSaveTask(void) {
    taskDefaultMsg();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/save", GameAnmInit);

void GameAnmTerm(int a, int *p)
{
	if (p) {
		int t = *p;
		*p = 0;
		if (t)
			taskKill(t, 0, 0);
	}
}
