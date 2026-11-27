/* cflags: -Os */
#include "common.h"

void GtCalcPoint()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"vtfm3.t C110.t,E000.t,C100.t\n"
		"vadd.t C110.t,C030.t,C110.t\n"
		"sv.q C110.q,0($6)\n"
		: : : "memory");
}
