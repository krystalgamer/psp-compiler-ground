#include "common.h"

/* declarations recovered from DWARF */
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

static void net_create_listen_socket(void);
static void net_create_connect_socket(void);
int net_connect_socket(void);
int net_send_members_ptp(void);
int net_flush_members_ptp(void);
int net_recv_members_ptp(void);
int net_update_multi_player(void);

/* SDK functions (tools/sdk_protos.h) */
int printf(const char *fmt, ...);


extern int D_000DB7D8;

/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);

int matching_get_established_num(void) {
    return D_000DB7D8 - 1;
}

extern int D_000DB7F8;

int matching_parent_select(struct SceNetEtherAddr *addr) {
    int temp_v0;

    temp_v0 = sceNetAdhocMatchingSelectTarget(D_000DB7F8, addr, 8, &game_group_name);
    if (temp_v0 >= 0) {

    } else {
        printf("sceNetAdhocMatchingSelectTarget() failed. ret = 0x%x\n", temp_v0);
    }
    return temp_v0;
}

extern int D_000DB7F8;

int matching_parent_cancel(struct SceNetEtherAddr *addr) {
    return sceNetAdhocMatchingCancelTarget(D_000DB7F8, addr);
}

int sceNetAdhocPtpListen(const struct SceNetEtherAddr *saddr, unsigned short sport, unsigned int bufsize, unsigned int rexmt_int, int rexmt_cnt, int backlog, int flag);
int sceNetAdhocPtpOpen(const struct SceNetEtherAddr *saddr, unsigned short sport, const struct SceNetEtherAddr *daddr, unsigned short dport, unsigned int bufsize, unsigned int rexmt_int, int rexmt_cnt, int flag);
SceULong64 sceKernelGetSystemTimeWide(void);
void change_state(enum matching_room_state state);

void net_create_listen_socket(void)
{
	if (ptp_sock_id0 > 0) {
		return;
	}

	ptp_sock_id0 = sceNetAdhocPtpListen(&_mrinfo.local_addr, 66, 0x4000, 200000, 200000, 1, 0);
	if (ptp_sock_id0 < 0) {
		printf("sceNetAdhocPtpListen() failed. ret = 0x%x\n", ptp_sock_id0);
		change_state(MATCHING_ROOM_DISCONNECT);
		return;
	}

	change_state(MATCHING_ROOM_CHILD_WAIT);
}

void net_create_connect_socket(void)
{
	int i;

	if (ptp_sock_id0 > 0) {
		return;
	}

	sceKernelWaitSema(minfo_sid, 1, NULL);

	for (i = 0; i < 16; i++) {
		if (minfo[i].status == 5) {
			break;
		}
	}

	if (i == 16) {
		change_state(MATCHING_ROOM_START_GAME);
		goto error;
	}

	_mrinfo.informing_minfo_id = i;

	ptp_sock_id0 = sceNetAdhocPtpOpen(&_mrinfo.local_addr, 0, &minfo[i].addr, 66, 0x4000, 200000, 200000, 0);
	if (ptp_sock_id0 < 0) {
		printf("sceNetAdhocPtpOpen() failed. ret = 0x%x\n", ptp_sock_id0);
		change_state(MATCHING_ROOM_DISCONNECT);
	} else {
		change_state(MATCHING_ROOM_PARENT_INFORM_CONNECT);
	}

	_mrinfo.ptp_start_time = sceKernelGetSystemTimeWide();

error:
	sceKernelSignalSema(minfo_sid, 1);
}

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

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net_multi_player", net_connect_socket);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net_multi_player", net_send_members_ptp);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net_multi_player", net_flush_members_ptp);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net_multi_player", net_recv_members_ptp);

int matching_restart_to_create_room(void);
int net_update_multi_player(void)
{
	switch (_mrinfo.state) {
	case 20:
		if (matching_restart_to_create_room() < 0)
			change_state(17);
		else
			change_state(21);
		break;
	case 18:
		net_create_listen_socket();
		break;
	case 19:
		net_recv_members_ptp();
		break;
	case 21:
		break;
	case 22:
		net_create_connect_socket();
		break;
	case 23:
		net_connect_socket();
		break;
	case 24:
		net_send_members_ptp();
		break;
	case 25:
		net_flush_members_ptp();
		break;
	}
	return 0;
}
