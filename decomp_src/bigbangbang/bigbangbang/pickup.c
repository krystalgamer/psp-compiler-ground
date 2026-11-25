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



static void __matrix_inverse(ScePspFMatrix4 *pOut, ScePspFMatrix4 *pM);
static int __triangle_intersect(const ScePspFVector3 *org, const ScePspFVector3 *dir, ScePspFVector3 *v0, ScePspFVector3 *v1, ScePspFVector3 *v2);
int Pickup(int scrw, int scrh, int x, int y, ScePspFVector3 *v0, ScePspFVector3 *v1, ScePspFVector3 *v2);

/* SDK functions */
void sceGumMatrixMode(int mode);
void sceGumStoreMatrix(ScePspFMatrix4 *m);

static void __matrix_inverse(ScePspFMatrix4 *pOut, ScePspFMatrix4 *pM)
{
	ScePspFMatrix4 m;
	int i;

	m.x.x = pM->x.x; m.x.y = pM->y.x; m.x.z = pM->z.x; m.x.w = pM->w.x;
	m.y.x = pM->x.y; m.y.y = pM->y.y; m.y.z = pM->z.y; m.y.w = pM->w.y;
	m.z.x = pM->x.z; m.z.y = pM->y.z; m.z.z = pM->z.z; m.z.w = pM->w.z;
	m.w.x = pM->x.w; m.w.y = pM->y.w; m.w.z = pM->z.w; m.w.w = pM->w.w;
	for (i = 0; i < 16; i++)
		((float *)pOut)[i] = ((float *)&m)[i];
}

static int __triangle_intersect(const ScePspFVector3 *org, const ScePspFVector3 *dir, ScePspFVector3 *v0, ScePspFVector3 *v1, ScePspFVector3 *v2)
{
	ScePspFVector3 edge1;
	ScePspFVector3 edge2;
	ScePspFVector3 pvec;
	ScePspFVector3 tvec;
	ScePspFVector3 qvec;
	float d;
	float u;
	float v;

	edge1.x = v1->x - v0->x;
	edge1.y = v1->y - v0->y;
	edge1.z = v1->z - v0->z;
	edge2.x = v2->x - v0->x;
	edge2.y = v2->y - v0->y;
	edge2.z = v2->z - v0->z;
	pvec.x = dir->y * edge2.z - dir->z * edge2.y;
	pvec.y = dir->z * edge2.x - dir->x * edge2.z;
	pvec.z = dir->x * edge2.y - dir->y * edge2.x;
	d = edge1.x * pvec.x + edge1.y * pvec.y + edge1.z * pvec.z;
	if (d > 0.0f) {
		tvec.x = org->x - v0->x;
		tvec.y = org->y - v0->y;
		tvec.z = org->z - v0->z;
	} else {
		tvec.x = v0->x - org->x;
		tvec.y = v0->y - org->y;
		tvec.z = v0->z - org->z;
		d = -d;
	}
	if (d < 0.0001f)
		return 0;
	u = tvec.x * pvec.x + tvec.y * pvec.y + tvec.z * pvec.z;
	if (u < 0.0f || u > d)
		return 0;
	qvec.x = tvec.y * edge1.z - tvec.z * edge1.y;
	qvec.y = tvec.z * edge1.x - tvec.x * edge1.z;
	qvec.z = tvec.x * edge1.y - tvec.y * edge1.x;
	v = dir->x * qvec.x + dir->y * qvec.y + dir->z * qvec.z;
	if (v < 0.0f || u + v > d)
		return 0;
	return 1;
}

int Pickup(int scrw, int scrh, int x, int y, ScePspFVector3 *v0, ScePspFVector3 *v1, ScePspFVector3 *v2)
{
	ScePspFVector3 vDir;
	ScePspFVector3 vOrg;
	ScePspFVector3 v;
	ScePspFMatrix4 mProj;
	ScePspFMatrix4 mView;
	ScePspFMatrix4 m;

	v0->x = -v0->x;
	v0->y = -v0->y;
	v1->x = -v1->x;
	v1->y = -v1->y;
	v2->x = -v2->x;
	v2->y = -v2->y;
	sceGumMatrixMode(0);
	sceGumStoreMatrix(&mProj);
	sceGumMatrixMode(1);
	sceGumStoreMatrix(&mView);
	__matrix_inverse(&m, &mView);
	sceGumMatrixMode(2);
	v.x = ((2.0f * x) / scrw - 1.0f) / mProj.x.x;
	v.y = -((2.0f * y) / scrh - 1.0f) / mProj.y.y;
	v.z = 1.0f;
	vDir.x = v.x * m.x.x + v.y * m.y.x + v.z * m.z.x;
	vDir.y = v.x * m.x.y + v.y * m.y.y + v.z * m.z.y;
	vDir.z = v.x * m.x.z + v.y * m.y.z + v.z * m.z.z;
	vOrg.x = m.w.x;
	vOrg.y = m.w.y;
	vOrg.z = m.w.z;
	if (__triangle_intersect(&vOrg, &vDir, v0, v1, v2))
		return 1;
	return 0;
}
