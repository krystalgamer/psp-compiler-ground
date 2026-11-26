#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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

extern float parts[245];
extern ScePspFVector3 bone0[399];
extern ScePspFVector3 bone1[397];
extern ScePspFVector3 bone2[399];
extern ScePspFVector3 bone3[399];
extern ScePspFVector3 *bone_tbl[4];
extern short unsigned int mesh_pixel[256];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[80];
extern int frame;
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern ScePspFMatrix4 bone_m[4];
extern int cont;

static void boneCalc(void);
static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAmbient(unsigned int color);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);

static void boneCalc(void)
{
	ScePspFVector3	*tbl;
	ScePspFVector3	vec;
	int				i;

	sceGumPushMatrix();
	sceGumLoadIdentity();

	vec.x=-10.0, vec.y=0.0f, vec.z=0.0f;
	sceGumTranslate(&vec);

	for (i=0; i<4; i++) {
		tbl=bone_tbl[i];
		tbl=tbl+frame;

		sceGumRotateX(tbl->x);
		sceGumRotateY(tbl->y);
		sceGumRotateZ(tbl->z);
		sceGumStoreMatrix(&bone_m[i]);

		vec.x=5.0, vec.y=0.0f, vec.z=0.0f;
		sceGumTranslate(&vec);
	}

	sceGumPopMatrix();

	frame++;
	if (frame>=400) {
		frame=0;
	}
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_WEIGHT_4           ( 3 << 14 )
#define SCEGU_WEIGHT_FLOAT       ( 3 <<  9 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_CLOSE_CLOSE                  0
#define SCEGU_OPEN_OPEN                    3
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos);
	sceGumRotateX(SCEGU_RAD(rot.x));
	sceGumRotateY(SCEGU_RAD(rot.y));
	sceGumRotateZ(SCEGU_RAD(rot.z));

	boneCalc();
	sceGuBoneMatrix(0, &bone_m[0]);
	sceGuBoneMatrix(1, &bone_m[1]);
	sceGuBoneMatrix(2, &bone_m[2]);
	sceGuBoneMatrix(3, &bone_m[3]);

	sceGumDrawSpline(SCEGU_WEIGHT_4|SCEGU_WEIGHT_FLOAT|SCEGU_VERTEX_FLOAT,
				7, 5, SCEGU_CLOSE_CLOSE, SCEGU_OPEN_OPEN, 0, parts);

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", D_00011B90);
