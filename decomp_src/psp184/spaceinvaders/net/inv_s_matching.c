/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball matching) */
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

int matching_restart_to_create_room(void);


extern int minfo_sid;
extern int minfo_num;
int sceNetAdhocMatchingStop(int id);
int sceNetAdhocMatchingDelete(int id);
int sceNetAdhocMatchingTerm(void);
int sceKernelDeleteSema(int id);

int sceKernelCreateSema(const char *name, int attr, int init, int max, void *opt);
int sceKernelWaitSemaCB(int id, int n, void *timeout);
int sceKernelSignalSema(int id, int n);
int sceNetAdhocMatchingInit(int size);
int sceNetAdhocMatchingCancelTarget(int id, void *addr);
void *memset(void *, int, unsigned int);
void change_state(int state);
extern int D_0039AE60;

int sceNetAdhocMatchingCreate(int mode, int maxnum, int port, int rxbuflen, unsigned int hello_int, unsigned int ping_int, int init_count, unsigned int msg_delay, void *handler);
int sceNetAdhocMatchingStart(int id, int prio, int stack, int prio2, int stack2, int optlen, void *opt);
int sceNetAdhocMatchingSelectTarget(int id, void *addr, int optlen, void *opt);
int sceUtilityGetSystemParamString(int id, void *str, int len);
int randomize_group_name(void *group_name);
void child_handler(int id, int event, void *addr, int optlen, void *opt);
void parent_handler(int id, int event, void *addr, int optlen, void *opt);
typedef struct { int state; char opt[0x80]; int f84; int f88; int f8c; int f90; int f94; char pad[0x10]; int ctx_id; } MRI_SM; /* spaceinvaders _mrinfo layout */
#define MR (*(MRI_SM *)&_mrinfo)

#define MR (*(MRI_SM *)&_mrinfo)
int matching_start_to_enter_room(void)
{
	int ret;

	MR.f84 = 0;
	ret = sceNetAdhocMatchingCreate(2, MR.f8c, 1, 0x400, 1000000, 2000000, 3, 500000, child_handler);
	if (ret < 0)
		goto error;
	MR.ctx_id = ret;
	sceUtilityGetSystemParamString(1, MR.opt, 0x80);
	ret = sceNetAdhocMatchingStart(MR.ctx_id, 0x36, 0x2000, 0x36, 0x2000, 0x8C, MR.opt);
	if (ret < 0)
		goto error;
	return 0;

error:
	matching_stop();
	return ret;
}

void matching_stop(void);
int matching_restart_to_create_room(void)
{
	int ret;

	matching_stop();

	_mrinfo.hello_opt.game_type = GAME_TYPE_PARENT;
	randomize_group_name(&game_group_name);
	ret = sceNetAdhocMatchingCreate(1, _mrinfo.hello_opt.req_player_num, 1, 1024, 1000000, 2000000, 3, 500000, parent_handler);
	if (ret < 0) {
		goto error;
	}
	_mrinfo.ctx_id = ret;
	_mrinfo.hello_opt.cur_player_num = 1;

	ret = sceUtilityGetSystemParamString(1, (char *)&_mrinfo.hello_opt.nickname, sizeof(struct SceNetAdhocctlNickname));
	if (ret < 0) {
	}

	ret = sceNetAdhocMatchingStart(_mrinfo.ctx_id, 54, 0x2000, 54, 0x2000, sizeof(struct p2p_hello_opt), &_mrinfo.hello_opt);
	if (ret < 0) {
		goto error;
	}

	return 0;

error:
	matching_stop();
	return ret;
}

extern int minfo_sid;
extern int minfo_num;
int sceNetAdhocMatchingStop(int id);
int sceNetAdhocMatchingDelete(int id);
int sceNetAdhocMatchingTerm(void);
int sceKernelDeleteSema(int id);
void matching_stop(void)
{
	u8 *m = (u8 *)&_mrinfo;

	if (*(int *)(m + 0xA8) > 0) {
		sceNetAdhocMatchingStop(*(int *)(m + 0xA8));
		sceNetAdhocMatchingDelete(*(int *)(m + 0xA8));
		*(int *)(m + 0xA8) = 0;
	}
}

int sceKernelCreateSema(const char *name, int attr, int init, int max, void *opt);
int sceKernelWaitSemaCB(int id, int n, void *timeout);
int sceKernelSignalSema(int id, int n);
int sceNetAdhocMatchingInit(int size);
int sceNetAdhocMatchingCancelTarget(int id, void *addr);
void *memset(void *, int, unsigned int);
void change_state(int state);
extern int D_0039AE60;
int matching_start(void)
{
	int ret;

	minfo_num = 0;
	ret = sceKernelCreateSema("Minfo_Sema", 0, 1, 1, 0);
	if (ret < 0)
		goto error;
	minfo_sid = ret;
	memset(minfo, 0, 0x260);
	ret = sceNetAdhocMatchingInit(0x8000);
	if (ret < 0)
		goto error;
	ret = matching_start_to_enter_room();
	if (ret < 0)
		goto error;
	return 0;

error:
	matching_term();
	return ret;
}

void matching_term(void)
{
	matching_stop();
	sceNetAdhocMatchingTerm();
	if (minfo_sid > 0) {
		sceKernelDeleteSema(minfo_sid);
		minfo_sid = 0;
	}
	minfo_num = 0;
}

int matching_select(int peer_idx)
{
	int ret;

	sceKernelWaitSemaCB(minfo_sid, 1, 0);
	if (minfo[peer_idx].status == 2) {
		ret = sceNetAdhocMatchingSelectTarget(MR.ctx_id, &minfo[peer_idx].addr, 0, 0);
	} else {
		randomize_group_name(&game_group_name);
		ret = sceNetAdhocMatchingSelectTarget(MR.ctx_id, &minfo[peer_idx].addr, 8, &game_group_name);
	}
	if (ret >= 0 && minfo[peer_idx].status == 2) {
		minfo[peer_idx].status = 4;
		MR.f94 = peer_idx;
	}
	sceKernelSignalSema(minfo_sid, 1);
	return 0;
}

int matching_cancel(int peer_idx)
{
	int ret;

	sceKernelWaitSemaCB(minfo_sid, 1, 0);
	ret = sceNetAdhocMatchingCancelTarget(D_0039AE60, &minfo[peer_idx].addr);
	if (ret >= 0)
		minfo[peer_idx].status = 2;
	sceKernelSignalSema(minfo_sid, 1);
	change_state(0);
	return 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF64);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF6C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF84);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF8C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF94);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AF9C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AFA8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AFB0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching", D_0007AFB8);
