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

int sceNetAdhocctlConnect(const struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocctlGetState(int *state);

int sceNetAdhocDialogConnect(struct SceNetAdhocctlGroupName *group_name)
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

	ret = sceNetAdhocctlConnect(&info.group_name);
	if (ret < 0) {
		info.error_code = ret;
		goto error;
	}

	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING;

error:
	return ret;
}

int sceNetAdhocctlCreate(const struct SceNetAdhocctlGroupName *group_name);

int sceNetAdhocDialogCreate(struct SceNetAdhocctlGroupName *group_name)
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

	ret = sceNetAdhocctlCreate(&info.group_name);
	if (ret < 0) {
		info.error_code = ret;
		goto error;
	}

	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING;

error:
	return ret;
}

int sceNetAdhocctlCreateEnterGameMode(const struct SceNetAdhocctlGroupName *group_name, int game_type, int num, const struct SceNetEtherAddr *members, SceUInt timeout, int flag);

int sceNetAdhocDialogCreateEnterGameMode(struct SceNetAdhocctlGroupName *group_name, int game_type, int num, struct SceNetEtherAddr *members, SceUInt timeout)
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

	if (state != 0) {
		return (int)0x80000021;
	}

	if (group_name == NULL) {
		memset(&info.group_name, 0, sizeof(info.group_name));
	} else {
		info.group_name = *group_name;
	}

	info.game_type = game_type;
	info.num = num;
	memcpy(info.members, members, sizeof(struct SceNetEtherAddr) * num);
	info.timeout = timeout;

	ret = sceNetAdhocctlCreateEnterGameMode(group_name, game_type, num, members, timeout, 0);
	if (ret < 0) {
		info.error_code = ret;
		goto error;
	}

	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE;

error:
	return ret;
}

int sceNetAdhocctlJoinEnterGameMode(const struct SceNetAdhocctlGroupName *group_name, const struct SceNetEtherAddr *gc, SceUInt timeout, int flag);

int sceNetAdhocDialogJoinEnterGameMode(struct SceNetAdhocctlGroupName *group_name, struct SceNetEtherAddr *gc, SceUInt timeout)
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

	if (state != 0) {
		return (int)0x80000021;
	}

	if (group_name == NULL) {
		memset(&info.group_name, 0, sizeof(info.group_name));
	} else {
		info.group_name = *group_name;
	}

	memcpy(&info.members[0], gc, sizeof(struct SceNetEtherAddr));
	info.timeout = timeout;

	ret = sceNetAdhocctlJoinEnterGameMode(group_name, gc, timeout, 0);
	if (ret < 0) {
		info.error_code = ret;
		goto error;
	}

	info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN;

error:
	return ret;
}

int _sce_pspnet_adhoc_dialog_get_evf(struct SceNetAdhocDialogInfo *info, SceUInt *evf);
int _sce_pspnet_adhoc_dialog_clear_evf(struct SceNetAdhocDialogInfo *info);
int _sce_pspnet_adhoc_dialog_set_error_state(struct SceNetAdhocDialogInfo *info, int error_code);
extern __typeof__(scaninfo) scaninfo_8B954;
#define scaninfo scaninfo_8B954

int sceNetAdhocDialogGetState(enum SceNetAdhocDialogState *state)
{
	int ret;
	SceUInt evf;
	int buflen;
	int ctlstate;
	struct SceNetAdhocctlScanInfo *sinfo;

	if (inited == 0) {
		return (int)0x80000001;
	}

	switch (info.state) {
	case SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN:
		ret = sceNetAdhocctlScan();
		if (ret < 0) {
			goto error;
		}
		info.scan_num++;
		info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING;
		*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
		break;

	case SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING:
		ret = _sce_pspnet_adhoc_dialog_get_evf(&info, &evf);
		if (ret < 0) {
			goto error;
		}
		if (evf & 0x8) {
			_sce_pspnet_adhoc_dialog_clear_evf(&info);
			buflen = sizeof(scaninfo);
			ret = sceNetAdhocctlGetScanInfo(&buflen, scaninfo);
			if (ret < 0) {
				goto error;
			}
			sinfo = NULL;
			if (buflen != 0) {
				for (sinfo = scaninfo; sinfo != NULL; sinfo = sinfo->next) {
					if (strncmp((char *)sinfo->group_name.data, (char *)info.group_name.data, sizeof(info.group_name)) == 0) {
						break;
					}
				}
			}
			if (sinfo == NULL) {
				if (info.scan_num >= 5) {
					ret = (int)0x80000024;
					goto error;
				}
				info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN;
				*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
				break;
			}
			ret = sceNetAdhocctlJoin(sinfo);
			if (ret < 0) {
				goto error;
			}
			info.state = SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING;
			*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
			break;
		}
		*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
		break;

	case SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED:
		ret = sceNetAdhocctlGetState(&ctlstate);
		if (ret < 0) {
			break;
		}
		switch (ctlstate) {
		case 0:
			*state = SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED;
			break;
		case 1:
			*state = SCE_NET_ADHOC_DIALOG_STATE_CONNECTED;
			break;
		case 2:
			*state = SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED;
			break;
		case 3:
			*state = SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE;
			break;
		}
		break;

	default:
		*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
		break;
	}

	return 0;

error:
	info.error_code = ret;
	_sce_pspnet_adhoc_dialog_set_error_state(&info, ret);
	*state = SCE_NET_ADHOC_DIALOG_STATE_OPENED;
	return 0;
}
#undef scaninfo

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
