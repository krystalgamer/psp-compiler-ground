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


static __inline__ void _sceGumTranslate(const ScePspFVector3 *v)
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
}

#define SCEGU_MATRIX_PROJECTION 0
#define SCEGU_MATRIX_VIEW 1
#define SCEGU_MATRIX_WORLD 2

float sinf_nb(float) __asm__("sinf");
float cosf_nb(float) __asm__("cosf");

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

void sceGumRotateXYZ(const ScePspFVector3 *vec)
{
	ScePspFMatrix4	m;
	float	s[3], c[3];

	s[0] = (float)sinf_nb(vec->x);
	c[0] = (float)cosf_nb(vec->x);
	s[1] = (float)sinf_nb(vec->y);
	c[1] = (float)cosf_nb(vec->y);
	s[2] = (float)sinf_nb(vec->z);
	c[2] = (float)cosf_nb(vec->z);

	m.x.x = c[2] * c[1];
	m.x.y = (c[2] * s[1] * s[0]) + (s[2] * c[0]);
	m.x.z = (-1.0f * c[2] * s[1] * c[0]) + (s[2] * s[0]);
	m.x.w = 0.0f;
	m.y.x = -1.0f * s[2] * c[1];
	m.y.y = (-1.0f * s[2] * s[1] * s[0]) + (c[2] * c[0]);
	m.y.z = (s[2] * s[1] * c[0]) + (c[2] * s[0]);
	m.y.w = 0.0f;
	m.z.x = s[1];
	m.z.y = -1.0f * c[1] * s[0];
	m.z.z = c[1] * c[0];
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
	update[cur_matrix] = 1;
	return;
}

void sceGumRotateZYX(const ScePspFVector3 *vec)
{
	ScePspFMatrix4	m;
	float	s[3], c[3];

	s[0] = (float)sinf_nb(vec->x);
	c[0] = (float)cosf_nb(vec->x);
	s[1] = (float)sinf_nb(vec->y);
	c[1] = (float)cosf_nb(vec->y);
	s[2] = (float)sinf_nb(vec->z);
	c[2] = (float)cosf_nb(vec->z);

	m.x.x = c[1] * c[2];
	m.x.y = c[1] * s[2];
	m.x.z = -1.0f * s[1];
	m.x.w = 0.0f;
	m.y.x = (-1.0f * c[0] * s[2]) + (s[0] * s[1] * c[2]);
	m.y.y = (c[0] * c[2]) + (s[0] * s[1] * s[2]);
	m.y.z = s[0] * c[1];
	m.y.w = 0.0f;
	m.z.x = (s[0] * s[2]) + (c[0] * s[1] * c[2]);
	m.z.y = (-1.0f * s[0] * c[2]) + (c[0] * s[1] * s[2]);
	m.z.z = c[0] * c[1];
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
	update[cur_matrix] = 1;
	return;
}

void sceGumPerspective(float fovy, float aspect, float r_near, float r_far)
{
	ScePspFMatrix4	m;
	float	f, asp, nf1, nf2;

	f = fovy * 0.5f;
	f = (float)cosf(f) / (float)sinf(f);

	asp = 1.0f / aspect;

	nf1 = 1.0f / (r_near - r_far);
	nf2 = r_near + r_far;

	m.x.x = f * asp;
	m.x.y = 0.0f;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = f;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = 0.0f;
	m.z.z = nf1 * nf2;
	m.z.w = -1.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 2.0f * r_near * r_far * nf1;
	m.w.w = 0.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
	update[cur_matrix] = 1;
	return;
}

void sceGumOrtho(float left, float right, float bottom, float top,
			float r_near, float r_far)
{
	ScePspFMatrix4	m;
	float	rl1, rl2;
	float	tb1, tb2;
	float	fn1, fn2;

	rl1 = 1.0f / (right - left);
	rl2 = right + left;
	tb1 = 1.0f / (top - bottom);
	tb2 = top + bottom;
	fn1 = 1.0f / (r_far - r_near);
	fn2 = r_far + r_near;

	m.x.x = 2.0f * rl1;
	m.x.y = 0.0f;
	m.x.z = 0.0f;
	m.x.w = 0.0f;
	m.y.x = 0.0f;
	m.y.y = 2.0f * tb1;
	m.y.z = 0.0f;
	m.y.w = 0.0f;
	m.z.x = 0.0f;
	m.z.y = 0.0f;
	m.z.z = -2.0f * fn1;
	m.z.w = 0.0f;
	m.w.x = -1.0f * rl2 * rl1;
	m.w.y = -1.0f * tb2 * tb1;
	m.w.z = -1.0f * fn2 * fn1;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);
	update[cur_matrix] = 1;
	return;
}

void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center,
					const ScePspFVector3 *up)
{
	ScePspFMatrix4	m;
	ScePspFVector3	xvec, yvec, zvec;
	ScePspFVector3	tmpvec;
	float			tmpscal;

	zvec.x = eye->x - center->x;
	zvec.y = eye->y - center->y;
	zvec.z = eye->z - center->z;

	tmpvec.x = zvec.x * zvec.x;
	tmpvec.y = zvec.y * zvec.y;
	tmpvec.z = zvec.z * zvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	if (tmpscal) {
		zvec.x = zvec.x * tmpscal;
		zvec.y = zvec.y * tmpscal;
		zvec.z = zvec.z * tmpscal;
	}

	yvec.x = up->x;
	yvec.y = up->y;
	yvec.z = up->z;

	xvec.x = yvec.y * zvec.z - yvec.z * zvec.y;
	xvec.y = yvec.z * zvec.x - yvec.x * zvec.z;
	xvec.z = yvec.x * zvec.y - yvec.y * zvec.x;

	yvec.x = zvec.y * xvec.z - zvec.z * xvec.y;
	yvec.y = zvec.z * xvec.x - zvec.x * xvec.z;
	yvec.z = zvec.x * xvec.y - zvec.y * xvec.x;

	tmpvec.x = xvec.x * xvec.x;
	tmpvec.y = xvec.y * xvec.y;
	tmpvec.z = xvec.z * xvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	if (tmpscal) {
		xvec.x = xvec.x * tmpscal;
		xvec.y = xvec.y * tmpscal;
		xvec.z = xvec.z * tmpscal;
	}

	tmpvec.x = yvec.x * yvec.x;
	tmpvec.y = yvec.y * yvec.y;
	tmpvec.z = yvec.z * yvec.z;

	tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);

	if (tmpscal) {
		yvec.x = yvec.x * tmpscal;
		yvec.y = yvec.y * tmpscal;
		yvec.z = yvec.z * tmpscal;
	}

	m.x.x = xvec.x;
	m.x.y = yvec.x;
	m.x.z = zvec.x;
	m.x.w = 0.0f;
	m.y.x = xvec.y;
	m.y.y = yvec.y;
	m.y.z = zvec.y;
	m.y.w = 0.0f;
	m.z.x = xvec.z;
	m.z.y = yvec.z;
	m.z.z = zvec.z;
	m.z.w = 0.0f;
	m.w.x = 0.0f;
	m.w.y = 0.0f;
	m.w.z = 0.0f;
	m.w.w = 1.0f;

	_sceGumMulMatrix(cur_stack, cur_stack, &m);

	tmpvec.x = eye->x * ( -1.0f );
	tmpvec.y = eye->y * ( -1.0f );
	tmpvec.z = eye->z * ( -1.0f );

	_sceGumTranslate(&tmpvec);
	update[cur_matrix] = 1;
	return;
}

ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos)
{
	ScePspFMatrix4 tm;
	ScePspFVector4 tv;
	float q;

	if (mat_stack[SCEGU_MATRIX_VIEW].cur!=NULL) {
		{_sceGumMulMatrix(&tm, mat_stack[SCEGU_MATRIX_PROJECTION].cur, mat_stack[SCEGU_MATRIX_VIEW].cur);}
	} else {
		memcpy(&tm, mat_stack[SCEGU_MATRIX_PROJECTION].cur, sizeof(ScePspFMatrix4));
	}
	if (mat_stack[SCEGU_MATRIX_WORLD].cur!=NULL) {
		{_sceGumMulMatrix(&tm, &tm, mat_stack[SCEGU_MATRIX_WORLD].cur);}
	}
	_sceGumHomogeneousTransform(&tv, &tm, pos);
	q = 1.0f / tv.w;
	xyzq->x = tv.x * q;
	xyzq->y = tv.y * q;
	xyzq->z = tv.z * q;
	xyzq->w = q;
	return (xyzq);
}

void sceGumSetCurMatrix(void)
{
	mat_stack[cur_matrix].cur = cur_stack;
	if (cur_stack != NULL)
		sceGuSetMatrix(cur_matrix, cur_stack);
}

void sceGumUpdateMatrix(void) {
    _sceGumCheckUpdate();
}

typedef struct { int cur_matrix; ScePspFMatrix4 *cur_stack; MATRIX_STACK mat_stack[4]; int update[4]; } _SceGumContext;
void sceGumStoreContext(SceGumContext *ctx)
{
	int i;
	_SceGumContext *cp = (_SceGumContext *)ctx;
	cp->cur_matrix = cur_matrix;
	cp->cur_stack = cur_stack;
	for (i = 0; i < 4; i++) {
		cp->mat_stack[i].top = mat_stack[i].top;
		cp->mat_stack[i].bottom = mat_stack[i].bottom;
		cp->mat_stack[i].cur = mat_stack[i].cur;
		cp->update[i] = update[i];
	}
}

void sceGumLoadContext(SceGumContext *ctx)
{
	int i;
	const _SceGumContext *cp = (const _SceGumContext *)ctx;
	cur_matrix = cp->cur_matrix;
	cur_stack = cp->cur_stack;
	for (i = 0; i < 4; i++) {
		mat_stack[i].top = cp->mat_stack[i].top;
		mat_stack[i].bottom = cp->mat_stack[i].bottom;
		mat_stack[i].cur = cp->mat_stack[i].cur;
		update[i] = cp->update[i];
	}
}

void sceGumRotateX(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf_nb(angle);
 c = (float)cosf_nb(angle);
 m.x.x = 1.0f;
 m.x.y = 0.0f;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = c;
 m.y.z = s;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = -1.0f * s;
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
