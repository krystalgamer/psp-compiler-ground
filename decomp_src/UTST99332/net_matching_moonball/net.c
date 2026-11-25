#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int;
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlParameter { /* size 0x94 */
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetAdhocctlBSSId bssid;
};
struct SceNetAdhocctlAdhocId;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceUChar8 data[9];
    SceUChar8 padding[3];
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

extern struct SceNetAdhocctlAdhocId adhoc_id;
extern struct matching_room_info _mrinfo;
extern struct SceNetAdhocctlGroupName game_group_name;
extern int handlerId;
extern int evf;
extern int error_code;
extern char event_str[5][16];

static u_int get_random_num(u_int min, u_int max);
int get_bssid(char *bssid);
int randomize_group_name(struct SceNetAdhocctlGroupName *group_name);
static void adhocctl_handler(int event, int error, void *arg);
int net_init(void);
static int net_scan(void);
static int net_connect(void);
static int net_disconnect(void);
static int check_adhocctl_scan_completed(void);
static int check_adhocctl_connect_completed(void);
static int check_adhocctl_disconnect_completed(void);
static int check_adhocctl_connected_error(void);
static int check_error_dialog_closed(void);
int net_update(void);


INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", get_random_num);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", get_bssid);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", randomize_group_name);

void clear_evf(void) {
    evf = 0;
    error_code = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", adhocctl_handler);

int polling_error(void) {
    int var_a0;

    var_a0 = 0;
    if (evf & 1) {
        evf &= ~1;
        var_a0 = error_code;
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_init);

void net_term(void) {
    if (handlerId >= 0) {
        sceNetAdhocctlDelHandler(handlerId);
        handlerId = -1;
    }
    sceNetAdhocctlTerm();
    sceNetAdhocTerm();
    sceNetTerm();
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_scan);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_connect);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", D_00019974);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_disconnect);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_scan_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_connect_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_disconnect_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_connected_error);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_error_dialog_closed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_update);
