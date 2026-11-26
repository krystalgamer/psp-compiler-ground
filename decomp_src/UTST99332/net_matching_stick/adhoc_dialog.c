/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef unsigned int SceUInt;
enum SceNetAdhocDialogState {
    SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED = 0,
    SCE_NET_ADHOC_DIALOG_STATE_CONNECTED = 1,
    SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE = 2,
    SCE_NET_ADHOC_DIALOG_STATE_OPENED = 3,
};
struct SceNetAdhocDialogInfo;
enum SceNetAdhocDialogInternalState {
    SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED = 0,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING = 1,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING = 2,
    SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN = 3,
    SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING = 4,
    SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING = 5,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE = 6,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN = 7,
    SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_SWITCH_OFF = 8,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE = 9,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE = 10,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_SCAN = 11,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_JOIN = 12,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE = 13,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN = 14,
    SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR = 15,
};
typedef int SceUID;
struct SceNetAdhocDialogInfo { /* size 0x88 */
    enum SceNetAdhocDialogInternalState state;
    SceUID tid;
    int error_code;
    int handler_id;
    struct SceNetAdhocctlGroupName group_name;
    int game_type;
    int num;
    struct SceNetEtherAddr members[16];
    int timeout;
    int scan_num;
};
struct SceNetAdhocctlScanInfo;
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlScanInfo { /* size 0x1c */
    struct SceNetAdhocctlScanInfo *next;
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlBSSId bssid;
    int mode;
};

extern struct SceNetAdhocDialogInfo info;
extern int inited;
extern struct SceNetAdhocctlScanInfo scaninfo[24];

int sceNetAdhocDialogConnect(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogCreate(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogCreateEnterGameMode(struct SceNetAdhocctlGroupName *group_name, int game_type, int num, struct SceNetEtherAddr *members, SceUInt timeout);
int sceNetAdhocDialogJoinEnterGameMode(struct SceNetAdhocctlGroupName *group_name, struct SceNetEtherAddr *gc, SceUInt timeout);
int sceNetAdhocDialogGetState(enum SceNetAdhocDialogState *state);
int sceNetAdhocDialogInit(void);
int sceNetAdhocDialogTerm(void);
int sceNetAdhocDialogJoin(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogWlanError(int error_code);
int sceNetAdhocDialogUpdate(void);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogConnect);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogCreate);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogCreateEnterGameMode);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogJoinEnterGameMode);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogGetState);

int sceNetAdhocctlAddHandler(void (*handler)(int event, int error, void *arg), void *arg);
int sceNetAdhocctlDelHandler(int id);
void _sce_pspnet_adhoc_dialog_adhocctl_handler(int event, int error, void *arg);

int sceNetAdhocDialogInit(void)
{
	int ret;

	if (inited > 0) {
		return (int)0x80000020;
	}

	memset(&info, 0, sizeof(info));
	info.handler_id = -1;

	ret = sceNetAdhocctlAddHandler(_sce_pspnet_adhoc_dialog_adhocctl_handler, &info);
	if (ret < 0) {
		printf("sceNetAdhocctlAddHandler() failed. ret = 0x%x\n", ret);
		goto error;
	}

	info.handler_id = ret;
	inited = 1;

error:
	return ret;
}

int sceNetAdhocDialogTerm(void)
{
	int ret;

	if (inited == 0) {
		return (int)0x80000001;
	}

	if (info.handler_id >= 0) {
		ret = sceNetAdhocctlDelHandler(info.handler_id);
		if (ret < 0) {
			printf("sceNetAdhocctlDelHandler() failed. ret = 0x%x\n", ret);
		}
		info.handler_id = -1;
	}

	inited = 0;

	return 0;
}

int sceNetAdhocctlGetState(int *state);

int sceNetAdhocDialogJoin(struct SceNetAdhocctlGroupName *group_name)
{
	int ret;
	int state;

	if (inited == 0) {
		return (int)0x80000001;
	}

	if (info.state != SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED) {
		return (int)0x80000021;
	}

	ret = sceNetAdhocctlGetState(&state);
	if (ret < 0) {
		info.error_code = ret;
		goto error;
	}

	if (state != 0 && state != 2) {
		return (int)0x80000021;
	}

	if (group_name == NULL) {
		memset(&info.group_name, 0, sizeof(info.group_name));
	} else {
		info.group_name = *group_name;
	}

	info.scan_num = 0;
	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN;

error:
	return ret;
}

int sceNetAdhocDialogWlanError(int error_code)
{
	if (inited == 0) {
		return (int)0x80000001;
	}

	if (info.state != SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED) {
		return (int)0x80000021;
	}

	info.error_code = error_code;
	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR;

	return 0;
}

int _sce_pspnet_adhoc_dialog_update(struct SceNetAdhocDialogInfo *info);

int sceNetAdhocDialogUpdate(void)
{
	if (inited == 0) {
		return (int)0x80000001;
	}

	_sce_pspnet_adhoc_dialog_update(&info);

	return 0;
}
