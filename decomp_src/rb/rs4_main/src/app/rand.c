/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
 /* extern */
void consPrintf(const char *, ...);
unsigned long long copGetSeed(void);
void copSetSeed(unsigned long long);
float copRand(float);
float copRandS(float);
extern int l_uTick;

extern unsigned long long l_au64RandSeed[];

extern unsigned long long l_au64RandSeed[];

extern unsigned long long l_aau64SavedRandSeed[][5];

extern unsigned long long l_aau64SavedRandSeed[][5];

void randInit(void)
{
	int i;
	for (i = 0; i < 5; i++) {
		copRand(0.0f);
		l_au64RandSeed[i] = copGetSeed();
		l_aau64SavedRandSeed[0][i] = l_au64RandSeed[i];
		l_aau64SavedRandSeed[1][i] = l_au64RandSeed[i];
	}
	l_uTick = 0;
}

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

float randU(int i, float r)
{
	if (i < 5) {
		unsigned long long save = copGetSeed();
		copSetSeed(l_au64RandSeed[i]);
		r = copRand(r);
		l_au64RandSeed[i] = copGetSeed();
		copSetSeed(save);
		return r;
	}
	return 0.0f;
}

float randS(int i, float r)
{
	if (i < 5) {
		unsigned long long save = copGetSeed();
		copSetSeed(l_au64RandSeed[i]);
		r = copRandS(r);
		l_au64RandSeed[i] = copGetSeed();
		copSetSeed(save);
		return r;
	}
	return 0.0f;
}

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

int sceWlanGetEtherAddr(unsigned char *);
void randSetSeedByMacAddr(int i)
{
	unsigned char mac[8];
	unsigned long long seed = -1;
	int ret = sceWlanGetEtherAddr(mac);
	if (ret < 0) {
		consPrintf("%s : sceWlanGetEtherAddr error\n", __FUNCTION__);
		seed = ret;
	} else
		__builtin_memcpy(&seed, mac, 8);
	randSetSeed(i, seed);
}
