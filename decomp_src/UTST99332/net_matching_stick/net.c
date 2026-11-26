#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int;
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlParameter { /* size 0x94 */
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetAdhocctlBSSId bssid;
};
enum SceNetAdhocDialogState {
    SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED = 0,
    SCE_NET_ADHOC_DIALOG_STATE_CONNECTED = 1,
    SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE = 2,
    SCE_NET_ADHOC_DIALOG_STATE_OPENED = 3,
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlAdhocId;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceUChar8 data[9];
    SceUChar8 padding[3];
};
struct matching_room_info;
enum matching_room_state {
    MATCHING_ROOM_TOP = 0,
    MATCHING_ROOM_SCAN = 1,
    MATCHING_ROOM_SCANNING = 2,
    MATCHING_ROOM_SCAN_RESULT = 3,
    MATCHING_ROOM_CONNECT_ROOM = 4,
    MATCHING_ROOM_CONNECTING_ROOM = 5,
    MATCHING_ROOM_DISCONNECT_ROOM = 6,
    MATCHING_ROOM_DISCONNECTING_ROOM = 7,
    MATCHING_ROOM_CONNECTING_GAME = 8,
    MATCHING_ROOM_DISCONNECTING = 9,
    MATCHING_ROOM_ERROR_DIALOG = 10,
    MATCHING_ROOM_ROOM_LIST = 11,
    MATCHING_ROOM_NEIGHBORS = 12,
    MATCHING_ROOM_REQUESTING = 13,
    MATCHING_ROOM_CANCELED = 14,
    MATCHING_ROOM_DENIED = 15,
    MATCHING_ROOM_START_GAME = 16,
    MATCHING_ROOM_DISCONNECT = 17,
    MATCHING_ROOM_CHILD_ENTER_ROOM = 18,
    MATCHING_ROOM_CHILD_WAIT = 19,
    MATCHING_ROOM_CREATE_ROOM = 20,
    MATCHING_ROOM_PARENT_WAIT = 21,
    MATCHING_ROOM_PARENT_START_INFORM = 22,
    MATCHING_ROOM_PARENT_INFORM_CONNECT = 23,
    MATCHING_ROOM_PARENT_INFORM_SEND = 24,
    MATCHING_ROOM_PARENT_INFORM_FLUSH = 25,
    MATCHING_ROOM_GAME = 26,
    MATCHING_ROOM_GAME_DISCONNECT = 27,
};
struct p2p_hello_opt;
struct p2p_hello_opt_game_param;
enum room_color {
    ROOM_COLOR_WHITE = 0,
    ROOM_COLOR_YELLOW = 1,
    ROOM_COLOR_GREEN = 2,
    ROOM_COLOR_LIGHT_BLUE = 3,
};
enum room_speed {
    ROOM_SPEED_SLOW = 0,
    ROOM_SPEED_NORMAL = 1,
    ROOM_SPEED_FAST = 2,
};
struct p2p_hello_opt_game_param { /* size 0xc */
    int player_num;
    enum room_color color;
    enum room_speed speed;
};
enum game_type {
    GAME_TYPE_CHILD = 0,
    GAME_TYPE_PARENT = 1,
};
struct p2p_hello_opt { /* size 0x98 */
    struct SceNetAdhocctlNickname nickname;
    struct p2p_hello_opt_game_param game_param;
    enum game_type game_type;
    int cur_player_num;
    int req_player_num;
};
typedef long long unsigned int SceULong64;
struct matching_room_info { /* size 0x130 */
    enum matching_room_state state;
    struct p2p_hello_opt hello_opt;
    struct p2p_hello_opt *agreed_hello_opt;
    int requesting_minfo_id;
    int v_cursor_pos;
    int ignore_pad_input;
    struct SceNetEtherAddr local_addr;
    int ctx_id;
    struct SceNetEtherAddr members[16];
    struct SceNetEtherAddr parent_addr;
    int informing_minfo_id;
    SceULong64 ptp_start_time;
};
struct minfo;
struct minfo { /* size 0xa4 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};

extern struct SceNetAdhocctlAdhocId adhoc_id;
extern struct matching_room_info _mrinfo;
extern struct SceNetAdhocctlGroupName game_group_name;
extern struct minfo minfo[16];
extern int handlerId;
extern int evf;
extern int error_code;
extern char event_str[5][16];

static u_int get_random_num(u_int min, u_int max);
int get_bssid(char *bssid);
int randomize_group_name(struct SceNetAdhocctlGroupName *group_name);
static void adhocctl_handler(int event, int error, void *arg);
int net_init(void);
static int net_scan(void);
static int net_connect(void);
static int net_disconnect(void);
static int net_exit_gamemode(void);
static int check_adhocctl_scan_completed(void);
static int check_adhocctl_connect_completed(void);
static int check_adhocctl_disconnect_completed(void);
static int check_adhocctl_connected_error(void);
static int check_error_dialog_closed(void);
int net_update(void);


int printf(const char *fmt, ...);
void *memset(void *s, int c, unsigned int n);
int rand(void);
int printf(const char *, ...);
int rand(void);
void *memset(void *, int, unsigned int);
static u_int get_random_num(u_int min, u_int max)
{
	u_int num;

	if (max == min)
		return min;
	num = rand();
	return num / (0x7fffffff / (max - min + 1) + 1) + min;
}

int get_bssid(char *bssid)
{
	struct SceNetAdhocctlParameter param;
	int ret;

	ret = sceNetAdhocctlGetParameter(&param);
	if (ret < 0) {
		printf("sceNetAdhocctlGetParameter() failed. ret = 0x%x\n", ret);
		return ret;
	}
	sceNetEtherNtostr(param.bssid.data, bssid);
	return ret;
}

int randomize_group_name(struct SceNetAdhocctlGroupName *group_name)
{
	u_int i;
	u_int len;
	char *ptr;

	len = get_random_num(1, 8);
	memset(group_name, 0, sizeof(*group_name));
	ptr = (char *)group_name->data;
	for (i = 0; i < len; i++)
		ptr[i] = get_random_num('A', 'Z');
	return 0;
}

extern int evf_6C28C;

void clear_evf(void) {
    evf_6C28C = 0;
    error_code = 0;
}

extern __typeof__(evf) evf_6C28C;
#define evf evf_6C28C
static void adhocctl_handler(int event, int error, void *arg)
{
	printf("event: [%s] error_code = 0x%x\n", event_str[event], error);
	if (event == 0) {
		error_code = error;
		evf |= 0x01;
	} else if (event == 1) {
		error_code = 0;
		evf |= 0x02;
	} else if (event == 2) {
		error_code = 0;
		evf |= 0x04;
	} else if (event == 3) {
		error_code = 0;
		evf |= 0x08;
	} else if (event == 4) {
		error_code = 0;
		evf |= 0x10;
	}
}
#undef evf

extern int evf_6C28C;

int polling_error(void) {
    int var_a0;

    var_a0 = 0;
    if (evf_6C28C & 1) {
        evf_6C28C &= ~1;
        var_a0 = error_code;
    }
    return var_a0;
}

int net_init(void)
{
	int ret;

	ret = sceNetInit(0x20000, 0x20, 0x1000, 0x20, 0x1000);
	if (ret < 0) {
		printf("sceNetInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	ret = sceNetAdhocInit();
	if (ret < 0) {
		printf("sceNetAdhocInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	ret = sceNetAdhocctlInit(0x2000, 0x30, &adhoc_id);
	if (ret < 0) {
		printf("sceNetAdhocctlInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	clear_evf();
	ret = sceNetAdhocctlAddHandler(adhocctl_handler, NULL);
	if (ret < 0) {
		printf("sceNetAdhocctlAddHandler() failed. ret = 0x%x\n", ret);
		goto error;
	}
	handlerId = ret;
	ret = sceNetAdhocDialogInit();
	if (ret < 0) {
		printf("sceNetAdhocDialogInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	memset(&_mrinfo.hello_opt, 0, sizeof(struct p2p_hello_opt));
	_mrinfo.hello_opt.req_player_num = 2;
	return 0;

error:
	net_term();
	return -1;
}

void net_term(void) {
    sceNetAdhocDialogTerm();
    if (handlerId >= 0) {
        sceNetAdhocctlDelHandler(handlerId);
        handlerId = -1;
    }
    sceNetAdhocctlTerm();
    sceNetAdhocTerm();
    sceNetTerm();
}

extern __typeof__(evf) evf_6C28C;
#define evf evf_6C28C
static int net_scan(void)
{
	int ret;

	evf = 0;
	ret = sceNetAdhocctlScan();
	if (ret < 0) {
		printf("sceNetAdhocctlScan() failed. ret = 0x%x\n", ret);
		change_state(MATCHING_ROOM_TOP);
	} else if (_mrinfo.state == MATCHING_ROOM_SCAN) {
		change_state(MATCHING_ROOM_SCANNING);
	}
	return ret;
}
#undef evf

static int net_connect(void)
{
	int ret;

	ret = sceNetAdhocDialogConnect(NULL);
	if (ret < 0) {
		printf("sceNetAdhocDialogConnect() failed. ret = 0x%x\n", ret);
		change_state(MATCHING_ROOM_TOP);
	} else {
		change_state(MATCHING_ROOM_CONNECTING_ROOM);
	}
	return ret;
}

static int net_disconnect(void)
{
	int ret;

	net_delete_ptp();
	matching_term();
	game_term();
	ret = sceNetAdhocctlDisconnect();
	if (ret < 0) {
		printf("sceNetAdhocctlDisconnect() failed. ret = 0x%x\n", ret);
		return 0;
	}
	if (_mrinfo.state == MATCHING_ROOM_START_GAME)
		change_state(MATCHING_ROOM_DISCONNECTING_ROOM);
	else if (_mrinfo.state == MATCHING_ROOM_DISCONNECT)
		change_state(MATCHING_ROOM_DISCONNECTING);
	return 0;
}

static int net_exit_gamemode(void)
{
	int ret;

	game_term();
	ret = sceNetAdhocctlExitGameMode();
	if (ret < 0) {
		printf("sceNetAdhocctlExitGamemode() failed. ret = 0x%x\n", ret);
		return 0;
	}
	change_state(MATCHING_ROOM_DISCONNECTING);
	return 0;
}

extern __typeof__(evf) evf_6C28C;
#define evf evf_6C28C
static int check_adhocctl_scan_completed(void)
{
	int adhocctl_state;
	int ret;

	ret = 0;
	if (!(evf & 9))
		goto END;
	ret = sceNetAdhocctlGetState(&adhocctl_state);
	if (ret < 0)
		goto END;
	if (adhocctl_state == 2)
		goto END;
	ret = polling_error();
	if (ret < 0)
		change_state(MATCHING_ROOM_TOP);
	else
		change_state(MATCHING_ROOM_SCAN_RESULT);
END:
	return ret;
}
#undef evf

static int check_adhocctl_connect_completed(void)
{
	int ret;
	enum SceNetAdhocDialogState state;

	ret = sceNetAdhocDialogGetState(&state);
	if (ret < 0)
		return ret;
	switch (state) {
	case SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED:
		change_state(MATCHING_ROOM_TOP);
		_mrinfo.ignore_pad_input = 1;
		break;
	case SCE_NET_ADHOC_DIALOG_STATE_CONNECTED:
	case SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE:
		if (_mrinfo.state == MATCHING_ROOM_CONNECTING_ROOM) {
			sceNetGetLocalEtherAddr(&_mrinfo.local_addr);
			ret = matching_start();
			if (ret < 0)
				change_state(MATCHING_ROOM_GAME_DISCONNECT);
			else
				change_state(MATCHING_ROOM_ROOM_LIST);
		} else if (_mrinfo.state == MATCHING_ROOM_CONNECTING_GAME) {
			ret = game_init();
			if (ret < 0)
				change_state(MATCHING_ROOM_GAME_DISCONNECT);
			else
				change_state(MATCHING_ROOM_GAME);
		}
		break;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/net", check_adhocctl_disconnect_completed);

static int check_adhocctl_connected_error(void)
{
	int ret;

	ret = polling_error();
	if (ret == 0)
		goto END;
	ret = sceNetAdhocDialogWlanError(ret);
	if (ret < 0) {
		printf("sceNetAdhocDialogWlanError() failed. ret = 0x%x\n", ret);
		goto END;
	}
	change_state(MATCHING_ROOM_ERROR_DIALOG);
END:
	return ret;
}

static int check_error_dialog_closed(void)
{
	int ret;
	int state;

	ret = sceNetAdhocDialogGetState(&state);
	if (ret < 0)
		return ret;
	if (state == SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED || state == SCE_NET_ADHOC_DIALOG_STATE_CONNECTED) {
		change_state(MATCHING_ROOM_DISCONNECT);
		_mrinfo.ignore_pad_input = 1;
	} else if (state == SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE) {
		change_state(MATCHING_ROOM_GAME_DISCONNECT);
		_mrinfo.ignore_pad_input = 1;
	}
	return ret;
}

int net_update(void)
{
	switch (_mrinfo.state) {
	case MATCHING_ROOM_SCAN:
		net_scan();
		break;
	case MATCHING_ROOM_SCANNING:
		check_adhocctl_scan_completed();
		break;
	case MATCHING_ROOM_CONNECT_ROOM:
		net_connect();
		break;
	case MATCHING_ROOM_CONNECTING_ROOM:
	case MATCHING_ROOM_CONNECTING_GAME:
		check_adhocctl_connect_completed();
		break;
	case MATCHING_ROOM_DISCONNECTING_ROOM:
	case MATCHING_ROOM_DISCONNECTING:
		check_adhocctl_disconnect_completed();
		break;
	case MATCHING_ROOM_ERROR_DIALOG:
		check_error_dialog_closed();
		break;
	case MATCHING_ROOM_START_GAME:
	case MATCHING_ROOM_DISCONNECT:
		net_disconnect();
		break;
	case MATCHING_ROOM_GAME:
		send_recv_game_data();
		break;
	case MATCHING_ROOM_GAME_DISCONNECT:
		net_exit_gamemode();
		break;
	default:
		net_update_multi_player();
		break;
	}
	if (_mrinfo.state < MATCHING_ROOM_ROOM_LIST)
		goto END;
	check_adhocctl_connected_error();
END:
	return 0;
}
