/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int uint;
typedef unsigned char uchar;
struct _anon1;
struct _anon2;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon2 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon2 geWORLD;
struct _anon3;
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
struct _anon3 { /* size 0xb0 */
    int type;
    int model;
    int motion;
    float step;
    ScePspFVector3 t;
    ScePspFVector3 r;
    ScePspFVector3 s;
    ScePspFMatrix4 m;
    ScePspFVector3 co[2];
    uint swflag;
    int dummy[3];
};
typedef struct _anon3 geOBJECT;
struct _anon1 { /* size 0xb50 */
    int walkmode;
    int nextgnd;
    int count;
    int light_dir;
    int light_flag;
    int light_cnt;
    int obj_num;
    int tex_num;
    int face;
    int face_cnt;
    int face_wait;
    geWORLD world;
    geOBJECT obj[16];
};
typedef struct _anon1 MAINDATA;
typedef struct _anon1 *PMAINDATA;
struct _anon4;
struct _anon5;
struct _anon5 { /* size 0xc */
    float zs;
    float ze;
    uint col;
};
typedef struct _anon5 geFOG;
struct _anon6;
struct _anon6 { /* size 0xc */
    int func;
    int aref;
    int amsk;
};
typedef struct _anon6 geALPHA;
struct _anon7;
struct _anon7 { /* size 0x14 */
    int equ;
    int asel;
    int bsel;
    int afix;
    int bfix;
};
typedef struct _anon7 geBLEND;
struct _anon4 { /* size 0x80 */
    int vramdepth;
    int offset_x;
    int offset_y;
    int depth_min;
    int depth_max;
    uint col_clear;
    uint col_ambient;
    uint col_model;
    int depth_test;
    int shade_mode;
    int front_face;
    int clip_plane;
    int normal_patch;
    int normal_prim;
    int cull_face;
    int dither;
    int col_material;
    float specular;
    int fog;
    geFOG fog_param;
    int alpha;
    geALPHA alpha_param;
    int blend;
    geBLEND blend_param;
};
typedef struct _anon4 geCONTEXT;
struct _anon8;
struct _anon8 { /* size 0x3c */
    int type;
    int comp;
    ScePspFVector3 vec;
    uint diff_col;
    uint spec_col;
    float spot_s;
    float spot_c;
    ScePspFVector3 spot_vec;
    float att_a;
    float att_b;
    float att_c;
};
typedef struct _anon8 geLIGHT;
struct _anon9;
struct _anon9 { /* size 0x34 */
    float cam_fovy;
    float cam_aspect;
    float cam_near;
    float cam_far;
    ScePspFVector3 cam_eye;
    ScePspFVector3 cam_center;
    ScePspFVector3 cam_up;
};
typedef struct _anon9 geCAMERA;
struct _anon10;
struct _anon11;
struct _anon11 { /* size 0x10 */
    void *tbp;
    int w;
    int h;
    int bw;
};
typedef struct _anon11 geTEXIMAGE;
struct _anon12;
struct _anon12 { /* size 0x14 */
    void *cbp;
    int np;
    int shift;
    int mask;
    int csa;
};
typedef struct _anon12 geCLUT;
struct _anon10 { /* size 0xe8 */
    int tpf;
    int cpf;
    int mode_lod;
    int mode_mc;
    int mode_hsm;
    geTEXIMAGE tex[8];
    geCLUT clut;
    int func_mode;
    int func_comp;
    int fil_min;
    int fil_mag;
    int wrapu;
    int wrapv;
    int level_mode;
    float level_offset;
    int map_mode;
    int map_lu;
    int map_lv;
    float su;
    float sv;
    float tu;
    float tv;
    uint col;
};
typedef struct _anon10 geTEXTURE;
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
struct _anon13;
struct _anon13 { /* size 0x18 */
    void (*init)(void);
    void (*pre)(void);
    int (*pad)(uint, uint, uchar *);
    void (*draw)(void);
    void (*post)(void);
    void (*deinit)(void);
};
typedef struct _anon13 geMODULE;

extern MAINDATA MainData;
extern PMAINDATA md;
extern geCONTEXT context;
extern geLIGHT light[2];
extern geCAMERA camera;
extern unsigned int clut_fly[8];
extern unsigned int pix_fly[32];
extern unsigned int clut_ground[128];
extern unsigned int pix_ground0[4096];
extern unsigned int pix_ground1[1024];
extern unsigned int pix_ground2[256];
extern unsigned int clut_s_face_0[128];
extern unsigned int pix_s_face_0[4096];
extern unsigned int clut_s_face_1[128];
extern unsigned int pix_s_face_1[4096];
extern unsigned int clut_s_face_2[128];
extern unsigned int pix_s_face_2[4096];
extern unsigned int clut_s_face_3[128];
extern unsigned int pix_s_face_3[4096];
extern unsigned int clut_s_face_4[128];
extern unsigned int pix_s_face_4[4096];
extern short unsigned int pix_logo[4096];
extern geTEXTURE tex[8];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern geMODULE module;
extern geMODULE cmodule;

int main(void);
void light_ctrl(uint c);
void init(void); /* static in the original; global here because asm .data refers to it */
int pad(uint padd, uint cont, uchar *axis);
static void fade_start(void);
void draw(void); /* static in the original; global here because asm .data refers to it */
void pre(void); /* static in the original; global here because asm .data refers to it */
void post(void);
static void drawinit(void);


/* module functions defined in other units */
void draw_bg(void);
void draw_char(void);
void draw_fly(void);
void draw_ground(void);
void geCommonSetModule(geMODULE *module);
void geFadeSetup(int mode, int step, uint c);
int geFadeState(void);
void geInit(void);
int geMainLoop(void);
void geSendProc(void (*func)(void));
void geSetCamera(int param, geCAMERA *camera);
void geSetContext(geCONTEXT *context);
void geSetLight(int n, int param, geLIGHT *light);
int geSetModule(int num, geMODULE *module);
void geSetWorld(geWORLD *world);
int geTexOption(int n, int param, geTEXTURE *tex);
int geTexSet(int n, geTEXTURE *tex);
void init_bg(void);
void init_char(void);
void init_fly(void);
void init_ground(void);
void init_logo(void);
void menuTerm(int cat, int num);
int pad_char(uint padd, uint cont, uchar *axis);
void post_char(void);
void post_fly(void);
int post_ground(void);
void set_char_pos(void);
void set_nextgnd(void);

/* module functions defined in other units */
void geIdentity(void);
void gePop(void);
void gePush(void);

int main(void) {
    menuInit();
    geInit();
    geSetModule(0, &module);
    geCommonSetModule(&cmodule);
    geMainLoop();
    geTerm();
    menuTerm(0, 2);
    return 0;
}

void light_ctrl(uint c)
{
	geLIGHT *l[2];

	l[0] = &light[0];
	l[1] = &light[1];

	l[0]->diff_col = c;
	l[0]->spec_col = c;
	l[1]->diff_col = c;
	l[1]->spec_col = c;
}

void init(void)
{
	geSendProc(drawinit);

	md->walkmode = 0;
	md->nextgnd = 0;
	md->count = 0;

	md->world = (geWORLD){ { 0.0f, -10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } };

	init_char();

	init_ground();

	init_fly();

	init_bg();

	init_logo();

	geTexSet(0, &tex[0]);
	geTexSet(1, &tex[1]);
	geTexOption(1, 1, &tex[1]);
	geTexOption(1, 8, &tex[1]);
	geTexSet(2, &tex[2]);
	geTexSet(3, &tex[3]);
	geTexSet(4, &tex[4]);
	geTexSet(5, &tex[5]);
	geTexSet(6, &tex[6]);
	geTexSet(7, &tex[7]);
	geModelSetTexFunc(NULL);

	geFadeSetup(2, 1, 0);
}

void term(void) {
    term_ground();
    term_char();
}

static inline void fade_out(void)
{
	if (geFadeState() == 0) {
		geFadeSetup(1, 4, 0xffe0f0f0);
	}
}

int pad(uint padd, uint cont, uchar *axis)
{
	pad_char(padd, cont, axis);

	if (padd & 0x1000) {
		fade_out();
	}

	return padd & 1;
}

void draw(void) {
    geSetLight(0, 1, light);
    geSetLight(1, 1, &light[1]);
    gePush();
    geIdentity();
    geSetWorld(&md->world);
    draw_bg();
    draw_ground();
    draw_char();
    draw_fly();
    gePop();
}

void cdraw(void) {
    draw_logo();
}

extern int D_001480D0;
void pre(void)
{
	int old = D_001480D0;

	D_001480D0 = geFadeState();
	if (old != D_001480D0 && old == 1) {
		if (D_001480D0 == 0) {
			geFadeSetup(2, 2, 0xffe0f0f0);
			md->walkmode ^= 1;
			md->count = 0;
			set_char_pos();
			set_nextgnd();
		}
	}
}

void post(void)
{
	post_char();

	if (post_ground()) {
		md->count++;
		if (md->count >= 21) {
			fade_out();
		}
	}

	post_fly();
}

static void drawinit(void)
{
	geSetContext(&context);
	geSetLight(0, 1, &light[0]);
	geSetLight(1, 1, &light[1]);
	geSetCamera(-1, &camera);
}

