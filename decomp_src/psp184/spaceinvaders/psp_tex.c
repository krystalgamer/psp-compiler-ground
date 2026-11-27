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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_copy_addrset);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d_efc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d_efc_rot);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_scr_disp);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_packet_scr);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_packet_3d);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_screencopy_disp);

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
