#include "common.h"

/* declarations recovered from DWARF */
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
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
extern int minfo_num;
extern struct minfo minfo[16];
extern char *eventtypestr[11];

static int get_minfo_id(struct SceNetEtherAddr *addr);
int clear_minfo(int index);
void child_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);
void parent_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);

int sceNetAdhocctlGetNameByAddr(const struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname *nickname);

static int get_minfo_id(struct SceNetEtherAddr *addr)
{
	int i;

	for (i = 0; i < 16; i++) {
		if (memcmp(&minfo[i].addr, addr, sizeof(struct SceNetEtherAddr)) == 0) {
			return i;
		}
		if (minfo[i].status == 0) {
			minfo[i].status = 1;
			memcpy(&minfo[i].addr, addr, sizeof(struct SceNetEtherAddr));
			sceNetAdhocctlGetNameByAddr(addr, &minfo[i].hello_opt.nickname);
			minfo_num++;
			return i;
		}
	}

	return -1;
}

int clear_minfo(int index)
{
	int i;

	memset(&minfo[index], 0, sizeof(struct minfo));
	minfo[index].status = 0;

	for (i = index; i < 15; i++) {
		memcpy(&minfo[i], &minfo[i + 1], sizeof(struct minfo));
	}

	memset(&minfo[15], 0, sizeof(struct minfo));
	minfo[15].status = 0;
	minfo_num--;

	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D1C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D24);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D2C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D34);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D3C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D44);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D4C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D54);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D60);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D68);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D70);

void change_state(enum matching_room_state state);
int sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);

void child_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt)
{
	char etherstr[18];
	int i;

	if (ev == 1 && optlen == sizeof(struct p2p_hello_opt)) {
		if (((struct p2p_hello_opt *)opt)->game_type != GAME_TYPE_PARENT) {
			return;
		}
	}

	sceNetEtherNtostr(peer, etherstr);
	printf("%s from %s\n", eventtypestr[ev], etherstr);

	sceKernelWaitSema(minfo_sid, 1, NULL);
	i = get_minfo_id(peer);
	if (i < 0) {
		goto bad;
	}

	switch (ev) {
	case 1:
		if (minfo[i].status == 5) {
			break;
		}
		minfo[i].status = 2;
		memcpy(&minfo[i].addr, peer, sizeof(struct SceNetEtherAddr));
		if (optlen == sizeof(struct p2p_hello_opt)) {
			memcpy(&minfo[i].hello_opt, opt, sizeof(struct p2p_hello_opt));
		}
		break;
	case 4:
		if (_mrinfo.state == MATCHING_ROOM_REQUESTING && i == _mrinfo.requesting_minfo_id) {
			clear_minfo(i);
			change_state(MATCHING_ROOM_DENIED);
		}
		break;
	case 6:
		if (optlen == sizeof(struct SceNetAdhocctlGroupName)) {
			game_group_name = *(struct SceNetAdhocctlGroupName *)opt;
		}
		break;
	case 7:
		memcpy(&_mrinfo.parent_addr, peer, sizeof(struct SceNetEtherAddr));
		_mrinfo.agreed_hello_opt = &minfo[i].hello_opt;
		minfo[i].status = 5;
		change_state(MATCHING_ROOM_CHILD_ENTER_ROOM);
		break;
	case 10:
		if ((_mrinfo.state == MATCHING_ROOM_CHILD_ENTER_ROOM || _mrinfo.state == MATCHING_ROOM_CHILD_WAIT)
		    && i == _mrinfo.requesting_minfo_id) {
			clear_minfo(i);
			change_state(MATCHING_ROOM_CANCELED);
			break;
		}
		if (minfo[i].status == 5) {
			break;
		}
		/* fallthrough */
	case 8:
		clear_minfo(i);
		if (i != _mrinfo.requesting_minfo_id) {
			break;
		}
		switch (_mrinfo.state) {
		case MATCHING_ROOM_REQUESTING:
			change_state(MATCHING_ROOM_DENIED);
			break;
		case MATCHING_ROOM_CHILD_ENTER_ROOM:
		case MATCHING_ROOM_CHILD_WAIT:
			change_state(MATCHING_ROOM_CANCELED);
			break;
		default:
			break;
		}
		break;
	}

bad:
	sceKernelSignalSema(minfo_sid, 1);
}

int matching_parent_select(struct SceNetEtherAddr *addr);
int sceNetAdhocMatchingCancelTarget(int id, const struct SceNetEtherAddr *mac);
int sceNetAdhocMatchingSetHelloOpt(int id, int optlen, const void *opt);

void parent_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt)
{
	int ret, i;
	char etherstr[18];

	sceNetEtherNtostr(peer, etherstr);
	printf("%s from %s\n", eventtypestr[ev], etherstr);

	if (_mrinfo.state >= MATCHING_ROOM_PARENT_START_INFORM && _mrinfo.state <= MATCHING_ROOM_PARENT_INFORM_FLUSH) {
		goto bad;
	}

	sceKernelWaitSema(minfo_sid, 1, NULL);

	i = get_minfo_id(peer);
	if (i < 0) {
		goto bad;
	}

	switch (ev) {
	case 2:
		if (_mrinfo.state != MATCHING_ROOM_PARENT_WAIT) {
			sceNetAdhocMatchingCancelTarget(_mrinfo.ctx_id, &minfo[i].addr);
			break;
		}
		memcpy(&minfo[i].addr, peer, sizeof(struct SceNetEtherAddr));
		matching_parent_select(peer);
		minfo[i].status = 3;
		break;
	case 3:
	case 5:
		if (minfo[i].status == 3) {
			clear_minfo(i);
			break;
		}
		/* fallthrough */
	case 8:
	case 10:
		if (minfo[i].status == 6) {
			break;
		}
		if (minfo[i].status == 5) {
			_mrinfo.hello_opt.cur_player_num--;
			sceNetAdhocMatchingSetHelloOpt(_mrinfo.ctx_id, sizeof(struct p2p_hello_opt), &_mrinfo.hello_opt);
		}
		clear_minfo(i);
		break;
	case 7:
		_mrinfo.agreed_hello_opt = &_mrinfo.hello_opt;
		minfo[i].status = 5;
		_mrinfo.hello_opt.cur_player_num++;
		sceNetAdhocMatchingSetHelloOpt(_mrinfo.ctx_id, sizeof(struct p2p_hello_opt), &_mrinfo.hello_opt);
		break;
	}

bad:
	sceKernelSignalSema(minfo_sid, 1);
}
