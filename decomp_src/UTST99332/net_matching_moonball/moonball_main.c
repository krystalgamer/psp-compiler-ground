#include "common.h"

/* declarations recovered from DWARF */
struct ScePspIMatrix4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
typedef short unsigned int u_short16;
struct _anon1 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
};
typedef struct _anon1 Gu2dV16T;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon2 Gu2dV16;
typedef unsigned int u_int32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct SceNetAdhocctlAdhocId;
typedef unsigned char SceUChar8;
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
struct minfo;
struct minfo { /* size 0x98 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};
struct _anon3;
struct _anon3 { /* size 0x8 */
    int flag;
    int mode;
};
typedef struct _anon3 PROG;
struct _anon4;
typedef void voidfunc(void);
typedef void voidfuncuint2(u_int32, u_int32);
struct _anon4 { /* size 0x10 */
    voidfunc *init;
    voidfunc *run;
    voidfunc *draw;
    voidfuncuint2 *key;
};
typedef struct _anon4 FUNCLIST;
struct _info;
struct _info { /* size 0x10 */
    int server_flag;
    int client_ready;
    struct SceNetEtherAddr server;
};
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

extern struct SceNetAdhocctlAdhocId adhoc_id;
extern struct matching_room_info _mrinfo;
extern struct minfo minfo[16];
extern int exitflag;
extern u_int32 cont;
extern u_int32 vcount;
extern PROG program;
extern FUNCLIST func[1];
extern float sphere[84];
extern float rsphere[18];
extern u_int32 clut_scope[8];
extern u_int32 chr_scope[128];
extern u_int32 clut_water[8];
extern u_int32 chr_water[2048];
extern u_int32 clut_moon[8];
extern u_int32 chr_moon[2048];
extern u_int32 clut_ball[8];
extern u_int32 chr_ball[128];
extern u_int32 clut_mission[8];
extern u_int32 chr_mission[4096];
extern u_int32 clut_ready[128];
extern u_int32 chr_ready[8192];
extern struct _info _info;
extern char displist[327680];
extern ScePspFMatrix4 matrix_stack[48];
extern int __sscale_x;
extern int __sscale_y;
extern int __fade;
extern int __fadestep;
extern int __fadecolor;


/* SDK functions (tools/sdk_protos.h) */
int sceCtrlPeekBufferPositive(SceCtrlData *data, int count);

static void InitFunc(void);
void DrawSprite(int x, int y, int w, int h, int u, int v, Gu2dV16T *model);
void FadeDraw(void);
static void DrawFunc(void);
static void KeyFunc(void);
static void ProgramSwitch(void);
int game_init(void);
void draw_top_for_game(void);
void draw_p2p_game_parameter(int index, int color, int x, int *y_ptr);
int game_pad_read_top(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceDisplayWaitVblankStart(void);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", D_0001A020);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", D_0001A060);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", D_0001A074);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", D_0001A084);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", InitFunc);

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", DrawSprite);

void FadeSetup(int mode, int c) {
    __fade = mode;
    __fadecolor = c;
    __fadestep = 0;
}

int FadeState(void) {
    return __fade;
}

void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
extern Gu2dV16 D_0007D908[2];
void FadeDraw(void)
{
	u_int32 c;
	u_int32 a;

	if (__fadestep < 255 && __fade != 0) {
		if (__fade == 1)
			a = 255 - __fadestep;
		else
			a = __fadestep;
		sceGuDisable(9);
		c = (a << 24) | __fadecolor;
		sceGuColor(c);
		D_0007D908[0].p[0] = 0;
		D_0007D908[0].p[1] = 0;
		D_0007D908[0].p[2] = 0;
		D_0007D908[1].p[0] = 480;
		D_0007D908[1].p[1] = 272;
		D_0007D908[1].p[2] = 0;
		sceGumDrawArray(6, 0x800100, 2, NULL, D_0007D908);
		__fadestep += 16;
		if (__fadestep < 255)
			return;
		__fadestep = 255;
	}
	__fade = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", DrawFunc);

static void KeyFunc(void)
{
	u_int32		prev=cont;
	u_int32		padd;
	SceCtrlData	buf;

	sceCtrlPeekBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd=cont & (cont^prev);

	if (func[program.mode].key!=0)
		func[program.mode].key(padd, cont);
}

static void ProgramSwitch(void)
{
	switch (program.flag) {
	case 0:
		if (func[program.mode].init)
			func[program.mode].init();
		program.flag = 1;
		break;
	case 1:
		if (func[program.mode].run)
			func[program.mode].run();
		break;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/moonball_main", game_init);

int game_term(void) {
    return game_net_term();
}

extern char D_0001A060[];
extern char D_0001A074[];
int snprintf(char *buf, unsigned int size, const char *fmt, ...);
void draw_top_for_game(void)
{
	char mess_buff[128];
	int x, y;

	y = 61;
	snprintf(mess_buff, sizeof(mess_buff), D_0001A060);
	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 15;
	x += 24;

	sprintf(mess_buff, D_0001A074, _mrinfo.hello_opt.req_player_num);
	sceGuDebugPrint(x, y, 0xff, mess_buff);
}

extern char D_0001A084[];
void draw_p2p_game_parameter(int index, int color, int x, int *y_ptr)
{
	char mess_buff[128];
	int y;

	y = *y_ptr;
	if (_mrinfo.hello_opt.game_type != GAME_TYPE_CHILD)
		return;
	sprintf(mess_buff, D_0001A084,
		minfo[index].hello_opt.cur_player_num,
		minfo[index].hello_opt.req_player_num);
	sceGuDebugPrint(x, y, color, mess_buff);
	y += 10;
	*y_ptr = y;
}

void draw_game(void) {
    DrawFunc();
    vcount = (vcount + 1) & 0xFFFF;
}

extern int D_0007D914;

int game_pad_read_top(void) {
    SceCtrlData buf;
    int temp_s0;
    int temp_s0_2;

    temp_s0 = D_0007D914;
    sceCtrlPeekBufferPositive(&buf, 1);
    temp_s0_2 = buf.Buttons & (buf.Buttons ^ temp_s0);
    D_0007D914 = buf.Buttons;
    if ((temp_s0_2 & 0x20) && (_mrinfo.hello_opt.req_player_num < 0x10)) {
        _mrinfo.hello_opt.req_player_num += 1;
    }
    if (temp_s0_2 & 0x80) {
        if (_mrinfo.hello_opt.req_player_num >= 3) {
            _mrinfo.hello_opt.req_player_num -= 1;
        }
    }
    return 1;
}

int game_pad_read(void) {
    ProgramSwitch();
    KeyFunc();
    return 0;
}
