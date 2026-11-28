/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_ring;
extern int gmo_max;
extern int ring_pri_no;
extern int ring_tex_no;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);



void inv_ring_all_init(void) {
    memset(&inv_ring, 0, 0x6F00U);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_ring_priset(void) {
    ring_pri_no = gmo_max;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_ring_priget(void) {
    return ring_pri_no;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_ring_texno(int arg0) {
    ring_tex_no = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_start);

int inv_ring_end(unsigned int no)
{
	if (no >= 16)
		return 0;
	*(int *)((u8 *)&inv_ring + no * 0x6F0) = 0;
	return 1;
}

typedef struct __attribute__((packed)) { float u, v; unsigned int c; float x, y, z; } RVTX;
typedef struct {
	int on, disp, f8;
	float pos[3], r0[3], r1[3];
	float f30, f34, f38;
	int f3c, f40, f44;
	int r[2], g[2], b[2];
	int f60, f64;
	float u[2];
	int f70, f74;
	float v[2];
	int f80, f84;
	unsigned int col[2];
	RVTX v0[34];
	RVTX v1[34];
} RINGC;
extern int game_pause, g_packet;
float sinf_nb(float) __asm__("sinf");
float cosf_nb(float) __asm__("cosf");
int inv_ring_control(RINGC *r)
{
	RVTX *v;
	int i, k, flip, a;
	float rr[2], ang;

	if (game_pause == 0) {
		r->f38 += r->f30;
		r->f8++;
	}
	if (!g_packet)
		v = r->v0;
	else
		v = r->v1;
	if (r->on == 0 || r->disp == 0) {
		for (i = 0; i < 34; i++) {
			v[i].u = 0;
			v[i].v = 0;
			v[i].c = 0;
			v[i].x = 0;
			v[i].y = 0;
			v[i].z = 0;
		}
		return 0;
	}
	rr[0] = r->f38;
	rr[1] = r->f38 - r->f34;
	if (rr[1] < 0.0f)
		rr[1] = 0.0f;
	if (game_pause == 0)
		r->f40 += r->f3c;
	a = r->f40;
	r->col[0] = 0xFF000000 | (r->b[0] * a / 255) << 16 | (r->g[0] * a / 255) << 8 | (r->r[0] * a / 255);
	r->col[1] = 0xFF000000 | (r->b[1] * a / 255) << 16 | (r->g[1] * a / 255) << 8 | (r->r[1] * a / 255);
	if (a <= 0) {
		r->on = 0;
		r->disp = 0;
		return 0;
	}
	flip = 0;
	for (k = 0; k < 34; k += 2) {
		ang = (float)(k / 2 * 360 / 16) / 180.0f * 3.1415927f;
		v[k].x = sinf_nb(ang) * rr[0];
		v[k].y = 0;
		v[k].z = cosf_nb(ang) * rr[0];
		v[k + 1].x = sinf_nb(ang) * rr[1];
		v[k + 1].y = 0;
		v[k + 1].z = cosf_nb(ang) * rr[1];
		v[k].c = r->col[0];
		v[k + 1].c = r->col[1];
		if (flip == 0) {
			v[k].u = r->u[0];
			v[k].v = r->v[0];
			v[k + 1].u = r->u[0];
			v[k + 1].v = r->v[1];
		} else {
			v[k].u = r->u[1];
			v[k].v = r->v[0];
			v[k + 1].u = r->u[1];
			v[k + 1].v = r->v[1];
		}
		flip ^= 1;
	}
	return 1;
}

typedef struct { int on, disp, f8; float pos[3]; float r0[3]; float r1[3]; u8 pad[0x90 - 0x30]; u8 v0[0x330]; u8 v1[0x330]; } RING_T;
extern RING_T inv_ring_a[16] __asm__("inv_ring");
extern int inv_ring_disp_max, inv_ring_disp_time, g_packet;
unsigned int sceKernelGetSystemTimeLow(void);
int inv_ring_control();
void sceGuDisable(int);
void sceGuEnable(int);
void sceGuTexFunc(int, int);
void sceGuTexMapMode(int, unsigned int, unsigned int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void set_texture(int);
void sceGuAlphaFunc(int, int, int);
void sceGuBlendFunc(int, int, int, unsigned int, unsigned int);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumTranslate(const void *v);
void sceGumRotateX(float);
void sceGumRotateY(float);
void sceGumRotateZ(float);
int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void inv_ring_disp(void)
{
	RING_T *r;
	int i, n;
	unsigned int t;
	void *v;

	n = 0;
	inv_ring_disp_max = 0;
	inv_ring_disp_time = 0;
	t = sceKernelGetSystemTimeLow();
	for (i = 0; i < 16; i++)
		n += inv_ring_control(&inv_ring_a[i]);
	if (n == 0)
		return;
	sceGuDisable(10);
	sceGuDisable(5);
	sceGuDisable(1);
	sceGuDisable(7);
	if (ring_tex_no != -1) {
		sceGuEnable(9);
		sceGuTexFunc(0, 1);
		sceGuTexMapMode(0, 0, 0);
		sceGuTexWrap(1, 1);
		sceGuTexFilter(1, 1);
		set_texture(ring_tex_no);
	}
	sceGuAlphaFunc(1, 0, 0xFF);
	sceGuEnable(0);
	sceGuBlendFunc(0, 10, 10, -1, -1);
	sceGuEnable(0);
	for (i = 0; i < 16; i++) {
		r = &inv_ring_a[i];
		if (r->on != 0 && r->disp != 0) {
			if (!g_packet)
				v = r->v0;
			else
				v = r->v1;
			inv_ring_disp_max++;
			sceGumPushMatrix();
			sceGumTranslate(r->pos);
			sceGumRotateY(r->r1[1] * 3.1415927f / 180.0f);
			sceGumRotateX(r->r1[0] * 3.1415927f / 180.0f);
			sceGumRotateZ(r->r1[2] * 3.1415927f / 180.0f);
			sceGumRotateY(r->r0[1] * 3.1415927f / 180.0f);
			sceGumRotateX(r->r0[0] * 3.1415927f / 180.0f);
			sceGumRotateZ(r->r0[2] * 3.1415927f / 180.0f);
			sceKernelDcacheWritebackInvalidateRange(v, 0x330);
			sceGumDrawArray(4, 0x19F, 0x22, 0, v);
			sceGumPopMatrix();
		}
	}
	sceGuEnable(1);
	sceGuEnable(5);
	sceGuEnable(10);
	sceGuEnable(7);
	inv_ring_disp_time = sceKernelGetSystemTimeLow() - t;
}
