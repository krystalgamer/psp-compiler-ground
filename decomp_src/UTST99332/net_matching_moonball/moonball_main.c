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
struct __attribute__((packed)) _anon1 { /* size 0xa */
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

extern const ScePspIMatrix4 D_0001A020;
void InitParticle(void);
#define SCEGU_IMMEDIATE                    0
#define SCEGU_PF5551                       1
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_GREATER                      6
#define SCEGU_ALPHA_TEST                   0
#define SCEGU_CW                           0
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_LIGHT0                      11
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT1                      12
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT2                      13
#define SCEGU_LIGHTING                    10
#define SCEGU_FOG                          7
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define SCEGU_DISPLAY_ON		1

static void InitFunc(void)
{
	ScePspIMatrix4 dith = D_0001A020;
	ScePspFVector3	vec;

	sceGuTerm();
	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, displist, sizeof(displist));
	sceGuDrawBuffer(SCEGU_PF5551, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
					SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuDisable(SCEGU_ALPHA_TEST);

	sceGuFrontFace(SCEGU_CW);

	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);


	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xff808080);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(1, SCEGU_DIFFUSE, 0x00000000);
	sceGuLightColor(1, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT1);

	vec.x=-0.614497f;
	vec.y=-0.391714f;
	vec.z=-0.379372f;
	sceGuLightColor(2, SCEGU_DIFFUSE, 0xffc0c0c0);
	sceGuLight(2, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuDisable(SCEGU_LIGHT2);

	sceGuEnable(SCEGU_LIGHTING);
	sceGuSpecular(20.0f);

	sceGuDisable(SCEGU_FOG);
	sceGuAmbient(0xff808080);
	sceGuColor(0xffffffff);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 1000.00000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00000000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	InitParticle();

	program.flag=0;
	program.mode=0;

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

void DrawSprite(int x, int y, int w, int h, int u, int v, Gu2dV16T *model)
{
	sceGuEnable(9);

	model[0].u=u, model[0].v=v+h;
	model[0].p[0]=(short)x;
	model[0].p[1]=(short)y+(h*__sscale_y);
	model[0].p[2]=0;

	model[1].u=u, model[1].v=v;
	model[1].p[0]=(short)x;
	model[1].p[1]=(short)y;
	model[1].p[2]=0;

	model[2].u=u+w, model[2].v=v+h;
	model[2].p[0]=(short)x+(w*__sscale_x);
	model[2].p[1]=(short)y+(h*__sscale_y);
	model[2].p[2]=0;

	model[3].u=u+w, model[3].v=v;
	model[3].p[0]=(short)x+(w*__sscale_x);
	model[3].p[1]=(short)y;
	model[3].p[2]=0;

	sceGumDrawArray(4,
		0x800102,
		4, 0, (void *)model);
}

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

static void DrawFunc(void)
{
	if (func[program.mode].draw)
		func[program.mode].draw();
}

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

int game_init(void)
{
	int ret;

	memset(&_info, 0, sizeof(_info));
	InitFunc();
	ret = game_net_init();
	if (ret >= 0)
		ProgramSwitch();
	return ret;
}

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
