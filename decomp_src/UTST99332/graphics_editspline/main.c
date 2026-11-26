/* cflags: -O2 -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef unsigned int u_int32;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int mode;
extern int prim;
extern int current;
extern int knot[4];
extern int param;
extern int unum;
extern int vnum;
extern ScePspFVector3 control[256];
extern const int primflag[3];
extern const float spline[48];
extern const float dot[6];
extern u_int32 cont;
extern int analog;

static void resize_model(int pu, int pv, int nu, int nv);
static int get_knotflag(int s, int e);
static void draw_spline(void);
static void draw_dot(void);
static void num2str(int num, char *str);
static void draw_param(void);
static void draw_frame(void);
static void init_param(void);
static void init_all(void);
static int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAmbient(unsigned int color);
void sceGuClear(int flags);
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
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchPrim(int prim);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);
int sceKernelDcacheWritebackAll(void);

#define MAXCTRL		16
#define SCEGU_PRIM_RECTANGLES              6
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_DEPTH_TEST                   1
#define MAXPRIM		3
#define MAXMODE		2
#define MAXPARAM	7
#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0
#define BASECTRL	16
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
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_NORMAL_REVERSE_PATCH        20
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHTING                    10
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_DISPLAY_ON		1
#define DTRANS		0.1f;
#define SCE_CTRL_CIRCLE				(1<<13)
#define SCE_CTRL_CROSS				(1<<14)
#define SCE_CTRL_TRIANGLE			(1<<12)
#define SCE_CTRL_SQUARE				(1<<15)
#define SCE_CTRL_UP					(1<<4)
#define SCE_CTRL_DOWN				(1<<6)
#define SCE_CTRL_LEFT				(1<<7)
#define SCE_CTRL_RIGHT				(1<<5)
#define VTRANS		1.0f;
#define SCE_CTRL_L					(1<<8)
#define SCE_CTRL_L1					SCE_CTRL_L
#define SCE_CTRL_R					(1<<9)
#define SCE_CTRL_R1					SCE_CTRL_R
#define SCE_CTRL_START				(1<<3)
#define SCE_CTRL_SELECT				(1<<0)

static void resize_model(int pu,int pv, int nu,int nv)
{
	ScePspFVector3	tmp[MAXCTRL*MAXCTRL];
	int		i,j;
	int		u,v;
	float	n;

	u=nu-pu;
	v=nv-pv;

	for (i=0; i<pu; i++) {
		for (j=0; j<pv; j++) {
			tmp[i+j*MAXCTRL].x=control[i+j*pu].x;
			tmp[i+j*MAXCTRL].y=control[i+j*pu].y;
			tmp[i+j*MAXCTRL].z=control[i+j*pu].z;
		}
	}

	if (u>0) {
		for (j=0; j<pv; j++) {
			for (i=0; i<pu; i++) {
				control[i+j*nu].x=tmp[i+j*MAXCTRL].x;
				control[i+j*nu].y=tmp[i+j*MAXCTRL].y;
				control[i+j*nu].z=tmp[i+j*MAXCTRL].z;
			}
			n=control[i+j*nu-1].x-control[i+j*nu-2].x;
			control[i+j*nu].x=control[i+j*nu-1].x+n;
			n=control[i+j*nu-1].y-control[i+j*nu-2].y;
			control[i+j*nu].y=control[i+j*nu-1].y+n;
			n=control[i+j*nu-1].z-control[i+j*nu-2].z;
			control[i+j*nu].z=control[i+j*nu-1].z+n;
		}
	}
	else if (u<0) {
		for (i=0; i<nu; i++) {
			for (j=0; j<nv; j++) {
				control[i+j*nu].x=tmp[i+j*MAXCTRL].x;
				control[i+j*nu].y=tmp[i+j*MAXCTRL].y;
				control[i+j*nu].z=tmp[i+j*MAXCTRL].z;
			}
		}
	}

	if (v>0) {
		for (i=0; i<pu; i++) {
			for (j=0; j<pv; j++) {
				control[i+j*nu].x=tmp[i+j*MAXCTRL].x;
				control[i+j*nu].y=tmp[i+j*MAXCTRL].y;
				control[i+j*nu].z=tmp[i+j*MAXCTRL].z;
			}
			n=control[i+(j-1)*nu].x-control[i+(j-2)*nu].x;
			control[i+j*nu].x=control[i+(j-1)*nu].x+n;
			n=control[i+(j-1)*nu].y-control[i+(j-2)*nu].y;
			control[i+j*nu].y=control[i+(j-1)*nu].y+n;
			n=control[i+(j-1)*nu].z-control[i+(j-2)*nu].z;
			control[i+j*nu].z=control[i+(j-1)*nu].z+n;
		}
	}
	else if (v<0) {
		for (i=0; i<nu; i++) {
			for (j=0; j<nv; j++) {
				control[i+j*nu].x=tmp[i+j*MAXCTRL].x;
				control[i+j*nu].y=tmp[i+j*MAXCTRL].y;
				control[i+j*nu].z=tmp[i+j*MAXCTRL].z;
			}
		}
	}
}

static int get_knotflag(int s, int e)
{
	int ret;

	ret = 0;
	if (s) {
		ret = 1;
	}
	if (e) {
		ret += 2;
	}

	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", draw_spline);

static void draw_dot(void)
{
	int		i;

	sceGuDisable(SCEGU_DEPTH_TEST);
	for (i=0; i<(unum*vnum); i++) {
		if (i==current)	sceGuColor(0xffffff80);
		else			sceGuColor(0xff80ffff);

		sceGumPushMatrix();

		sceGumTranslate(&control[i]);
		sceGumDrawArray(SCEGU_PRIM_RECTANGLES,
						SCEGU_VERTEX_FLOAT, 2, 0, (void *)dot);

		sceGumPopMatrix();
	}
	sceGuEnable(SCEGU_DEPTH_TEST);
}

static void num2str(int num, char *str)
{
	const int columns = 2;
	int i;
	int a;

	a = num;
	for (i = columns - 1; i >= 0; i--) {
		str[i] = a % 10 + '0';
		a /= 10;
	}
	str[columns] = 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", primflag);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", spline);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", dot);

static void draw_param(void)
{
	const char	char_prim[MAXPRIM][16]={
		"TRIANGLE_STRIP",
		"LINE_STRIP",
		"POINTS"
	};
	const char	char_knot[MAXMODE][8]={
		"CLOSE",
		"OPEN"
	};
	const char	char_label[MAXPARAM][8]={
		"PRIM:",
		"UNUM:",
		"VNUM:",
		"U ST:",
		"  ED:",
		"V ST:",
		"  ED:"
	};
	char			buf[8];
	char			*p=0;
	unsigned int	c;
	int				i;

	for (i=0; i<MAXPARAM; i++) {
		if (param==i)	c=0x00ff80ff;
		else			c=0x00ffffff;

		sceGuDebugPrint( 16,24+16*i, c, char_label[i]);

		switch (i)
		{
		case 0:	p=(char *)char_prim[prim];		break;
		case 1:	num2str(unum,buf);
				p=(char *)buf;					break;
		case 2:	num2str(vnum,buf);
				p=(char *)buf;					break;
		case 3:	p=(char *)char_knot[knot[0]];	break;
		case 4:	p=(char *)char_knot[knot[1]];	break;
		case 5:	p=(char *)char_knot[knot[2]];	break;
		case 6:	p=(char *)char_knot[knot[3]];	break;
		}
		if(p)
			sceGuDebugPrint( 56,24+16*i, c, p);
	}
}

static void draw_frame(void)
{
	const char	char_mode[MAXMODE][8]={
		"[EDIT]",
		"[VIEW]"
	};

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuDebugPrint(  8, 8, 0x00ffffff, char_mode[mode]);

	if (!mode)
		draw_param();

	sceGumPushMatrix();

	sceGumLoadIdentity();

	sceGumTranslate(&pos);
	sceGumRotateX(SCEGU_RAD(rot.x));
	sceGumRotateY(SCEGU_RAD(rot.y));
	sceGumRotateZ(SCEGU_RAD(rot.z));

	draw_spline();

	if (!mode)
		draw_dot();

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

static void init_param(void)
{
	int		i;

	pos.x=pos.y=pos.z=0.0f;
	rot.x=rot.y=rot.z=0.0f;

	pos.z=-14.0f;

	mode=0;
	prim=0;
	current=0;
	param=0;

	unum=4;
	vnum=4;

	knot[0]=0;
	knot[1]=0;
	knot[2]=0;
	knot[3]=0;

	for (i=0; i<BASECTRL; i++) {
		control[i].x=spline[i*3+0];
		control[i].y=spline[i*3+1];
		control[i].z=spline[i*3+2];
	}
}

static void init_all(void)
{
	ScePspFVector3	vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
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

	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

	vec.x=0.614497f;
	vec.y=0.691714f;
	vec.z=0.379372f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT0);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuAmbient(0xffdddddd);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT,
					1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);

	sceGuClearColor(0x00800000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	init_param();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

static int pad_read(void)
{
	SceCtrlData	buf;
	u_int32		prev=cont;
	u_int32		padd;
	int			prevanalog=analog;
	int			pu,pv;

	sceCtrlReadBufferPositive(&buf, 1);
	cont = buf.Buttons;
	padd=cont&(cont^prev);

	if (!mode) {
		ScePspFVector3	*cur_pt=&control[current];

		if (cont & SCE_CTRL_UP) {
			cur_pt->y+=DTRANS;
		}
		if (cont & SCE_CTRL_DOWN) {
			cur_pt->y-=DTRANS;
		}
		if (cont & SCE_CTRL_LEFT) {
			cur_pt->x-=DTRANS;
		}
		if (cont & SCE_CTRL_RIGHT) {
			cur_pt->x+=DTRANS;
		}
		if (cont & SCE_CTRL_L1) {
			cur_pt->z+=DTRANS;
		}
		if (cont & SCE_CTRL_R1) {
			cur_pt->z-=DTRANS;
		}

		if (buf.Lx<0x40)
			analog=-1;
		else if (buf.Lx>0xc0)
			analog= 1;
		else
			analog= 0;

		if (!analog) {
			if (prevanalog==-1)
				current=(current-1<0?(unum*vnum)-1:current-1);
			else if (prevanalog==1)
				current=(current+1>=(unum*vnum)?0:current+1);
		}

		if (padd & SCE_CTRL_CIRCLE) {
			switch (param)
			{
			case 0:
				prim=(prim+1>=MAXPRIM?0:prim+1);
				break;
			case 1:
				pu=unum,pv=vnum;
				unum=(unum+1>MAXCTRL?MAXCTRL:unum+1);
				resize_model(pu,pv,unum,vnum);
				break;
			case 2:
				pu=unum,pv=vnum;
				vnum=(vnum+1>MAXCTRL?MAXCTRL:vnum+1);
				resize_model(pu,pv,unum,vnum);
				break;
			case 3: case 4: case 5: case 6:
				knot[param-3]^=1;
				break;
			}
		}
		if (padd & SCE_CTRL_CROSS) {
			switch (param)
			{
			case 0:
				prim=(prim-1<0?MAXPRIM-1:prim-1);
				break;
			case 1:
				pu=unum,pv=vnum;
				unum=(unum-1<4?4:unum-1);
				resize_model(pu,pv,unum,vnum);
				break;
			case 2:
				pu=unum,pv=vnum;
				vnum=(vnum-1<4?4:vnum-1);
				resize_model(pu,pv,unum,vnum);
				break;
			case 3: case 4: case 5: case 6:
				knot[param-3]^=1;
				break;
			}
		}

		if (padd & SCE_CTRL_TRIANGLE)
			param=(param-1<0?MAXPARAM-1:param-1);
		if (padd & SCE_CTRL_SQUARE)
			param=(param+1>=MAXPARAM?0:param+1);
	}
	else {
		if (cont & SCE_CTRL_UP) {
			rot.x+=VTRANS;
			if (rot.x>=360.0f)
				rot.x=0.0f;
		}
		if (cont & SCE_CTRL_DOWN) {
			rot.x-=VTRANS;
			if (rot.x<0.0f)
				rot.x+=360.0f;
		}
		if (cont & SCE_CTRL_LEFT) {
			rot.y+=VTRANS;
			if (rot.y>=360.0f)
				rot.y=0.0f;
		}
		if (cont & SCE_CTRL_RIGHT) {
			rot.y-=VTRANS;
			if (rot.y<0.0f)
				rot.y+=360.0f;
		}
		if (cont & SCE_CTRL_L1) {
			pos.z+=VTRANS;
		}
		if (cont & SCE_CTRL_R1) {
			pos.z-=VTRANS;
		}

		if ((cont & SCE_CTRL_L1) && (cont & SCE_CTRL_R1)) {
			init_param();
		}
	}

	if (padd & SCE_CTRL_START)
		mode=(mode+1>=MAXMODE?0:mode+1);

	if (padd & SCE_CTRL_SELECT)
		return 0;

	return 1;
}

int main(void) {
    menuInit();
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 9);
    return 0;
}
