/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_particle;
extern int inv_particle_max;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);



void inv_particle_all_init(void) {
    memset(&inv_particle, 0, 0xFDC00U);
    inv_particle_max = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF4);

typedef struct { float x, y, z; } PV3;
typedef struct { int cnt, end; PV3 pos, v, r, vr, a, b, c; float f78, f7c, f80, f84; } PSUB;
typedef struct { int used, f4, tex, fc; PV3 pos; PSUB s[16]; u8 pad[0xFDC - 0x1C - 16 * 0x6C]; } PSTART;
extern const double D_0007CEE8;
extern const double D_0007CEF0;
unsigned long genrand_int32(void);
double genrand_real2(void);
double genrand_real3(void);
int inv_particle_start(int tex, PV3 pos, int type, int fc, float size, float speed)
{
	int i, k, r;
	PSTART *p;
	PSUB *s;
	float f;

	if (inv_particle_max >= 256)
		return -1;
	for (i = 0; i < 256; i++) {
		p = &((PSTART *)&inv_particle)[i];
		if (p->used == 0) {
			p->tex = tex;
			p->pos = pos;
			p->fc = fc;
			p->used = 1;
			p->f4 = 0;
			if (type == 0) {
				for (k = 0; k < 16; k++) {
					s = &p->s[k];
					s->cnt = 0;
					s->end = genrand_int32() % 15 + 15;
					f = genrand_real2() * size + D_0007CEE8;
					s->pos = p->pos;
					/* block-scope initialised temporaries: all three share one stack slot */
					{
						PV3 t = { -f, 0, -f };
						s->a = t;
					}
					{
						PV3 t = { -f, 0, f };
						s->b = t;
					}
					{
						PV3 t = { f, 0, -f };
						s->c = t;
					}
					s->v.x = (genrand_real3() - D_0007CEF0) * speed;
					s->v.y = (genrand_real3() - D_0007CEF0) * speed;
					s->v.z = (genrand_real3() - D_0007CEF0) * speed;
					s->r.x = genrand_int32() % 360;
					s->r.y = genrand_int32() % 360;
					s->r.z = genrand_int32() % 360;
					r = genrand_int32() % 3;
					if (r == 0) {
						s->vr.x = (genrand_real2() + D_0007CEE8) * speed;
						s->vr.y = 0;
						s->vr.z = 0;
					} else if (r == 1) {
						s->vr.x = 0;
						s->vr.y = (genrand_real2() + D_0007CEE8) * speed;
						s->vr.z = 0;
					} else if (r == 2) {
						s->vr.x = 0;
						s->vr.y = 0;
						s->vr.z = (genrand_real2() + D_0007CEE8) * speed;
					}
					s->f78 = genrand_real2();
					s->f80 = genrand_real2();
					s->f7c = s->f78 + 0.125f;
					s->f84 = s->f80 + 0.125f;
				}
			} else {
				p->used = 0;
			}
			if (p->used == 1) {
				inv_particle_max++;
				if (inv_particle_max >= 256)
					inv_particle_max = 255;
			}
			return i;
		}
	}
	return -1;
}

int inv_particle_check(unsigned int no)
{
	if (no >= 256)
		return 1;
	return *(int *)((u8 *)&inv_particle + no * 0xFDC) != 1;
}

typedef struct {
	int f0[7];
	int cnt, end;
	float x, y, z, vx, vy, vz;
	float rx, ry, rz, vrx, vry, vrz;
	int f54[6];
} PTC1;
typedef struct { PTC1 p[16]; u8 pad[0xFDC - 16 * 0x6C]; } PTC;

typedef struct { int used, f4, pri; u8 pad[0xFDC - 12]; } PS;
extern int par_co[], par_pri_co[];
void inv_particle_control(void)
{
	PTC *g;
	PTC1 *p;
	int i, j, n;

	for (i = 0; i < 0x100; i++) {
		g = &((PTC *)&inv_particle)[i];
		n = 0;
		if (g->p[0].f0[0] != 1)
			continue;
		p = g->p;
		for (j = 0; j < 16; j++, p++) {
			if (++p->cnt >= p->end) {
				n++;
			} else {
				p->x += p->vx;
				p->y += p->vy;
				p->z += p->vz;
				p->rx += p->vrx;
				p->ry += p->vry;
				p->rz += p->vrz;
			}
		}
		if (n >= 16) {
			g->p[0].f0[0] = 0;
			inv_particle_max--;
			if (inv_particle_max < 0)
				inv_particle_max = 0;
		}
	}
}

typedef struct __attribute__((packed)) { float u, v; unsigned int c; float x, y, z; } PVTX;
typedef struct { int used, f4, tex, fc; PV3 pos; PSUB s[16]; PVTX v0[48]; PVTX v1[48]; } PDISP;
extern int inv_particle_disp_max, inv_particle_disp_time, g_packet;
unsigned int sceKernelGetSystemTimeLow(void);
void inv_particle_syncsort(void);
void vec_roll_yxz(PV3 *in, PV3 *rot, PV3 *out);
void sceGuEnable(int);
void sceGuDisable(int);
void sceGuTexFunc(int, int);
void sceGuTexMapMode(int, unsigned int, unsigned int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void set_texture(int);
void sceGuAlphaFunc(int, int, int);
void sceGuBlendFunc(int, int, int, unsigned int, unsigned int);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices);
void inv_particle_disp(void)
{
	PDISP *p;
	PSUB *s;
	PVTX *v, *w;
	PV3 t[3];
	int i, j, k;
	unsigned int tm;
	int set;
	int tex;

	inv_particle_disp_max = 0;
	inv_particle_disp_time = 0;
	if (inv_particle_max <= 0)
		return;
	tm = sceKernelGetSystemTimeLow();
	inv_particle_syncsort();
	set = 0;
	tex = -1;
	for (i = 0; i < inv_particle_max; i++) {
		p = &((PDISP *)&inv_particle)[par_co[i]];
		if (p->used != 1)
			continue;
		if (!g_packet)
			v = p->v0;
		else
			v = p->v1;
		for (j = 0; j < 16; j++) {
			s = &p->s[j];
			w = &v[j * 3];
			if (s->cnt < s->end) {
				w[0].u = s->f78;
				w[0].v = s->f80;
				w[1].u = s->f78;
				w[1].v = s->f84;
				w[2].u = s->f7c;
				w[2].v = s->f80;
				w[0].c = -1;
				w[1].c = -1;
				w[2].c = -1;
				vec_roll_yxz(&s->a, &s->r, &t[0]);
				vec_roll_yxz(&s->b, &s->r, &t[1]);
				vec_roll_yxz(&s->c, &s->r, &t[2]);
				w[0].x = s->pos.x + t[0].x;
				w[0].y = s->pos.y + t[0].y;
				w[0].z = s->pos.z + t[0].z;
				w[1].x = s->pos.x + t[1].x;
				w[1].y = s->pos.y + t[1].y;
				w[1].z = s->pos.z + t[1].z;
				w[2].x = s->pos.x + t[2].x;
				w[2].y = s->pos.y + t[2].y;
				w[2].z = s->pos.z + t[2].z;
			} else {
				for (k = 0; k < 3; k++) {
					v[j * 3 + k].u = 0;
					v[j * 3 + k].v = 0;
					v[j * 3 + k].c = 0;
					v[j * 3 + k].x = 0;
					v[j * 3 + k].y = 0;
					v[j * 3 + k].z = 0;
				}
			}
		}
		if (set == 0) {
			sceGuDisable(5);
			sceGuAlphaFunc(1, 0, 255);
			sceGuEnable(0);
			sceGuBlendFunc(0, 2, 3, 0, 0);
			set = 1;
			sceGuEnable(4);
		}
		if (p->tex == -1 && tex == p->tex) {
			sceGuDisable(9);
		} else {
			tex = p->tex;
			sceGuEnable(9);
			sceGuTexFunc(0, 1);
			sceGuTexMapMode(0, 0, 0);
			sceGuTexWrap(0, 0);
			sceGuTexFilter(1, 1);
			set_texture(p->tex);
		}
		sceGumPushMatrix();
		sceKernelDcacheWritebackInvalidateRange(v, 0x480);
		sceGumDrawArrayN(3, 0x19F, 3, 16, 0, v);
		sceGumPopMatrix();
	}
	if (set == 1)
		sceGuEnable(5);
	inv_particle_disp_time = sceKernelGetSystemTimeLow() - tm;
	inv_particle_disp_max = inv_particle_max;
}

void inv_particle_syncsort(void)
{
	int i, j, k, n, key, no, m;

	n = 0;
	if (inv_particle_max <= 0)
		return;
	for (i = 0; i < 256; i++) {
		if (n >= inv_particle_max)
			break;
		if (((PS *)&inv_particle)[i].used == 1) {
			par_co[n] = i;
			par_pri_co[n] = ((PS *)&inv_particle)[i].pri;
			n++;
		}
	}
	if (n <= 0)
		return;
	for (k = 1; k < n; k++) {
		no = par_co[k];
		key = par_pri_co[k];
		for (j = k - 1; j >= 0 && par_pri_co[j] >= key; j--) {
			par_co[j + 1] = par_co[j];
			par_pri_co[j + 1] = par_pri_co[j];
		}
		par_co[j + 1] = no;
		par_pri_co[j + 1] = key;
	}
}
