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
void sceKernelDcacheWritebackAll(void);
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

static void set_object(float *analog)
{
	MODEL		*p;
	int			i,j;
	int			n;
	float		h;
	u_int32		c;

	const	int	tbl_m[9]={
		-MAX_U-1,
		-MAX_U,
		-MAX_U+1,
		-1,
		 0,
		 1,
		 MAX_U-1,
		 MAX_U,
		 MAX_U+1,
	};

	const	int	tbl_c[12]={
		-MAX_U*2-1,
		-MAX_U*2,
		-MAX_U*2+1,
		-MAX_U-2,
		-MAX_U+2,
		-2,
		 2,
		 MAX_U-2,
		 MAX_U+2,
		 MAX_U*2+1,
		 MAX_U*2,
		 MAX_U*2-1,
	};

	for (i=0; i<MAXCONTROL; i++) {
		p=&model[i];
		p->vtx.x=((float)-(MAX_U/2)+(float)(i%MAX_U))*0.3f;
		p->vtx.y=((float) (MAX_V/2)-(float)(i/MAX_V))*0.3f;
		p->vtx.z=0.0f;

		if (connect_state == PRIMARY_IBSS)
			p->c=0xffffffff;
		else if (connect_state == SECONDARY_IBSS)
			p->c=0xff00f0f0;
	}

	for (i=0; i<MAX_OBJ; i++) {
		if (obj[i].detect==0)
			continue;

		n=obj[i].y*MAX_U+obj[i].x;
		c=obj[i].c;
		h=obj[i].high*(!obj[i].comp?1.0f:0.5f);
		for (j=0; j<9; j++) {
			p=&model[n+tbl_m[j]];
			if (i==0) {
				p->vtx.x+=analog[0];
				p->vtx.y+=analog[1];
			} else {
				p->vtx.x+=obj[i].vtx_x;
				p->vtx.y+=obj[i].vtx_y;
			}
			p->vtx.z=h;
			p->c=c;
		}
		for (j=0; j<12; j++) {
			p=&model[n+tbl_c[j]];
			p->c=c;
		}
	}

	sceKernelDcacheWritebackAll();
}

char *strncpy(char *d, const char *s, unsigned int n);
static void draw_string(void)
{
	ScePspIVector2	vec;
	MODEL			*p;
	char			str[128];
	int				i;

	sceGumPushMatrix();
	for (i=0; i<MAX_OBJ; i++) {
		if (obj[i].detect==0)
			continue;

				p = &model[obj[i].y*MAX_U+obj[i].x];
		rot_trans_pers(&p->vtx, &vec);
		strncpy(str, (char *)obj[i].nickname.data, 128);
		sceGuDebugPrint(vec.x-16, vec.y-8, obj[i].c, str) ;

		if (i==0 || connect_state == SECONDARY_IBSS)
			continue;

				if (obj[i].peer_state == MATCHING_DISCONNECTED)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: DISCONNECTED");
		if (obj[i].peer_state == MATCHING_HELLO)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: recv HELLO");
		if (obj[i].peer_state == MATCHING_SEND_REQ)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: send REQ");
		if (obj[i].peer_state == MATCHING_RECV_REQ)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: recv REQ");
		if (obj[i].peer_state == MATCHING_DENY)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: DENY");
		if (obj[i].peer_state == MATCHING_ESTABLISHED)
			sceGuDebugPrint(vec.x-16, vec.y-16, obj[i].c, "matching: ESTABLISHED");

		if (i == focused_peer) {
			pointer[0][0] = 0xffff;
			pointer[0][1] = p->vtx.x-0.5f;
			pointer[0][2] = p->vtx.y+0.2f;
			pointer[0][3] = 2.2f;
			pointer[1][0] = 0xffff;
			pointer[1][1] = p->vtx.x;
			pointer[1][2] = p->vtx.y-0.4f;
			pointer[1][3] = 2.2f;
			pointer[2][0] = 0xc0;
			pointer[2][1] = p->vtx.x+0.5f;
			pointer[2][2] = p->vtx.y+0.2f;
			pointer[2][3] = 2.2f;
			sceGumDrawArray(5,
				0x19C,
				3, 0, (void *)pointer);
		}
	}
	sceGumPopMatrix();
}

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(0xFFFFFFU);
    sceGumDrawBezier(0x19C, 0x32, 0x32, NULL, model);
    sceGumPopMatrix();
}

extern short int board_16A8C[2][3];
static void draw_menu(void)
{
	char line_buff[64];

	sceGumPushMatrix();
	sceGuColor(0x90000000);
	sceGumDrawArray(6, 0x800100, 2, NULL, board_16A8C);
	sprintf(line_buff, "MAC addr  :%s", etherstr);
	sceGuDebugPrint(8, 8, 0xffffff, line_buff);
	sprintf(line_buff, "group_name:%s", adhocctl_param.group_name.data);
	sceGuDebugPrint(8, 24, 0xffffff, line_buff);
	sprintf(line_buff, "channel   :%d", adhocctl_param.channel);
	sceGuDebugPrint(8, 32, 0xffffff, line_buff);
	sprintf(line_buff, "BSSID     :%02x:%02x:%02x:%02x:%02x:%02x", adhocctl_param.bssid.data[0], adhocctl_param.bssid.data[1], adhocctl_param.bssid.data[2], adhocctl_param.bssid.data[3], adhocctl_param.bssid.data[4], adhocctl_param.bssid.data[5]);
	sceGuDebugPrint(8, 40, 0xffffff, line_buff);
	sprintf(line_buff, "nickname  :%s", adhocctl_param.nickname.data);
	sceGuDebugPrint(8, 48, 0xffffff, line_buff);
	sceGumPopMatrix();
}

extern char disp_list_17400[65536];
void draw_model(void);
static void draw_frame_DB4(void)
{
	switch (connect_state) {
	case PRIMARY_IBSS:
	case SECONDARY_IBSS:
		sceGuStart(0, disp_list_17400, sizeof(disp_list_17400));
		sceGuClear(7);
		sceGumPushMatrix();
		sceGumLoadIdentity();
		sceGumTranslate(&world.pos);
		sceGumRotateX(world.rot.x * 3.14159265358979323846f / 180.0f);
		sceGumRotateY(world.rot.y * 3.14159265358979323846f / 180.0f);
		sceGumRotateZ(world.rot.z * 3.14159265358979323846f / 180.0f);
		if (display_menu)
			draw_menu();
		draw_string();
		draw_model();
		sceGumPopMatrix();
		sceGuFinish();
		sceGuSync(0, 0);
		break;
	case CONNECTING_PRIMARY_IBSS:
	case CONNECTING_SECONDARY_IBSS:
	case ERROR_DIALOG:
		sceNetAdhocDialogUpdate();
		break;
	}
}

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

extern char disp_list_17400[65536];
int net_init(OBJECT *obj, struct SceNetAdhocctlNickname *nickname);
static int init_all(struct SceNetAdhocctlNickname *nickname)
{
	ScePspFVector3	vec;
	int				ret;

	sceGuInit();

	sceGuStart(0, disp_list_17400, sizeof(disp_list_17400));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT,
					(void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);

	sceGuOffset(1808, 1912);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(2);

	sceGuDepthFunc(7);
	sceGuEnable(1);

	sceGuEnable(8);
	sceGuEnable(16);
	sceGuShadeModel(1);

	sceGuEnable(20);
	sceGuPatchDivide(16, 16);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, 2, 0xffffffff);
	sceGuLight(0, 0, 2, &vec);
	sceGuEnable(11);
	sceGuEnable(10);

	sceGuAmbient(0xffc0c0c0);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective((45.0f*3.14159265358979323846f/180.0f), ((float)480/(float)272),
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00202020);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();

	init_param();
	obj[0].c=0xff0000ff;
	ret = net_init(&obj[0], nickname);
	sceGuDisplay(1);

	return ret;
}

extern u_int32 cont_322B0;
#define cont cont_322B0
extern int matching_ctx_id_17344;
static int pad_read_11DC(void)
{
	u_int32			prev=cont;
	u_int32			padd;
	SceCtrlData		buf;
	float			axis[2];
	OBJECT			*o;
	int				ret;

	o=&obj[0];

	sceCtrlReadBufferPositive( &buf, 1 );
	cont = buf.Buttons;
	axis[0]=(float)((int)buf.Lx-128)* 0.01f;
	axis[1]=(float)((int)buf.Ly-128)*-0.01f;
	padd=cont&(cont^prev);
	o->vtx_x = axis[0];
	o->vtx_y = axis[1];

	if (connect_state != PRIMARY_IBSS && connect_state != SECONDARY_IBSS)
		return 1;
	if (ignore_pad_input == 1) {
		ignore_pad_input = 0;
		return 1;
	}

	if (cont & 0x0010) {
		o->y-=GRID;
		if (o->y<GRID) o->y=GRID;
	}
	if (cont & 0x0040) {
		o->y+=GRID;
		if (o->y>=(MAX_V-GRID)) o->y-=GRID;
	}
	if (cont & 0x0080) {
		o->x-=GRID;
		if (o->x<GRID) o->x=GRID;
	}
	if (cont & 0x0020) {
		o->x+=GRID;
		if (o->x>=(MAX_U-GRID)) o->x-=GRID;
	}
	o->comp=0;
	if (cont & 0x0100)
		o->comp=1;
	if (cont& 0x1000)
		o->c += 0xff;
	if (padd & 0x8000)
		display_menu = (display_menu)?0:1;

	if (padd & 0x0200) {
		int i;
		for (i=1; i<MAX_OBJ; i++) {
			focused_peer++;
			focused_peer = (focused_peer>=MAX_OBJ)?1:focused_peer; 

			if (obj[focused_peer].detect == 1)
				break;
		}
		if (i==MAX_OBJ)
			focused_peer = 0;
	}
		
	if (padd & 0x2000) {
		if (obj[focused_peer].detect == 1 && 
			(obj[focused_peer].peer_state ==  MATCHING_HELLO ||
			 obj[focused_peer].peer_state ==  MATCHING_RECV_REQ) &&
			 connect_state == PRIMARY_IBSS) {
			ret = sceNetAdhocMatchingSelectTarget(
					matching_ctx_id_17344, 
					&obj[focused_peer].addr, 
					sizeof(obj[focused_peer].nickname),
					(void *)(&obj[focused_peer].nickname));
			if (ret < 0 && ret != (int)0x80410810) {
				printf("sceNetAdhocMatchingSelectTarget() failed. ret = 0x%x\n", ret);
				return ret;
			}
			adversary = &obj[focused_peer].addr;
			obj[focused_peer].peer_state = MATCHING_SEND_REQ;
		}
	}

	if (padd & 0x4000) {
		if (obj[focused_peer].detect == 1 && connect_state == PRIMARY_IBSS) {
			ret = sceNetAdhocMatchingCancelTarget(matching_ctx_id_17344, &obj[focused_peer].addr);
			if (ret < 0) {
				printf("sceNetAdhocMatchingCancelTarget() failed. ret = 0x%x\n", ret);
				return ret;
			}
			obj[focused_peer].peer_state = MATCHING_DISCONNECTED;
		} else if (connect_state == SECONDARY_IBSS) {
			connect_state = DISCONNECT_SECONDARY_IBSS;
		}
	}

	set_object(axis);

	/* Reset Parameter */
	if (padd & 0x0008)
		init_param();

	/* Exit */
	if (padd & 0x0001)
		return 0;

	return 1;
}
#undef cont

extern int matching_ctx_id_17344;
int net_create_pdp(char *etherstr);
int matching_start(OBJECT *obj);
int poll_adhoc_dialog_state(void)
{
	enum SceNetAdhocDialogState adhoc_dialog_state;
	int ret;

	if (connect_state != CONNECTING_PRIMARY_IBSS && connect_state != CONNECTING_SECONDARY_IBSS && connect_state != ERROR_DIALOG)
		return 0;
	ret = sceNetAdhocDialogGetState(&adhoc_dialog_state);
	if (ret < 0)
		goto error;
	if (adhoc_dialog_state == SCE_NET_ADHOC_DIALOG_STATE_CONNECTED) {
		switch (connect_state) {
		case CONNECTING_PRIMARY_IBSS:
			connect_state = PRIMARY_IBSS;
			net_create_pdp(etherstr);
			sceNetAdhocctlGetParameter(&adhocctl_param);
			matching_ctx_id_17344 = matching_start(obj);
			init_param();
			break;
		case CONNECTING_SECONDARY_IBSS:
			connect_state = SECONDARY_IBSS;
			net_create_pdp(etherstr);
			sceNetAdhocctlGetParameter(&adhocctl_param);
			init_param();
			break;
		case ERROR_DIALOG:
			connect_state = ERROR_DISCONNECT;
			break;
		}
		ignore_pad_input = 1;
	} else if (adhoc_dialog_state == SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED) {
		connect_state = DISCONNECTED;
		ignore_pad_input = 1;
		goto error;
	}
error:
	return ret;
}

int send_position(OBJECT *obj);
int recv_allpacket(OBJECT *obj);
int sceNetAdhocDialogConnect(void *group_name);
extern struct SceNetAdhocctlNickname D_0001734C;
#define nickname D_0001734C
int main(int ac, char **av)
{
	int ret;

	menuInit();
	if (load_required_modules() < 0)
		return 1;
	memset(&nickname, 0, sizeof(nickname));
	ret = sceUtilityGetSystemParamString(1, (char *)nickname.data, sizeof(nickname));
	if (ret < 0)
		printf("sceUtilityGetSystemParamString() failed. ret = 0x%x\n", ret);
	sceCtrlSetSamplingMode(1);
	if (init_all(&nickname) < 0)
		return 1;
	ret = sceNetAdhocDialogConnect(NULL);
	if (ret < 0) {
		printf("sceNetAdhoDialogConnect() failed. ret = 0x%x\n", ret);
		return 1;
	}
	connect_state = CONNECTING_PRIMARY_IBSS;
	while (1) {
		if (pad_read_11DC() <= 0)
			connect_state = ERROR_DISCONNECT;
		if (connect_state == PRIMARY_IBSS || connect_state == SECONDARY_IBSS) {
			ret = polling_error();
			if (ret < 0) {
				printf("polling_error() failed. ret = 0x%x\n", ret);
				ret = sceNetAdhocDialogWlanError(ret);
				if (ret < 0)
					printf("sceNetAdhocDialogWlanError() failed. ret = 0x%x\n", ret);
				else
					connect_state = ERROR_DIALOG;
			} else {
				send_position(&obj[0]);
				recv_allpacket(obj);
			}
		}
		disconnect_check();
		poll_adhoc_dialog_state();
		draw_frame_DB4();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
		if (connect_state == DISCONNECTED)
			break;
	}
	net_term();
	sceGuTerm();
	if (unload_required_modules() < 0)
		return 1;
	printf("terminated.\n");
	menuTerm(3, 2);
	return 1;
}
#undef nickname
