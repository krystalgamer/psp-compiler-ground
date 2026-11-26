/* cflags: -O2 */
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
extern SceUtilityMsgDialogParam msgdialog_param __asm__("msgdialog_param_28DDF4");

int utility_update_netconf(void);
int utility_net_connect(struct SceNetAdhocctlGroupName *group_name);
int utility_update_msgdialog(void);
int utility_check_msgdialog_completed(int *done_flag);

void *memcpy(void *, const void *, unsigned int);
int sceUtilityNetconfInitStart(SceUtilityNetconfParam *param);

void *memcpy(void *, const void *, unsigned int);
int sceUtilityNetconfInitStart(SceUtilityNetconfParam *param);
int utility_init_netconf(SceUtilityNetconfType type, struct SceNetAdhocctlGroupName *group_name)
{
	netconfParam.base.size = sizeof(netconfParam);
	netconfParam.base.main_thread_priority = 0x11;
	netconfParam.base.sub_thread_priority = 0x13;
	netconfParam.base.font_thread_priority = 0x12;
	netconfParam.base.sound_thread_priority = 0x10;
	netconfParam.adhoc_param = 0;
	netconfParam.base.message_lang = 0;
	netconfParam.base.result = 0;
	netconfParam.base.reserved1 = 0;
	netconfParam.base.reserved2 = 0;
	netconfParam.base.reserved3 = 0;
	netconfParam.base.reserved4 = 0;
	netconfParam.base.ctrl_assign = 0;
	netconfParam.type = type;
	if (group_name == 0)
		memset(netconfAdhocParam.group_name, 0, 8);
	else
		*(struct SceNetAdhocctlGroupName *)netconfAdhocParam.group_name = *group_name;
	netconfParam.adhoc_param = &netconfAdhocParam;
	return sceUtilityNetconfInitStart(&netconfParam);
}

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

int sceUtilityNetconfGetStatus(void);
int sceUtilityNetconfShutdownStart(void);
extern int D_0028DDD0;
int utility_check_connect_completed(int *result)
{
	int ret;

	ret = sceUtilityNetconfGetStatus();
	if (ret < 0)
		goto end;
	if (ret == 0) {
		if (D_0028DDD0 == 0)
			*result = 1;
		else
			*result = -1;
		goto end;
	}
	if (ret == 3)
		ret = sceUtilityNetconfShutdownStart();
end:
	return ret;
}

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
        ;
    }
    return temp_v0;
}

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
