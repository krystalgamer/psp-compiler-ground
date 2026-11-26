/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
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
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
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
typedef unsigned int u_int32;

extern char disp_list[327680];
extern short int board[2][3];
extern u_int32 cont;
extern int evf;

void _sce_pspnet_adhoc_dialog_adhocctl_handler(int event, int error, void *arg);
int _sce_pspnet_adhoc_dialog_set_error_state(struct SceNetAdhocDialogInfo *info, int error_code);
void _sce_pspnet_adhoc_dialog_clear_evf(struct SceNetAdhocDialogInfo *info);
int _sce_pspnet_adhoc_dialog_get_evf(struct SceNetAdhocDialogInfo *info, int *evf_ptr);
#define draw_frame draw_frame_6AF0
#define pad_read pad_read_6DBC
static void draw_frame(struct SceNetAdhocDialogInfo *info);
static void print_connecting_message(void);
static void print_wlan_off_message(void);
static void print_failure_message(void);
static void print_wlan_error_message(struct SceNetAdhocDialogInfo *info);
static void pad_read(struct SceNetAdhocDialogInfo *info);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceGuFinish(void);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);

extern __typeof__(evf) evf_8BC00;
#define evf evf_8BC00

void _sce_pspnet_adhoc_dialog_adhocctl_handler(int event, int error, void *arg)
{
	struct SceNetAdhocDialogInfo *info = (struct SceNetAdhocDialogInfo *)arg;

	if (info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED || info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR) {
		return;
	}

	if (event == 0) {
		info->error_code = error;
		_sce_pspnet_adhoc_dialog_set_error_state(info, error);
		evf |= 1;
	} else if (event == 1) {
		info->error_code = 0;
		if (info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING || info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING
		    || info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING) {
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED;
		}
		evf |= 2;
	} else if (event == 2) {
		info->error_code = 0;
		evf |= 4;
	} else if (event == 3) {
		info->error_code = 0;
		evf |= 8;
	} else if (event == 4) {
		info->error_code = 0;
		if (info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE || info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN) {
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED;
		}
		evf |= 0x10;
	}
}

int _sce_pspnet_adhoc_dialog_set_error_state(struct SceNetAdhocDialogInfo *info, int error_code)
{
	switch (error_code) {
	case (int)0x80410B03:
	case (int)0x80410D0C:
		info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_SWITCH_OFF;
		break;
	default:
		switch (info->state) {
		case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN:
		case SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_SCAN;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_JOIN;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN;
			break;
		default:
			break;
		}
		break;
	}

	return 0;
}

int _sce_pspnet_adhoc_dialog_update(struct SceNetAdhocDialogInfo *info) {
    pad_read(info);
    draw_frame(info);
    return 0;
}

void _sce_pspnet_adhoc_dialog_clear_evf(struct SceNetAdhocDialogInfo *info)
{
	evf = 0;
	info->error_code = 0;
}

int _sce_pspnet_adhoc_dialog_get_evf(struct SceNetAdhocDialogInfo *info, int *evf_ptr)
{
	*evf_ptr = evf;

	return 0;
}

extern __typeof__(disp_list) disp_list_8BC40;
#define disp_list disp_list_8BC40
extern __typeof__(board) board_1AD54;
#define board board_1AD54

static inline void print_connecting_message(void)
{
	char buf[64];

	sprintf(buf, "Now Connecting to Network ...");
	sceGuDebugPrint(69, 106, 0xffffff, buf);
}

static inline void print_wlan_off_message(void)
{
	char buf[64];

	sprintf(buf, "Wireless LAN Switch is turned off .");
	sceGuDebugPrint(69, 106, 0xffffff, buf);

	sprintf(buf, "Turn on it if you connect to network .");
	sceGuDebugPrint(69, 116, 0xffffff, buf);

	sprintf(buf, "Press CROSS button to Close");
	sceGuDebugPrint(65 + (350 - strlen(buf) * 8) / 2, 166, 0xffffff, buf);
}

static inline void print_failure_message(void)
{
	char buf[64];

	sprintf(buf, "Failed to connect .");
	sceGuDebugPrint(69, 106, 0xffffff, buf);

	sprintf(buf, "Try again ?");
	sceGuDebugPrint(69, 116, 0xffffff, buf);

	sprintf(buf, "CROSS: NO        CIRCLE: YES");
	sceGuDebugPrint(65 + (350 - strlen(buf) * 8) / 2, 166, 0xffffff, buf);
}

static inline void print_wlan_error_message(struct SceNetAdhocDialogInfo *info)
{
	char buf[64];

	sprintf(buf, "Network Error Happened .");
	sceGuDebugPrint(69, 106, 0xffffff, buf);

	switch (info->error_code) {
	case (int)0x80410B03:
		sprintf(buf, "Wireless LAN Switch becomes turned off .");
		break;
	case (int)0x80410B0E:
		sprintf(buf, "Network Signal has been lost .");
		break;
	case (int)0x80410B0F:
		sprintf(buf, "Disconnected by Suspend Operation .");
		break;
	default:
		sprintf(buf, "Error Code: (0x%08x)", info->error_code);
		break;
	}
	sceGuDebugPrint(69, 116, 0xffffff, buf);

	sprintf(buf, "Press CROSS button to Close");
	sceGuDebugPrint(65 + (350 - strlen(buf) * 8) / 2, 166, 0xffffff, buf);
}

static void draw_frame(struct SceNetAdhocDialogInfo *info)
{
	if (info->state == SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED) {
		return;
	}

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);

	sceGuColor(0xff800000);
	sceGuDrawArray(6, 0x800100, 2, NULL, board);

	switch (info->state) {
	case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN:
		print_connecting_message();
		break;
	case SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_SWITCH_OFF:
		print_wlan_off_message();
		break;
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_SCAN:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_JOIN:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE:
	case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN:
		print_failure_message();
		break;
	case SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR:
		print_wlan_error_message(info);
		break;
	default:
		break;
	}

	sceGuFinish();
	sceGuSync(0, 0);
}

typedef struct SceCtrlData {
	unsigned int TimeStamp;
	unsigned int Buttons;
	unsigned char Lx;
	unsigned char Ly;
	unsigned char Rsrv[6];
} SceCtrlData;

int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceNetAdhocctlConnect(const struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocctlCreate(const struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocctlCreateEnterGameMode(const struct SceNetAdhocctlGroupName *group_name, int game_type, int num, const struct SceNetEtherAddr *members, unsigned int timeout, int flag);
int sceNetAdhocctlJoinEnterGameMode(const struct SceNetAdhocctlGroupName *group_name, const struct SceNetEtherAddr *gc, unsigned int timeout, int flag);

extern __typeof__(cont) cont_DBC40;
#define cont cont_DBC40

static void pad_read(struct SceNetAdhocDialogInfo *info)
{
	SceCtrlData buf;
	u_int32 prev, padd;
	int ret;

	prev = cont;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);

	if (padd & 0x2000) {
		switch (info->state) {
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE:
			ret = sceNetAdhocctlConnect(&info->group_name);
			if (ret < 0) {
				info->error_code = ret;
				info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE;
				break;
			}
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE:
			ret = sceNetAdhocctlCreate(&info->group_name);
			if (ret < 0) {
				info->error_code = ret;
				info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE;
				break;
			}
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_SCAN:
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_JOIN:
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN;
			info->scan_num = 0;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE:
			ret = sceNetAdhocctlCreateEnterGameMode(&info->group_name, info->game_type, info->num, info->members, info->timeout, 0);
			if (ret < 0) {
				info->error_code = ret;
				info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE;
				break;
			}
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE;
			break;
		case SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN:
			ret = sceNetAdhocctlJoinEnterGameMode(&info->group_name, &info->members[0], info->timeout, 0);
			if (ret < 0) {
				info->error_code = ret;
				info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN;
				break;
			}
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN;
			break;
		default:
			break;
		}
	} else if (padd & 0x1000) {
		return;
	} else if (padd & 0x4000) {
		if (info->state >= SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_SWITCH_OFF && info->state <= SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR) {
			info->state = SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED;
		}
	}
}
