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
struct SceNetAdhocctlGroupName;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct minfo;
struct minfo { /* size 0xa4 */
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

int matching_get_established_members(struct SceNetEtherAddr *addrs);
int matching_get_members(struct SceNetEtherAddr *addrs);
static void net_create_listen_socket(void);
static void net_create_connect_socket(void);
int net_connect_socket(void);
int net_send_members_ptp(void);
int net_flush_members_ptp(void);
int net_recv_members_ptp(void);
int net_update_multi_player(void);

/* SDK functions (tools/sdk_protos.h) */
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);

void *memcpy(void *d, const void *s, unsigned int n);

int matching_get_established_members(struct SceNetEtherAddr *addrs)
{
	int i, j;

	sceKernelWaitSema(minfo_sid, 1, NULL);

	memcpy(&addrs[0], &_mrinfo.local_addr, sizeof(struct SceNetEtherAddr));
	j = 1;
	for (i = 0; i < 16; i++) {
		if (minfo[i].status == 5 || minfo[i].status == 6) {
			memcpy(&addrs[j], &minfo[i].addr, sizeof(struct SceNetEtherAddr));
			j++;
		}
	}

	sceKernelSignalSema(minfo_sid, 1);

	return j;
}

int matching_get_members(struct SceNetEtherAddr *addrs)
{
	int i, j;
	struct SceNetEtherAddr zero_addr;

	sceKernelWaitSema(minfo_sid, 1, NULL);
	memset(&zero_addr, 0, sizeof(zero_addr));
	for (i = 0, j = 0; i < 16; i++) {
		if (memcmp(&_mrinfo.members[i], &_mrinfo.local_addr, sizeof(struct SceNetEtherAddr)) == 0) {
			continue;
		}
		if (memcmp(&_mrinfo.members[i], &zero_addr, sizeof(struct SceNetEtherAddr)) == 0) {
			break;
		}
		addrs[j] = _mrinfo.members[i];
		j++;
	}
	sceKernelSignalSema(minfo_sid, 1);

	return j;
}

extern int D_000E3FF4;

int matching_get_established_num(void) {
    return D_000E3FF4 - 1;
}

extern int D_000E4014;

int matching_parent_select(struct SceNetEtherAddr *addr) {
    int temp_v0;

    temp_v0 = sceNetAdhocMatchingSelectTarget(D_000E4014, addr, 8, &game_group_name);
    if (temp_v0 >= 0) {

    } else {
        printf("sceNetAdhocMatchingSelectTarget() failed. ret = 0x%x\n", temp_v0);
    }
    return temp_v0;
}

extern int D_000E4014;

int matching_parent_cancel(struct SceNetEtherAddr *addr) {
    return sceNetAdhocMatchingCancelTarget(D_000E4014, addr);
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
		sceKernelWaitSema(minfo_sid, 1, NULL);
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
		printf("sceNetAdhocPtpConnect() failed. ret = 0x%x\n", ret);
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
	sceKernelWaitSema(minfo_sid, 1, NULL);
	if (_mrinfo.state != MATCHING_ROOM_PARENT_INFORM_SEND) {
		ignore = 1;
		goto ignore;
	}
	memset(_mrinfo.members, 0, sizeof(_mrinfo.members));
	memcpy(&ptp_buf[4], &_mrinfo.local_addr, 6);
	memcpy(&_mrinfo.members[0], &_mrinfo.local_addr, 6);
	num = 1;
	for (i = 0; i < 16; i++) {
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
		printf("sceNetAdhocPtpSend() failed. ret = 0x%x\n", ret);
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
		sceKernelWaitSema(minfo_sid, 1, NULL);
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
		printf("sceNetAdhocPtpFlush() failed. ret = 0x%x\n", ret);
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

int sceNetAdhocPtpAccept(int id, struct SceNetEtherAddr *addr, unsigned short *port, unsigned int timeout, int flag);
int sceNetAdhocPtpRecv(int id, void *buf, int *len, unsigned int timeout, int flag);
int net_recv_members_ptp(void)
{
	struct SceNetEtherAddr parent_addr;
	int buflen;
	int num;
	int i, ret, ignore;

	ignore = 0;
	sceKernelWaitSema(minfo_sid, 1, NULL);
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
