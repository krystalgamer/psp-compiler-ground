/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball draw_net) */
struct SceNetAdhocctlScanInfo;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
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
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct SceNetAdhocctlPeerInfo;
struct SceNetAdhocctlPeerInfo { /* size 0x8c */
    struct SceNetAdhocctlPeerInfo *next;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetEtherAddr mac_addr;
    SceUChar8 padding[2];
};
struct SceNetAdhocMatchingMember;
struct SceNetAdhocMatchingMember { /* size 0xc */
    struct SceNetAdhocMatchingMember *next;
    struct SceNetEtherAddr addr;
    SceUChar8 padding[2];
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
extern int minfo_sid;
extern struct minfo minfo[16];
extern struct SceNetAdhocctlPeerInfo peerinfo[16];
extern struct SceNetAdhocctlScanInfo scaninfo[32];
extern struct SceNetAdhocMatchingMember mmember[17];

void draw_net_scan_result_list(int *x_ptr, int *y_ptr);
void draw_net_hello_list(int *x_ptr, int *y_ptr);
void draw_net_established_list(int *x_ptr, int *y_ptr);
static int get_nickname(int buflen, struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname **n);
void draw_net_member_list(int *x_ptr, int *y_ptr);
void draw_net_neighbors(int *x_ptr, int *y_ptr);

extern int net_error;
extern int net_gid[];
extern int net_num;
extern int net_pause;
extern int net_timeerror;
int pad_sw(void);
int net_update(void);
int net_gamecomm_packinit(void);

typedef struct { int f[10]; } WIN_T;
extern WIN_T win[4];
extern int D_0039AE3C;
void utility_update_netconf(void);
void utility_update_msgdialog(void);
void psp_loopstart(void);
void psp_loopend(void);
int sceGuSync(int mode, int what);
void game_net_term(void);
int _net_term(void);
int sceNetAdhocctlGetState(int *state);
int net_lobbysub(void);
int matching_get_established_num(void);

extern WIN_T win[4];
extern int D_0039AE3C;
void utility_update_netconf(void);
void utility_update_msgdialog(void);
void psp_loopstart(void);
void psp_loopend(void);
int sceGuSync(int mode, int what);
void game_net_term(void);
int _net_term(void);
int sceNetAdhocctlGetState(int *state);
int net_lobbysub(void);
int matching_get_established_num(void);
void win_init(void)
{
	int i;

	for (i = 0; i < 4; i++) {

		win[i].f[0] = 0;
		win[i].f[6] = 0;
		win[i].f[9] = 0;
		win[i].f[1] = 0;
		win[i].f[2] = 0;
		win[i].f[5] = 1;
		win[i].f[8] = 0;
		win[i].f[7] = 1;
		win[i].f[3] = 0;
		win[i].f[4] = 0;

	}
}

void gu_init(void) {
}

void utility_update(void)
{
	switch ((int)_mrinfo.state) {
	case 5:
	case 8:
		utility_update_netconf();
		break;
	case 10:
		utility_update_msgdialog();
		break;
	}
}

void change_state(enum matching_room_state state) {
    if (state != MATCHING_ROOM_ROOM_LIST) {

    } else {
        net_delete_ptp();
    }
    _mrinfo.state = state;
    _mrinfo.v_cursor_pos = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", get_nickname);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_p2p_game_parameter);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", D_0007B554);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_established_list);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_scan_result_list);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_member_list);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_hello_list);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_neighbors);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", D_0007B5A8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_scan);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_canceled);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", drawpic);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", net_init);

extern int net_error;
extern int net_gid[];
extern int net_num;
extern int net_pause;
extern int net_timeerror;
int pad_sw(void);
int net_update(void);
int net_gamecomm_packinit(void);
void net_core(void)
{
	utility_update();
	net_update();
}

void net_term(void)
{
	int state;

	sceNetAdhocctlGetState(&state);
	change_state(17);
	do {
		psp_loopstart();
		psp_loopend();
		net_gamecomm_pack();
	} while (_mrinfo.state != 0);
	game_net_term();
	_net_term();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", net_lobbysub);

int net_lobby(void)
{
	int ret;

	ret = net_lobbysub();
	if (ret == 1)
		return 1;
	if (ret == 2)
		return 2;
	return 1;
}

int net_gamecomm_pack(void)
{
	net_core();
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", net_gamecomm_packinit);

int net_gamecomm_packend(void)
{
	if (net_errorget() == 2) {
		do {
			psp_loopstart();
			sceGuSync(0, 0);
			net_gamecomm_pack();
			psp_loopend();
		} while (_mrinfo.state != 0);
		return 1;
	}
	return _mrinfo.state == 0;
}

int net_mynumget(void)
{
	return net_num;
}

void net_mynumset(int num)
{
	net_num = num;
}

int net_errorget(void)
{
	return net_error;
}

void net_errorset(int err)
{
	net_error = err;
}

int net_gidget(int i)
{
	return net_gid[i];
}

int *net_gidgetadd(void)
{
	return net_gid;
}

void net_gidset(int gid, int i)
{
	net_gid[i] = gid;
}

void net_pauseset(void)
{
	net_pause = (net_pause + 1) & 1;
}

void net_pausewait(void)
{
	net_timeerror = 0;
	net_gamecomm_packinit();
	net_timeerror = 1;
}

int net_pauseget(void)
{
	return net_pause;
}

int net_entryget(void)
{
	if (D_0039AE3C)
		return matching_get_established_num();
	return 0;
}

int net_timeerrorget(void)
{
	return net_timeerror;
}

int net_user_cancel(void)
{
	if (pad_sw() & 8)
		return 1;
	return 0;
}
