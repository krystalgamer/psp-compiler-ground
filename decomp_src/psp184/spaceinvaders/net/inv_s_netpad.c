/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball pad) */
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
struct matching_room_info { /* size 0xd8 */
    enum matching_room_state state;
    struct p2p_hello_opt hello_opt;
    struct p2p_hello_opt *agreed_hello_opt;
    int requesting_minfo_id;
    int v_cursor_pos;
    int ignore_pad_input;
    struct SceNetEtherAddr local_addr;
    int ctx_id;
    struct SceNetEtherAddr members[4];
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
static void pad_square(void);
static void pad_up(void);
static void pad_down(void);
int pad_read(void);


extern int minfo_num;

void matching_cancel(int id);

typedef struct { u8 pad[6]; u8 num; u8 rest[0x3F0 - 7]; } NETDATA;
extern NETDATA netdata[];
int _net_init(void);
int matching_get_established_num(void);
int matching_select(int peer_idx);
int net_mynumget(void);
void net_mynumset(int num);
int *net_gidgetadd(void);
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
void sceNetEtherStrton(const char *str, struct SceNetEtherAddr *addr);
void pad_circle(void)
{
	char etherstr[32];
	struct SceNetEtherAddr mac;
	int *gid;

	switch ((int)_mrinfo.state) {
	case MATCHING_ROOM_TOP:
		_net_init();
		change_state(MATCHING_ROOM_CONNECT_ROOM);
		break;
	case MATCHING_ROOM_ROOM_LIST:
		if (minfo[_mrinfo.v_cursor_pos].status != 0) {
			matching_select(_mrinfo.v_cursor_pos);
			if (_mrinfo.hello_opt.game_type == 0) {
				net_mynumset(minfo[_mrinfo.v_cursor_pos].hello_opt.cur_player_num);
				netdata[net_mynumget()].num = net_mynumget();
				sceNetEtherNtostr(&minfo[_mrinfo.v_cursor_pos].addr, etherstr);
				sceNetEtherStrton(etherstr, &mac);
				gid = net_gidgetadd();
				gid[0] = mac.data[0];
				gid[1] = mac.data[1];
				gid[2] = mac.data[2];
				gid[3] = mac.data[3];
				gid[4] = mac.data[4];
				gid[5] = mac.data[5];
			}
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
}

typedef struct { int state; char pad[0x90]; int id; } MRI_SI; /* spaceinvaders _mrinfo layout */

static void pad_cross(void)
{
	switch (_mrinfo.state) {
	case 13:
		matching_cancel(((MRI_SI *)&_mrinfo)->id);
		break;
	case 3:
	case 11:
	case 12:
	case 14:
	case 15:
	case 21:
		change_state(0);
		break;
	}
}

void pad_square(void) {
    if (_mrinfo.state != MATCHING_ROOM_ROOM_LIST) {

    } else if (_mrinfo.hello_opt.game_type == GAME_TYPE_CHILD) {
        change_state(0x14);
    }
}

extern int minfo_num;
static void pad_up(void)
{
	u8 *m = (u8 *)&_mrinfo;

	if (*(int *)m == 11) {
		if (*(int *)(m + 0x98) + 1 < minfo_num)
			*(int *)(m + 0x98) += 1;
	}
}

static void pad_down(void)
{
	u8 *m = (u8 *)&_mrinfo;

	if (*(int *)m == 11) {
		if (*(int *)(m + 0x98) > 0)
			*(int *)(m + 0x98) -= 1;
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netpad", Lobby_pad_read);
