/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* sinf, cosf and sqrtf are not declared: the builtins (pure, sqrtf inline) */

typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;
typedef struct ScePspFVector4 { float x, y, z, w; } ScePspFVector4;
typedef struct ScePspFMatrix4 { ScePspFVector4 x, y, z, w; } ScePspFMatrix4;

typedef struct {
	ScePspFMatrix4 *top;
	ScePspFMatrix4 *bottom;
	ScePspFMatrix4 *cur;
} SceGumStack;

typedef struct {
	int cur_matrix;
	ScePspFMatrix4 *cur_stack;
	SceGumStack mat_stack[4];
	int update[4];
} SceGumContext;

void sceGuSetMatrix(int type, const ScePspFMatrix4 *matrix);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);

extern int cur_matrix;
extern ScePspFMatrix4 *cur_stack;
extern SceGumStack mat_stack[4];
extern int update[4];

void sceGumLoadIdentity(void);

static void __mulMatrix(ScePspFMatrix4 *d, const ScePspFMatrix4 *a, const ScePspFMatrix4 *b)
{
	ScePspFMatrix4 t;
	int i;

	t.x.x = b->x.x * a->x.x + b->x.y * a->y.x + b->x.z * a->z.x + b->x.w * a->w.x;
	t.x.y = b->x.x * a->x.y + b->x.y * a->y.y + b->x.z * a->z.y + b->x.w * a->w.y;
	t.x.z = b->x.x * a->x.z + b->x.y * a->y.z + b->x.z * a->z.z + b->x.w * a->w.z;
	t.x.w = b->x.x * a->x.w + b->x.y * a->y.w + b->x.z * a->z.w + b->x.w * a->w.w;
	t.y.x = b->y.x * a->x.x + b->y.y * a->y.x + b->y.z * a->z.x + b->y.w * a->w.x;
	t.y.y = b->y.x * a->x.y + b->y.y * a->y.y + b->y.z * a->z.y + b->y.w * a->w.y;
	t.y.z = b->y.x * a->x.z + b->y.y * a->y.z + b->y.z * a->z.z + b->y.w * a->w.z;
	t.y.w = b->y.x * a->x.w + b->y.y * a->y.w + b->y.z * a->z.w + b->y.w * a->w.w;
	t.z.x = b->z.x * a->x.x + b->z.y * a->y.x + b->z.z * a->z.x + b->z.w * a->w.x;
	t.z.y = b->z.x * a->x.y + b->z.y * a->y.y + b->z.z * a->z.y + b->z.w * a->w.y;
	t.z.z = b->z.x * a->x.z + b->z.y * a->y.z + b->z.z * a->z.z + b->z.w * a->w.z;
	t.z.w = b->z.x * a->x.w + b->z.y * a->y.w + b->z.z * a->z.w + b->z.w * a->w.w;
	t.w.x = b->w.x * a->x.x + b->w.y * a->y.x + b->w.z * a->z.x + b->w.w * a->w.x;
	t.w.y = b->w.x * a->x.y + b->w.y * a->y.y + b->w.z * a->z.y + b->w.w * a->w.y;
	t.w.z = b->w.x * a->x.z + b->w.y * a->y.z + b->w.z * a->z.z + b->w.w * a->w.z;
	t.w.w = b->w.x * a->x.w + b->w.y * a->y.w + b->w.z * a->z.w + b->w.w * a->w.w;
	for (i = 0; i < 16; i++)
		((float *)d)[i] = ((float *)&t)[i];
}

static void __setMatrix(int type)
{
	mat_stack[cur_matrix].cur = cur_stack;
	sceGuSetMatrix(type, mat_stack[type].cur);
}

static void __checkUpdate(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		if (update[i]) {
			__setMatrix(i);
			update[i] = 0;
		}
	}
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumSetMatrixStack);

void sceGumSetCurMatrix(void)
{
	__setMatrix(cur_matrix);
}

void sceGumUpdateMatrix(void)
{
	__checkUpdate();
}

void sceGumLoadContext(const SceGumContext *context)
{
	int i;

	cur_matrix = context->cur_matrix;
	cur_stack = context->cur_stack;
	for (i = 0; i < 4; i++) {
		mat_stack[i].top = context->mat_stack[i].top;
		mat_stack[i].bottom = context->mat_stack[i].bottom;
		mat_stack[i].cur = context->mat_stack[i].cur;
		update[i] = context->update[i];
	}
}

void sceGumStoreContext(SceGumContext *context)
{
	int i;

	context->cur_matrix = cur_matrix;
	context->cur_stack = cur_stack;
	for (i = 0; i < 4; i++) {
		context->mat_stack[i].top = mat_stack[i].top;
		context->mat_stack[i].bottom = mat_stack[i].bottom;
		context->mat_stack[i].cur = mat_stack[i].cur;
		context->update[i] = update[i];
	}
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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumRotateZYX);

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
	__mulMatrix(cur_stack, cur_stack, m);
	update[cur_matrix] = 1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumPerspective);

void sceGumOrtho(float left, float right, float bottom, float top, float near, float far)
{
	ScePspFMatrix4 m;
	float rl = 1.0f / (right - left);
	float tb = 1.0f / (top - bottom);
	float fn = 1.0f / (far - near);
	float tx = -(right + left) * rl;
	float ty = -(top + bottom) * tb;
	float tz = -(far + near) * fn;

	m.x.x = 2.0f * rl; m.x.y = 0.0f; m.x.z = 0.0f; m.x.w = 0.0f;
	m.y.x = 0.0f; m.y.y = 2.0f * tb; m.y.z = 0.0f; m.y.w = 0.0f;
	m.z.x = 0.0f; m.z.y = 0.0f; m.z.z = -2.0f * fn; m.z.w = 0.0f;
	m.w.x = tx; m.w.y = ty; m.w.z = tz; m.w.w = 1.0f;
	__mulMatrix(cur_stack, cur_stack, &m);
	update[cur_matrix] = 1;
}

#define NORMALIZE(v) \
	t.x = (v).x * (v).x; \
	t.y = (v).y * (v).y; \
	t.z = (v).z * (v).z; \
	l = sqrtf(t.x + t.y + t.z); \
	l = 1.0f / l; \
	if (l != 0.0f) { \
		(v).x *= l; \
		(v).y *= l; \
		(v).z *= l; \
	}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libgum", sceGumLookAt);

void sceGumMatrixMode(int mode)
{
	mat_stack[cur_matrix].cur = cur_stack;
	cur_matrix = mode;
	cur_stack = mat_stack[mode].cur;
}

void sceGumPushMatrix(void)
{
	ScePspFMatrix4 *prev = cur_stack;
	int i;

	cur_stack++;
	if (cur_stack >= mat_stack[cur_matrix].bottom) {
		cur_stack = prev;
		return;
	}
	for (i = 0; i < 16; i++)
		((float *)cur_stack)[i] = ((float *)(cur_stack - 1))[i];
}

void sceGumPopMatrix(void)
{
	ScePspFMatrix4 *prev = cur_stack;

	cur_stack--;
	if (cur_stack < mat_stack[cur_matrix].top) {
		cur_stack = prev;
		return;
	}
	update[cur_matrix] = 1;
}

void sceGumLoadMatrix(const ScePspFMatrix4 *m)
{
	int i;

	for (i = 0; i < 16; i++)
		((float *)cur_stack)[i] = ((const float *)m)[i];
	update[cur_matrix] = 1;
}

void sceGumStoreMatrix(ScePspFMatrix4 *m)
{
	int i;

	for (i = 0; i < 16; i++)
		((float *)m)[i] = ((float *)cur_stack)[i];
}

void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArray(prim, vtype, count, indices, vertices);
}

void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArrayN(prim, vtype, count, n, indices, vertices);
}

void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawBezier(vtype, ucount, vcount, indices, vertices);
}

void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawSpline(vtype, ucount, vcount, uedge, vedge, indices, vertices);
}
