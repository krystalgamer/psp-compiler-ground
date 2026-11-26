#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
struct SceNetAdhocctlAdhocId;
typedef unsigned char SceUChar8;
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
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
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
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
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
extern struct minfo minfo[16];
extern const char *const room_color_str[4];
extern const char *const room_speed_str[3];

void draw_top_for_game(void);
void draw_p2p_game_parameter(int index, int color, int x, int *y_ptr);
int game_pad_read_top(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlPeekBufferPositive(SceCtrlData *data, int count);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_00019364);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_0001936C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_00019374);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_0001937C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", room_color_str);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_00019398);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_000193A0);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", D_000193A8);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/stick_main", room_speed_str);

int snprintf(char *buf, unsigned int size, const char *fmt, ...);
void draw_top_for_game(void)
{
	char mess_buff[128];
	int x, y, color;

	y = 61;
	snprintf(mess_buff, sizeof(mess_buff), "Matching Parameter");
	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 15;
	x += 24;

	color = (_mrinfo.v_cursor_pos == 0) ? 0xff : 0xffffff;
	sprintf(mess_buff, "Color: %s", room_color_str[_mrinfo.hello_opt.game_param.color]);
	sceGuDebugPrint(x, y, color, mess_buff);
	y += 10;

	color = (_mrinfo.v_cursor_pos == 1) ? 0xff : 0xffffff;
	sprintf(mess_buff, "Speed: %s", room_speed_str[_mrinfo.hello_opt.game_param.speed]);
	sceGuDebugPrint(x, y, color, mess_buff);
	y += 10;

	color = (_mrinfo.v_cursor_pos == 2) ? 0xff : 0xffffff;
	sprintf(mess_buff, "Player num: %d", _mrinfo.hello_opt.req_player_num);
	sceGuDebugPrint(x, y, color, mess_buff);
}

void draw_p2p_game_parameter(int index, int color, int x, int *y_ptr)
{
	char mess_buff[128];
	int y;

	y = *y_ptr;
	if (_mrinfo.hello_opt.game_type != GAME_TYPE_CHILD)
		return;
	sprintf(mess_buff, "Color:%s    Speed: %s   PlayerNum: %d/%d",
		room_color_str[minfo[index].hello_opt.game_param.color],
		room_speed_str[minfo[index].hello_opt.game_param.speed],
		minfo[index].hello_opt.cur_player_num,
		minfo[index].hello_opt.req_player_num);
	sceGuDebugPrint(x, y, color, mess_buff);
	y += 10;
	*y_ptr = y;
}

extern u_int32 D_0006C2A0;
#define cont D_0006C2A0
int game_pad_read_top(void)
{

	u_int32 prev;
	u_int32 padd;
	SceCtrlData buf;

	prev = cont;
	sceCtrlPeekBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd = cont & (cont ^ prev);

	if (padd & 0x0010) {
		if (_mrinfo.v_cursor_pos > 0)
			_mrinfo.v_cursor_pos--;
	}
	if (padd & 0x0020) {
		if (_mrinfo.v_cursor_pos == 0) {
			if (_mrinfo.hello_opt.game_param.color + 1 < 4)
				_mrinfo.hello_opt.game_param.color++;
		} else if (_mrinfo.v_cursor_pos == 1) {
			if (_mrinfo.hello_opt.game_param.speed + 1 < 3)
				_mrinfo.hello_opt.game_param.speed++;
		} else if (_mrinfo.v_cursor_pos == 2) {
			if (_mrinfo.hello_opt.req_player_num < 16)
				_mrinfo.hello_opt.req_player_num++;
		}
	}
	if (padd & 0x0040) {
		if (_mrinfo.v_cursor_pos + 1 < 3)
			_mrinfo.v_cursor_pos++;
	}
	if (padd & 0x0080) {
		if (_mrinfo.v_cursor_pos == 0) {
			if (_mrinfo.hello_opt.game_param.color != 0)
				_mrinfo.hello_opt.game_param.color--;
		} else if (_mrinfo.v_cursor_pos == 1) {
			if (_mrinfo.hello_opt.game_param.speed != 0)
				_mrinfo.hello_opt.game_param.speed--;
		} else if (_mrinfo.v_cursor_pos == 2) {
			if (_mrinfo.hello_opt.req_player_num > 2)
				_mrinfo.hello_opt.req_player_num--;
		}
	}
	return 1;
}
#undef cont
