#include "common.h"
/* cflags: -O2 -frename-registers */

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

extern const unsigned char __psp_libinfo__[24];
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
void sceGumSetCurMatrix(void);
static void _sceGumSetMatrix(int n);
void sceGumStoreContext(SceGumContext *ctx);
void sceGumLoadContext(SceGumContext *ctx);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *vec);
void sceGumFrustum(float left, float right, float bottom, float top, float r_near, float r_far);
void sceGumMatrixMode(int mode);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumLoadMatrix(const ScePspFMatrix4 *m);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
static void _sceGumCheckUpdate(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", __psp_libinfo___2FC2C);

extern __typeof__(update) update_8BE54;
#define update update_8BE54
void sceGumLoadIdentity(void)
{
	int i;

	for (i = 0; i < 16; i++)
		((float *)cur_stack)[i] = 0.0f;
	cur_stack->x.x = 1.0f;
	cur_stack->y.y = 1.0f;
	cur_stack->z.z = 1.0f;
	cur_stack->w.w = 1.0f;
	update[cur_matrix] = 1;
}
#undef update

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumProject);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumSetCurMatrix);

void sceGumUpdateMatrix(void) {
    _sceGumCheckUpdate();
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumFrustum);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", sceGumStoreMatrix);

void sceGumDrawArray(int prim, int type, int count, void *idx, void *p) {
    _sceGumCheckUpdate();
    sceGuDrawArray(prim, type, count, idx, p);
}

void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims, void *idx, void *p) {
    _sceGumCheckUpdate();
    sceGuDrawArrayN(prim, type, n_verts, n_prims, idx, p);
}

void sceGumDrawBezier(int type, int ucount, int vcount, void *idx, void *p) {
    _sceGumCheckUpdate();
    sceGuDrawBezier(type, ucount, vcount, idx, p);
}

void sceGumDrawSpline(int type, int ucount, int vcount, int uflag, int vflag, void *idx, void *p) {
    _sceGumCheckUpdate();
    sceGuDrawSpline(type, ucount, vcount, uflag, vflag, idx, p);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libgum", _sceGumCheckUpdate);
