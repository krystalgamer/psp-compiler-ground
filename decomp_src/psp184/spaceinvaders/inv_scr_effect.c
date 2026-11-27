/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int alpha_mode_348800;
extern int texture_no_3487FC;
extern int alpha_mode2;
extern int texture_no2;
extern int e_pri;
extern int d_pri;


void *memset(void *s, int c, unsigned int n);
extern unsigned char inv_screfc, p_3307FC, inv_scrdisp, p2;
extern int e_co, d_co;
typedef struct { int on; int x[4]; int y[4]; float u0, u1, v0, v1; unsigned short col; } SCREFC;
void inv_screffect_all_init(void)
{
	memset(&inv_screfc, 0, 0x7000);
	memset(&p_3307FC, 0, 0xC000);
	memset(&inv_scrdisp, 0, 0x7000);
	memset(&p2, 0, 0xC000);
	alpha_mode_348800 = 2;
	texture_no_3487FC = -1;
	texture_no2 = -1;
	alpha_mode2 = 3;
	d_pri = 500;
	e_co = 0;
	d_co = 0;
	e_pri = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_screffect_tex_set(int arg0, int arg1) {
    texture_no_3487FC = arg0;
    alpha_mode_348800 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_scrdisp_tex_set(int arg0, int arg1) {
    texture_no2 = arg0;
    alpha_mode2 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_screffect_pri_set(int arg0) {
    e_pri = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_screffect_pri_get(void) {
    return e_pri;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_scrdisp_pri_set(int arg0) {
    d_pri = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_scrdisp_pri_get(void) {
    return d_pri;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_screffect_start);

int inv_screffect_start2(int x, int y, int w, int h, int u, int v, int r, int g, float sx, float sy, int b, int a)
{
	SCREFC *p;
	int i, ret, dw, dh, x0, y0, x1, y1;
	float fw, fh, fu, fv;
	int col1, col2, uu, vv, am;

	ret = -1;
	if (a <= 0 || sx <= 0.0f || sy <= 0.0f)
		goto end;
	uu = u + 1;
	vv = v + 1;
	am = alpha_mode_348800 >= 2 && alpha_mode_348800 <= 4;
	p = (SCREFC *)&inv_screfc;
	for (i = 0; i < 512; i++, p++) {
		if (p->on == 0) {
			fw = w;
			fh = h;
			dw = fw * sx / 100.0f;
			dh = fh * sy / 100.0f;
			x0 = x - dw / 2;
			y0 = y - dh / 2;
			y1 = y0 + dh;
			x1 = x0 + dw;
			p->x[0] = x0;
			p->y[0] = y0;
			p->x[1] = x0;
			p->y[1] = y1;
			p->x[2] = x1;
			p->y[2] = y0;
			p->x[3] = x1;
			p->y[3] = y1;
			if (x0 > 480) 
				break;
			if (x1 < 0) 
				break;
			if (y0 > 272) 
				break;
			if (y1 < 0) 
				break;
			fu = uu;
			fv = vv;
			p->u0 = fu;
			p->v0 = fv;
			p->u1 = fu + fw - 2.0f;
			p->v1 = fv + fh - 2.0f;
			if (am)
				{ int rr, gg, bb; rr = r * a / 255; gg = g * a / 255; bb = b * a / 255; p->col = ((a >> 4) << 12) | ((bb >> 4) << 8) | ((gg >> 4) << 4) | (rr >> 4); }
			else
				p->col = ((a >> 4) << 12) | ((b >> 4) << 8) | ((g >> 4) << 4) | (r >> 4);
			p->on = 1;
			e_co++;
			ret = i;
			goto end;
		}
	}
	ret = -1;
end:
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_scr_effect", inv_scrdisp_start);

typedef struct __attribute__((packed)) { unsigned short u, v; unsigned short c; short x, y, z; } SCRV_T;
extern int g_packet;
extern int inv_screfc_disp_max, inv_screfc_disp_time;
extern SCRV_T D_003367FC[];
unsigned int sceKernelGetSystemTimeLow(void);
void sceGuEnable(int);
void sceGuDisable(int);
void sceGuTexFunc(int, int);
void sceGuTexMapMode(int, unsigned int, unsigned int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void set_texture(int);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices);
int inv_screffect_disp(void)
{
	SCREFC *p;
	SCRV_T *v;
	int i, n, k, j;
	unsigned int t;

	n = 0;
	inv_screfc_disp_max = 0;
	inv_screfc_disp_time = 0;
	if (e_co == 0)
		return 0;
	t = sceKernelGetSystemTimeLow();
	v = (SCRV_T *)&p_3307FC;
	if (g_packet)
		v = D_003367FC;
	k = 0;
	for (i = 0; i < 512; i++) {
		p = &((SCREFC *)&inv_screfc)[i];
		if (p->on) {
			p->on = 0;
			j = k;
			k += 4;
			v[j].u = p->u0;
			v[j].v = p->v0;
			v[j + 1].u = p->u0;
			v[j + 1].v = p->v1;
			v[j + 2].u = p->u1;
			v[j + 2].v = p->v0;
			v[j + 3].u = p->u1;
			v[j + 3].v = p->v1;
			n++;
			v[j].c = p->col;
			v[j + 1].c = p->col;
			v[j + 2].c = p->col;
			v[j + 3].c = p->col;
			v[j].x = p->x[0];
			v[j].y = p->y[0];
			v[j].z = e_pri;
			v[j + 1].x = p->x[1];
			v[j + 1].y = p->y[1];
			v[j + 1].z = e_pri;
			v[j + 2].x = p->x[2];
			v[j + 2].y = p->y[2];
			v[j + 2].z = e_pri;
			v[j + 3].x = p->x[3];
			v[j + 3].y = p->y[3];
			v[j + 3].z = e_pri;
		}
	}
	if (n == 0)
		return 0;
	inv_screfc_disp_max = n;
	if (texture_no_3487FC != -1) {
		sceGuEnable(9);
		sceGuTexFunc(0, 1);
		sceGuTexMapMode(0, 0, 0);
		sceGuTexWrap(1, 1);
		sceGuTexFilter(1, 1);
		set_texture(texture_no_3487FC);
	}
	sceGuAlphaFunc(1, 0, 0xFF);
	sceGuEnable(0);
	if (alpha_mode_348800 == 0) {
		sceGuDisable(4);
	} else if (alpha_mode_348800 == 1) {
		sceGuBlendFunc(0, 2, 3, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode_348800 == 2) {
		sceGuBlendFunc(0, 10, 10, -1, -1);
		sceGuEnable(4);
	} else if (alpha_mode_348800 == 3) {
		sceGuBlendFunc(4, 0, 0, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode_348800 == 4) {
		sceGuBlendFunc(2, 10, 10, -1, -1);
		sceGuEnable(4);
	}
	sceKernelDcacheWritebackInvalidateRange(v, n * 3 * 16);
	sceGumDrawArrayN(4, 0x80011A, 4, n, 0, v);
	inv_screfc_disp_time = sceKernelGetSystemTimeLow() - t;
	return 1;
}

extern int g_packet;
extern int inv_scrdisp_disp_max, inv_scrdisp_disp_time;
extern SCRV_T D_003427FC[];
unsigned int sceKernelGetSystemTimeLow(void);
void sceGuEnable(int);
void sceGuDisable(int);
void sceGuTexFunc(int, int);
void sceGuTexMapMode(int, unsigned int, unsigned int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void set_texture(int);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices);
int inv_scrdisp_disp(void)
{
	SCREFC *p;
	SCRV_T *v;
	int i, n, k, j;
	unsigned int t;

	n = 0;
	inv_scrdisp_disp_max = 0;
	inv_scrdisp_disp_time = 0;
	if (d_co == 0)
		return 0;
	t = sceKernelGetSystemTimeLow();
	v = (SCRV_T *)&p2;
	if (g_packet)
		v = D_003427FC;
	k = 0;
	for (i = 0; i < 512; i++) {
		p = &((SCREFC *)&inv_scrdisp)[i];
		if (p->on) {
			p->on = 0;
			j = k;
			k += 4;
			v[j].u = p->u0;
			v[j].v = p->v0;
			v[j + 1].u = p->u0;
			v[j + 1].v = p->v1;
			v[j + 2].u = p->u1;
			v[j + 2].v = p->v0;
			v[j + 3].u = p->u1;
			v[j + 3].v = p->v1;
			n++;
			v[j].c = p->col;
			v[j + 1].c = p->col;
			v[j + 2].c = p->col;
			v[j + 3].c = p->col;
			v[j].x = p->x[0];
			v[j].y = p->y[0];
			v[j].z = d_pri;
			v[j + 1].x = p->x[1];
			v[j + 1].y = p->y[1];
			v[j + 1].z = d_pri;
			v[j + 2].x = p->x[2];
			v[j + 2].y = p->y[2];
			v[j + 2].z = d_pri;
			v[j + 3].x = p->x[3];
			v[j + 3].y = p->y[3];
			v[j + 3].z = d_pri;
		}
	}
	if (n == 0)
		return 0;
	inv_scrdisp_disp_max = n;
	if (texture_no2 != -1) {
		sceGuEnable(9);
		sceGuTexFunc(0, 1);
		sceGuTexMapMode(0, 0, 0);
		sceGuTexWrap(1, 1);
		sceGuTexFilter(1, 1);
		set_texture(texture_no2);
	}
	sceGuAlphaFunc(1, 0, 0xFF);
	sceGuEnable(0);
	if (alpha_mode2 == 0) {
		sceGuDisable(4);
	} else if (alpha_mode2 == 1) {
		sceGuBlendFunc(0, 2, 3, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode2 == 2) {
		sceGuBlendFunc(0, 10, 10, -1, -1);
		sceGuEnable(4);
	} else if (alpha_mode2 == 3) {
		sceGuBlendFunc(4, 0, 0, 0, 0);
		sceGuEnable(4);
	} else if (alpha_mode2 == 4) {
		sceGuBlendFunc(2, 10, 10, -1, -1);
		sceGuEnable(4);
	}
	sceKernelDcacheWritebackInvalidateRange(v, n * 3 * 16);
	sceGumDrawArrayN(4, 0x80011A, 4, n, 0, v);
	inv_scrdisp_disp_time = sceKernelGetSystemTimeLow() - t;
	return 1;
}

const float D_0007CEE4 = 0.0f;
