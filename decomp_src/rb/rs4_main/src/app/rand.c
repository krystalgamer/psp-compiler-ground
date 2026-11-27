/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
 /* extern */
void consPrintf(const char *, ...);
extern int l_uTick;

extern unsigned long long l_au64RandSeed[];

extern unsigned long long l_au64RandSeed[];

extern unsigned long long l_aau64SavedRandSeed[][5];

extern unsigned long long l_aau64SavedRandSeed[][5];

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/rand", randInit);

void randDumpSeed(int i)
{
	if (i < 5)
		consPrintf("%s : Tick=%08x Ch=%d %0qx\n", __FUNCTION__, l_uTick, i, l_au64RandSeed[i]);
}

void randDumpSeedAll(void)
{
	int i;
	for (i = 0; i < 5; i++) {
		randDumpSeed(i);
	}
}

void randSetSeed(int i, unsigned long long seed)
{
	if (i < 5) {
		l_au64RandSeed[i] = seed;
	}
	randDumpSeed(i);
}

unsigned long long randGetSeed(int i)
{
	if (i < 5)
		return l_au64RandSeed[i];
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/rand", randU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/rand", randS);

void randSave(int slot)
{
	int i;
	for (i = 0; i < 5; i++) {
		l_aau64SavedRandSeed[slot][i] = l_au64RandSeed[i];
	}
	l_uTick++;
}

void randLoad(int slot)
{
	int i;
	for (i = 0; i < 5; i++) {
		l_au64RandSeed[i] = l_aau64SavedRandSeed[slot][i];
	}
}

int randGetTick(void) {
    return l_uTick;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/rand", randSetSeedByMacAddr);
