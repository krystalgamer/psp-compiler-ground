#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <thread.h>
#include <pspnet.h>
#include <pspnet_apctl.h>
#include <pspnet_ap_dialog_dummy.h>
#include <utility/utility_netparam.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aosstype.h"
#include "wlla.h"
#include "aoss.h"

extern volatile int scan_flag;
/* static int handler_id; network.c has a global of the same name */
extern int handler_id_218800;
#define handler_id handler_id_218800
extern AOSS_STAT aoss_stat;
extern int isconnect;
extern WLLA_BSS_LIST *pListOld;
extern struct SceNetApDialogDummyParam ap_dialog_dummy_param;

/* the asm of localConnect calls localSetNetParam by splat's unique name */
#define localSetNetParam localSetNetParam_E7974

static int localConnect(void);
static WLLA_BSS_LIST *CopyBSSList(WLLA_BSS_LIST *pSrc);

static void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg)
{
	if (prev_state == 1 && new_state == 0 && event == 2)
		scan_flag = 1;
	if (event == 6)
		scan_flag = -1;
}

static int localSetNetParam(int code, union SceUtilityNetParamEntry *entry)
{
	int ret;

	ret = sceUtilitySetNetParam(code, entry);
	if (ret < 0)
		printf("sceUtilitySetNetParam Error:%x : %x\n", code, ret);
	return ret;
}

#ifdef NON_MATCHING
/* Close: the state wait loop is 8 bytes shorter. */
static int localConnect(void)
{
	int ret;
	union SceNetApctlInfo apctl_info;
	int state;
	union SceUtilityNetParamEntry entry;
	struct SceNetApDialogDummyParam *pParam;

	pParam = &ap_dialog_dummy_param;
	memcpy(entry.ssid, pParam->ssid, 32);
	localSetNetParam(1, &entry);
	entry.auth_proto = pParam->auth_proto;
	localSetNetParam(2, &entry);
	memcpy(entry.wep_key, pParam->wep_key, 13);
	localSetNetParam(3, &entry);
	entry.how_to_set_ip = pParam->how_to_set_ip;
	localSetNetParam(4, &entry);
	memcpy(entry.ip_address, pParam->ip_opt.static_ip.ip_address, 16);
	localSetNetParam(5, &entry);
	memcpy(entry.netmask, pParam->ip_opt.static_ip.netmask, 16);
	localSetNetParam(6, &entry);
	memcpy(entry.default_route, pParam->ip_opt.static_ip.default_route, 16);
	localSetNetParam(7, &entry);
	entry.dns_flag = 0;
	localSetNetParam(8, &entry);
	entry.http_proxy_flag = 0;
	localSetNetParam(13, &entry);
	ret = sceNetApctlConnect(0);
	if (ret < 0) {
		if (ret == 0x80410d0c)
			puts("Wireless LAN switch has been turned off.");
		printf("sceNetApctlConnect() failed. %x\n", ret);
		return -1;
	}
	while (1) {
		sceKernelDelayThread(1000000);
		if (sceNetApctlGetState(&state) != 0)
			continue;
		if (state == 4 || state == 0)
			break;
	}
	if (state == 0) {
		puts("failed to Join or Get IP addr.");
		return -1;
	}
	puts("obtained Infomation");
	if (sceNetApctlGetInfo(3, &apctl_info) >= 0) {
		int len = apctl_info.ssidlen;
		char ssid[33];

		if (sceNetApctlGetInfo(2, &apctl_info) >= 0) {
			memcpy(ssid, apctl_info.ssid, len);
			ssid[len] = 0;
			printf(" SSID   : '%s'\n", ssid);
		}
	}
	if (sceNetApctlGetInfo(4, &apctl_info) >= 0)
		printf(" AUTH   : %d\n", apctl_info.auth_proto);
	if (sceNetApctlGetInfo(8, &apctl_info) >= 0)
		printf(" IP addr: %s\n", apctl_info.ip_address);
	if (sceNetApctlGetInfo(9, &apctl_info) >= 0)
		printf(" Netmask: %s\n", apctl_info.netmask);
	if (sceNetApctlGetInfo(10, &apctl_info) >= 0)
		printf(" Gateway: %s\n", apctl_info.default_route);
	isconnect = 1;
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", localConnect);
#endif

static int localDisconnect(void)
{
	int apctl_state;
	int ret;

	ret = sceNetApctlDisconnect();
	if (ret < 0) {
		puts("sceNetApctlDisconnect() failed.");
		return -1;
	}
	while (sceNetApctlGetState(&apctl_state) != 0 || apctl_state != 0)
		sceKernelDelayThread(1000000);
	isconnect = 0;
	return 0;
}

#ifdef NON_MATCHING
/* Matches, but shares its "Memory full" string with AOSS_WLANGetBSSList,
   whose asm refers to it by label: asm until that one is decompiled. */
static WLLA_BSS_LIST *CopyBSSList(WLLA_BSS_LIST *pSrc)
{
	WLLA_BSS_LIST *pDst;
	int nCount;
	int i;

	if (pSrc == NULL)
		return NULL;
	nCount = pSrc->Num;
	pDst = malloc(nCount * sizeof(WLLA_BSS_INFO) + 4);
	if (pDst == NULL) {
		puts("Memory full");
		return NULL;
	}
	pDst->Num = nCount;
	for (i = 0; i < nCount; i++)
		memcpy(&pDst->BssInfo[i], &pSrc->BssInfo[i], sizeof(WLLA_BSS_INFO));
	return pDst;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", CopyBSSList);
#endif

#ifndef NON_MATCHING
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_00140EB4);
#endif

#ifdef NON_MATCHING
/* Draft: the control flow around the retries and errors differs. */
INT AOSS_WLANGetBSSList(WLLA_BSS_LIST **bssList)
{
	INT result;
	int nCount;
	int i;
	int ret;
	int buflen;
	union SceNetApctlBSSDescEntry bssdesc;
	struct SceNetApctlBSSDescID *bssid;
	struct SceNetApctlBSSDescID *p;
	int len;
	WLLA_BSS_LIST *pList;
	WLLA_BSS_INFO *pInfo;
	int retryCount;
	int oldconnect;

	result = -1;
	bssid = NULL;
	puts("AOSS_WLANGetBSSList");
	*bssList = NULL;
	oldconnect = isconnect;
	if (oldconnect)
		localDisconnect();
	retryCount = 3;
	while (1) {
		if (retryCount-- <= 0) {
			puts("AOSS_WLANGetBSSList Error!");
			goto end;
		}
		scan_flag = 0;
		ret = sceNetApctlScanUser();
		if (ret < 0) {
			printf("sceNetApctlScanUser: %08x\n", ret);
			continue;
		}
		for (i = 0; i < 600; i++) {
			if (scan_flag != 0)
				break;
			sceKernelDelayThread(100000);
		}
		if (scan_flag < 0)
			continue;
		buflen = 0;
		ret = sceNetApctlGetBSSDescIDListUser(&buflen, NULL);
		if (ret < 0) {
			printf("sceNetApctlGetBSSDescIDListUser 1: %08x\n", ret);
			continue;
		}
		if (buflen > 0)
			break;
	}
	bssid = malloc(buflen + 16);
	if (bssid == NULL) {
		puts("Memory full");
		goto end;
	}
	ret = sceNetApctlGetBSSDescIDListUser(&buflen, bssid);
	if (ret < 0) {
		printf("sceNetApctlGetBSSDescIDListUser 2: %08x\n", ret);
		goto end;
	}
	nCount = 0;
	for (p = bssid; p != NULL; p = p->next)
		nCount++;
	pList = malloc(nCount * sizeof(WLLA_BSS_INFO) + 4);
	if (pList == NULL) {
		puts("Memory full");
		goto end;
	}
	pList->Num = 0;
	for (i = 0; i < nCount; i++)
		memset(&pList->BssInfo[i], 0, sizeof(WLLA_BSS_INFO));
	printf(" nCount:%d\n", nCount);
	pInfo = pList->BssInfo;
	for (p = bssid; p != NULL; p = p->next) {
		ret = sceNetApctlGetBSSDescEntryUser(p->bssdesc_id, 1, &bssdesc);
		if (ret < 0)
			goto entry_error;
		printf(" SSID:'%s' ", bssdesc.ssid);
		len = strlen(bssdesc.ssid);
		if (len > 32)
			len = 32;
		pInfo->Ssid.Len = len;
		memcpy(pInfo->Ssid.Ssid, bssdesc.ssid, len);
		ret = sceNetApctlGetBSSDescEntryUser(p->bssdesc_id, 3, &bssdesc);
		if (ret < 0)
			goto entry_error;
		pInfo->Channel = bssdesc.channel;
		pInfo->Noise = -1;
		pInfo->Signal = -1;
		ret = sceNetApctlGetBSSDescEntryUser(p->bssdesc_id, 0, &bssdesc);
		if (ret < 0)
			goto entry_error;
		printf(" BSSID:'%s'\n", bssdesc.bssid);
		len = strlen(bssdesc.bssid);
		if (len > 5)
			len = 5;
		strncpy(pInfo->Bssid, bssdesc.bssid, len);
		pInfo->BeaconPeriod = -1;
		pInfo->Capability = 3;
		pInfo->SupportRates.Num = -1;
		pInfo++;
		pList->Num++;
	}
	*bssList = pList;
	goto done;
entry_error:
	printf("sceNetApctlGetBSSDescEntryUser: %08x\n", ret);
	*bssList = pList;
done:
	if (pListOld) {
		free(pListOld);
		pListOld = NULL;
	}
	pListOld = CopyBSSList(pList);
	result = 0;
end:
	localDisconnect();
	if (bssid)
		free(bssid);
	printf(" result:%d\n", result);
	if (oldconnect) {
		puts("try to reconect");
		sceKernelDelayThread(1000000);
		localConnect();
	}
	return result;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", AOSS_WLANGetBSSList);
#endif

INT AOSS_WLANConnect(WLLA_CONNECT_PARAM *conParam, WLLA_LINK_STAT *linkStat)
{
	struct SceNetApDialogDummyParam *pParam;
	WLLA_BSS_INFO *pInfo;
	int len;

	pParam = &ap_dialog_dummy_param;
	puts("AOSS_WLANConnect");
	len = conParam->Ssid.Len;
	if (len > 32) {
		printf("SSID is too long! %d(max:%d)\n", len, 32);
		return -1;
	}
	memcpy(pParam->ssid, conParam->Ssid.Ssid, len);
	pParam->ssid[len] = 0;
	if (conParam->AuthAlgo == 0) {
		pParam->auth_proto = 0;
	} else {
		len = conParam->Key.Len;
		if (len > 13) {
			printf("WEP Key is too long! %ld(max:%d) \n", len, 13);
			return -1;
		}
		if (len < 6)
			pParam->auth_proto = 1;
		else
			pParam->auth_proto = 2;
		memcpy(pParam->wep_key, conParam->Key.Key, len);
	}
	linkStat->LinkStat = 1;
	pInfo = &linkStat->BssInfo;
	len = strlen(pParam->ssid);
	pInfo->Ssid.Len = strlen(pParam->ssid);
	memcpy(pInfo->Ssid.Ssid, pParam->ssid, len);
	pInfo->Channel = -1;
	pInfo->Noise = -1;
	pInfo->Signal = -1;
	pInfo->Bssid[0] = 0;
	pInfo->SupportRates.Num = -1;
	pInfo->BeaconPeriod = -1;
	pInfo->Capability = 3;
	return 0;
}

static void SetIPString(char *p, UINT32 ip)
{
	sprintf(p, "%lu.%lu.%lu.%lu", ip >> 24, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
}

static void PrintIPString(UINT32 ip)
{
	printf("%lu.%lu.%lu.%lu", ip >> 24, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
}

INT AOSS_SetIPAddr(UINT32 ip, UINT32 sm, UINT32 gw)
{
	struct SceNetApDialogDummyParam *pParam;
	int retryCount;
	int result;

	printf("AOSS_SetIPAddr: ");
	PrintIPString(ip);
	printf(", ");
	PrintIPString(sm);
	printf(", ");
	PrintIPString(gw);
	putchar('\n');
	pParam = &ap_dialog_dummy_param;
	if (ip == 0) {
		pParam->how_to_set_ip = 0;
	} else {
		pParam->how_to_set_ip = 1;
		SetIPString(pParam->ip_opt.static_ip.ip_address, ip);
		SetIPString(pParam->ip_opt.static_ip.netmask, sm);
		SetIPString(pParam->ip_opt.static_ip.default_route, gw);
	}
	if (isconnect)
		localDisconnect();
	result = -1;
	retryCount = 3;
	for (;;) {
		if (retryCount-- <= 0)
			break;
		if (localConnect() >= 0) {
			result = 0;
			break;
		}
		sceKernelDelayThread(1000000);
	}
	return result;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_00141050);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_00141064);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_00141078);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_0014108C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_001410A0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_001410B4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspsp/aosspsp", D_001410C8);

/* AOSS_Status's "static char *statstr[7]" (pointing at the strings above),
   kept in the asm .data for now */
extern char *D_00218804[7];

INT AOSS_Status(AOSS_STAT stat)
{
	aoss_stat = stat;
	printf("AOSS_Status:%d (%s)\n", stat, D_00218804[stat]);
	return 0;
}

void AOSS_Sleep(UINT32 time)
{
	UINT32 curtime;

	printf("AOSS_Sleep:%lu\n", time);
	while (time != 0) {
		curtime = 0x20c45a;
		if (time < curtime)
			curtime = time;
		sceKernelDelayThread(curtime * 1000);
		time -= curtime;
	}
}

INT AOSS_PSP_Init(void)
{
	int ret;

	aoss_stat = 0;
	memset(&ap_dialog_dummy_param, 0, sizeof(ap_dialog_dummy_param));
	ret = sceNetApctlAddHandler(apctl_handler, NULL);
	if (ret < 0) {
		puts("sceNetApctlAddHandler() failed.");
		return -1;
	}
	handler_id = ret;
	return 0;
}

INT AOSS_PSP_GetStatus(void)
{
	return aoss_stat;
}

void AOSS_PSP_Term(void)
{
	sceNetFreeThreadinfo(sceKernelGetThreadId());
	localDisconnect();
	if (handler_id >= 0) {
		sceNetApctlDelHandler(handler_id);
		handler_id = -1;
	}
	if (pListOld) {
		free(pListOld);
		pListOld = NULL;
	}
}
