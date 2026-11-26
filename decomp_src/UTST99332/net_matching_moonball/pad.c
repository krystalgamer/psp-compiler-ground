#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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
struct SceNetAdhocctlNickname;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
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
struct minfo;
struct minfo { /* size 0x98 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};

extern struct matching_room_info _mrinfo;
extern int minfo_num;
extern struct minfo minfo[16];
extern u_int32 cont;


static void pad_circle(void);
static void pad_triangle(void);
static void pad_cross(void);
int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

void change_state(enum matching_room_state state);
int matching_get_established_num(void);
int matching_select(int index);
int matching_cancel(int index);

void pad_circle(void)
{
	switch (_mrinfo.state) {
	case MATCHING_ROOM_TOP:
		change_state(MATCHING_ROOM_CONNECT_ROOM);
		break;
	case MATCHING_ROOM_ROOM_LIST:
		if (minfo[_mrinfo.v_cursor_pos].status != 0) {
			matching_select(_mrinfo.v_cursor_pos);
			change_state(MATCHING_ROOM_REQUESTING);
		}
		break;
	case MATCHING_ROOM_PARENT_WAIT:
		if (matching_get_established_num() > 0) {
			change_state(MATCHING_ROOM_PARENT_START_INFORM);
		}
		break;
	default:
		break;
	}
}

void pad_triangle(void) {
    int var_a0;

    var_a0 = 1;
    if ((_mrinfo.state != MATCHING_ROOM_TOP) && (var_a0 = 0xC, (_mrinfo.state != MATCHING_ROOM_ROOM_LIST))) {

    } else {
        change_state(var_a0);
    }
}

void pad_cross(void)
{
	switch (_mrinfo.state) {
	case MATCHING_ROOM_SCAN_RESULT:
		change_state(MATCHING_ROOM_TOP);
		break;
	case MATCHING_ROOM_ROOM_LIST:
	case MATCHING_ROOM_PARENT_WAIT:
		change_state(MATCHING_ROOM_DISCONNECT);
		break;
	case MATCHING_ROOM_REQUESTING:
	case MATCHING_ROOM_CHILD_WAIT:
		matching_cancel(_mrinfo.requesting_minfo_id);
		break;
	case MATCHING_ROOM_NEIGHBORS:
	case MATCHING_ROOM_CANCELED:
	case MATCHING_ROOM_DENIED:
		change_state(MATCHING_ROOM_ROOM_LIST);
		break;
	default:
		break;
	}
}

void pad_square(void) {
    if (_mrinfo.state != MATCHING_ROOM_ROOM_LIST) {

    } else if (_mrinfo.hello_opt.game_type == GAME_TYPE_CHILD) {
        change_state(0x14);
    }
}

void pad_up(void) {
    if (_mrinfo.state != MATCHING_ROOM_ROOM_LIST) {

    } else if (_mrinfo.v_cursor_pos > 0) {
        _mrinfo.v_cursor_pos -= 1;
    }
}

void pad_down(void) {
    int temp_v0;

    if (_mrinfo.state == MATCHING_ROOM_ROOM_LIST) {
        temp_v0 = _mrinfo.v_cursor_pos + 1;
        if (temp_v0 < minfo_num) {
            _mrinfo.v_cursor_pos = temp_v0;
        }
    }
}

extern u_int32 cont_7D8D4;
#define cont cont_7D8D4

void game_pad_read(void);
void game_pad_read_top(void);

int pad_read(void)
{
	u_int32 prev = cont;
	u_int32 padd;
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);

	switch (_mrinfo.state) {
	case MATCHING_ROOM_GAME:
		game_pad_read();
		return 1;
	case MATCHING_ROOM_CONNECTING_ROOM:
	case MATCHING_ROOM_CONNECTING_GAME:
	case MATCHING_ROOM_ERROR_DIALOG:
		return 1;
	case MATCHING_ROOM_TOP:
		if (padd & 1) {
			return 0;
		}
		game_pad_read_top();
		break;
	default:
		break;
	}

	if (_mrinfo.ignore_pad_input == 1) {
		_mrinfo.ignore_pad_input = 0;
		return 1;
	}

	if (padd & 0x2000) {
		pad_circle();
	}
	if (padd & 0x1000) {
		pad_triangle();
	}
	if (padd & 0x4000) {
		pad_cross();
	}
	if (padd & 0x8000) {
		pad_square();
	}
	if (padd & 0x10) {
		pad_up();
	}
	if (padd & 0x40) {
		pad_down();
	}

	return 1;
}
