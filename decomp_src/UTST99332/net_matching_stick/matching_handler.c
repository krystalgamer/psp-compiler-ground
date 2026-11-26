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

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019060);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019068);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019070);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019078);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019080);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019088);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019090);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_00019098);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_000190A4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_000190AC);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_000190B4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", D_000190B8);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", child_handler);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/matching_handler", parent_handler);
