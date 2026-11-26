#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspIVector2;
struct ScePspIVector2 { /* size 0x8 */
    int x;
    int y;
};
typedef struct ScePspIVector2 ScePspIVector2;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x10 */
    u_int32 c;
    ScePspFVector3 vtx;
};
typedef struct _anon1 MODEL;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _anon2;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct _anon2 { /* size 0x2c */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
    float vtx_x;
    float vtx_y;
    int detect;
    u_int32 last_v;
    struct SceNetEtherAddr addr;
};
typedef struct _anon2 OBJECT;
struct SceNetAdhocPdpStat;
typedef short unsigned int SceUShort16;
struct SceNetAdhocPdpStat { /* size 0x14 */
    struct SceNetAdhocPdpStat *next;
    int id;
    struct SceNetEtherAddr laddr;
    SceUShort16 lport;
    unsigned int rcv_sb_cc;
};
typedef short unsigned int u_int16;
struct SceNetAdhocGameModeOptData;
typedef unsigned int SceSize;
typedef unsigned int SceUInt32;
struct SceNetAdhocGameModeOptData { /* size 0x8 */
    SceSize size;
    SceUInt32 flag;
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
struct _anon3;
struct _anon3 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon3 POS;
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlGroupName;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
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
struct _anon4;
struct _anon4 { /* size 0x8 */
    u_int32 counter;
    u_int32 last_c;
};
typedef struct _anon4 STATISTICS;

extern struct matching_room_info _mrinfo;
extern int room_color_val[4];
extern int room_speed_val[3];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern POS world;
extern MODEL model[2500];
extern OBJECT obj[17];
extern struct SceNetAdhocctlNickname nickname[17];
extern u_int32 last_v;
extern int display_menu;
extern short int board[2][3];
extern char etherstr[18];
extern struct SceNetAdhocctlParameter adhocctl_param;
extern int peer_num;
extern struct SceNetEtherAddr peer_addr[16];
extern int peer_id[16];
extern STATISTICS rcvpkt[17];
extern u_int32 cont;
extern int socket_id;
extern struct SceNetEtherAddr local_addr;

static void rot_trans_pers(ScePspFVector3 *in, ScePspIVector2 *out);
static void draw_string(void);
static void set_object(float *analog);
void draw_game(void);
static void init_param(void);
int game_re_init_gu(void);
int game_pad_read(void);
int game_net_init(void);
int game_net_term(void);
int send_position(OBJECT *obj);
int recv_allpacket(OBJECT *obj);
int send_recv_game_data(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuColor(unsigned int color);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);
int puts(const char *s);
int sceCtrlPeekBufferPositive(SceCtrlData *data, int count);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);
int sceKernelDcacheWritebackAll(void);
int sprintf(char *buf, const char *fmt, ...);

#ifndef SCEGU_MATRIX_PROJECTION
#define SCEGU_MATRIX_PROJECTION            0
#endif
#ifndef SCEGU_MATRIX_WORLD
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef SCEGU_SCR_WIDTH
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef SCEGU_SCR_HEIGHT
#define SCEGU_SCR_HEIGHT      272
#endif
static void rot_trans_pers(ScePspFVector3 *in, ScePspIVector2 *out)
{
	ScePspFMatrix4  wmat, pmat;
	ScePspFVector4  tmp1, tmp2;

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumStoreMatrix(&pmat);
	sceGumMatrixMode(SCEGU_MATRIX_WORLD);
	sceGumStoreMatrix(&wmat);
	tmp1.x=wmat.x.x*in->x+wmat.y.x*in->y+wmat.z.x*in->z+wmat.w.x;
	tmp1.y=wmat.x.y*in->x+wmat.y.y*in->y+wmat.z.y*in->z+wmat.w.y;
	tmp1.z=wmat.x.z*in->x+wmat.y.z*in->y+wmat.z.z*in->z+wmat.w.z;
	tmp1.w=wmat.x.w*in->x+wmat.y.w*in->y+wmat.z.w*in->z+wmat.w.z;

	tmp2.x=pmat.x.x*tmp1.x+pmat.y.x*tmp1.y+pmat.z.x*tmp1.z;
	tmp2.y=pmat.x.y*tmp1.x+pmat.y.y*tmp1.y+pmat.z.y*tmp1.z;
	tmp2.z=pmat.x.z*tmp1.x+pmat.y.z*tmp1.y+pmat.z.z*tmp1.z;
	tmp2.w=pmat.x.w*tmp1.x+pmat.y.w*tmp1.y+pmat.z.w*tmp1.z;

	out->x = (int)((SCEGU_SCR_WIDTH/2)*tmp2.x/tmp2.w+SCEGU_SCR_WIDTH/2);
	out->y = (int)((-SCEGU_SCR_HEIGHT/2)*tmp2.y/tmp2.w+SCEGU_SCR_HEIGHT/2);
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", draw_string);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", set_object);

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(-1U);
    sceGumDrawBezier(0x19C, 0x32, 0x32, NULL, model);
    draw_string();
    sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", draw_game);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", init_param);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", game_re_init_gu);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", game_pad_read);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019478);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_0001947C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019480);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_000194A4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_000194D4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019500);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019510);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019520);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_00019530);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", D_0001955C);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", game_net_init);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", game_net_term);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", send_position);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", recv_allpacket);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_game", send_recv_game_data);

int game_init(void) {
    int var_v0;

    var_v0 = game_re_init_gu();
    if (var_v0 >= 0) {
        var_v0 = game_net_init();
    }
    return var_v0;
}

int game_term(void) {
    return game_net_term();
}
