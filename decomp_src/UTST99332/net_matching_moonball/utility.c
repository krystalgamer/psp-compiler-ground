#include "common.h"

/* declarations recovered from DWARF */
enum _anon1 {
    SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET = 0,
    SCE_UTILITY_NETCONF_TYPE_STATUS_APNET = 1,
    SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC = 2,
};
typedef enum _anon1 SceUtilityNetconfType;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
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
struct _anon5;
struct _anon5 { /* size 0x244 */
    SceUtilityParamBase base;
    int result;
    int type;
    unsigned int errorNum;
    char msgString[512];
    int optionType;
    int buttonResult;
};
typedef struct _anon5 SceUtilityMsgDialogParam;

extern SceUtilityNetconfParam netconfParam;
extern SceUtilityNetconfAdhocParam netconfAdhocParam;
extern SceUtilityMsgDialogParam msgdialog_param;

int utility_init_netconf(SceUtilityNetconfType type, struct SceNetAdhocctlGroupName *group_name);
int utility_check_connect_completed(int *done_flag);
int utility_check_msgdialog_completed(int *done_flag);

/* SDK functions (tools/sdk_protos.h) */
int printf(const char *fmt, ...);
void *memset(void *s, int c, unsigned int n);


INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/utility", utility_init_netconf);

int utility_update_netconf(void) {
    int temp_v0;
    int var_s0;
    int var_v0;

    var_s0 = 0;
    if (sceUtilityNetconfGetStatus() != 2) {
        goto block_1;
    }
    temp_v0 = sceUtilityNetconfUpdate(1);
    var_s0 = temp_v0;
    if (temp_v0 < 0) {
        printf("sceUtilityNetconfUpdate() failed. ret = 0x%x\n", temp_v0);
        var_v0 = var_s0;
    } else {
block_1:
        var_v0 = var_s0;
    }
    return var_v0;
}

int utility_net_connect(struct SceNetAdhocctlGroupName *group_name) {
    return utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC, group_name);
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/utility", utility_check_connect_completed);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/utility", D_0001A270);

int utility_msgdialog(int error_code) {
    int temp_v0;

    memset(&msgdialog_param, 0, 0x244U);
    msgdialog_param.base.size = 0x244;
    msgdialog_param.base.main_thread_priority = 0x11;
    msgdialog_param.base.sub_thread_priority = 0x13;
    msgdialog_param.base.font_thread_priority = 0x12;
    msgdialog_param.base.sound_thread_priority = 0x10;
    msgdialog_param.errorNum = (unsigned int) error_code;
    msgdialog_param.base.ctrl_assign = 0;
    msgdialog_param.type = 0;
    temp_v0 = sceUtilityMsgDialogInitStart(&msgdialog_param);
    if (temp_v0 == 0) {

    } else {
        printf("sceMsgDialogDialogInit failed - 0x%x\n", temp_v0);
    }
    return temp_v0;
}

int utility_update_msgdialog(void) {
    int temp_v0;
    int var_s0;
    int var_v0;

    var_s0 = 0;
    if (sceUtilityMsgDialogGetStatus() != 2) {
        goto block_1;
    }
    temp_v0 = sceUtilityMsgDialogUpdate(1);
    var_s0 = temp_v0;
    if (temp_v0 < 0) {
        printf("sceUtilityMsgDialogUpdate() failed. ret = 0x%x\n", temp_v0);
        var_v0 = var_s0;
    } else {
block_1:
        var_v0 = var_s0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/utility", utility_check_msgdialog_completed);
