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

extern __typeof__(disp_list) disp_list_1B580;
#define disp_list disp_list_1B580

extern __typeof__(disp_list) disp_list_1B580;
#define SCEGU_IMMEDIATE                    0
#define SCEGU_PF8888                       3
#define SCEGU_VRAM_BP32_0     (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP32_1     (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BP32_2     (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_BLEND                        4
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_NEAREST                      0
#define SCEGU_REPEAT                       0
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define SCEGU_DISPLAY_ON		1

void gu_init(void)
{
	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(SCEGU_PF8888, SCEGU_VRAM_BP32_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
	SCEGU_VRAM_BP32_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP32_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(0, 0);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);

	sceGuClearColor(0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}


extern __typeof__(board) board_1AC98;
#define board board_1AC98

int snprintf(char *buf, unsigned int size, const char *fmt, ...);
void draw_top_for_game(void);
int get_bssid(char *bssid);
void draw_net_scan_result_list(int *x_ptr, int *y_ptr);
void draw_net_hello_list(int *x_ptr, int *y_ptr);
void draw_net_established_list(int *x_ptr, int *y_ptr);
void draw_net_member_list(int *x_ptr, int *y_ptr);
void draw_net_neighbors(int *x_ptr, int *y_ptr);
int matching_get_established_num(void);
void draw_game(void);

static void draw_top(void)
{
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	draw_top_for_game();

	snprintf(mess_buff, sizeof(mess_buff), "o: enter network play    t: scan");
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 262, 0xffffff, mess_buff);
}

static void draw_scan_result(void)
{
	char mess_buff[128];
	int x, y;

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 11;
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	y += 20;

	snprintf(mess_buff, sizeof(mess_buff), "SCAN RESULT");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);

	y += 10;

	snprintf(mess_buff, sizeof(mess_buff), "---------------------------");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);

	y += 10;

	draw_net_scan_result_list(&x, &y);

	snprintf(mess_buff, sizeof(mess_buff), "x: Back");
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 262, 0xffffff, mess_buff);
}



static void draw_room_list(void)
{
	char mess_buff[128];
	char bssid[32];
	int x, y;

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 11;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);

	y += 20;

	get_bssid(bssid);

	snprintf(mess_buff, sizeof(mess_buff), "ROOM LIST (BSSID: %s)", bssid);
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);

	y += 10;

	snprintf(mess_buff, sizeof(mess_buff), "---------------------------");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);

	y += 10;

	draw_net_hello_list(&x, &y);

	if (_mrinfo.hello_opt.game_type == GAME_TYPE_CHILD) {
		snprintf(mess_buff, sizeof(mess_buff), "o: enter room            s: create room      ");
	} else {
		snprintf(mess_buff, sizeof(mess_buff), "o: enter room                                ");
	}
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 252, 0xffffff, mess_buff);

	snprintf(mess_buff, sizeof(mess_buff), "x: exit network play     t: display neighbors");
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 262, 0xffffff, mess_buff);
}


static void draw_parent_wait(void)
{
	int x, y;
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 11;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 20;

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	snprintf(mess_buff, sizeof(mess_buff), "ESTABLISHED MEMBERS");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	snprintf(mess_buff, sizeof(mess_buff), "---------------------------");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	draw_net_established_list(&x, &y);

	if (matching_get_established_num() > 0) {
		snprintf(mess_buff, sizeof(mess_buff), "o: start game     x: exit network play");
	} else {
		snprintf(mess_buff, sizeof(mess_buff), "x: exit network play");
	}
	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 262;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
}

static void draw_child_wait(void)
{
	int x, y;
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 11;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 20;

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	snprintf(mess_buff, sizeof(mess_buff), "ESTABLISHED MEMBERS");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	snprintf(mess_buff, sizeof(mess_buff), "---------------------------");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	draw_net_member_list(&x, &y);

	snprintf(mess_buff, sizeof(mess_buff), "x: exit this room");
	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 262;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
}

static void draw_neighbors(void)
{
	char mess_buff[128];
	int x, y;

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	y = 11;
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 20;

	x = (480 - strlen(mess_buff) * 8) / 2 + 1;
	snprintf(mess_buff, sizeof(mess_buff), "NEIGHBOR LIST");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	snprintf(mess_buff, sizeof(mess_buff), "---------------------------");
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;

	draw_net_neighbors(&x, &y);

	snprintf(mess_buff, sizeof(mess_buff), "x: Back");
	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 262, 0xffffff, mess_buff);
}

static void draw_scanning(void)
{
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	sceGuColor(0xff800000);
	sceGuDrawArray(6, 0x800100, 2, NULL, board);

	sprintf(mess_buff, "Now Scanning ...");
	sceGuDebugPrint(69, 106, 0xffffff, mess_buff);
}

static void draw_requesting(void)
{
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	sceGuColor(0xff800000);
	sceGuDrawArray(6, 0x800100, 2, NULL, board);

	sprintf(mess_buff, "Requesting to");
	sceGuDebugPrint(69, 106, 0xffffff, mess_buff);

	sprintf(mess_buff, "%s", minfo[_mrinfo.requesting_minfo_id].hello_opt.nickname.data);
	sceGuDebugPrint(65 + (350 - strlen(mess_buff) * 8) / 2, 121, 0xffffff, mess_buff);

	sprintf(mess_buff, "Waiting Response ...");
	sceGuDebugPrint(69, 136, 0xffffff, mess_buff);

	sprintf(mess_buff, "x: Cancel");
	sceGuDebugPrint(65 + (350 - strlen(mess_buff) * 8) / 2, 166, 0xffffff, mess_buff);
}

static void draw_canceled(void)
{
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	sceGuColor(0xff800000);
	sceGuDrawArray(6, 0x800100, 2, NULL, board);

	sprintf(mess_buff, "Request is Canceled by peer");
	sceGuDebugPrint(69, 106, 0xffffff, mess_buff);

	sprintf(mess_buff, "x: Close");
	sceGuDebugPrint(65 + (350 - strlen(mess_buff) * 8) / 2, 166, 0xffffff, mess_buff);
}


static void draw_denied(void)
{
	char mess_buff[128];

	snprintf(mess_buff, sizeof(mess_buff), "************ MATCHING ROOM SAMPLE ***********");

	sceGuDebugPrint((480 - strlen(mess_buff) * 8) / 2 + 1, 11, 0xffffff, mess_buff);

	sceGuColor(0xff800000);
	sceGuDrawArray(6, 0x800100, 2, NULL, board);

	sprintf(mess_buff, "Request is Denied by peer");
	sceGuDebugPrint(69, 106, 0xffffff, mess_buff);

	sprintf(mess_buff, "x: Close");
	sceGuDebugPrint(65 + (350 - strlen(mess_buff) * 8) / 2, 166, 0xffffff, mess_buff);
}

void app_draw_frame(void)
{
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);

	switch (_mrinfo.state) {
	case MATCHING_ROOM_TOP:
		draw_top();
		break;
	case MATCHING_ROOM_SCANNING:
		draw_scanning();
		break;
	case MATCHING_ROOM_SCAN_RESULT:
		draw_scan_result();
		break;
	case MATCHING_ROOM_ROOM_LIST:
		draw_room_list();
		break;
	case MATCHING_ROOM_NEIGHBORS:
		draw_neighbors();
		break;
	case MATCHING_ROOM_REQUESTING:
		draw_requesting();
		break;
	case MATCHING_ROOM_CANCELED:
		draw_canceled();
		break;
	case MATCHING_ROOM_DENIED:
		draw_denied();
		break;
	case MATCHING_ROOM_PARENT_WAIT:
		draw_parent_wait();
		break;
	case MATCHING_ROOM_CHILD_WAIT:
		draw_child_wait();
		break;
	case MATCHING_ROOM_GAME:
		draw_game();
		break;
	default:
		break;
	}

	sceGuFinish();
	sceGuSync(0, 0);
}

int sceNetAdhocDialogUpdate(void);

static void draw_frame_11E8(void)
{
	switch (_mrinfo.state) {
	case MATCHING_ROOM_CONNECTING_ROOM:
	case MATCHING_ROOM_CONNECTING_GAME:
	case MATCHING_ROOM_ERROR_DIALOG:
		sceNetAdhocDialogUpdate();
		break;
	default:
		app_draw_frame();
		break;
	}
}

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

int load_required_modules(void);
int unload_required_modules(void);
int net_init(void);
void net_term(void);
int net_update(void);
int pad_read(void);
void menuInit(void);
void menuTerm(int cat, int num);

int main(int argc, char **argv)
{
	int ret;

	menuInit();

	if (load_required_modules() < 0)
		return 1;

	srand(sceKernelGetSystemTimeLow());
	memset(&game_group_name, 0, sizeof(game_group_name));
	memset(&_mrinfo, 0, sizeof(_mrinfo));
	change_state(MATCHING_ROOM_TOP);

	sceCtrlSetSamplingMode(1);

	ret = net_init();
	if (ret < 0)
		goto end;

	gu_init();

	while (pad_read()) {
		draw_frame_11E8();
		net_update();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}

	sceGuTerm();
	net_term();

	if (unload_required_modules() < 0)
		return 1;
end:
	menuTerm(3, 1);
	return 1;
}
