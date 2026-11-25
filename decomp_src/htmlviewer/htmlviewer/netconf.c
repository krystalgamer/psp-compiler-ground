#include "common.h"

/* declarations recovered from DWARF */
enum _anon1 {
    SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET = 0,
    SCE_UTILITY_NETCONF_TYPE_STATUS_APNET = 1,
    SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC = 2,
    SCE_UTILITY_NETCONF_TYPE_RECONNECT_APNET = 3,
    SCE_UTILITY_NETCONF_TYPE_CREATE_ADHOC = 4,
    SCE_UTILITY_NETCONF_TYPE_JOIN_ADHOC = 5,
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
struct _anon4 { /* size 0xc */
    unsigned char group_name[8];
    unsigned int timeout;
};
typedef struct _anon4 SceUtilityNetconfAdhocParam;
typedef unsigned int SceUInt32;
struct _anon2 { /* size 0x40 */
    SceUtilityParamBase base;
    int type;
    SceUtilityNetconfAdhocParam *adhoc_param;
    SceUInt32 browser_available;
    SceUInt32 browser_flag;
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


#define SCE_UTILITY_COMMON_STATUS_NONE 0
#define SCE_UTILITY_COMMON_STATUS_INITIALIZE 1
#define SCE_UTILITY_COMMON_STATUS_RUNNING 2
#define SCE_UTILITY_COMMON_STATUS_FINISHED 3
#define SCE_UTILITY_COMMON_STATUS_SHUTDOWN 4

void *memset(void *, int, unsigned int);
int printf(const char *, ...);
int GetMessageLang(void);
int GetAssign(void);
int sceUtilityNetconfInitStart(SceUtilityNetconfParam *);
int sceUtilityNetconfGetStatus(void);
int sceUtilityNetconfUpdate(int);
int sceUtilityNetconfShutdownStart(void);
int sceNetAdhocctlGetState(int *);
int sceNetAdhocctlDisconnect(void);
int sceNetApctlDelHandler(int);
int sceNetApctlAddHandler(void (*)(int, int, int, int, void *), void *);
int sceNetApctlDisconnect(void);
int init_net(void);
int term_net(void);
int init_apnet(void);
int term_apnet(void);
int init_adhoc(void);
int term_adhoc(void);
void Menu_UnlockInput(void);
void Menu_LockInput(void);
void Menu_Show(void);
void Menu_Hide(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, void (*callback)(int));
void Menu_SetCancelCallback(void (*callback)(int));
void Menu_WriteLine(const char *line, int color);
void CreateMenu_Root(void);
static void OnPush_Nectonf_ApnetConnect(int selection);
static void OnPush_Nectonf_ApnetStatus(int selection);
static void OnPush_Nectonf_ApnetReConnect(int selection);
static void OnPush_Nectonf_AdhocConnect(int selection);

void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg)
{
    if ((new_state == 0) & (event == 5)) {
        disconnected = 1;
    }
}

int utility_init_netconf(SceUtilityNetconfType type)
{
    int ret;

    memset(&netconfParam, 0, sizeof(netconfParam));
    netconfParam.base.size = sizeof(netconfParam);
    netconfParam.base.message_lang = GetMessageLang();
    netconfParam.base.ctrl_assign = GetAssign();
    netconfParam.base.main_thread_priority = 17;
    netconfParam.base.sub_thread_priority = 19;
    netconfParam.base.font_thread_priority = 18;
    netconfParam.base.sound_thread_priority = 16;
    netconfParam.type = type;
    memset(netconfAdhocParam.group_name, 0, sizeof(netconfAdhocParam.group_name));
    netconfAdhocParam.timeout = 0;
    netconfParam.adhoc_param = &netconfAdhocParam;
    netconfParam.browser_available = 0;
    ret = sceUtilityNetconfInitStart(&netconfParam);
    return ret;
}

int utility_update_netconf(void)
{
    int ret = 0;
    int status;
    int adhocctl_state;

    status = sceUtilityNetconfGetStatus();
    switch (sample_status) {
    case 0:
        switch (status) {
        case SCE_UTILITY_COMMON_STATUS_INITIALIZE:
            break;
        case SCE_UTILITY_COMMON_STATUS_RUNNING:
            Menu_Hide();
            ret = sceUtilityNetconfUpdate(1);
            break;
        case SCE_UTILITY_COMMON_STATUS_NONE:
            Menu_UnlockInput();
            Menu_Show();
            sample_type = 0;
            break;
        case SCE_UTILITY_COMMON_STATUS_FINISHED:
            ret = sceUtilityNetconfShutdownStart();
            break;
        case SCE_UTILITY_COMMON_STATUS_SHUTDOWN:
            break;
        }
        break;
    case 1:
        if (disconnected > 0) {
            if (handler_id >= 0) {
                sceNetApctlDelHandler(handler_id);
            }
            handler_id = -1;
            term_apnet();
            term_net();
            Menu_UnlockInput();
            CreateMenu_Root();
            sample_type = 0;
        }
        break;
    case 2:
        sceNetAdhocctlGetState(&adhocctl_state);
        if (adhocctl_state == 0) {
            term_adhoc();
            term_net();
            Menu_UnlockInput();
            CreateMenu_Root();
            sample_type = 0;
        }
        break;
    }
    return ret;
}

void OnPush_Netconf_Apnet(int selection)
{
    int ret;

    Menu_WriteLine("OnPush_Netconf_Apnet", 0x00ffffff);
    init_net();
    init_apnet();
    ret = sceNetApctlAddHandler(apctl_handler, 0);
    if (ret < 0) {
        printf("sceNetApctlAddHandler() failed. ret = 0x%x\n", ret);
        return;
    }
    handler_id = ret;
    Menu_ClearItems();
    Menu_AppendItem("0 : Connect", OnPush_Nectonf_ApnetConnect);
    Menu_AppendItem("1 : Status", OnPush_Nectonf_ApnetStatus);
    Menu_AppendItem("2 : ReConnect", OnPush_Nectonf_ApnetReConnect);
    Menu_SetCancelCallback(OnCancel_Netconf_Apnet);
}

static void OnCancel_Netconf_Apnet(int selection)
{
    Menu_WriteLine("OnCancel_Netconf_Apnet", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 1;
    Menu_WriteLine("Disconnect apnet", 0x00ffffff);
    disconnected = 0;
    sceNetApctlDisconnect();
}

static void OnPush_Nectonf_ApnetConnect(int selection)
{
    Menu_WriteLine("OnPush_Nectonf_ApnetConnect", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET);
}

static void OnPush_Nectonf_ApnetStatus(int selection)
{
    Menu_WriteLine("OnPush_Nectonf_ApnetStatus", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_STATUS_APNET);
}

static void OnPush_Nectonf_ApnetReConnect(int selection)
{
    Menu_WriteLine("OnPush_Nectonf_ApnetReConnect", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_RECONNECT_APNET);
}

void OnPush_Netconf_Adhoc(int selection)
{
    Menu_WriteLine("OnPush_Netconf_Adhoc", 0x00ffffff);
    init_net();
    init_adhoc();
    Menu_ClearItems();
    Menu_AppendItem("0 : Connect", OnPush_Nectonf_AdhocConnect);
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

static void OnPush_Nectonf_AdhocConnect(int selection)
{
    Menu_WriteLine("OnPush_Nectonf_AdhocConnect", 0x00ffffff);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC);
}
