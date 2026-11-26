#include "common.h"

/* declarations recovered from DWARF */
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct _anon1;
typedef unsigned int u_int32;
enum PeerState {
    MATCHING_DISCONNECTED = 0,
    MATCHING_HELLO = 1,
    MATCHING_SEND_REQ = 2,
    MATCHING_RECV_REQ = 3,
    MATCHING_DENY = 4,
    MATCHING_ESTABLISHED = 5,
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct _anon1 { /* size 0xb0 */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
    float vtx_x;
    float vtx_y;
    int detect;
    u_int32 last_v;
    enum PeerState peer_state;
    struct SceNetEtherAddr addr;
    struct SceNetAdhocctlNickname nickname;
};
typedef struct _anon1 OBJECT;
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
struct _anon2;
struct _anon2 { /* size 0x10 */
    u_int32 c;
    ScePspFVector3 vtx;
};
typedef struct _anon2 MODEL;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
enum SceNetAdhocDialogState {
    SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED = 0,
    SCE_NET_ADHOC_DIALOG_STATE_CONNECTED = 1,
    SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE = 2,
    SCE_NET_ADHOC_DIALOG_STATE_OPENED = 3,
};
enum connect_state {
    CONNECTING_PRIMARY_IBSS = 0,
    PRIMARY_IBSS = 1,
    DISCONNECT_PRIMARY_IBSS = 2,
    DISCONNECTING_PRIMARY_IBSS = 3,
    CONNECTING_SECONDARY_IBSS = 4,
    SECONDARY_IBSS = 5,
    DISCONNECT_SECONDARY_IBSS = 6,
    DISCONNECTING_SECONDARY_IBSS = 7,
    ERROR_DIALOG = 8,
    ERROR_DISCONNECT = 9,
    ERROR_DISCONNECTING = 10,
    DISCONNECTED = 11,
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

extern enum connect_state connect_state;
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int ignore_pad_input;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern POS world;
extern MODEL model[2500];
extern OBJECT obj[8];
extern int display_menu;
extern short int board[2][3];
extern float pointer[3][4];
extern char etherstr[18];
extern struct SceNetAdhocctlParameter adhocctl_param;
extern int matching_ctx_id;
extern struct SceNetEtherAddr *adversary;
extern int focused_peer;
extern u_int32 cont;

void handler_p2p(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);
static void rot_trans_pers(ScePspFVector3 *in, ScePspIVector2 *out);
static void set_object(float *analog);
static void draw_string(void);
static void draw_menu(void);
static void draw_frame(void);
static void init_param(void);
static int init_all(struct SceNetAdhocctlNickname *nickname);
static int pad_read(void);
int poll_adhoc_dialog_state(void);
int main(int ac, char **av);

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
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
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
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
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

void handler_p2p(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt)
{
	OBJECT *p;
	int i;

	p = NULL;
	for (i = 1; i < 8; i++) {
		if (memcmp(&obj[i].addr, peer, 6) == 0) {
			p = &obj[i];
			break;
		}
	}
	if (p == NULL)
		return;
	switch (ev) {
	case 0:
		break;
	case 1:
		p->peer_state = MATCHING_HELLO;
		break;
	case 2:
		p->peer_state = MATCHING_RECV_REQ;
		break;
	case 3:
	case 4:
		p->peer_state = MATCHING_DENY;
		break;
	case 5:
		printf("received invalid matching packet\n");
		break;
	case 6:
		p->peer_state = MATCHING_ESTABLISHED;
		break;
	case 7:
		p->peer_state = MATCHING_ESTABLISHED;
		connect_state = DISCONNECT_PRIMARY_IBSS;
		break;
	case 8:
		p->peer_state = MATCHING_DISCONNECTED;
		break;
	case 9:
		p->peer_state = MATCHING_DISCONNECTED;
		printf("event error had occured.\n");
		break;
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014D68);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014D8C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014DBC);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014DD4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014DE4);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014DF8);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E0C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E24);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E3C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E4C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E5C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E6C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014E98);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014EA8);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014ECC);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014F04);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014F3C);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014F74);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014F98);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014FCC);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", D_00014FD8);

#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define MAX_U		50
#define MAX_V		50
#define MAXCONTROL	(MAX_U*MAX_V)
#define MIN_OBJ_Z	2.0f
#define GRID		3
#define DPOS		1.0f
#define DROT		1.0f
#define LOBBY_IBSS_START	0
#define LOBBY_IBSS			1
#define GAME_IBSS			2
#define GAME_IBSS_START		3
#define MAX_OBJ		8

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

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", set_object);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", draw_string);

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(0xFFFFFFU);
    sceGumDrawBezier(0x19C, 0x32, 0x32, NULL, model);
    sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", draw_menu);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", draw_frame_DB4);

static void init_param(void)
{
	int i;

	world.pos.x=world.pos.y=world.pos.z=0.0f;
	world.rot.x=world.rot.y=world.rot.z=0.0f;

	world.pos.z=-10.0f;
	world.rot.x=300.0f;

	obj[0].x=GRID*7;
	obj[0].y=GRID*6;
//	obj[0].c=0xff0000ff;
	obj[0].comp=0;
	obj[0].high=MIN_OBJ_Z;
	sceNetGetLocalEtherAddr(&obj[0].addr);
	obj[0].detect = 1;
	obj[0].last_v = 0;

	for (i=1; i<MAX_OBJ; i++) {
		obj[i].high = MIN_OBJ_Z;
		obj[i].vtx_x = 0.0f;
		obj[i].vtx_y = 0.0f;
		obj[i].last_v = 0;
		obj[i].detect = 0;
		obj[i].peer_state = MATCHING_DISCONNECTED;
	}

	adversary = NULL;
	focused_peer = 1;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", pad_read_11DC);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", poll_adhoc_dialog_state);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/main", main);
