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

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", matching_start_to_enter_room);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", matching_restart_to_create_room);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", D_00019B1C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", D_00019B4C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", D_00019B84);

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

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", matching_start);

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

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", matching_select);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/matching", matching_cancel);
