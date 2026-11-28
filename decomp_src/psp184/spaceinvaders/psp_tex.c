/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int D_0035AE84;


typedef struct { u8 pad[0xC]; int nearest; u8 rest[0xD0 - 0x10]; } SPRITE_W;
typedef struct { u8 pad[0x14]; int nearest; u8 rest[0x168 - 0x18]; } BILL_W;
extern SPRITE_W sprite[];
extern BILL_W billbord[];

typedef struct { int used; int f4; int f8; int type; int f10; int f14; void *p18; void *p1c; int f20; int f24; } TEX_FILE;
extern TEX_FILE tex_file[64];
extern int tex_file_max;
void *LoadFile(char *name, int *size);
void psp_free(void *p);
int bmp_addr_load(void *buf);
int bmp_addr_load_normal(void *buf);
int bmp_addr_load_alpha(void *buf);
int bmp_addr_load16(void *buf);
int bmp_addr_load16_normal(void *buf);
int bmp_addr_load16_alpha(void *buf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_init);

extern TEX_FILE tex_file[64];
extern int tex_file_max;
void *LoadFile(char *name, int *size);
void psp_free(void *p);
int bmp_addr_load(void *buf);
int bmp_addr_load_normal(void *buf);
int bmp_addr_load_alpha(void *buf);
int bmp_addr_load16(void *buf);
int bmp_addr_load16_normal(void *buf);
int bmp_addr_load16_alpha(void *buf);
int bmp_file_load(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load_normal(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load_normal(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", color_check);

int bmp_file_load_alpha(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load_alpha(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_alpha);

int bmp_file_load16(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load16_normal(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16_normal(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load16_alpha(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16_alpha(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_make);

int bmp_file_unload(int no)
{
	TEX_FILE *t = &tex_file[no];

	if ((unsigned int)no >= 64)
		return 0;
	if (t->used == 0)
		return 0;
	if ((unsigned int)t->type < 2)
		psp_free(t->p18);
	else
		psp_free(t->p1c);
	t->used = 0;
	t->p1c = 0;
	t->p18 = 0;
	tex_file_max--;
	return 1;
}

void bmp_file_all_unload(void)
{
	int i;

	for (i = 0; i < 64; i++)
		bmp_file_unload(i);
}

int bmp_file_copy_addrset(int no, int addr);
int bmp_file_copy(int no)
{
	return bmp_file_copy_addrset(no, 0);
}

typedef struct { u8 b[0x40]; } CLUT16_T;
typedef struct { u8 b[0x400]; } CLUT256_T;
void *sceGeEdramGetAddr(void);
void *memcpy(void *d, const void *s, unsigned int n);
int bmp_file_copy_addrset(int no, int addr)
{
	TEX_FILE *t;
	u8 *vram;
	int sz;

	if ((unsigned int)no >= 64)
		return -1;
	t = &tex_file[no];
	if (t->used == 0)
		return -1;
	vram = (u8 *)sceGeEdramGetAddr();
	vram += 0x154000;
	vram += addr;
	sz = 0;
	if (t->type == 2) {
		t->f24 = (int)vram;
		sz = t->f4 * t->f8 * 4;
		memcpy(vram, t->p1c, sz);
	} else if (t->type == 1) {
		t->f24 = (int)(vram + 0x400);
		t->f20 = (int)vram;
		sz = t->f4 * t->f8 + 0x400;
		*(CLUT256_T *)vram = *(CLUT256_T *)t->p18;
		memcpy((void *)t->f24, t->p1c, t->f4 * t->f8);
	} else if (t->type == 0) {
		t->f24 = (int)(vram + 0x40);
		t->f20 = (int)vram;
		sz = t->f4 * t->f8 / 2 + 0x40;
		*(CLUT16_T *)vram = *(CLUT16_T *)t->p18;
		memcpy((void *)t->f24, t->p1c, t->f4 * t->f8 / 2);
	}
	return sz;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", screen_capture);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_center_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_gt4_set);

void sprite_nearest(unsigned int no)
{
	if (no < 345)
		sprite[no].nearest = 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", poly_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", poly_g4_set);

extern int billbord_max;
typedef struct {
	int used, f4, tex, fc, f10, nearest, f18, f1c;
	float x, y, z, f2c, f30, f34;
	float u1, v1, u0, v0, f48, f4c, f50;
	int r, g, b, a, f64;
	u8 rest[0x168 - 0x68];
} BILL3D;
int sprite_set_3d(int tex, int a1, float x, float y, float z, float u0, float v0, float u1, float v1, float f48, int r, int g, int b, int a, int f64, int f18, float f4c, float f50, int f1c)
{
	int i, ret;
	BILL3D *p;

	ret = -1;
	if (billbord_max < 512) { i = 0; if (f1c != 0) {
		for (; i < 512; i++) {
			p = (BILL3D *)&billbord[i];
			if (p->used == 0)
				break;
		}
		p->x = x;
		p->y = y;
		p->z = z;
		p->u0 = u0 - 1.0f;
		p->v0 = v0 - 1.0f;
		p->u1 = u1 + 0.5f;
		p->v1 = v1 + 0.5f;
		p->f48 = f48;
		p->f4c = f4c;
		p->f50 = f50;
		billbord_max++;
		p->used = 1;
		p->fc = 1;
		p->f10 = 1;
		p->tex = tex;
		p->f64 = f64;
		p->r = r;
		p->g = g;
		p->b = b;
		p->a = a;
		p->f18 = f18;
		p->nearest = 0;
		p->f1c = f1c;
		ret = i;
	}
	}
	return ret;
}

int sprite_set_3d_efc(int tex, int a1, float x, float y, float z, float u0, float v0, float u1, float v1, float f48, int r, int g, int b, int a, int f64, int f18, float f4c, float f50, int f1c)
{
	int i, ret;
	BILL3D *p;

	ret = -1;
	if (billbord_max < 512) { i = 0; if (f1c != 0) {
		for (; i < 512; i++) {
			p = (BILL3D *)&billbord[i];
			if (p->used == 0)
				break;
		}
		p->x = x;
		p->y = y;
		p->z = z;
		p->u0 = u0 - 1.0f;
		p->v0 = v0 - 1.0f;
		p->u1 = u1 + 0.5f;
		p->v1 = v1 + 0.5f;
		p->f48 = f48;
		p->f4c = f4c;
		p->f50 = f50;
		billbord_max++;
		p->used = 1;
		p->fc = 0;
		p->f10 = 1;
		p->tex = tex;
		p->f64 = f64;
		p->r = r;
		p->g = g;
		p->b = b;
		p->a = a;
		p->f18 = f18;
		p->nearest = 0;
		p->f1c = f1c;
		ret = i;
	}
	}
	return ret;
}

int sprite_set_3d_efc_rot(int tex, int a1, float x, float y, float z, float u0, float v0, float u1, float v1, float f48, int r, int g, int b, int a, int f64, int f18, float f4c, float rx, float ry, float rz, int f1c)
{
	int i, ret;
	BILL3D *p;

	ret = -1;
	if (billbord_max < 512) { i = 0; if (f1c != 0) {
		for (; i < 512; i++) {
			p = (BILL3D *)&billbord[i];
			if (p->used == 0)
				break;
		}
		p->x = x;
		p->y = y;
		p->z = z;
		p->u0 = u0 - 1.0f;
		p->v0 = v0 - 1.0f;
		p->u1 = u1 + 0.5f;
		p->v1 = v1 + 0.5f;
		p->f48 = f48;
		p->f4c = f4c;
		billbord_max++;
		p->f2c = rx;
		p->used = 1;
		p->fc = 0;
		p->f10 = 0;
		p->tex = tex;
		p->f64 = f64;
		p->f30 = ry;
		p->f34 = rz;
		p->r = r;
		p->g = g;
		p->b = b;
		p->a = a;
		p->f18 = f18;
		p->nearest = 0;
		p->f1c = f1c;
		ret = i;
	}
	}
	return ret;
}

void sprite_3d_nearest(unsigned int no)
{
	if (no < 512)
		billbord[no].nearest = 1;
}

extern int spr_co[];
extern int sprite_max;
void set_packet_scr(int no);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexWrap(int u, int v);
void sceGuTexFilter(int min, int mag);
void sprite_bg_disp(void)
{
	int i, cur;
	int *s;

	if (sprite_max == 0)
		return;
	sceGuDisable(1);
	sceGuEnable(9);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(1, 1);
	cur = -1;
	for (i = 0; i < sprite_max; i++) {
		s = (int *)&sprite[spr_co[i]];
		if (s[0] == 0)
			continue;
		if (s[4] != 0)
			continue;
		if (cur != s[2]) {
			cur = s[2];
			if (cur != -1)
				set_texture(cur);
		}
		set_packet_scr(spr_co[i]);
	}
	sceGuTexFilter(1, 1);
	sceGuEnable(1);
}

extern int spr_pri_co[];
extern int sprite_disp_max;
unsigned int sceKernelGetSystemTimeLow(void);
extern int sprite_disp_time;
int inv_screffect_pri_get(void);
int inv_scrdisp_pri_get(void);
int inv_font_pri_get(void);
int sprite_screencopy_pri_get(void);
int inv_screffect_disp(void);
int inv_scrdisp_disp(void);
int inv_font_disp(void);
int sprite_screencopy_disp(void);
void sprite_scr_disp(void)
{
	unsigned int t;
	int i, cur, pri, d0, d1, d2, d3;
	int *s;

	sprite_disp_time = 0;
	t = sceKernelGetSystemTimeLow();
	sceGuDisable(1);
	sceGuDisable(5);
	sceGuDisable(10);
	if (sprite_max == 0) {
		if (inv_font_pri_get() < sprite_screencopy_pri_get()) {
			inv_screffect_disp();
			inv_scrdisp_disp();
			inv_font_disp();
			sprite_screencopy_disp();
		} else {
			inv_screffect_disp();
			inv_scrdisp_disp();
			sprite_screencopy_disp();
			inv_font_disp();
		}
		sceGuEnable(1);
		sceGuEnable(5);
		sceGuEnable(10);
	} else {
		sceGuEnable(9);
		sceGuTexFunc(0, 1);
		sceGuTexMapMode(0, 0, 0);
		sceGuTexWrap(0, 0);
		sceGuTexFilter(1, 1);
		cur = -1;
		d0 = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
		for (i = 0; i < sprite_max; i++) {
			pri = spr_pri_co[i];
			if (d0 == 0 && pri >= inv_screffect_pri_get()) {
				d0 = 1;
				if (inv_screffect_disp())
					cur = -1;
			}
			if (d1 == 0 && pri >= inv_scrdisp_pri_get()) {
				d1 = 1;
				if (inv_scrdisp_disp())
					cur = -1;
			}
			if (d2 == 0 && pri >= inv_font_pri_get()) {
				d2 = 1;
				if (inv_font_disp())
					cur = -1;
			}
			if (d3 == 0 && pri >= sprite_screencopy_pri_get()) {
				d3 = 1;
				if (sprite_screencopy_disp())
					cur = -1;
			}
			s = (int *)&sprite[spr_co[i]];
			if (s[0] == 0)
				continue;
			if (s[4] != 2)
				continue;
			if (cur != s[2]) {
				cur = s[2];
				if (cur != -1)
					set_texture(cur);
			}
			set_packet_scr(spr_co[i]);
			sprite_disp_max++;
		}
		if (d0 == 0)
			inv_screffect_disp();
		if (d1 == 0)
			inv_scrdisp_disp();
		if (d2 == 0)
			inv_font_disp();
		if (d3 == 0)
			sprite_screencopy_disp();
		sceGuTexFilter(1, 1);
		sceGuEnable(1);
		sceGuEnable(5);
		sceGuEnable(10);
		sprite_max = 0;
	}
	sprite_disp_time = sceKernelGetSystemTimeLow() - t;
}

extern int bill_co[];
extern int billbord_max, billbord_disp_max, billbord_disp_time;
unsigned int sceKernelGetSystemTimeLow(void);
void set_packet_3d(int no);
void sprite_3d_disp(void)
{
	int i, cur;
	unsigned int t;
	int *b;

	billbord_disp_time = 0;
	if (billbord_max == 0)
		return;
	cur = -1;
	t = sceKernelGetSystemTimeLow();
	sceGuEnable(9);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(1, 1);
	for (i = 0; i < billbord_max; i++) {
		b = (int *)&billbord[bill_co[i]];
		if (b[0] == 0)
			continue;
		if (cur != b[2]) {
			cur = b[2];
			if (cur != -1)
				set_texture(cur);
		}
		set_packet_3d(bill_co[i]);
		billbord_disp_max++;
	}
	billbord_max = 0;
	sceGuTexFilter(1, 1);
	billbord_disp_time = sceKernelGetSystemTimeLow() - t;
}

void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void set_texture(int no)
{
	TEX_FILE *t = &tex_file[no];

	if (t->type == 2) {
		sceGuTexMode(3, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	} else if (t->type == 3) {
		sceGuTexMode(2, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	} else if (t->type == 4) {
		sceGuTexMode(1, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	} else if (t->type == 5) {
		sceGuTexMode(0, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	} else if (t->type == 1) {
		if (t->f10 == 2) {
			sceGuClutMode(3, 0, 0xFF, 0);
			sceGuClutLoad(32, t->p18);
		} else {
			sceGuClutMode(1, 0, 0xFF, 0);
			sceGuClutLoad(16, t->p18);
		}
		sceGuTexMode(5, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	} else if (t->type == 0) {
		if (t->f10 == 2) {
			sceGuClutMode(3, 0, 0xFF, 0);
			sceGuClutLoad(2, t->p18);
		} else {
			sceGuClutMode(1, 0, 0xFF, 0);
			sceGuClutLoad(1, t->p18);
		}
		sceGuTexMode(4, 0, 0, t->f14);
		sceGuTexImage(0, t->f4, t->f8, t->f4, t->p1c);
	}
}

typedef struct __attribute__((packed)) { unsigned short u, v; unsigned short c; short x, y, z; } SCRV_T;
typedef struct {
	int used, f4, tex, nearest, f10, mode;
	u8 alpha;
	u8 pad19[3];
	int x[4], y[4], u[4], v[4], c[4];
	int z;
	SCRV_T pkt[2][4];
} SPRITE_S;
extern int g_packet;
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void set_packet_scr(int no)
{
	SPRITE_S *s = (SPRITE_S *)&sprite[no];
	SCRV_T *v;
	int i;

	s->used = 0;
	if (s->tex == -1)
		sceGuDisable(9);
	else
		sceGuEnable(9);
	if (s->mode == 0) {
		sceGuDisable(4);
	} else if (s->mode == 1) {
		sceGuBlendFunc(0, 2, 3, 0, 0);
		sceGuEnable(4);
	} else if (s->mode == 2) {
		sceGuBlendFunc(0, 10, 10, (s->alpha << 24) | (s->alpha << 16) | (s->alpha << 8) | s->alpha, -1);
		sceGuEnable(4);
	} else if (s->mode == 3) {
		sceGuBlendFunc(4, 0, 0, 0, 0);
		sceGuEnable(4);
	} else if (s->mode == 4) {
		sceGuBlendFunc(2, 10, 10, (s->alpha << 24) | (s->alpha << 16) | (s->alpha << 8) | s->alpha, -1);
		sceGuEnable(4);
	}
	sceGuAlphaFunc(7, 0, 0xFF);
	sceGuEnable(0);
	if (s->nearest == 0)
		sceGuTexFilter(1, 1);
	else
		sceGuTexFilter(0, 0);
	v = s->pkt[0];
	if (g_packet)
		v = s->pkt[1];
	for (i = 0; i < 4; i++) {
		v[i].u = s->u[i];
		v[i].v = s->v[i];
		v[i].c = s->c[i];
		v[i].x = s->x[i];
		v[i].y = s->y[i];
		v[i].z = s->z;
	}
	sceKernelDcacheWritebackInvalidateRange(v, 0x30);
	sceGumDrawArray(4, 0x80011A, 4, 0, v);
	sceGuEnable(9);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_packet_3d);

typedef struct { unsigned short u, v, x, y, z; } SBV_T;
typedef struct { int on, z, mode, x, y, w, h, u, v, sx, sy, f2c, r, g, b, a; SBV_T vtx[2]; } SBLUR2_T;
extern SBLUR2_T screen_blur;
extern int dbp;
void sceGuColor(unsigned int color);
int sprite_screencopy_disp(void)
{
	SBLUR2_T *sb = &screen_blur;
	u8 *vram;

	if (sb->on == 0)
		return 0;
	if (sb->a <= 0)
		return 0;
	vram = (u8 *)sceGeEdramGetAddr();
	vram += dbp;
	sceGuEnable(9);
	sceGuTexFunc(0, 1);
	sceGuTexMapMode(0, 0, 0);
	sceGuTexWrap(0, 0);
	sceGuTexFilter(1, 1);
	sceGuTexMode(0, 0, 0, 0);
	sceGuTexImage(0, 512, 512, 512, vram);
	sceGuColor(((u8)sb->a << 24) | ((u8)sb->b << 16) | ((u8)sb->g << 8) | (u8)sb->r);
	if (sb->mode == 2)
		sceGuBlendFunc(0, 10, 10, ((u8)sb->a << 24) | ((u8)sb->a << 16) | ((u8)sb->a << 8) | (u8)sb->a, -1);
	else if (sb->mode == 3)
		sceGuBlendFunc(4, 0, 0, 0, 0);
	else if (sb->mode == 4)
		sceGuBlendFunc(2, 10, 10, ((u8)sb->a << 24) | ((u8)sb->a << 16) | ((u8)sb->a << 8) | (u8)sb->a, -1);
	else
		sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuAlphaFunc(7, 0, 0xFF);
	sceGuEnable(0);
	sb->vtx[0].u = sb->u;
	sb->vtx[0].v = sb->v;
	sb->vtx[0].x = sb->x;
	sb->vtx[0].y = sb->y;
	sb->vtx[0].z = sb->z;
	sb->vtx[1].u = sb->u + sb->w;
	sb->vtx[1].v = sb->v + sb->h;
	sb->vtx[1].x = sb->x + sb->w * sb->sx / 100;
	sb->vtx[1].y = sb->y + sb->h * sb->sy / 100;
	sb->vtx[1].z = sb->z;
	sceKernelDcacheWritebackInvalidateRange(sb->vtx, 0x14);
	sceGumDrawArray(6, 0x800102, 2, 0, sb->vtx);
	return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sprite_screencopy_pri_set(int arg0) {
    D_0035AE84 = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sprite_screencopy_pri_get(void) {
    return D_0035AE84;
}

extern int bill_pri_co[], spr_pri_co[];
extern int sprite_disp_max;
typedef struct { int used; u8 pad[0x64 - 4]; int pri; u8 rest[0x168 - 0x68]; } BILL_S;
typedef struct { int used; u8 pad[0x6C - 4]; int pri; u8 rest[0xD0 - 0x70]; } SPR_S;
static inline void bill_sort(int n)
{
	int i, j, k, p;

	if (n <= 0)
		return;
	for (i = 1; i < n; i++) {
		k = bill_co[i];
		p = bill_pri_co[i];
		for (j = i - 1; j >= 0 && bill_pri_co[j] >= p; j--) {
			bill_co[j + 1] = bill_co[j];
			bill_pri_co[j + 1] = bill_pri_co[j];
		}
		bill_co[j + 1] = k;
		bill_pri_co[j + 1] = p;
	}
}
static inline void spr_sort(int n)
{
	int i, j, k, p;

	if (n <= 0)
		return;
	for (i = 1; i < n; i++) {
		k = spr_co[i];
		p = spr_pri_co[i];
		for (j = i - 1; j >= 0 && spr_pri_co[j] >= p; j--) {
			spr_co[j + 1] = spr_co[j];
			spr_pri_co[j + 1] = spr_pri_co[j];
		}
		spr_co[j + 1] = k;
		spr_pri_co[j + 1] = p;
	}
}
void sprite_syncsort(void)
{
	int i, j, n, k, p;
	BILL_S *b;
	SPR_S *s;

	sprite_disp_max = 0;
	billbord_disp_max = 0;
	n = 0;
	for (i = 0; i < 512; i++) {
		b = &((BILL_S *)billbord)[i];
		if (n >= billbord_max)
			break;
		if (b->used == 1) {
			bill_co[n] = i;
			bill_pri_co[n] = b->pri;
			n++;
		}
	}
	bill_sort(n);
	n = 0;
	for (i = 0; i < 345; i++) {
		s = &((SPR_S *)sprite)[i];
		if (n >= sprite_max)
			break;
		if (s->used == 1) {
			spr_co[n] = i;
			spr_pri_co[n] = s->pri;
			n++;
		}
	}
	spr_sort(n);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", D_0007A91C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", D_0007A94C);
