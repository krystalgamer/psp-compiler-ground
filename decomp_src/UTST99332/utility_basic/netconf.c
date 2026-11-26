#include "common.h"

void Menu_WriteLine(const char *line, int color);

/* declarations recovered from DWARF */
enum _anon1 {
    SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET = 0,
    SCE_UTILITY_NETCONF_TYPE_STATUS_APNET = 1,
    SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC = 2,
};
typedef enum _anon1 SceUtilityNetconfType;
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x30 */
    unsigned int size;
    int message_lang;
    int ctrl_assign;
    int main_thread_priority;
    int sub_thread_priority;
    int font_thread_priority;
    int sound_thread_priority;
    int result;
    int reserved1;
    int reserved2;
    int reserved3;
    int reserved4;
};
typedef struct _anon3 SceUtilityParamBase;
struct _anon4;
struct _anon4 { /* size 0x8 */
    unsigned char group_name[8];
};
typedef struct _anon4 SceUtilityNetconfAdhocParam;
struct _anon2 { /* size 0x38 */
    SceUtilityParamBase base;
    int type;
    SceUtilityNetconfAdhocParam *adhoc_param;
};
typedef struct _anon2 SceUtilityNetconfParam;

extern int sample_type;
extern int sample_status;
extern SceUtilityNetconfParam netconfParam;
extern SceUtilityNetconfAdhocParam netconfAdhocParam;
extern int handler_id;
extern int disconnected;

int utility_init_netconf(SceUtilityNetconfType type);
int utility_update_netconf(void);
void OnPush_Netconf_Apnet(int selection);
static void OnCancel_Netconf_Apnet(int selection);
void OnPush_Netconf_Adhoc(int selection);
static void OnCancel_Netconf_Adhoc(int selection);


/* SDK prototypes (tools/sdk_protos.h) */
int printf(const char *fmt, ...);

void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg) {
    if ((new_state == 0) & (event == 5)) {
        disconnected = 1;
    }
}

int utility_init_netconf(SceUtilityNetconfType type)
{
	memset(&netconfParam, 0, sizeof(netconfParam));
	netconfParam.base.size = sizeof(netconfParam);
	netconfParam.base.message_lang = GetMessageLang();
	netconfParam.base.ctrl_assign = GetAssign();
	netconfParam.base.main_thread_priority = 0x11;
	netconfParam.base.sub_thread_priority = 0x13;
	netconfParam.base.font_thread_priority = 0x12;
	netconfParam.base.sound_thread_priority = 0x10;
	netconfParam.type = type;
	memset(&netconfAdhocParam, 0, sizeof(netconfAdhocParam));
	netconfParam.adhoc_param = &netconfAdhocParam;
	return sceUtilityNetconfInitStart(&netconfParam);
}

void CreateMenu_Root(void);
void Menu_Show(void);
int utility_update_netconf(void)
{
	int ret;
	int state;
	int status;

	ret = 0;
	status = sceUtilityNetconfGetStatus();
	switch (sample_status) {
	case 0:
		switch (status) {
		case 1:
			break;
		case 2:
			Menu_Hide();
			ret = sceUtilityNetconfUpdate(1);
			break;
		case 3:
			ret = sceUtilityNetconfShutdownStart();
			break;
		case 4:
			break;
		case 0:
			Menu_UnlockInput();
			Menu_Show();
			sample_type = 0;
			break;
		}
		break;
	case 1:
		if (disconnected > 0) {
			if (handler_id >= 0)
				sceNetApctlDelHandler(handler_id);
			handler_id = -1;
			term_apnet();
			Menu_UnlockInput();
			CreateMenu_Root();
			sample_type = 0;
		}
		break;
	case 2:
		sceNetAdhocctlGetState(&state);
		if (state == 0) {
			term_adhoc();
			Menu_UnlockInput();
			CreateMenu_Root();
			sample_type = 0;
		}
		break;
	}
	return ret;
}

extern char D_000167B4[];
extern char D_000167C0[];
void OnPush_Nectonf_ApnetConnect(int selection);
void OnPush_Nectonf_ApnetStatus(int selection);
void Menu_AppendItem(const char *name, void (*cb)(int));
void Menu_SetCancelCallback(void (*cb)(int));
void OnPush_Netconf_Apnet(int selection)
{
	int ret;

	Menu_WriteLine("OnPush_Netconf_Apnet", 0xFFFFFF);
	init_apnet();
	ret = sceNetApctlAddHandler(apctl_handler, NULL);
	if (ret < 0) {
		printf("sceNetApctlAddHandler() failed. ret = 0x%x\n", ret);
		return;
	}
	handler_id = ret;
	Menu_ClearItems();
	Menu_AppendItem(D_000167B4, OnPush_Nectonf_ApnetConnect);
	Menu_AppendItem(D_000167C0, OnPush_Nectonf_ApnetStatus);
	Menu_SetCancelCallback(OnCancel_Netconf_Apnet);
}

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", D_000167B4);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", D_000167C0);

void OnCancel_Netconf_Apnet(int selection)
{
	Menu_WriteLine("OnCancel_Netconf_Apnet", 0xFFFFFF);
	Menu_LockInput();

	sample_type = 3;
	sample_status = 1;

	Menu_WriteLine("Disconnect apnet", 0xFFFFFF);
	disconnected = 0;
	sceNetApctlDisconnect();
}

void OnPush_Nectonf_ApnetConnect(int selection) {
    Menu_WriteLine("OnPush_Nectonf_ApnetConnect", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET);
}

void OnPush_Nectonf_ApnetStatus(int selection) {
    Menu_WriteLine("OnPush_Nectonf_ApnetStatus", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_STATUS_APNET);
}

void OnPush_Nectonf_AdhocConnect(int selection);
void Menu_AppendItem(const char *name, void (*cb)(int));
void Menu_SetCancelCallback(void (*cb)(int));
extern char D_000167B4[];
void OnPush_Netconf_Adhoc(int selection)
{
	Menu_WriteLine("OnPush_Netconf_Adhoc", 0xFFFFFF);
	init_adhoc();
	Menu_ClearItems();
	Menu_AppendItem(D_000167B4, OnPush_Nectonf_AdhocConnect);
	Menu_SetCancelCallback(OnCancel_Netconf_Adhoc);
}

static void OnCancel_Netconf_Adhoc(int selection)
{
    int state;

    Menu_WriteLine("OnCancel_Netconf_Adhoc", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 2;
    sceNetAdhocctlGetState(&state);
    if (state != 0) {
        Menu_WriteLine("Disconnect adhoc", 0x00ffffff);
        sceNetAdhocctlDisconnect();
    }
}

void OnPush_Nectonf_AdhocConnect(int selection) {
    Menu_WriteLine("OnPush_Nectonf_AdhocConnect", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC);
}
