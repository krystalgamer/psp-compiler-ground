#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <thread.h>
#include <pspnet.h>
#include <pspnet_inet.h>
#include <pspnet_resolver.h>
#include <pspnet_apctl.h>
#include <pspnet_ap_dialog_dummy.h>
#include <utility/utility_netconf.h>
#include <libssl.h>
#include <libhttp.h>
#include <libgu.h>
#include <displaysvc.h>
#include <stdio.h>
#include <string.h>
#include "pspBrowser.h"
#include "main.h"

extern SceUtilityNetconfParam netconfParam;
extern struct SceNetApDialogDummyStateInfo ap_dialog_dummy_state;
extern SceUtilityNetconfAdhocParam netconfAdhocParam;
extern int handler_id;
extern int _netInitState;

void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg)
{
	if (prev_state == 4 && new_state == 0 && event == 6)
		printf("Apctl error happened, error = 0x%x\n", error_code);
}

#ifdef NON_MATCHING
/* Close: only the scheduling of the netconfParam/netconfAdhocParam
   stores differs. */
int pspNetworkInit(void)
{
	int ret;
	int handler_id;
	struct SceNetApDialogDummyStateInfo ap_dialog_dummy_state;
	union SceNetApctlInfo apctl_info;
	int state;
	int i;

	puts("sceNetInit");
	ret = sceNetInit(0x20000, 0x20, 0x1000, 0x20, 0x1000);
	if (ret < 0) {
		puts("sceNetInit() failed.");
		return -1;
	}
	_netInitState |= 0x1;
	ret = sceNetInetInit();
	if (ret < 0) {
		puts("sceNetInetInit() failed.");
		return -1;
	}
	_netInitState |= 0x2;
	ret = sceNetResolverInit();
	if (ret < 0) {
		puts("sceNetResolverInit() failed.");
		return -1;
	}
	_netInitState |= 0x4;
	ret = sceNetApctlInit(0x1000, 0x42);
	if (ret < 0) {
		puts("sceNetApctlInit() failed.");
		return -1;
	}
	_netInitState |= 0x8;
	handler_id = sceNetApctlAddHandler(apctl_handler, NULL);
	if (handler_id < 0) {
		puts("sceNetApctlAddHandler() failed.");
		return -1;
	}
	_netInitState |= 0x10;

	i = 0;
	NetconfMgrInit();
	netconfParam.base.size = sizeof(netconfParam);
	netconfParam.base.main_thread_priority = 0x11;
	netconfParam.base.sub_thread_priority = 0x13;
	netconfParam.base.font_thread_priority = 0x12;
	netconfParam.base.sound_thread_priority = 0x10;
	netconfParam.adhoc_param = &netconfAdhocParam;
	netconfParam.base.message_lang = 0;
	netconfParam.base.result = 0;
	netconfParam.base.reserved1 = 0;
	netconfParam.base.reserved2 = 0;
	netconfParam.base.reserved3 = 0;
	netconfParam.base.reserved4 = 0;
	netconfParam.base.ctrl_assign = 0;
	netconfParam.type = 0;
	netconfAdhocParam.group_name[0] = 0;
	netconfAdhocParam.group_name[1] = 0;
	netconfAdhocParam.group_name[2] = 0;
	netconfAdhocParam.group_name[3] = 0;
	netconfAdhocParam.group_name[4] = 0;
	netconfAdhocParam.group_name[5] = 0;
	netconfAdhocParam.group_name[6] = 0;
	netconfAdhocParam.group_name[7] = 0;
	ret = NetconfInitStart(&netconfParam);
	if (ret != 0)
		printf("sceUtilityNetconfInitStart failed - %d\n", ret);
	do {
		gCls();
		sceGuFinish();
		state = NetconfGetStatus();
		switch (state) {
		case 0:
			return -1;
		case 1:
			break;
		case 2:
			ret = NetconfUpdate(1);
			if (ret != 0) {
				printf("sceUtilityNetconfUpdate failed - %d\n", ret);
				return -1;
			}
			break;
		case 3:
			ret = NetconfShutdownStart();
			i = 1;
			if (ret != 0) {
				printf("sceUtilityNetconfShutdownStart failed - %d\n", ret);
				return -1;
			}
			break;
		case 4:
			break;
		}
		sceGuSync(0, 0);
		sceDisplayWaitVblankStartCB();
		sceGuSwapBuffers();
		if (_cPspBrowserExit)
			return -1;
	} while (i == 0);

	ret = sceNetApctlGetInfo(8, &apctl_info);
	if (ret < 0) {
		puts("sceNetApctlGetInfo() failed. ");
		return -1;
	}
	printf("obtained IP addr: %s\n", apctl_info.ip_address);
	ret = sceSslInit(0x25800);
	if (ret < 0) {
		puts("sceSslInit() failed. ");
		return -1;
	}
	_netInitState |= 0x20;
	ret = sceHttpInit(0xA000);
	if (ret != 0) {
		puts("sceHttpInit() failed. ");
		return -1;
	}
	_netInitState |= 0x40;
	ret = sceHttpsInitWithPath(0, 0, 0);
	if (ret < 0) {
		puts("sceHttpsInitWithPath() failed. ");
		return -1;
	}
	_netInitState |= 0x80;
	ret = sceHttpsLoadDefaultCert(0, 0);
	if (ret < 0) {
		puts("sceHttpsLoadDefaultCert() failed. ");
		return -1;
	}
	ret = sceHttpInitCache(0);
	if (ret < 0) {
		puts("sceHttpInitCache() failed. ");
		return -1;
	}
	_netInitState |= 0x100;
	sceHttpsDisableOption(1);
	return 0;
}

#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/network", pspNetworkInit);
#endif

void pspNetworkExit(void)
{
	int apctl_state;
	int ret;

	NetconfMgrTerm();
	if (_netInitState & 0x100) {
		sceHttpEndCache();
		_netInitState &= ~0x100;
	}
	if (_netInitState & 0x80) {
		sceHttpsEnd();
		_netInitState &= ~0x80;
	}
	if (_netInitState & 0x40) {
		sceHttpEnd();
		_netInitState &= ~0x40;
	}
	if (_netInitState & 0x20) {
		sceSslEnd();
		_netInitState &= ~0x20;
	}
	sceNetFreeThreadinfo(sceKernelGetThreadId());
	ret = sceNetApctlDisconnect();
	if (ret < 0) {
		puts("sceNetApctlDisconnect() failed.");
	} else {
		while (1) {
			ret = sceNetApctlGetState(&apctl_state);
			if (ret == 0 && apctl_state == 0)
				break;
			sceKernelDelayThread(1000000);
		}
	}
	if (handler_id >= 0) {
		sceNetApctlDelHandler(handler_id);
		handler_id = -1;
		_netInitState &= ~0x10;
	}
	if (_netInitState & 0x8) {
		sceNetApctlTerm();
		_netInitState &= ~0x8;
	}
	if (_netInitState & 0x4) {
		sceNetResolverTerm();
		_netInitState &= ~0x4;
	}
	if (_netInitState & 0x2) {
		sceNetInetTerm();
		_netInitState &= ~0x2;
	}
	if (_netInitState & 0x1) {
		sceNetTerm();
		_netInitState &= ~0x1;
	}
}
