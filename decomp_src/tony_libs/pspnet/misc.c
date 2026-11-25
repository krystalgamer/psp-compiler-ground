/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"
/* --- end declarations --- */

int func_000079DC(void)
{
	return 0;
}

int func_000079E4(void)
{
	return 0;
}

int sceNetGetSystemClockSec(void)
{
	SceKernelSysClock clk;
	int sec, usec;

	sceKernelGetSystemTime(&clk);
	sceKernelSysClock2USec(&clk, &sec, &usec);
	return sec;
}

int func_00007A1C(char c)
{
	int r;

	if ((unsigned char)(c - '0') < 10)
		r = c - '0';
	else if ((unsigned int)(c - 'A') < 26)
		r = c - 'A' + 10;
	else if ((unsigned int)(c - 'a') < 26)
		r = c - 'a' + 10;
	else
		r = 9999999;
	return r;
}

void sceNetEtherNtostr(const unsigned char *mac, char *str)
{
	sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/misc", sceNetEtherStrton);

int sceNetGetMallocStat(void *stat)
{
	return sceNetIfhandle_lib_4C2886CB(stat);
}

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}
