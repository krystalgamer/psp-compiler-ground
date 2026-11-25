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
};
struct p2p_hello_opt;
struct p2p_hello_opt_game_param;
struct p2p_hello_opt_game_param { /* size 0x0 */

};
enum game_type {
    GAME_TYPE_CHILD = 0,
    GAME_TYPE_PARENT = 1,
};
struct p2p_hello_opt { /* size 0x8c */
    struct SceNetAdhocctlNickname nickname;
    struct p2p_hello_opt_game_param game_param;
    enum game_type game_type;
    int cur_player_num;
    int req_player_num;
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef long long unsigned int SceULong64;
struct matching_room_info { /* size 0x120 */
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

extern struct SceNetAdhocctlAdhocId adhoc_id;
extern struct matching_room_info _mrinfo;
extern struct SceNetAdhocctlGroupName game_group_name;
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
static int check_adhocctl_scan_completed(void);
static int check_adhocctl_connect_completed(void);
static int check_adhocctl_disconnect_completed(void);
static int check_adhocctl_connected_error(void);
static int check_error_dialog_closed(void);
int net_update(void);


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

void clear_evf(void) {
    evf = 0;
    error_code = 0;
}

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

int polling_error(void) {
    int var_a0;

    var_a0 = 0;
    if (evf & 1) {
        evf &= ~1;
        var_a0 = error_code;
    }
    return var_a0;
}

void change_state(int state);
int utility_net_connect(int flag);
void net_delete_ptp(void);
void matching_term(void);
void game_term(void);
#define net_param D_000DB754	/* 0x8c bytes; the field at 0x88 is set to 2 */
extern struct { char pad[0x88]; int type; } net_param;
#define net_connect_failed D_00019974	/* shared with check_adhocctl_disconnect_completed */
extern char net_connect_failed[];
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
	memset(&net_param, 0, 0x8c);
	net_param.type = 2;
	return 0;

error:
	net_term();
	return -1;
}

void net_term(void) {
    if (handlerId >= 0) {
        sceNetAdhocctlDelHandler(handlerId);
        handlerId = -1;
    }
    sceNetAdhocctlTerm();
    sceNetAdhocTerm();
    sceNetTerm();
}

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

static int net_connect(void)
{
	int ret;

	ret = utility_net_connect(0);
	if (ret < 0) {
		printf(net_connect_failed, ret);
		change_state(MATCHING_ROOM_TOP);
	} else {
		change_state(MATCHING_ROOM_CONNECTING_ROOM);
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", D_00019974);

void gu_init(void);
int polling_error(void);
int matching_start(void);
int game_init(void);
int utility_check_connect_completed(int *result);
int utility_msgdialog(int error);
int utility_check_msgdialog_completed(int *result);
void net_update_multi_player(void);
void send_recv_game_data(void);
#define net_error_flag D_000DB7EC	/* set when the connection ends in an error */
extern int net_error_flag;
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

static int check_adhocctl_connect_completed(void)
{
	int ret;
	int done_flag;

	ret = 0;
	done_flag = 0;
	utility_check_connect_completed(&done_flag);
	if (done_flag > 0) {
		if (_mrinfo.state == MATCHING_ROOM_CONNECTING_ROOM) {
			sceNetGetLocalEtherAddr(&_mrinfo.local_addr);
			ret = matching_start();
			if (ret < 0)
				change_state(MATCHING_ROOM_DISCONNECT);
			else
				change_state(MATCHING_ROOM_ROOM_LIST);
		} else if (_mrinfo.state == MATCHING_ROOM_CONNECTING_GAME) {
			ret = game_init();
			if (ret < 0)
				change_state(MATCHING_ROOM_DISCONNECT);
			else
				change_state(MATCHING_ROOM_GAME);
		}
	} else if (done_flag < 0) {
		change_state(MATCHING_ROOM_TOP);
		net_error_flag = 1;
	}
	return ret;
}

static int check_adhocctl_disconnect_completed(void)
{
	int adhocctl_state;
	int ret;

	ret = sceNetAdhocctlGetState(&adhocctl_state);
	if (ret < 0)
		return ret;
	if (adhocctl_state != 0)
		return ret;
	if (_mrinfo.state == MATCHING_ROOM_DISCONNECTING_ROOM) {
		ret = utility_net_connect((int)&game_group_name);
		if (ret < 0) {
			printf(net_connect_failed, ret);
			change_state(MATCHING_ROOM_TOP);
		} else {
			change_state(MATCHING_ROOM_CONNECTING_GAME);
		}
	} else if (_mrinfo.state == MATCHING_ROOM_DISCONNECTING) {
		gu_init();
		change_state(MATCHING_ROOM_TOP);
	}
	return ret;
}

static int check_adhocctl_connected_error(void)
{
	int ret;

	ret = polling_error();
	if (ret == 0)
		goto END;
	ret = utility_msgdialog(ret);
	if (ret < 0) {
		printf("utility_msgdialog() failed. ret = 0x%x\n", ret);
		goto END;
	}
	change_state(MATCHING_ROOM_ERROR_DIALOG);
END:
	return ret;
}

static int check_error_dialog_closed(void)
{
	int ret;
	int done_flag;

	done_flag = 0;
	ret = utility_check_msgdialog_completed(&done_flag);
	if (done_flag) {
		change_state(MATCHING_ROOM_DISCONNECT);
		net_error_flag = 1;
	}
	return 0;
}

#ifdef NON_MATCHING
/* the closing state check falls through into the call in the original */
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
	default:
		net_update_multi_player();
		break;
	}
	if ((unsigned int)_mrinfo.state >= MATCHING_ROOM_ROOM_LIST)
		check_adhocctl_connected_error();
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_update);
#endif
