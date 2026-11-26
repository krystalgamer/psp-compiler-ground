/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon1;
struct _anon1 { /* size 0x80 */
    int buffer[32];
};
typedef struct _anon1 SceGumContext;
struct _anon2;
struct _anon2 { /* size 0xc */
    ScePspFMatrix4 *top;
    ScePspFMatrix4 *bottom;
    ScePspFMatrix4 *cur;
};
typedef struct _anon2 MATRIX_STACK;

extern unsigned char __psp_libinfo__[24];
extern int cur_matrix;
extern ScePspFMatrix4 *cur_stack;
extern MATRIX_STACK mat_stack[4];
extern int update[4];

void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex);
void sceGumLoadIdentity(void);
void sceGumRotateXYZ(const ScePspFVector3 *vec);
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2);
void sceGumRotateZYX(const ScePspFVector3 *vec);
void sceGumPerspective(float fovy, float aspect, float r_near, float r_far);
void sceGumMultMatrix(const ScePspFMatrix4 *m);
void sceGumOrtho(float left, float right, float bottom, float top, float r_near, float r_far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumTranslate(const ScePspFVector3 *vec);
ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos);
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1);
static void _sceGumSetMatrix(int n);
void sceGumUpdateMatrix(void);
void sceGumStoreContext(SceGumContext *ctx);
void sceGumLoadContext(SceGumContext *ctx);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *vec);
static void _sceGumCheckUpdate(void);


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumProject);

void sceGumSetCurMatrix(void)
{
	mat_stack[cur_matrix].cur = cur_stack;
	if (cur_stack != NULL)
		sceGuSetMatrix(cur_matrix, cur_stack);
}

void sceGumUpdateMatrix(void) {
    _sceGumCheckUpdate();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumMultMatrix);

void sceGumMatrixMode(int mode)
{
	mat_stack[cur_matrix].cur = cur_stack;
	if (mat_stack[mode].cur != NULL) {
		cur_matrix = mode;
		cur_stack = mat_stack[cur_matrix].cur;
	}
}

void sceGumPushMatrix(void)
{
	if (cur_stack + 1 < mat_stack[cur_matrix].bottom) {
		cur_stack++;
		*cur_stack = *(cur_stack - 1);
	}
}

void sceGumPopMatrix(void)
{
	if (cur_stack != mat_stack[cur_matrix].top) {
		cur_stack--;
		update[cur_matrix] = 1;
	}
}

void sceGumLoadMatrix(const ScePspFMatrix4 *m)
{
	*cur_stack = *m;
	update[cur_matrix] = 1;
}

void sceGumStoreMatrix(ScePspFMatrix4 *m)
{
	*m = *cur_stack;
}

void sceGumDrawArray(int prim, int type, int count, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawArray(prim, type, count, idx, p);
 return;
}

void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawArrayN(prim, type, n_verts, n_prims, idx, p);
 return;
}

void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawBezier(type, ucount, vcount, idx, p);
 return;
}

void sceGumDrawSpline(int type, int ucount, int vcount, int uflag,
     int vflag, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawSpline(type, ucount, vcount, uflag, vflag, idx, p);
 return;
}

static void _sceGumCheckUpdate(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		if (update[i]) {
			mat_stack[cur_matrix].cur = cur_stack;
			if (mat_stack[i].cur != NULL)
				sceGuSetMatrix(i, mat_stack[i].cur);
			update[i] = 0;
		}
	}
}
