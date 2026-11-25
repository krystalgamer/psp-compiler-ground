#include "common.h"
#include <psptypes.h>
#include <utility/utility_netconf.h>
#include <pspnet_apctl.h>
#include <libgu.h>
#include <stdio.h>
#include <stdarg.h>
#include "xpdebugprint.h"
#include "menumgr.h"
#include "rxstate.h"

typedef int (*Func_InitStart)(SceUtilityNetconfParam *);
typedef int (*Func_ShutdownStart)(void);
typedef int (*Func_Update)(int);
typedef int (*Func_GetStatus)(void);
typedef struct {
	Func_InitStart InitStart;
	Func_ShutdownStart ShutdownStart;
	Func_Update Update;
	Func_GetStatus GetStatus;
} FuncTable;

int sceUtilityGetSystemParamInt(int id, int *value);
int sceUtilitySetSystemParamInt(int id, int value);

/* the static data stays in the asm .data/.bss for now; names that other
   files also use are splat's unique ones */
extern FuncTable funcTable[3];
extern char g_PacketBuff_25BD40[131072];
#define g_PacketBuff g_PacketBuff_25BD40
extern char *rootTable[7];
extern char *netchkTable[7];
extern char *netdisconTable[2];
extern TMenuMgr rootMenu_27BD40;
#define rootMenu rootMenu_27BD40
extern TMenuMgr *curMenu_25BD00;
#define curMenu curMenu_25BD00
extern int g_State_25BD04;
#define g_State g_State_25BD04
extern int g_Index;
extern int g_oldpowersave;
extern rxStateMachine g_MoveState_27BD70;
#define g_MoveState g_MoveState_27BD70
extern SceUtilityNetconfParam *g_Param_25BD08;
#define g_Param g_Param_25BD08

/* the asm of NetconfUpdate calls DrawMenu by splat's unique name */
#define DrawMenu DrawMenu_E50AC

/* the menu tables' strings */
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140300);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_0014030C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140310);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140324);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140338);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140358);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140380);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140390);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_00140398);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", D_001403A0);

void DebugPrint(int nX, int nY, unsigned int nColor, const char *pFormat, ...)
{
	va_list vlist;
	char buff[1024];

	va_start(vlist, pFormat);
	vsprintf(buff, pFormat, vlist);
	va_end(vlist);
	sceGuDebugPrint(nX, nY, nColor, buff);
}

static void DrawInfo(void)
{
	DebugPrint(20, 6, 0xffffffff, "NetConf   ver.%x.%02x   Lib.%d.%0d.%0d", 1, 0, 1, 0, 3);
	DebugPrint(50, 258, 0xffffffff, "Copyright (C) 2005 Sony Computer Entertainment Inc.");
}

static void DrawMenu(void)
{
	sceGuStart(0, g_PacketBuff, sizeof(g_PacketBuff));
	if (curMenu)
		MenuMgrDraw(curMenu);
	sceGuFinish();
}

int NetconfGetStatus(void)
{
	return g_State;
}

int NetconfInitStart(SceUtilityNetconfParam *param)
{
	sceUtilityGetSystemParamInt(3, &g_oldpowersave);
	sceUtilitySetSystemParamInt(3, 0);
	g_Param = param;
	rxStateInit(&g_MoveState);
	g_State = 2;
	return 0;
}

int NetconfShutdownStart(void)
{
	sceUtilitySetSystemParamInt(3, g_oldpowersave);
	g_State = 4;
	return 0;
}

#ifdef NON_MATCHING
/* Close: same code, but _stack and curMenu's address swap s5/s6 and
   g_Index's address is not kept in a register. */
int NetconfUpdate(int animation_speed)
{
	int index;
	int exitcode;
	int ret;
	int apctl_state;

	if (g_State != 2)
		return 0;
	RX_BEGIN(&g_MoveState);
	puts("netchk");
#line 175
	while (sceNetApctlGetState(&apctl_state) != 0) RX_YIELD();
	if (apctl_state == 0)
		goto loop;
	{
		curMenu = MenuMgrCreate(&rootMenu, netchkTable, 36, 40);
#line 186
		while ((exitcode = curMenu->ExitCode) == 0) { MenuMgrMove(curMenu); RX_YIELD(); }
		index = curMenu->Index;
		MenuMgrDestroy(curMenu);
		curMenu = NULL;
		printf("exitcode:%d, index:%d\n", exitcode, index);
		if (index != 0)
			goto finish;
		curMenu = MenuMgrCreate(&rootMenu, netdisconTable, 36, 40);
		do {
			puts("netdisconnect");
#line 206
			while (sceNetApctlDisconnect() < 0) RX_YIELD();
#line 209
			RX_YIELD();
#line 215
			while (sceNetApctlGetState(&apctl_state) != 0) RX_YIELD();
		} while (apctl_state != 0);
		MenuMgrDestroy(curMenu);
		curMenu = NULL;
	}
loop:
	for (;;) {
		puts("loop");
		curMenu = MenuMgrCreate(&rootMenu, rootTable, 36, 40);
#line 235
		while ((exitcode = curMenu->ExitCode) == 0) { MenuMgrMove(curMenu); RX_YIELD(); }
		index = curMenu->Index;
		MenuMgrDestroy(curMenu);
		curMenu = NULL;
		printf("exitcode:%d, index:%d\n", exitcode, index);
		if (index == -1)
			break;
		g_Index = index;
		puts("netwin");
		ret = funcTable[g_Index].InitStart(g_Param);
		if (ret != 0) {
			printf("NetconfInitStart failed - %x\n", ret);
			continue;
		}
#line 259
		RX_MARK();
		ret = funcTable[g_Index].GetStatus();
		if (ret == 2) {
			ret = funcTable[g_Index].Update(animation_speed);
			if (ret != 0)
				printf("NetconfUpdate failed - %d\n", ret);
			RX_LEAVE();
		}
		if (ret != 3)
			RX_LEAVE();
		ret = funcTable[g_Index].ShutdownStart();
		if (ret != 0)
			printf("NetconfShutdownStart failed - %d\n", ret);
#line 289
		while (sceNetApctlGetState(&apctl_state) != 0) RX_YIELD();
		if (apctl_state == 4)
			break;
	}
finish:
	puts("finish");
	g_State = 3;
#line 302
	RX_YIELD();
	RX_END();
	DrawMenu();
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/netcnfmgr", NetconfUpdate);
#endif

void NetconfMgrInit(void)
{
}

void NetconfMgrTerm(void)
{
}
