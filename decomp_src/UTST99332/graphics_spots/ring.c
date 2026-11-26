#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x10 */
    unsigned int color;
    int unum;
    int vnum;
    const float *vert;
};
typedef struct _anon1 RING_PARTS;
struct _anon2;
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon2 { /* size 0x68 */
    u_int32 amb;
    u_int32 diff;
    u_int32 spec;
    ScePspFVector3 pos;
    ScePspFVector3 dir;
    float exp;
    float cut;
    float atte[3];
    ScePspFVector3 trans;
    ScePspFVector3 rot;
    ScePspFVector3 angle;
    ScePspFVector3 speed;
};
typedef struct _anon2 LIGHT_INFO;
struct _anon3;
struct _anon3 { /* size 0x1c */
    int w;
    int h;
    int tw;
    float scalex;
    float scaley;
    const unsigned int *clut;
    const unsigned int *tex;
};
typedef struct _anon3 TEX_INFO;

extern LIGHT_INFO spots[3];
extern const unsigned int wall_clut[8];
extern const unsigned int guest_clut[8];
extern const unsigned int wall_tex[32];
extern const unsigned int guest_tex[128];
extern TEX_INFO tinfo[2];
extern const float light_body[5][48];
extern const float light_arm[48];
extern const float light_spot[5][48];
extern const float mat[48];
extern const float wall[48];
extern const float guest[48];
extern const float pole_1[48];
extern const float pole_2[48];
extern const float pole_head[48];
extern const float cushion[60];
extern const float rope[48];
extern const ScePspFVector3 rot[4];
extern const ScePspFVector3 trans[3];
extern const ScePspFVector3 light_pos;
extern const ScePspFVector3 light_trans;
extern RING_PARTS ring_parts[11];

void DrawRing(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexScale(float u, float v);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateXYZ(const ScePspFVector3 *v);
void sceGumRotateY(float angle);
void sceGumRotateZYX(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

void InitRing(void) {
    sceGuTexMode(4, 0, 0, 0);
    sceGuTexFilter(7, 1);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(0, 0);
    sceGuTexMapMode(0, 0U, 1U);
    sceGuTexOffset(0.0f, 0.0f);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_arm);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_spot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", mat);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_head);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", cushion);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", rope);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", rot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", trans);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_pos);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_trans);

#define NUM_LIGHTS 3
#define OBJ_MAT (0)
#define SCEGU_LIGHT3                      14
#define OBJ_LIGHTB ((0)+8)
#define LIGHT_BODYNUM	5
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define OBJ_LIGHTA ((0)+9)
#define OBJ_LIGHTS ((0)+10)
#define LIGHT_SPOTNUM	5
#define OBJ_WALL ((0)+1)
#define OBJ_GUEST ((0)+2)
#define SCEGU_TEXTURE                      9
#define OBJ_POLE1 ((0)+3)
#define OBJ_POLE2 ((0)+4)
#define OBJ_POLEH ((0)+5)
#define OBJ_CUSHION ((0)+6)
#define OBJ_ROPE ((0)+7)
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_OPEN_OPEN                    3
#define SCE_NULL		(0)

void DrawRing(void)
{
	RING_PARTS	*p;
	int			i, j, n;

	sceGumPushMatrix();

	sceGuDisable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHT3);

	
	p = &ring_parts[OBJ_MAT];
	sceGuPatchDivide(32, 32);
	sceGuColor(p->color);
	sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
		SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

	sceGuEnable(SCEGU_LIGHT3);
	sceGuPatchDivide(8, 8);

	
	sceGumPushMatrix();
	sceGumTranslate(&light_pos);
	p = &ring_parts[OBJ_LIGHTB];
	sceGuColor(p->color);
	n = p->unum * p->vnum * 3;
	for (i = 0; i < LIGHT_BODYNUM; i++) {
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, &p->vert[n*i]);
	}

	for (i = 0; i < NUM_LIGHTS; i++) {
		sceGumPushMatrix();
		sceGumRotateY(SCEGU_RAD(i*120.0f));

		
		p = &ring_parts[OBJ_LIGHTA];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		
		p = &ring_parts[OBJ_LIGHTS];
		sceGuColor(p->color);
		n = p->unum * p->vnum * 3;
		for (j = 0; j < LIGHT_SPOTNUM; j++) {
			sceGumPushMatrix();
			sceGumTranslate(&light_trans);
			sceGumRotateXYZ(&spots[i].rot);
			sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
				SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, &p->vert[n*j]);
			sceGumPopMatrix();
		}
		sceGumPopMatrix();
	}
	sceGumPopMatrix();

	for (i = 0; i < 4; i++) {
		sceGumPushMatrix();
		sceGumRotateZYX(&rot[i]);

		sceGuEnable(SCEGU_TEXTURE);
		
		sceGuTexScale(tinfo[0].scalex, tinfo[0].scaley);
		sceGuTexImage(0, tinfo[0].w, tinfo[0].h, tinfo[0].tw, tinfo[0].tex);
		sceGuClutLoad(1, tinfo[0].clut);
		p = &ring_parts[OBJ_WALL];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		
		sceGuTexScale(tinfo[1].scalex, tinfo[1].scaley);
		sceGuTexImage(0, tinfo[1].w, tinfo[1].h, tinfo[1].tw, tinfo[1].tex);
		sceGuClutLoad(1, tinfo[1].clut);
		p = &ring_parts[OBJ_GUEST];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		sceGuDisable(SCEGU_TEXTURE);
		
		p = &ring_parts[OBJ_POLE1];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		
		p = &ring_parts[OBJ_POLE2];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		
		p = &ring_parts[OBJ_POLEH];
		sceGuColor(p->color);
		sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
			SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

		for (j = 0; j < 3; j++) {
			sceGumPushMatrix();
			sceGumTranslate(&trans[j]);

			
			p = &ring_parts[OBJ_CUSHION];
			sceGuColor(p->color);
			sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
				SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

			
			p = &ring_parts[OBJ_ROPE];
			sceGuColor(p->color);
			sceGumDrawSpline(SCEGU_VERTEX_FLOAT, p->unum, p->vnum,
				SCEGU_OPEN_OPEN, SCEGU_OPEN_OPEN, SCE_NULL, p->vert);

			sceGumPopMatrix();
		}
		sceGumPopMatrix();
	}

	sceGumPopMatrix();
}
