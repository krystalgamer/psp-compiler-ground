#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct _anon1;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
typedef unsigned char u_char8;
struct _anon1 { /* size 0x30 */
    int flg;
    ScePspFVector3 pos;
    ScePspFVector3 spd;
    ScePspFVector3 rot;
    u_int32 c;
    u_char8 a;
};
typedef struct _anon1 PARTICLE;

extern PARTICLE particle[128];
extern int nextindex;
extern float flit[18];
extern u_int32 rand_data;

void InitParticle(void);
int CheckParticle(void);
void SetParticle(float x, float y, float z, float speed, int number, int c);
void DrawParticle(void);


/* SDK prototypes (tools/sdk_protos.h) */
float cosf(float x);
float sinf(float x);

void random_seed(unsigned int seed) {
    rand_data = seed;
}

int random(void) {
    unsigned int temp_v1;

    temp_v1 = (rand_data * 0x4E6D) + 0x3039;
    rand_data = temp_v1;
    return (int) (temp_v1 >> 4);
}

void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void InitParticle(void)
{
	int i;

	for (i = 0; i < 128; i++)
		particle[i].flg = 0;
	nextindex = 0;
}

int CheckParticle(void)
{
	int i;

	for (i = 0; i < 128; i++) {
		if (particle[i].flg)
			return 1;
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/particle", SetParticle);

void sceGuColor(unsigned int color);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuColor(unsigned int color);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumScale(const ScePspFVector3 *v);
void sceGuColor(unsigned int color);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void DrawParticle(void)
{
	PARTICLE *p;
	ScePspFVector3 vec;
	int i;
	u_int32 c;

	for (i = 0; i < 128; i++) {
		p = &particle[i];
		if (p->flg != 1)
			continue;
		p->pos.x += p->spd.x;
		p->pos.y += p->spd.y;
		p->pos.z += p->spd.z;
		p->spd.x *= 0.98f;
		p->spd.y *= 0.98f;
		p->spd.z *= 0.98f;
		p->a -= 4;
		p->rot.x += 2.0f;
		p->rot.y += 2.0f;
		p->rot.z += 2.0f;
		if (p->rot.x > 360.0f)
			p->rot.x -= 360.0f;
		if (p->rot.y > 360.0f)
			p->rot.y -= 360.0f;
		if (p->rot.z > 360.0f)
			p->rot.z -= 360.0f;
		if (p->a < 33)
			p->flg = 0;
		if (p->pos.z >= 30.0f)
			p->flg = 0;
		sceGumPushMatrix();
		vec.x = p->pos.x;
		vec.y = p->pos.y;
		vec.z = p->pos.z;
		sceGumTranslate(&vec);
		sceGumRotateX(p->rot.x * 3.1415927f / 180.0f);
		sceGumRotateY(p->rot.y * 3.1415927f / 180.0f);
		sceGumRotateZ(p->rot.z * 3.1415927f / 180.0f);
		vec.x = 0.84f;
		vec.y = 0.84f;
		vec.z = 0.84f;
		sceGumScale(&vec);
		c = (p->a << 24) | (p->c & 0xffffff);
		sceGuColor(c);
		sceGumDrawArray(3, 0x1e0, 3, NULL, flit);
		sceGumPopMatrix();
	}
}
