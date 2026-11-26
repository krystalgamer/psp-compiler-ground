#include "common.h"

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


void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg) {
    if ((new_state == 0) & (event == 5)) {
        disconnected = 1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", utility_init_netconf);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", utility_update_netconf);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", OnPush_Netconf_Apnet);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", D_000167B4);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", D_000167C0);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", OnCancel_Netconf_Apnet);

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

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/netconf", OnPush_Netconf_Adhoc);

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
