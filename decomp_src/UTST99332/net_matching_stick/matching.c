#include "common.h"

/* declarations recovered from DWARF */
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
typedef unsigned char SceUChar8;
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
extern int minfo_num;
extern struct minfo minfo[16];

int matching_start_to_enter_room(void);
int matching_restart_to_create_room(void);
int matching_start(void);
int matching_select(int peer_idx);
int matching_cancel(int peer_idx);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelDeleteSema(int semid);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memset(void *s, int c, unsigned int n);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);

typedef void (*SceNetAdhocMatchingHandler)(int id, int event, struct SceNetEtherAddr *peer, int optlen, void *opt);
int sceNetAdhocMatchingCreate(int mode, int maxnum, unsigned short port, int rxbuflen, unsigned int hello_int, unsigned int keepalive_int, int retry_cnt, unsigned int rexmt_int, SceNetAdhocMatchingHandler handler);
int sceNetAdhocMatchingStart(int id, int evthpri, int evthstack, int inthpri, int inthstack, int optlen, void *opt);
int sceUtilityGetSystemParamString(int id, char *str, int len);
void matching_stop(void);
void child_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);
void parent_handler(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);

int matching_start_to_enter_room(void)
{
	int ret;

	_mrinfo.hello_opt.game_type = GAME_TYPE_CHILD;
	ret = sceNetAdhocMatchingCreate(2, _mrinfo.hello_opt.req_player_num, 1, 1024, 1000000, 2000000, 3, 500000, child_handler);
	if (ret < 0) {
		printf("sceNetAdhocMatchingCreate() failed. ret = 0x%x\n", ret);
		goto error;
	}
	_mrinfo.ctx_id = ret;

	ret = sceUtilityGetSystemParamString(1, (char *)&_mrinfo.hello_opt.nickname, sizeof(struct SceNetAdhocctlNickname));
	if (ret < 0) {
		printf("sceUtilityGetSystemParamString() failed. ret = 0x%x\n", ret);
	}

	ret = sceNetAdhocMatchingStart(_mrinfo.ctx_id, 54, 0x2000, 54, 0x2000, sizeof(struct p2p_hello_opt), &_mrinfo.hello_opt);
	if (ret < 0) {
		printf("sceNetAdhocMatchingStart() failed. ret = 0x%x\n", ret);
		goto error;
	}

	return 0;

error:
	matching_stop();
	return ret;
}

int matching_restart_to_create_room(void)
{
	int ret;

	matching_stop();

	_mrinfo.hello_opt.game_type = GAME_TYPE_PARENT;
	randomize_group_name(&game_group_name);
	ret = sceNetAdhocMatchingCreate(1, _mrinfo.hello_opt.req_player_num, 1, 1024, 1000000, 2000000, 3, 500000, parent_handler);
	if (ret < 0) {
		printf("sceNetAdhocMatchingCreate() failed. ret = 0x%x\n", ret);
		goto error;
	}
	_mrinfo.ctx_id = ret;
	_mrinfo.hello_opt.cur_player_num = 1;

	ret = sceUtilityGetSystemParamString(1, (char *)&_mrinfo.hello_opt.nickname, sizeof(struct SceNetAdhocctlNickname));
	if (ret < 0) {
		printf("sceUtilityGetSystemParamString() failed. ret = 0x%x\n", ret);
	}

	ret = sceNetAdhocMatchingStart(_mrinfo.ctx_id, 54, 0x2000, 54, 0x2000, sizeof(struct p2p_hello_opt), &_mrinfo.hello_opt);
	if (ret < 0) {
		printf("sceNetAdhocMatchingStart() failed. ret = 0x%x\n", ret);
		goto error;
	}

	return 0;

error:
	matching_stop();
	return ret;
}

void matching_stop(void) {
    int temp_v0;
    int temp_v0_2;

    if (_mrinfo.ctx_id > 0) {
        temp_v0 = sceNetAdhocMatchingStop(_mrinfo.ctx_id);
        if (temp_v0 < 0) {
            printf("sceNetAdhocMatchingStop() failed. ret = 0x%x\n", temp_v0);
        }
        temp_v0_2 = sceNetAdhocMatchingDelete(_mrinfo.ctx_id);
        if (temp_v0_2 >= 0) {
            _mrinfo.ctx_id = 0;
        } else {
            printf("sceNetAdhocMatchingDelete() failed. ret = 0x%x\n", temp_v0_2);
            _mrinfo.ctx_id = 0;
        }
    }
}

int sceNetAdhocMatchingInit(int poolsize);
void matching_term(void);

int matching_start(void)
{
	int ret;

	minfo_num = 0;

	ret = sceKernelCreateSema("Minfo_Sema", 0, 1, 1, NULL);
	if (ret < 0) {
		printf("sceKernelCreaeSema() failed. ret = 0x%x\n", ret);
		goto error;
	}
	minfo_sid = ret;

	memset(minfo, 0, sizeof(minfo));

	ret = sceNetAdhocMatchingInit(0x8000);
	if (ret < 0) {
		printf("sceNetAdhocMatchingInit() failed. ret = 0x%x\n", ret);
		goto error;
	}

	ret = matching_start_to_enter_room();
	if (ret < 0) {
		goto error;
	}

	return 0;

error:
	matching_term();
	return ret;
}

void matching_term(void) {
    int temp_v0;

    matching_stop();
    temp_v0 = sceNetAdhocMatchingTerm();
    if (temp_v0 >= 0) {

    } else {
        printf("sceNetAdhocMatchingTerm() failed. ret = 0x%x\n", temp_v0);
    }
    if (minfo_sid > 0) {
        sceKernelDeleteSema(minfo_sid);
        minfo_sid = 0;
    }
    minfo_num = 0;
}

int sceNetAdhocMatchingSelectTarget(int id, const struct SceNetEtherAddr *mac, int optlen, void *opt);

int matching_select(int peer_idx)
{
	int ret;

	sceKernelWaitSema(minfo_sid, 1, NULL);
	if (minfo[peer_idx].status == 2) {
		ret = sceNetAdhocMatchingSelectTarget(_mrinfo.ctx_id, &minfo[peer_idx].addr, 0, NULL);
	} else {
		randomize_group_name(&game_group_name);
		ret = sceNetAdhocMatchingSelectTarget(_mrinfo.ctx_id, &minfo[peer_idx].addr, sizeof(game_group_name), &game_group_name);
	}

	if (ret < 0) {
		printf("sceNetAdhocMatchingSelectTarget() failed. ret = 0x%x\n", ret);
		goto error;
	}

	if (minfo[peer_idx].status == 2) {
		minfo[peer_idx].status = 4;
		_mrinfo.requesting_minfo_id = peer_idx;
	}

error:
	sceKernelSignalSema(minfo_sid, 1);
	return 0;
}

int sceNetAdhocMatchingCancelTarget(int id, const struct SceNetEtherAddr *mac);
void change_state(enum matching_room_state state);

int matching_cancel(int peer_idx)
{
	int ret;

	sceKernelWaitSema(minfo_sid, 1, NULL);
	ret = sceNetAdhocMatchingCancelTarget(_mrinfo.ctx_id, &minfo[peer_idx].addr);
	if (ret < 0) {
		printf("sceNetAdhocMatchingCancelTarget() failed. ret = 0x%x\n", ret);
		goto error;
	}

	minfo[peer_idx].status = 2;

error:
	sceKernelSignalSema(minfo_sid, 1);
	change_state(MATCHING_ROOM_ROOM_LIST);
	return 0;
}
