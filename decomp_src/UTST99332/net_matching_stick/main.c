#include "common.h"

/* declarations recovered from DWARF */
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
struct matching_room_info;
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
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};

extern struct matching_room_info _mrinfo;
extern struct SceNetAdhocctlGroupName game_group_name;
extern struct minfo minfo[16];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[327680];
extern short int board[2][3];

void gu_init(void);
static void draw_top(void);
static void draw_scan_result(void);
static void draw_room_list(void);
static void draw_parent_wait(void);
static void draw_child_wait(void);
static void draw_neighbors(void);
static void draw_scanning(void);
static void draw_requesting(void);
static void draw_canceled(void);
static void draw_denied(void);
static void app_draw_frame(void);
static void draw_frame(void);
int main(int argc, char **argv);

/* SDK functions (tools/sdk_protos.h) */
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memset(void *s, int c, unsigned int n);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayWaitVblankStart(void);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuInit(void);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
unsigned int sceKernelGetSystemTimeLow(void);
int sprintf(char *buf, const char *fmt, ...);
void srand(unsigned int seed);
unsigned int strlen(const char *s);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", gu_init);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", D_00018708);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_top);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_scan_result);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", D_00018768);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", D_00018784);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_room_list);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", D_00018834);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_parent_wait);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_child_wait);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_neighbors);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_scanning);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_requesting);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_canceled);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", D_00018914);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_denied);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", app_draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", draw_frame_11E8);

void change_state(enum matching_room_state state) {
    if (state != MATCHING_ROOM_ROOM_LIST) {

    } else {
        net_delete_ptp();
    }
    _mrinfo.state = state;
    _mrinfo.v_cursor_pos = 0;
}

void usage(void) {
    printf("usage: %s.prx\n", "matching_stick");
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/main", main);
