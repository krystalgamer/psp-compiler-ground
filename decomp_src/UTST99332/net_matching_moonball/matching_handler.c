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
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", get_minfo_id);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", clear_minfo);

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

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", D_00019D74);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", child_handler);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching_handler", parent_handler);
