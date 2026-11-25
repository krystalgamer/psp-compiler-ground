#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <thread.h>
#include <utility/utility_netconf.h>
#include <libgu.h>
#include <stdio.h>
#include <string.h>
#include "rxstate.h"
#include "menumgr.h"
#include "aosspsp/aosstype.h"
#include "aosspsp/wlla.h"
#include "aosspsp/aoss.h"

struct SceWlanEtherAddr {
	SceUChar8 addr[6];
	SceUChar8 reserved[2];
};
int sceWlanGetEtherAddr(struct SceWlanEtherAddr *addr);
INT AOSS_PSP_Init(void);
void AOSS_PSP_Term(void);
INT AOSS_Init(AOSS_INFO *info);
UINT32 AOSS_version(void);

/* the static data stays in the asm .data/.bss for now; names that other
   files also use are splat's unique ones */
extern AOSS_INFO aoss_info;
extern int gThreadId_1F83B4;
#define gThreadId gThreadId_1F83B4
extern volatile int g_AossIsBusy;
extern char g_PacketBuff_27C080[131072];
#define g_PacketBuff g_PacketBuff_27C080
extern TMenuMgr *curMenu_27BDC0;
#define curMenu curMenu_27BDC0
extern int g_State_27BDC4;
#define g_State g_State_27BDC4
extern rxStateMachine g_MoveState_27BDF4;
#define g_MoveState g_MoveState_27BDF4
extern SceUtilityNetconfParam *g_Param_27BDC8;
#define g_Param g_Param_27BDC8

/* the asm of AossNetconfUpdate calls these by splat's unique names */
#define DrawMenu DrawMenu_E5968
#define DumpChar DumpChar_E59B8

static void DrawMenu(void)
{
	sceGuStart(0, g_PacketBuff, sizeof(g_PacketBuff));
	if (curMenu)
		MenuMgrDraw(curMenu);
	sceGuFinish();
}

/* the menu tables' strings */
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001404CC);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001404E8);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140524);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140528);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140564);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140574);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140590);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001405AC);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001405D4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001405F4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140624);

static void DumpChar(char *p, int count)
{
	int i;

	for (i = 0; i < count; i++)
		printf("%02x ", (unsigned char)p[i]);
	putchar('\n');
}

/* AossThread's "static char *errstr[16]" strings; the table stays in the
   asm .data */
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140638);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140648);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140654);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140664);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_00140678);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_0014068C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001406A0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001406B4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001406C4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001406D8);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", D_001406E8);
extern char *D_001F841C[16];

static SceInt32 AossThread(SceSize args, ScePVoid argp)
{
	AOSS_INFO *pInfo;
	struct SceWlanEtherAddr addr;
	int ret;
	int i;

	pInfo = &aoss_info;
	memset(pInfo, 0, sizeof(AOSS_INFO));
	pInfo->aossResult = 15;
	pInfo->supportSecurity = 1;
	pInfo->productInfo.dataType = 0x50;
	strcpy(pInfo->productInfo.productName, "PSP AOSS");
	pInfo->productInfo.dataLen = strlen(pInfo->productInfo.productName) + 1;
	pInfo->retryCount_Scan = -1;
	pInfo->retryInterval_Scan = -1;
	pInfo->retryCount_Comu = -1;
	pInfo->retryInterval_Comu = -1;
	pInfo->selectInterval = -1;
	ret = sceWlanGetEtherAddr(&addr);
	if (ret < 0) {
		printf("*sceWlanGetEtherAddr Error:%08x\n", ret);
	} else {
		for (i = 0; i < 6; i++)
			pInfo->macAddress[i] = addr.addr[i];
		if (AOSS_PSP_Init() < 0) {
			puts("AOSS_PSP_Init Error");
		} else {
			ret = AOSS_Init(pInfo);
			AOSS_PSP_Term();
			sceKernelDelayThread(10000000);
		}
	}
	printf("AOSS_Init: %08x\n", ret);
	printf("aossResult:%d (%s)\n", pInfo->aossResult, D_001F841C[pInfo->aossResult]);
	if (pInfo->aossResult == 0) {
		printf("WEP40_SSID: '%s'\n", pInfo->secureInfo.WEP40_SSID);
		printf("WEP40Key1  : ");
		DumpChar(pInfo->secureInfo.WEP40Key1, 6);
	}
	g_AossIsBusy = 0;
	return 0;
}

static int AossThreadInit(void)
{
	int result;

	g_AossIsBusy = 1;
	gThreadId = sceKernelCreateThread("AossThread", AossThread, sceKernelGetThreadCurrentPriority(), 0x8000, 0, NULL);
	if (gThreadId < 0) {
		printf("sceKernelCreateThread failed %08x\n", gThreadId);
		return -1;
	}
	result = sceKernelStartThread(gThreadId, 0, NULL);
	if (result != 0) {
		printf("ERROR: sceKernelStartThread %08x\n", result);
		return -1;
	}
	return 0;
}

static void AossThreadTerm(void)
{
	while (g_AossIsBusy)
		sceKernelDelayThread(10000000);
	sceKernelTerminateDeleteThread(gThreadId);
	gThreadId = -1;
}

int AossNetconfGetStatus(void)
{
	return g_State;
}

int AossNetconfInitStart(SceUtilityNetconfParam *param)
{
	int ret;

	g_Param = param;
	g_State = 2;
	rxStateInit(&g_MoveState);
	ret = AOSS_version();
	printf("AOSS_version:%08x\n", ret);
	return 0;
}

int AossNetconfShutdownStart(void)
{
	g_State = 4;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/aosspspmgr", AossNetconfUpdate);
