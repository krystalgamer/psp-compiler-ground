#include "common.h"

/* declarations recovered from DWARF */
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
    MATCHING_ROOM_GAME_DISCONNECT = 27,
};
struct p2p_hello_opt;
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
struct minfo;
struct minfo { /* size 0xa4 */
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


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
int printf(const char *fmt, ...);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sprintf(char *buf, const char *fmt, ...);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", draw_net_scan_result_list);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", draw_net_hello_list);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", draw_net_established_list);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", get_nickname);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", D_00018A1C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", D_00018A28);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", draw_net_member_list);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", draw_net_neighbors);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/draw_net", D_00018A70);
