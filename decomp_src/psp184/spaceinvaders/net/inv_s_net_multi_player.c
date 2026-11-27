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

extern u8 D_0039AE58[];

extern u8 D_0039AE58[];
int matching_restart_to_create_room(void);

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

SceULong64 sceKernelGetSystemTimeWide(void);
int sceKernelWaitSemaCB(int semid, int signal, unsigned int *timeout);
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
void net_create_connect_socket(void)
{
	int i;
	char etherstr[18];

	if (ptp_sock_id0 > 0) {
		return;
	}

	sceKernelWaitSemaCB(minfo_sid, 1, NULL);

	for (i = 0; i < 4; i++) {
		sceNetEtherNtostr(&minfo[i].addr, etherstr);
		if (minfo[i].status == 5) {
			break;
		}
	}

	if (i == 4) {
		change_state(MATCHING_ROOM_START_GAME);
		goto error;
	}

	_mrinfo.informing_minfo_id = i;
	sceNetEtherNtostr(&_mrinfo.local_addr, etherstr);

	ptp_sock_id0 = sceNetAdhocPtpOpen(&_mrinfo.local_addr, 0, &minfo[i].addr, 66, 0x4000, 200000, 200000, 0);
	if (ptp_sock_id0 < 0) {
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

int sceKernelWaitSemaCB(int semid, int signal, unsigned int *timeout);
int sceNetAdhocPtpConnect(int id, unsigned int timeout, int flag);
int sceNetAdhocPtpFlush(int id, unsigned int timeout, int flag);
SceULong64 sceKernelGetSystemTimeWide(void);
void clear_minfo(int id);
int net_connect_socket(void)
{
	int ret, ignore;
	SceULong64 time;

	ignore = 0;
	if (_mrinfo.state != MATCHING_ROOM_PARENT_INFORM_CONNECT) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	time = sceKernelGetSystemTimeWide();
	if (time - _mrinfo.ptp_start_time > 5000000) {
		sceKernelWaitSemaCB(minfo_sid, 1, NULL);
		clear_minfo(_mrinfo.informing_minfo_id);
		sceKernelSignalSema(minfo_sid, 1);
		net_delete_ptp();
		change_state(MATCHING_ROOM_PARENT_START_INFORM);
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	ret = sceNetAdhocPtpConnect(ptp_sock_id0, 0, 1);
	if (ret == (int)0x80410709) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ret < 0) {
		goto error;
	}
error:
ignore:
	if (ignore > 0)
		return 0;
	if (ret < 0)
		change_state(MATCHING_ROOM_DISCONNECT);
	else
		change_state(MATCHING_ROOM_PARENT_INFORM_SEND);
	return ret;
}

int sceKernelWaitSemaCB(int semid, int signal, unsigned int *timeout);
int sceNetAdhocPtpSend(int id, void *data, int *len, unsigned int timeout, int flag);
SceULong64 sceKernelGetSystemTimeWide(void);
int net_send_members_ptp(void)
{
	int buflen;
	int num;
	int i, ret, ignore;

	ignore = 0;
	ret = 0;
	buflen = 0;
	sceKernelWaitSemaCB(minfo_sid, 1, NULL);
	if (_mrinfo.state != MATCHING_ROOM_PARENT_INFORM_SEND) {
		ignore = 1;
		goto ignore;
	}
	memset(_mrinfo.members, 0, sizeof(_mrinfo.members));
	memcpy(&ptp_buf[4], &_mrinfo.local_addr, 6);
	memcpy(&_mrinfo.members[0], &_mrinfo.local_addr, 6);
	num = 1;
	for (i = 0; i < 4; i++) {
		if (minfo[i].status != 5 && minfo[i].status != 6)
			continue;
		memcpy(&ptp_buf[4 + num * 6], &minfo[i].addr, 6);
		memcpy(&_mrinfo.members[num], &minfo[i].addr, 6);
		num++;
	}
	if (num <= 0) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	memcpy(ptp_buf, &num, 4);
	buflen = num * 6 + 4;
	ret = sceNetAdhocPtpSend(ptp_sock_id0, ptp_buf, &buflen, 0, 1);
	if (ret == (int)0x80410709) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ret < 0) {
		goto error;
	}
	_mrinfo.ptp_start_time = sceKernelGetSystemTimeWide();
error:
ignore:
	sceKernelSignalSema(minfo_sid, 1);
	if (ignore > 0)
		return 0;
	if (ret < 0)
		change_state(MATCHING_ROOM_DISCONNECT);
	else
		change_state(MATCHING_ROOM_PARENT_INFORM_FLUSH);
	return ret;
}

int sceKernelWaitSemaCB(int semid, int signal, unsigned int *timeout);
int sceNetAdhocPtpConnect(int id, unsigned int timeout, int flag);
int sceNetAdhocPtpFlush(int id, unsigned int timeout, int flag);
SceULong64 sceKernelGetSystemTimeWide(void);
void clear_minfo(int id);
int net_flush_members_ptp(void)
{
	int ret, ignore;
	SceULong64 time;

	ignore = 0;
	if (_mrinfo.state != MATCHING_ROOM_PARENT_INFORM_FLUSH) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	time = sceKernelGetSystemTimeWide();
	if (time - _mrinfo.ptp_start_time > 5000000) {
		sceKernelWaitSemaCB(minfo_sid, 1, NULL);
		clear_minfo(_mrinfo.informing_minfo_id);
		sceKernelSignalSema(minfo_sid, 1);
		net_delete_ptp();
		change_state(MATCHING_ROOM_PARENT_START_INFORM);
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	ret = sceNetAdhocPtpFlush(ptp_sock_id0, 0, 1);
	if (ret == (int)0x80410709) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ret < 0) {
		goto error;
	}
	minfo[_mrinfo.informing_minfo_id].status = 6;
error:
ignore:
	if (ignore > 0)
		return 0;
	net_delete_ptp();
	if (ret < 0)
		change_state(MATCHING_ROOM_DISCONNECT);
	else
		change_state(MATCHING_ROOM_PARENT_START_INFORM);
	return ret;
}

int sceKernelWaitSemaCB(int semid, int signal, unsigned int *timeout);
int sceNetAdhocPtpAccept(int id, struct SceNetEtherAddr *addr, unsigned short *port, unsigned int timeout, int flag);
int sceNetAdhocPtpRecv(int id, void *buf, int *len, unsigned int timeout, int flag);
int net_recv_members_ptp(void)
{
	struct SceNetEtherAddr parent_addr;
	int buflen;
	int num;
	int i, ret, ignore;

	ignore = 0;
	sceKernelWaitSemaCB(minfo_sid, 1, NULL);
	if (_mrinfo.state != MATCHING_ROOM_CHILD_WAIT) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ptp_sock_id > 0)
		goto recv_from_parent;
	ret = sceNetAdhocPtpAccept(ptp_sock_id0, &parent_addr, NULL, 0, 1);
	if (ret == (int)0x80410709) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ret < 0)
		goto error;
	if (memcmp(&minfo[_mrinfo.requesting_minfo_id].addr, &parent_addr, 6) != 0) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	ptp_sock_id = ret;
recv_from_parent:
	buflen = sizeof(ptp_buf);
	ret = sceNetAdhocPtpRecv(ptp_sock_id, ptp_buf, &buflen, 0, 1);
	if (ret == (int)0x80410709) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	if (ret < 0)
		goto error;
	if (buflen < 4) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	memcpy(&num, ptp_buf, 4);
	if (num <= 0) {
		ret = 0;
		ignore = 1;
		goto ignore;
	}
	ret = num;
	memset(_mrinfo.members, 0, sizeof(_mrinfo.members));
	for (i = 0; i < num; i++)
		memcpy(&_mrinfo.members[i], &ptp_buf[4 + i * 6], 6);
error:
ignore:
	sceKernelSignalSema(minfo_sid, 1);
	if (ignore > 0)
		return 0;
	if (ret < 0)
		change_state(MATCHING_ROOM_DISCONNECT);
	else
		change_state(MATCHING_ROOM_START_GAME);
	return ret;
}

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
