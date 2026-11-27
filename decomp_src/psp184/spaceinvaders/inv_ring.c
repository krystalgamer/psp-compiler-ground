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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_control);

typedef struct { int on, disp, f8; float pos[3]; float r0[3]; float r1[3]; u8 pad[0x90 - 0x30]; u8 v0[0x330]; u8 v1[0x330]; } RING_T;
extern RING_T inv_ring_a[16] __asm__("inv_ring");
extern int inv_ring_disp_max, inv_ring_disp_time, g_packet;
unsigned int sceKernelGetSystemTimeLow(void);
int inv_ring_control(RING_T *r);
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
