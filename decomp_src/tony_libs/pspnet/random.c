/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

void func_00007798(unsigned int seed)
{
	int i, j;
	unsigned int u;

	u = 0;
	for (i = 0; i <= 16; i++) {
		for (j = 0; j < 32; j++) {
			seed = seed * 1566083941UL + 1;
			u = (u >> 1) | (seed & (1UL << 31));
		}
		D_0000B0B4[i] = u;
	}
	D_0000B0B4[16] = (D_0000B0B4[16] << 23) ^ (D_0000B0B4[0] >> 9) ^ D_0000B0B4[15];
	for (i = 17; i <= 520; i++)
		D_0000B0B4[i] = (D_0000B0B4[i - 17] << 23) ^ (D_0000B0B4[i - 16] >> 9) ^ D_0000B0B4[i - 1];
	rnd521_refresh();
	rnd521_refresh();
	rnd521_refresh();
	D_0000B8D8 = 520;
}

unsigned int sceNetRand(void)
{
	if (++D_0000B8D8 >= 521) {
		rnd521_refresh();
		D_0000B8D8 = 0;
	}
	return D_0000B0B4[D_0000B8D8];
}
