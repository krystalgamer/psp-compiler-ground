/* cflags: -O3 */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef unsigned int uint;
struct _anon1 { /* size 0xb0 */
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
typedef struct _anon1 geOBJECT;



int geCollision(geOBJECT *obj0, geOBJECT *obj1);
static void __mulmatv(ScePspFMatrix4 *m, ScePspFVector3 *in, ScePspFVector3 *out);
static void __makebbox(ScePspFVector3 *in, ScePspFVector3 *out);


#define ABS(x) ((x) < 0.0f ? -(x) : (x))
static void __mulmatv(ScePspFMatrix4 *m, ScePspFVector3 *in, ScePspFVector3 *out)
{
	float tmp[3];

	tmp[0] = m->x.x * in->x + m->y.x * in->y + m->z.x * in->z + m->w.x;
	tmp[1] = m->x.y * in->x + m->y.y * in->y + m->z.y * in->z + m->w.y;
	tmp[2] = m->x.z * in->x + m->y.z * in->y + m->z.z * in->z + m->w.z;

	out->x = tmp[0];
	out->y = tmp[1];
	out->z = tmp[2];
}

static void __makebbox(ScePspFVector3 *in, ScePspFVector3 *out)
{
	float dx, dy, dz;

	dx = in[1].x * 0.5f;
	dy = in[1].y * 0.5f;
	dz = in[1].z * 0.5f;

	out[0].x = in[0].x - dx, out[0].y = in[0].y + dy, out[0].z = in[0].z + dz;
	out[1].x = in[0].x + dx, out[1].y = in[0].y + dy, out[1].z = in[0].z + dz;
	out[2].x = in[0].x + dx, out[2].y = in[0].y + dy, out[2].z = in[0].z - dz;
	out[3].x = in[0].x - dx, out[3].y = in[0].y + dy, out[3].z = in[0].z - dz;
	out[4].x = in[0].x - dx, out[4].y = in[0].y - dy, out[4].z = in[0].z + dz;
	out[5].x = in[0].x + dx, out[5].y = in[0].y - dy, out[5].z = in[0].z + dz;
	out[6].x = in[0].x + dx, out[6].y = in[0].y - dy, out[6].z = in[0].z - dz;
	out[7].x = in[0].x - dx, out[7].y = in[0].y - dy, out[7].z = in[0].z - dz;
}

int geCollision(geOBJECT *obj0, geOBJECT *obj1)
{
	ScePspFVector3 sphere[2];
	ScePspFVector3 bbox[2][8];
	ScePspFVector3 *p;
	float r[2];
	float tmp[3];
	int flag;
	int i;

	flag = 0;
	__mulmatv(&obj0->m, &obj0->co[0], &sphere[0]);
	__mulmatv(&obj1->m, &obj1->co[0], &sphere[1]);

	for (i = 0; i < 2; i++) {
		p = (i == 0) ? &obj0->co[1] : &obj1->co[1];
		r[i] = p->x;
		if (r[i] < p->y)
			r[i] = p->y;
		if (r[i] < p->z)
			r[i] = p->z;
		r[i] *= 0.5f;
	}

	tmp[0] = ABS(sphere[1].x - sphere[0].x) - (r[0] + r[1]);
	tmp[1] = ABS(sphere[1].y - sphere[0].y) - (r[0] + r[1]);
	tmp[2] = ABS(sphere[1].z - sphere[0].z) - (r[0] + r[1]);

	if (tmp[0] <= 0.0f && tmp[1] <= 0.0f && tmp[2] <= 0.0f) {
		__makebbox(obj0->co, bbox[0]);
		__makebbox(obj1->co, bbox[1]);
		flag = 1;
		for (i = 0; i < 8; i++) {
			__mulmatv(&obj0->m, &bbox[0][i], &bbox[0][i]);
			__mulmatv(&obj1->m, &bbox[1][i], &bbox[1][i]);
		}
	}
	return flag;
}
