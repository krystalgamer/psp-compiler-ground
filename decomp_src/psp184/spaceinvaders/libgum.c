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
void sceGumSetCurMatrix(void);
static void _sceGumSetMatrix(int n);
void sceGumUpdateMatrix(void);
void sceGumStoreContext(SceGumContext *ctx);
void sceGumLoadContext(SceGumContext *ctx);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *vec);
void sceGumMatrixMode(int mode);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumLoadMatrix(const ScePspFMatrix4 *m);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumDrawArray(int prim, int type, int count, const void *idx, const void *p);
void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims, const void *idx, const void *p);
void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx, const void *p);
void sceGumDrawSpline(int type, int ucount, int vcount, int uflag, int vflag, const void *idx, const void *p);
static void _sceGumCheckUpdate(void);


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumProject);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumSetCurMatrix);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumStoreMatrix);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumDrawArray);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumDrawArrayN);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumDrawBezier);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", sceGumDrawSpline);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libgum", _sceGumCheckUpdate);
