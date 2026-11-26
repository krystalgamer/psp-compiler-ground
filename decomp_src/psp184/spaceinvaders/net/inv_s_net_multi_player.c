/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball net_multi_player) */
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef long long unsigned int SceULong64;
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
struct SceNetAdhocctlGroupName;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct minfo;
struct minfo { /* size 0x98 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};

extern struct matching_room_info _mrinfo;
extern struct SceNetAdhocctlGroupName game_group_name;
extern int minfo_sid;
extern struct minfo minfo[16];
extern char ptp_buf[16384];
extern int ptp_sock_id0;
extern int ptp_sock_id;

int matching_get_established_num(void);
int matching_parent_select(struct SceNetEtherAddr *addr);
int matching_parent_cancel(struct SceNetEtherAddr *addr);
static void net_create_listen_socket(void);
static void net_create_connect_socket(void);
void net_delete_ptp(void);
int net_connect_socket(void);
int net_send_members_ptp(void);
int net_flush_members_ptp(void);
int net_recv_members_ptp(void);
int net_update_multi_player(void);

extern u8 D_0039AE58[];

extern u8 D_0039AE58[];
static void net_create_listen_socket(void)
{
	if (ptp_sock_id0 > 0)
		return;
	ptp_sock_id0 = sceNetAdhocPtpListen((void *)D_0039AE58, 0x42, 0x4000, 200000, 200000, 1, 0);
	if (ptp_sock_id0 < 0)
		change_state(17);
	else
		change_state(19);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_create_connect_socket);

void net_delete_ptp(void) {
    if (ptp_sock_id > 0) {
        sceNetAdhocPtpClose(ptp_sock_id, 0);
    }
    ptp_sock_id = 0;
    if (ptp_sock_id0 > 0) {
        sceNetAdhocPtpClose(ptp_sock_id0, 0);
    }
    ptp_sock_id0 = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_connect_socket);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_send_members_ptp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_flush_members_ptp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_recv_members_ptp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", net_update_multi_player);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B414);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B420);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B42C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B438);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B444);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B450);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B45C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B468);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B474);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B480);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B48C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B498);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B4F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B504);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B510);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B51C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B528);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net_multi_player", D_0007B534);
