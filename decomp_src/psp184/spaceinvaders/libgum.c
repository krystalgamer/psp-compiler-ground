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

void sceGumRotateXYZ(const ScePspFVector3 *vec);
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2);
void sceGumRotateZYX(const ScePspFVector3 *vec);
void sceGumPerspective(float fovy, float aspect, float r_near, float r_far);
void sceGumOrtho(float left, float right, float bottom, float top, float r_near, float r_far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos);
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1);
static void _sceGumSetMatrix(int n);
void sceGumUpdateMatrix(void);
void sceGumStoreContext(SceGumContext *ctx);
void sceGumLoadContext(SceGumContext *ctx);
void sceGumRotateX(float angle);
static void _sceGumCheckUpdate(void);


static __inline__ ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2)
{
 ScePspFMatrix4 tm;
 tm.x.x = m1->x.x*m2->x.x + m1->y.x*m2->x.y + m1->z.x*m2->x.z + m1->w.x*m2->x.w;
 tm.x.y = m1->x.y*m2->x.x + m1->y.y*m2->x.y + m1->z.y*m2->x.z + m1->w.y*m2->x.w;
 tm.x.z = m1->x.z*m2->x.x + m1->y.z*m2->x.y + m1->z.z*m2->x.z + m1->w.z*m2->x.w;
 tm.x.w = m1->x.w*m2->x.x + m1->y.w*m2->x.y + m1->z.w*m2->x.z + m1->w.w*m2->x.w;
 tm.y.x = m1->x.x*m2->y.x + m1->y.x*m2->y.y + m1->z.x*m2->y.z + m1->w.x*m2->y.w;
 tm.y.y = m1->x.y*m2->y.x + m1->y.y*m2->y.y + m1->z.y*m2->y.z + m1->w.y*m2->y.w;
 tm.y.z = m1->x.z*m2->y.x + m1->y.z*m2->y.y + m1->z.z*m2->y.z + m1->w.z*m2->y.w;
 tm.y.w = m1->x.w*m2->y.x + m1->y.w*m2->y.y + m1->z.w*m2->y.z + m1->w.w*m2->y.w;
 tm.z.x = m1->x.x*m2->z.x + m1->y.x*m2->z.y + m1->z.x*m2->z.z + m1->w.x*m2->z.w;
 tm.z.y = m1->x.y*m2->z.x + m1->y.y*m2->z.y + m1->z.y*m2->z.z + m1->w.y*m2->z.w;
 tm.z.z = m1->x.z*m2->z.x + m1->y.z*m2->z.y + m1->z.z*m2->z.z + m1->w.z*m2->z.w;
 tm.z.w = m1->x.w*m2->z.x + m1->y.w*m2->z.y + m1->z.w*m2->z.z + m1->w.w*m2->z.w;
 tm.w.x = m1->x.x*m2->w.x + m1->y.x*m2->w.y + m1->z.x*m2->w.z + m1->w.x*m2->w.w;
 tm.w.y = m1->x.y*m2->w.x + m1->y.y*m2->w.y + m1->z.y*m2->w.z + m1->w.y*m2->w.w;
 tm.w.z = m1->x.z*m2->w.x + m1->y.z*m2->w.y + m1->z.z*m2->w.z + m1->w.z*m2->w.w;
 tm.w.w = m1->x.w*m2->w.x + m1->y.w*m2->w.y + m1->z.w*m2->w.z + m1->w.w*m2->w.w;
 memcpy(m0, &tm, sizeof(ScePspFMatrix4));
 return (m0);
}

static __inline__ ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1)
{
 ScePspFVector4 tv;
 tv.x = m->x.x*v1->x + m->y.x*v1->y + m->z.x*v1->z + m->w.x;
 tv.y = m->x.y*v1->x + m->y.y*v1->y + m->z.y*v1->z + m->w.y;
 tv.z = m->x.z*v1->x + m->y.z*v1->y + m->z.z*v1->z + m->w.z;
 tv.w = m->x.w*v1->x + m->y.w*v1->y + m->z.w*v1->z + m->w.w;
 memcpy(v0, &tv, sizeof(ScePspFVector4));
 return (v0);
}


void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex)
{
 cur_stack = ((void *)0);
 if (tex) {
  mat_stack[3].top = &m[(proj+view+world)];
  mat_stack[3].cur = &m[(proj+view+world)];
  mat_stack[3].bottom = &m[(proj+view+world+tex)];
  cur_stack = mat_stack[3].cur;
  cur_matrix = 3;
  sceGumLoadIdentity();
  update[3] = 1;
 } else {
  mat_stack[3].top = ((void *)0);
  mat_stack[3].cur = ((void *)0);
  mat_stack[3].bottom = ((void *)0);
  update[3] = 0;
 }
 if (world) {
  mat_stack[2].top = &m[(proj+view)];
  mat_stack[2].cur = &m[(proj+view)];
  mat_stack[2].bottom = &m[(proj+view+world)];
  cur_stack = mat_stack[2].cur;
  cur_matrix = 2;
  sceGumLoadIdentity();
  update[2] = 1;
 } else {
  mat_stack[2].top = ((void *)0);
  mat_stack[2].cur = ((void *)0);
  mat_stack[2].bottom = ((void *)0);
  update[2] = 0;
 }
 if (view) {
  mat_stack[1].top = &m[proj];
  mat_stack[1].cur = &m[proj];
  mat_stack[1].bottom = &m[(proj+view)];
  cur_stack = mat_stack[1].cur;
  cur_matrix = 1;
  sceGumLoadIdentity();
  update[1] = 1;
 } else {
  mat_stack[1].top = ((void *)0);
  mat_stack[1].cur = ((void *)0);
  mat_stack[1].bottom = ((void *)0);
  update[1] = 0;
 }
 if (proj) {
  mat_stack[0].top = &m[0];
  mat_stack[0].cur = &m[0];
  mat_stack[0].bottom = &m[proj];
  cur_stack = mat_stack[0].cur;
  cur_matrix = 0;
  sceGumLoadIdentity();
  update[0] = 1;
 } else {
  mat_stack[0].top = ((void *)0);
  mat_stack[0].cur = ((void *)0);
  mat_stack[0].bottom = ((void *)0);
  update[0] = 1;
 }
 cur_matrix = 0;
 return;
}

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

void sceGumRotateY(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf(angle);
 c = (float)cosf(angle);
 m.x.x = c;
 m.x.y = 0.0f;
 m.x.z = -1.0f * s;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = 1.0f;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = s;
 m.z.y = 0.0f;
 m.z.z = c;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}

void sceGumRotateZ(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf(angle);
 c = (float)cosf(angle);
 m.x.x = c;
 m.x.y = s;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = -1.0f*s;
 m.y.y = c;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = 0.0f;
 m.z.z = 1.0f;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}

void sceGumTranslate(const ScePspFVector3 *v)
{
	ScePspFMatrix4 *c = cur_stack;
	ScePspFVector4 t;

	t.x = c->x.x * v->x + c->y.x * v->y + c->z.x * v->z;
	t.y = c->x.y * v->x + c->y.y * v->y + c->z.y * v->z;
	t.z = c->x.z * v->x + c->y.z * v->y + c->z.z * v->z;
	t.w = c->x.w * v->x + c->y.w * v->y + c->z.w * v->z;
	c->w.x += t.x;
	c->w.y += t.y;
	c->w.z += t.z;
	c->w.w += t.w;
	update[cur_matrix] = 1;
}

void sceGumScale(const ScePspFVector3 *v)
{
	ScePspFMatrix4 *c = cur_stack;

	c->x.x *= v->x;
	c->x.y *= v->x;
	c->x.z *= v->x;
	c->y.x *= v->y;
	c->y.y *= v->y;
	c->y.z *= v->y;
	c->z.x *= v->z;
	c->z.y *= v->z;
	c->z.z *= v->z;
	update[cur_matrix] = 1;
}

void sceGumMultMatrix(const ScePspFMatrix4 *m)
{
 _sceGumMulMatrix(cur_stack, cur_stack, m);
 update[cur_matrix] = 1;
 return;
}

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
