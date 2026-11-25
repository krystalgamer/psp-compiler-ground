#include "common.h"
#include <psptypes.h>
#include <utility/utility_netparam.h>
#include <libgu.h>
#include <stdio.h>
#include <string.h>
#include "rxstate.h"
#include "menumgr.h"

int sceUtilityCheckNetParam(int id);
int sceUtilityGetNetParam(int conf, int param, union SceUtilityNetParamEntry *data);
int sceUtilityCreateNetParam(int conf);
int sceUtilityCopyNetParam(int src, int dest);
int sceUtilityDeleteNetParam(int conf);

/* the static data stays in the asm .data/.bss for now; names that other
   files also use are splat's unique ones */
extern TMenuMgr *curMenu_2BC140;
#define curMenu curMenu_2BC140
extern int g_State_2BC144;
#define g_State g_State_2BC144
extern rxStateMachine g_MoveState_2BC170;
#define g_MoveState g_MoveState_2BC170
extern int g_AuthProto;
extern char g_CnfName[66];
extern char g_Utf8Name[66];
extern char g_Ssid[34];
extern char g_Wep[15];
extern char g_PacketBuff_2BC240[131072];
#define g_PacketBuff g_PacketBuff_2BC240

/* the asm of CnfSaveUpdate calls these by splat's unique names */
#define localSetNetParam localSetNetParam_E64DC
#define DumpChar DumpChar_E6534
#define DrawMenu DrawMenu_E69C4

/* the menu tables' strings; SaveCnfData shares the empty one */
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140B6C);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140B90);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140B94);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140BB4);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140BE0);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140C08);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140C24);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", D_00140C2C);
extern const char D_00140B90[] __attribute__((aligned(4)));

static int localSetNetParam(int code, union SceUtilityNetParamEntry *entry)
{
	int ret;

	ret = sceUtilitySetNetParam(code, entry);
	if (ret < 0)
		printf("sceUtilitySetNetParam Error:%x : %x\n", code, ret);
	return ret;
}

static void DumpChar(char *p, int count)
{
	int i;

	for (i = 0; i < count; i++)
		printf("%02x ", (unsigned char)p[i]);
	putchar('\n');
}

static int ScanCnfData(void)
{
	int ret;
	union SceUtilityNetParamEntry entry;
	int i;

	for (i = 1; i < 30; i++) {
		if (sceUtilityCheckNetParam(i) != 0)
			continue;
		sceUtilityGetNetParam(i, 0, &entry);
		DumpChar(entry.cnf_name, strlen(entry.cnf_name));
		if (strcmp(entry.cnf_name, g_Utf8Name) == 0) {
			printf("found:%d\n", i);
			return i;
		}
	}
	return 0;
}

#ifdef NON_MATCHING
/* Close: the original reads the 16 zero bytes of the empty string once and
   reuses them, as for a literal; here it shares D_00140B90 with the asm
   tables, so they are reloaded. */
static int SaveCnfData(void)
{
	int ret;
	union SceUtilityNetParamEntry entry;
	int i;

	if (sceUtilityCheckNetParam(0) < 0) {
		if (sceUtilityCreateNetParam(0) < 0)
			return 0;
	}
	memcpy(entry.cnf_name, g_Utf8Name, 64);
	localSetNetParam(0, &entry);
	memcpy(entry.ssid, g_Ssid, 32);
	localSetNetParam(1, &entry);
	entry.auth_proto = g_AuthProto;
	localSetNetParam(2, &entry);
	memcpy(entry.wep_key, g_Wep, 13);
	localSetNetParam(3, &entry);
	entry.how_to_set_ip = 0;
	localSetNetParam(4, &entry);
	memcpy(entry.ip_address, D_00140B90, 16);
	localSetNetParam(5, &entry);
	memcpy(entry.netmask, D_00140B90, 16);
	localSetNetParam(6, &entry);
	memcpy(entry.default_route, D_00140B90, 16);
	localSetNetParam(7, &entry);
	entry.dns_flag = 0;
	localSetNetParam(8, &entry);
	entry.http_proxy_flag = 0;
	localSetNetParam(13, &entry);
	for (i = 1; i < 30; i++) {
		if (sceUtilityCheckNetParam(i) != 0)
			continue;
		sceUtilityGetNetParam(i, 0, &entry);
		if (strcmp(entry.cnf_name, g_Utf8Name) == 0) {
			printf("delete:%d\n", i);
			sceUtilityDeleteNetParam(i);
			break;
		}
	}
	for (i = 1; i < 30; i++) {
		if (sceUtilityCheckNetParam(i) != (int)0x80110601)
			continue;
		ret = sceUtilityCreateNetParam(i);
		if (ret < 0) {
			printf("sceUtilityCreateNetParam error:%x\n", ret);
			return 0;
		}
		ret = sceUtilityCopyNetParam(0, i);
		if (ret < 0) {
			printf("sceUtilityCopyNetParam error:%x\n", ret);
			return 0;
		}
		return i;
	}
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", SaveCnfData);
#endif

static void DrawMenu(void)
{
	sceGuStart(0, g_PacketBuff, sizeof(g_PacketBuff));
	if (curMenu)
		MenuMgrDraw(curMenu);
	sceGuFinish();
}

int CnfSaveGetStatus(void)
{
	return g_State;
}

int CnfSaveInitStart(char *cnfname, char *utf8name, char *ssid, char *wep, int authproto)
{
	g_State = 2;
	rxStateInit(&g_MoveState);
	strcpy(g_CnfName, cnfname);
	memcpy(g_Utf8Name, utf8name, 64);
	g_AuthProto = authproto;
	strcpy(g_Ssid, ssid);
	memcpy(g_Wep, wep, 13);
	printf("cnfname:%s\n", g_CnfName);
	printf("authproto:%d\n", g_AuthProto);
	printf("ssid:'%s'\n", g_Ssid);
	printf("wep:'%s'\n", g_Wep);
	return 0;
}

int CnfSaveShutdownStart(void)
{
	g_State = 4;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/cnfsavemgr", CnfSaveUpdate);
