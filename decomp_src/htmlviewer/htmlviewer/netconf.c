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


void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg) {
    if ((new_state == 0) & (event == 5)) {
        disconnected = 1;
    }
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", utility_init_netconf);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", utility_update_netconf);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", OnPush_Netconf_Apnet);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", D_0001D954);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", D_0001D960);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", D_0001D96C);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", OnCancel_Netconf_Apnet);

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

void OnPush_Nectonf_ApnetReConnect(int selection) {
    Menu_WriteLine("OnPush_Nectonf_ApnetReConnect", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_RECONNECT_APNET);
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", OnPush_Netconf_Adhoc);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/netconf", OnCancel_Netconf_Adhoc);

void OnPush_Nectonf_AdhocConnect(int selection) {
    Menu_WriteLine("OnPush_Nectonf_AdhocConnect", 0xFFFFFF);
    Menu_LockInput();
    sample_type = 3;
    sample_status = 0;
    utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC);
}
