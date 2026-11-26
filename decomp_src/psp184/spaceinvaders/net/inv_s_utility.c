/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball utility) */
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
int utility_update_netconf(void);
int utility_net_connect(struct SceNetAdhocctlGroupName *group_name);
int utility_check_connect_completed(int *done_flag);
int utility_msgdialog(int error_code);
int utility_update_msgdialog(void);
int utility_check_msgdialog_completed(int *done_flag);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_utility", utility_init_netconf);

int utility_update_netconf(void)
{
	int ret = 0;

	if (sceUtilityNetconfGetStatus() == 2)
		ret = sceUtilityNetconfUpdate(1);
	return ret;
}

int utility_net_connect(struct SceNetAdhocctlGroupName *group_name) {
    return utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC, group_name);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_utility", utility_check_connect_completed);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_utility", utility_msgdialog);

int utility_update_msgdialog(void)
{
	int ret = 0;

	if (sceUtilityMsgDialogGetStatus() == 2)
		ret = sceUtilityMsgDialogUpdate(1);
	return ret;
}

extern int D_0028DE10;
int utility_check_msgdialog_completed(int *done_flag)
{
	int ret;

	ret = sceUtilityMsgDialogGetStatus();
	if (ret < 0)
		return ret;
	switch (ret) {
	case 0:
		if (D_0028DE10 == 0)
			*done_flag = 1;
		else
			*done_flag = -1;
		break;
	case 3:
		ret = sceUtilityMsgDialogShutdownStart();
		break;
	}
	return ret;
}
