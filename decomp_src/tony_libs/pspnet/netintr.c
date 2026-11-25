/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/netintr", func_000016BC);

int func_00001A00(int prio, int stack)
{
	int ret;

	D_0000ABF8 = 0;
	ret = sceKernelCreateEventFlag("SceNetNetintr", 0, 0, 0);
	if (ret < 0)
		goto fail;
	D_0000A090 = ret;
	ret = sceKernelCreateThread("SceNetNetintr", func_000016BC, prio, stack, 0, 0);
	if (ret < 0)
		goto fail;
	D_0000ABFC = ret;
	ret = sceKernelStartThread(ret, 0, 0);
	if (ret < 0)
		goto fail;
	sceNetIfhandleInit(D_0000A090);
	return 0;
fail:
	if (D_0000ABFC >= 0) {
		sceKernelTerminateThread(D_0000ABFC);
		sceKernelDeleteThread(D_0000ABFC);
	}
	D_0000ABFC = -1;
	if (D_0000A090 >= 0)
		sceKernelDeleteEventFlag(D_0000A090);
	D_0000A090 = -1;
	sceNetIfhandleTerm();
	return ret;
}

void _sce_pspnet_schednetintr(int isr)
{
	D_0000ABF8 |= 1 << isr;
}

void _sce_pspnet_schednetintr_with_evf(int isr)
{
	D_0000ABF8 |= 1 << isr;
	sceKernelSetEventFlag(D_0000A090, 0x10);
}

void func_00001B7C(void)
{
	if (D_0000ABFC >= 0) {
		sceKernelTerminateThread(D_0000ABFC);
		sceKernelDeleteThread(D_0000ABFC);
	}
	D_0000ABFC = -1;
	if (D_0000A090 >= 0)
		sceKernelDeleteEventFlag(D_0000A090);
	D_0000A090 = -1;
	sceNetIfhandleTerm();
}

int _sce_pspnet_start_of_inet_module_in_netintr(void (*ipintr)(void), void (*arpintr)(void))
{
	D_0000ABE0 = ipintr;
	D_0000ABE4 = arpintr;
	D_0000ABD0 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_netintr(void)
{
	D_0000ABD0 = 0;
	D_0000ABE0 = NULL;
	D_0000ABE4 = NULL;
	return 0;
}

int _sce_pspnet_start_of_ipv6_module_in_netintr(void (*f)(void))
{
	D_0000ABE8 = f;
	D_0000ABD4 = 1;
	return 0;
}

int _sce_pspnet_stop_of_ipv6_module_in_netintr(void)
{
	D_0000ABD4 = 0;
	D_0000ABE8 = NULL;
	return 0;
}

int _sce_pspnet_start_of_pppoe_module_in_netintr(void (*f)(void))
{
	D_0000ABEC = f;
	D_0000ABD8 = 1;
	return 0;
}

int _sce_pspnet_stop_of_pppoe_module_in_netintr(void)
{
	D_0000ABD8 = 0;
	D_0000ABEC = NULL;
	return 0;
}

int _sce_pspnet_start_of_adhoc_module_in_netintr(void (*f)(void), void (*g)(struct ifnet *))
{
	D_0000ABF0 = f;
	D_0000ABF4 = g;
	D_0000ABDC = 1;
	return 0;
}

int _sce_pspnet_stop_of_adhoc_module_in_netintr(void)
{
	D_0000ABDC = 0;
	D_0000ABF0 = NULL;
	D_0000ABF4 = NULL;
	return 0;
}
