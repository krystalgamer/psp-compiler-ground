#include "common.h"
#include <psptypes.h>
#include <utility/utility_netconf.h>
#include <libgu.h>
#include <stdio.h>
#include "rxstate.h"
#include "menumgr.h"

void DevPatchInit(void);
void DevPatchTerm(void);
int necApConfigGetVersion(void);

/* the static data stays in the asm .data/.bss for now; names that other
   files also use are splat's unique ones */
extern TMenuMgr *curMenu_29C080;
#define curMenu curMenu_29C080
extern int g_State_29C084;
#define g_State g_State_29C084
extern rxStateMachine g_MoveState_29C100;
#define g_MoveState g_MoveState_29C100
extern SceUtilityNetconfParam *g_Param_29C088;
#define g_Param g_Param_29C088
extern int oldstate;
extern int oldtimeout;
extern char g_PacketBuff_29C140[131072];
#define g_PacketBuff g_PacketBuff_29C140
extern char *CfgTable_1F845C[11];
#define CfgTable CfgTable_1F845C
extern char *Cfg2Table_1F8488[11];
#define Cfg2Table Cfg2Table_1F8488
extern char *CfgDoneTable_1F84B4[4];
#define CfgDoneTable CfgDoneTable_1F84B4
extern char *CfgFailTable_1F84C4[5];
#define CfgFailTable CfgFailTable_1F84C4

/* the asm of NecNetconfUpdate calls DrawMenu by splat's unique name */
#define DrawMenu DrawMenu_E6020

static void DrawMenu(void)
{
	sceGuStart(0, g_PacketBuff, sizeof(g_PacketBuff));
	if (curMenu)
		MenuMgrDraw(curMenu);
	sceGuFinish();
}

static char **GetStrTable(int id)
{
	char **result;

	switch (id) {
	case 3:
		result = Cfg2Table;
		break;
	case 4:
		result = CfgDoneTable;
		break;
	case 5:
		result = CfgFailTable;
		break;
	case 1:
	default:
		result = CfgTable;
		break;
	}
	return result;
}

int NecNetconfGetStatus(void)
{
	return g_State;
}

/* the menu tables' strings */
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_0014080C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140834);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_0014086C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140874);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140878);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_001408B0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_001408C4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140900);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140910);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140938);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_0014095C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140994);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_001409B0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_001409E8);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140A00);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140A3C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140A48);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140A80);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140AA0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140AD8);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140AE0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", D_00140B0C);

int NecNetconfInitStart(SceUtilityNetconfParam *param)
{
	int libver;

	g_Param = param;
	g_State = 2;
	rxStateInit(&g_MoveState);
	oldstate = 0;
	oldtimeout = 0;
	DevPatchInit();
	libver = necApConfigGetVersion();
	printf("nec_ap_set lib Ver.%d.%02d\n", ((libver & 0xf000) >> 12) * 10 + ((libver & 0xf00) >> 8),
	       ((libver & 0xf0) >> 4) * 10 + (libver & 0xf));
	return 0;
}

int NecNetconfShutdownStart(void)
{
	DevPatchTerm();
	g_State = 4;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpspmgr", NecNetconfUpdate);
