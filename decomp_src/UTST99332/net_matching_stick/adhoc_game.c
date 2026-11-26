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

#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCE_NET_ETHER_ADDR_LEN 6
#define PAYLOAD_MOVE_TYPE	0x01
#define PORT		777							
#define PAYLOAD_MOVE_LEN	(1+4+4+4+4+4+4)		
#define SCE_NET_ADHOC_F_NONBLOCK		0x0001
#define SCE_ERROR_NET_ADHOC_WOULD_BLOCK				0x80410709
#define SCE_OK							0

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

char *strncpy(char *d, const char *s, unsigned int n);
static void draw_string(void)
{
	ScePspIVector2	vec;
	MODEL			*p;
	char			str[128];
	int				i;

	for (i=0; i<17; i++) {
		if (obj[i].detect==0)
			continue;
		p = &model[obj[i].y*50+obj[i].x];
		rot_trans_pers(&p->vtx, &vec);
		strncpy(str, (char *)nickname[i].data, 128);
		sceGuDebugPrint(vec.x-16, vec.y-8, obj[i].c, str) ;
	}
}

static void set_object(float *analog)
{
	MODEL		*p;
	int			i,j;
	int			n;
	float		h;
	u_int32		c;

	const	int	tbl_m[9]={
		-50-1,
		-50,
		-50+1,
		-1,
		 0,
		 1,
		 50-1,
		 50,
		 50+1,
	};

	const	int	tbl_c[12]={
		-50*2-1,
		-50*2,
		-50*2+1,
		-50-2,
		-50+2,
		-2,
		 2,
		 50-2,
		 50+2,
		 50*2+1,
		 50*2,
		 50*2-1,
	};

	for (i=0; i<2500; i++) {
		p=&model[i];
		p->vtx.x=((float)-(50/2)+(float)(i%50))*0.3f;
		p->vtx.y=((float) (50/2)-(float)(i/50))*0.3f;
		p->vtx.z=0.0f;

		p->c=room_color_val[_mrinfo.agreed_hello_opt->game_param.color];
	}

	for (i=0; i<17; i++) {
		if (obj[i].detect==0)
			continue;

		n=obj[i].y*50+obj[i].x;
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

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(-1U);
    sceGumDrawBezier(0x19C, 0x32, 0x32, NULL, model);
    draw_string();
    sceGumPopMatrix();
}

extern short int board_876C4[2][3];
void *memcpy(void *d, const void *s, unsigned int n);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void draw_game(void)
{
	char buf[9];

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&world.pos);
	sceGumRotateX(world.rot.x * 3.14159265358979323846f / 180.0f);
	sceGumRotateY(world.rot.y * 3.14159265358979323846f / 180.0f);
	sceGumRotateZ(world.rot.z * 3.14159265358979323846f / 180.0f);
	draw_model();
	sceGumPopMatrix();

	if (display_menu) {
		char line_buff[64];
		int i, j;

		if (display_menu & 1) {
			board_876C4[0][0] = 4;
			board_876C4[0][1] = 4;
			board_876C4[0][2] = 0;
			board_876C4[1][0] = 240;
			board_876C4[1][1] = 60;
			board_876C4[1][2] = 0;
			sceGuColor(0x90000000);
			sceGuDrawArray(6, 0x800100, 2, NULL, board_876C4);

			sprintf(line_buff, "MAC addr  :%s", etherstr);
			sceGuDebugPrint(8, 8, 0x00ffffff, line_buff);

			memcpy(buf, adhocctl_param.group_name.data, 8);
			buf[8] = '\0';
			sprintf(line_buff, "group_name:%s", buf);
			sceGuDebugPrint(8, 24, 0x00ffffff, line_buff);
			sprintf(line_buff, "channel   :%d", adhocctl_param.channel);
			sceGuDebugPrint(8, 32, 0x00ffffff, line_buff);
			sprintf(line_buff, "BSSID     :%02x:%02x:%02x:%02x:%02x:%02x",
				adhocctl_param.bssid.data[0],
				adhocctl_param.bssid.data[1],
				adhocctl_param.bssid.data[2],
				adhocctl_param.bssid.data[3],
				adhocctl_param.bssid.data[4],
				adhocctl_param.bssid.data[5]);
			sceGuDebugPrint(8, 40, 0x00ffffff, line_buff);
			sprintf(line_buff, "nickname  :%s", adhocctl_param.nickname.data);
			sceGuDebugPrint(8, 48, 0x00ffffff, line_buff);
		} else {
			for (i = 0, j = 1; i < peer_num; j++, i++) {
				sprintf(line_buff, "%02x:%02x:%02x:%02x:%02x:%02x => %2u / 60",
					peer_addr[i].data[0], peer_addr[i].data[1], peer_addr[i].data[2],
					peer_addr[i].data[3], peer_addr[i].data[4], peer_addr[i].data[5],
					rcvpkt[i + 1].last_c);
				sceGuDebugPrint(8, j * 8, 0x00ffffff, line_buff);
			}
			if (j >= 2) {
				board_876C4[0][0] = 4;
				board_876C4[0][1] = 4;
				board_876C4[0][2] = 0;
				board_876C4[1][0] = 240;
				board_876C4[1][1] = j * 8 + 8;
				board_876C4[1][2] = 0;
				sceGuColor(0x90000000);
				sceGuDrawArray(6, 0x800100, 2, NULL, board_876C4);
			}
		}
	}
}

static void init_param(void)
{
	int i;

	world.pos.x=world.pos.y=world.pos.z=0.0f;
	world.rot.x=world.rot.y=world.rot.z=0.0f;

	world.pos.z=-10.0f;
	world.rot.x=300.0f;
	last_v = 0;

	obj[0].x=3*7;
	obj[0].y=3*6;
	obj[0].c=0xff0000ff;
	obj[0].comp=0;
	obj[0].high=2.0f;
	obj[0].detect = 1;
	obj[0].last_v = 0;

	for (i=1; i<17; i++) {
		obj[i].high = 2.0f;
		obj[i].vtx_x = 0.0f;
		obj[i].vtx_y = 0.0f;
		obj[i].last_v = 0;
		obj[i].detect = 0;
		rcvpkt[i].counter = 0;
		rcvpkt[i].last_c = 0;
	}
}

extern char disp_list_6C300[65536];
int game_re_init_gu(void)
{
	ScePspFVector3	vec;
	int				ret;

	sceGuTerm();
	sceGuInit();

	sceGuStart(0, disp_list_6C300, sizeof(disp_list_6C300));
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
	sceNetAdhocctlGetParameter(&adhocctl_param);
	sceNetGetLocalEtherAddr(&obj[0].addr);
	ret = sceUtilityGetSystemParamString(1, (char *)nickname[0].data, 128);
	sceGuDisplay(1);

	return ret;
}

extern u_int32 cont_878A4;
#define cont cont_878A4
int sceCtrlPeekBufferPositive(SceCtrlData *data, int count);
int game_pad_read(void)
{
	u_int32			prev=cont;
	u_int32			padd;
	SceCtrlData		buf;
	float			axis[2];
	OBJECT			*o;
	int				diff;

	o=&obj[0];

	sceCtrlPeekBufferPositive( &buf, 1 );
	cont = buf.Buttons;
	axis[0]=(float)((int)buf.Lx-128)* 0.01f;
	axis[1]=(float)((int)buf.Ly-128)*-0.01f;
	padd=cont&(cont^prev);
	o->vtx_x = axis[0];
	o->vtx_y = axis[1];

	if (cont & 0x0010) {
		diff = 3 * room_speed_val[_mrinfo.agreed_hello_opt->game_param.speed];
		o->y-=diff;
		if (o->y<diff) o->y=diff;
	}
	if (cont & 0x0040) {
		diff = 3 * room_speed_val[_mrinfo.agreed_hello_opt->game_param.speed];
		o->y+=diff;
		if (o->y>=(50-diff)) o->y-=diff;
	}
	if (cont & 0x0080) {
		diff = 3 * room_speed_val[_mrinfo.agreed_hello_opt->game_param.speed];
		o->x-=diff;
		if (o->x<diff) o->x=diff;
	}
	if (cont & 0x0020) {
		diff = 3 * room_speed_val[_mrinfo.agreed_hello_opt->game_param.speed];
		o->x+=diff;
		if (o->x>=(50-diff)) o->x-=diff;
	}
	o->comp=0;
	if (cont & 0x0200)
		o->comp=1;
	if (cont & 0x1000)
		o->c += 0xff;
	if (cont & 0x4000)
		o->c += 0xff00;
	if (padd & 0x2000)
		display_menu++;
	if (padd & 0x8000)
		display_menu = 0;

	set_object(axis);

	if (padd & 0x0008)
		init_param();

	if (padd & 0x0001)
		change_state(MATCHING_ROOM_GAME_DISCONNECT);

	return 1;
}
#undef cont











void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
int matching_get_members(struct SceNetEtherAddr *addrs);
int game_net_init(void)
{
	int ret;
	int i;

	sceNetGetLocalEtherAddr(&local_addr);
	memset(etherstr, 0, sizeof(etherstr));
	sceNetEtherNtostr(&local_addr, etherstr);
	ret = sceNetAdhocGameModeCreateMaster(&obj[0], sizeof(OBJECT));
	if (ret < 0) {
		printf("sceNetAdhocGameModeCreateMaster() failed. ret = 0x%x\n", ret);
		goto error;
	}
	memset(peer_addr, 0, sizeof(peer_addr));
	for (i = 0; i < 16; i++)
		peer_id[i] = -1;
	ret = matching_get_members(peer_addr);
	if (ret > 0) {
		peer_num = ret;
		for (i = 0; i < peer_num; i++) {
			ret = sceNetAdhocGameModeCreateReplica(&peer_addr[i], &obj[i + 1], sizeof(OBJECT));
			if (ret < 0) {
				printf("sceNetAdhocGameModeCreateReplica() failed. ret = 0x%x\n", ret);
				goto error;
			}
			peer_id[i] = ret;
			sceNetAdhocctlGetNameByAddr(&peer_addr[i], &nickname[i + 1]);
		}
	}
error:
	return ret;
}

int game_net_term(void)
{
	int ret;
	int i;

	for (i = 0; i < peer_num; i++) {
		if (peer_id[i] >= 0) {
			sceNetAdhocGameModeDeleteReplica(peer_id[i]);
			peer_id[i] = -1;
		}
	}
	sceNetAdhocGameModeDeleteMaster();
	return 0;
}

int
send_position(OBJECT *obj)
{
	int ret;
	struct SceNetEtherAddr broadcast;
	char buf[PAYLOAD_MOVE_LEN];

	memset(broadcast.data, 0xff, SCE_NET_ETHER_ADDR_LEN);

	
	*buf = PAYLOAD_MOVE_TYPE;
	memcpy(&buf[1], &obj->x, sizeof(int));
	memcpy(&buf[5], &obj->y, sizeof(int));
	memcpy(&buf[9], &obj->c, sizeof(int));
	memcpy(&buf[13], &obj->comp, sizeof(int));
	memcpy(&buf[17], &obj->vtx_x, sizeof(float));
	memcpy(&buf[21], &obj->vtx_y, sizeof(float));

	ret = sceNetAdhocPdpSend(
			socket_id,
			&broadcast,
			PORT,
			buf,
			PAYLOAD_MOVE_LEN,
			0,
			SCE_NET_ADHOC_F_NONBLOCK);

	if (ret == SCE_ERROR_NET_ADHOC_WOULD_BLOCK)
		ret = SCE_OK;

	return ret;
}

int
recv_allpacket(OBJECT *obj)
{
	int i, repeat_i, ret;
	struct SceNetEtherAddr saddr;
	struct SceNetAdhocPdpStat stat;
	u_int16 sport;
	int buflen;
	char buf[0x400];
	int repeat = 0;
	int stat_buflen;

	obj[0].last_v = last_v;
	stat_buflen = sizeof(struct SceNetAdhocPdpStat);
	ret = sceNetAdhocGetPdpStat(&stat_buflen, (void *)&stat);
	if (ret < 0) {
		printf("sceNetAdhocGetPdpStat() failed. ret = 0x%x\n", ret);
		return ret;
	}
	if (stat_buflen == 0 || stat.id != socket_id) {
		printf("sceNetAdhocGetPdpStat() invalid data.\n");
		return -1;
	}

	repeat = stat.rcv_sb_cc / PAYLOAD_MOVE_LEN;
	for (repeat_i=0; repeat_i<repeat; repeat_i++) {
		buflen = 0x400;
		ret = sceNetAdhocPdpRecv(
				socket_id,
				&saddr,
				&sport,
				buf,
				&buflen,
				0,
				SCE_NET_ADHOC_F_NONBLOCK);

		if (ret == SCE_ERROR_NET_ADHOC_WOULD_BLOCK) {
			ret = SCE_OK;
			break;
		}
		if (memcmp(&local_addr, &saddr, SCE_NET_ETHER_ADDR_LEN) == 0)
			continue;
		if (sport != PORT)
			continue;
		if (buflen == PAYLOAD_MOVE_LEN && buf[0] == PAYLOAD_MOVE_TYPE) {
			for (i=1; i<17; i++) {
				if (obj[i].detect == 0 ||
					(obj[i].detect==1 &&
					memcmp(&obj[i].addr.data, &saddr, SCE_NET_ETHER_ADDR_LEN) == 0)) {
					memcpy(&obj[i].x, &buf[1], sizeof(int));
					memcpy(&obj[i].y, &buf[5], sizeof(int));
					memcpy(&obj[i].c, &buf[9], sizeof(int));
					memcpy(&obj[i].comp, &buf[13], sizeof(int));
					memcpy(&obj[i].vtx_x, &buf[17], sizeof(float));
					memcpy(&obj[i].vtx_y, &buf[21], sizeof(float));
					if (obj[i].detect == 0) {
						memcpy(&obj[i].addr, &saddr, SCE_NET_ETHER_ADDR_LEN);
						sceNetAdhocctlGetNameByAddr(&saddr, &nickname[i]);
					}
					obj[i].last_v = last_v;
					obj[i].detect = 1;
					rcvpkt[i].counter++;
					break;
				}
			}
		}
	}

	for (i=1; i<17; i++) {
		if ((last_v - obj[i].last_v) > 60) {
			obj[i].high = 2.0f;
			obj[i].vtx_x = 0.0f;
			obj[i].vtx_y = 0.0f;
			obj[i].last_v = 0;
			obj[i].detect = 0;
			rcvpkt[i].counter = 0;
			rcvpkt[i].last_c = 0;
		}
	}

	return ret;
}

int send_recv_game_data(void)
{
	int i;
	struct SceNetAdhocGameModeOptData opt;

	if (_mrinfo.state != MATCHING_ROOM_GAME)
		return 0;
	if (++last_v % 60 == 0) {
		for (i = 0; i < 17; i++) {
			rcvpkt[i].last_c = rcvpkt[i].counter;
			rcvpkt[i].counter = 0;
		}
	}
	sceNetAdhocGameModeUpdateMaster();
	obj[0].last_v = last_v;
	opt.size = sizeof(opt);
	for (i = 0; i < peer_num; i++) {
		sceNetAdhocGameModeUpdateReplica(peer_id[i], &opt);
		if (opt.flag & 1) {
			obj[i + 1].detect = 1;
			obj[i + 1].last_v = last_v;
			rcvpkt[i + 1].counter++;
		}
	}
	for (i = 1; i < 17; i++) {
		if ((last_v - obj[i].last_v) > 60) {
			obj[i].high = 2.0f;
			obj[i].vtx_x = 0.0f;
			obj[i].vtx_y = 0.0f;
			obj[i].last_v = 0;
			obj[i].detect = 0;
			rcvpkt[i].counter = 0;
			rcvpkt[i].last_c = 0;
		}
	}
	return 0;
}

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
