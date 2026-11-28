/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char gmo;
extern unsigned char gmo_file;
extern int gmo_file_max;
extern int gmo_max;
typedef struct { int used; void *model; } GMO_FILE;
typedef struct { float x, y, z; } GVEC3;
typedef struct {
	int used, f4, file, fc;
	s8 b10, b11, b12, b13;
	int f14, f18, f1c;
	GVEC3 pos, rot, scale;
	int anime, motion, f4c;
	float speed;
	void *model;
	int effect[4];
} GMO_W;
#define GMO ((GMO_W *)&gmo)
#define GMO_FILE_W ((GMO_FILE *)&gmo_file)
int sceGmoModelDelete(void *model);
int sceGmoModelSetCurrentMotion(void *model, int motion, float speed);


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int gmo_file_unload(int no);
int gmo_unload(int no);

void gmo_init(void) {
    memset(&gmo_file, 0, 0x190U);
    memset(&gmo, 0, 0x6798U);
    gmo_file_max = 0;
    gmo_max = 0;
}

void *LoadFile(char *name, int *size);
void psp_free(void *p);
int gmo_addr_load(void *buf);
int gmo_file_load(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = gmo_addr_load(buf);
	psp_free(buf);
	return ret;
}

void *sceGmoModelCreate(int a0);
int sceGmoModelLoadFile(void *model, void *buf, int a2, int a3);
int gmo_addr_load(void *buf)
{
	int i, r;
	GMO_FILE *f = GMO_FILE_W;

	for (i = 0; i < 50; i++, f++) {
		if (f->used == 1)
			continue;
		f->used = 1;
		f->model = sceGmoModelCreate(0);
		r = sceGmoModelLoadFile(f->model, buf, 0, 0);
		gmo_file_max++;
		if (r != 1) {
			gmo_file_unload(i);
			return -1;
		}
		return i;
	}
	return -1;
}

int gmo_file_unload(int no)
{
	int ret;

	ret = 0;
	if ((unsigned int)no < 50 && GMO_FILE_W[no].used != 0) {
		sceGmoModelDelete(GMO_FILE_W[no].model);
		ret = 1;
		gmo_file_max--;
		GMO_FILE_W[no].used = 0;
		GMO_FILE_W[no].model = 0;
	}
	return ret;
}

int gmo_file_unload(int no);
int gmo_unload(int no);
void gmo_file_all_unload(void)
{
	int i;

	for (i = 0; i < 50; i++)
		gmo_file_unload(i);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", D_0007A8A4);

/* gmo_load: equivalent C, 1 insn short: the original keeps the -1 for
   fc/motion in a2 (the Duplicate arg) instead of a separate register. */
#ifdef NON_MATCHING
void *sceGmoModelDuplicate(void *model, int a1, int a2);
int gmo_load(int no)
{
	GMO_FILE *f;
	int i;

	if ((unsigned int)no >= 50)
		return -1;
	f = &GMO_FILE_W[no];
	if (f->used == 0)
		return -1;
	for (i = 0; i < 255; i++) {
		if (GMO[i].used == 1)
			continue;
		{
			GVEC3 one = {1.0f, 1.0f, 1.0f};
			GMO[i].scale = one;
		}
		GMO[i].speed = 1.0f;
		GMO[i].pos.x = 0;
		GMO[i].pos.y = 0;
		GMO[i].pos.z = 0;
		GMO[i].rot.x = 0;
		GMO[i].rot.y = 0;
		GMO[i].rot.z = 0;
		GMO[i].file = no;
		GMO[i].motion = -1;
		GMO[i].f14 = 1;
		GMO[i].used = 1;
		GMO[i].fc = -1;
		GMO[i].b11 = 1;
		GMO[i].b10 = 1;
		GMO[i].b12 = 1;
		GMO[i].b13 = 1;
		GMO[i].f18 = 255;
		GMO[i].f4 = 0;
		GMO[i].anime = 0;
		GMO[i].f4c = 0;
		GMO[i].f1c = 0;
		GMO[i].model = sceGmoModelDuplicate(f->model, 2, -1);
		sceGmoModelSetCurrentMotion(GMO[i].model, -1, 0);
		gmo_max++;
		return i;
	}
	return -1;
}
#else
INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_load);
#endif

int gmo_unload(int no)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			sceGmoModelDelete(g->model);
			ret = 1;
			g->used = 0;
			g->model = 0;
			gmo_max--;
		}
	}
	return ret;
}

void gmo_all_unload(void)
{
	int i;

	for (i = 0; i < 255; i++)
		gmo_unload(i);
}

int gmo_anime_start(int no, int motion, float speed, float f2)
{
	GMO_W *g;

	if ((unsigned int)no >= 255)
		return 0;
	g = &GMO[no];
	if (g->used == 0)
		return 0;
	g->anime = 1;
	g->motion = motion;
	g->speed = speed / 60.0f;
	sceGmoModelSetCurrentMotion(g->model, motion, f2);
	return 1;
}

int gmo_anime_direct(int no, int motion, float speed)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			g->anime = 2;
			g->motion = motion;
			g->speed = speed;
			sceGmoModelSetCurrentMotion(g->model, motion, 0);
			ret = 1;
		}
	}
	return ret;
}

int gmo_anime_stop(int no)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			g->speed = 0;
			g->motion = -1;
			g->anime = 0;
			sceGmoModelSetCurrentMotion(g->model, -1, g->speed);
			ret = 1;
		}
	}
	return ret;
}

int gmo_effect(int no, int eff)
{
	GMO_W *g;
	int i;

	if ((unsigned int)no >= 255)
		return 0;
	g = &GMO[no];
	if (g->used == 0)
		return 0;
	for (i = 0; i < 4; i++) {
		if (g->effect[i] == -1) {
			g->effect[i] = eff;
			return 1;
		}
	}
	return 0;
}

extern int gmo_disp_max, gmo_disp_time;
unsigned int sceKernelGetSystemTimeLow(void);
int inv_laser_priget(void);
int inv_ring_priget(void);
void inv_laser_disp(void);
void inv_ring_disp(void);
void set_texture(int tex);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumTranslate(const void *v);
void sceGumScale(const void *v);
void sceGumRotateX(float a);
void sceGumRotateY(float a);
void sceGumRotateZ(float a);
void sceGumStoreMatrix(void *m);
int sceGmoModelSetEnableMask(void *model, int mask, int v);
int sceGmoModelSetEnableBits(void *model, int mask, int v);
void sceGmoModelSetWorldMatrix(void *model, void *m);
void sceGmoModelAnimate(void *model, float t);
int sceGmoModelUpdate(void *model);
int sceGmoModelDraw(void *model);
void gmo_disp(void)
{
	GMO_W *g;
	unsigned int t;
	int i, n, tex, laser, ring;
	float m[16];

	gmo_disp_max = 0;
	gmo_disp_time = 0;
	if (gmo_max == 0)
		return;
	n = 0;
	t = sceKernelGetSystemTimeLow();
	tex = -1;
	laser = 0;
	ring = 0;
	for (i = 0; i < 255; i++) {
		if (laser == 0 && i >= inv_laser_priget()) {
			inv_laser_disp();
			laser = 1;
			tex = -1;
		}
		if (ring == 0 && i >= inv_ring_priget()) {
			inv_ring_disp();
			ring = 1;
			tex = -1;
		}
		if (n >= gmo_max)
			break;
		g = &GMO[i];
		if (g->used == 0)
			continue;
		n++;
		if (g->f4 == 0)
			continue;
		if (tex != g->fc) {
			tex = g->fc;
			if (tex >= 0) {
				set_texture(tex);
				sceGuEnable(9);
			}
		}
		if (g->f14 == 0) {
			sceGuDisable(4);
		} else if (g->f14 == 1) {
			sceGuBlendFunc(0, 2, 3, 0, 0);
			sceGuEnable(4);
		} else if (g->f14 == 2) {
			sceGuBlendFunc(0, 10, 10, -1, -1);
			sceGuEnable(4);
		} else if (g->f14 == 3) {
			sceGuBlendFunc(4, 0, 0, 0, 0);
			sceGuEnable(4);
		} else if (g->f14 == 4) {
			sceGuBlendFunc(2, 10, 10, -1, -1);
			sceGuEnable(4);
		}
		sceGumPushMatrix();
		sceGumTranslate(&g->pos);
		if (g->f1c == 0) {
			sceGumRotateY(g->rot.y * 3.1415927f / 180.0f);
			sceGumRotateX(g->rot.x * 3.1415927f / 180.0f);
			sceGumRotateZ(g->rot.z * 3.1415927f / 180.0f);
		} else if (g->f1c == 1) {
			sceGumRotateX(g->rot.x * 3.1415927f / 180.0f);
			sceGumRotateY(g->rot.y * 3.1415927f / 180.0f);
			sceGumRotateZ(g->rot.z * 3.1415927f / 180.0f);
		}
		sceGumScale(&g->scale);
		sceGumStoreMatrix(m);
		if (g->b12 == 0) {
			sceGmoModelSetEnableMask(g->model, 4, -1);
			sceGmoModelSetEnableBits(g->model, 4, 0);
		} else {
			sceGmoModelSetEnableMask(g->model, 4, 0);
			sceGmoModelSetEnableBits(g->model, 4, 1);
		}
		if (g->b10 == 0) {
			sceGmoModelSetEnableMask(g->model, 2, -1);
			sceGmoModelSetEnableBits(g->model, 2, 0);
		}
		if (g->b11 == 1) {
			sceGmoModelSetEnableMask(g->model, 8, 0);
			sceGmoModelSetEnableBits(g->model, 8, 1);
		} else {
			sceGmoModelSetEnableMask(g->model, 8, -1);
			sceGmoModelSetEnableBits(g->model, 8, 0);
		}
		if (g->b13 == 1) {
			sceGmoModelSetEnableMask(g->model, 1, 0);
			sceGmoModelSetEnableBits(g->model, 1, 1);
		} else {
			sceGmoModelSetEnableMask(g->model, 1, -1);
			sceGmoModelSetEnableBits(g->model, 1, 0);
		}
		if (g->f14 == 2) {
			sceGmoModelSetEnableMask(g->model, 0x40, -1);
			sceGmoModelSetEnableBits(g->model, 0x40, 0);
			sceGmoModelSetEnableMask(g->model, 0x80, -1);
			sceGmoModelSetEnableBits(g->model, 0x80, 0);
		} else {
			sceGmoModelSetEnableMask(g->model, 0x40, 0);
			sceGmoModelSetEnableBits(g->model, 0x40, 1);
			sceGmoModelSetEnableMask(g->model, 0x80, 0);
			sceGmoModelSetEnableBits(g->model, 0x80, 1);
		}
		sceGmoModelSetWorldMatrix(g->model, m);
		if (g->anime) {
			sceGmoModelAnimate(g->model, g->speed);
			if (g->anime == 2) {
				g->anime = 0;
				g->speed = 0;
			}
		}
		sceGmoModelUpdate(g->model);
		sceGmoModelDraw(g->model);
		sceGumPopMatrix();
		gmo_disp_max++;
	}
	if (laser == 0)
		inv_laser_disp();
	if (ring == 0)
		inv_ring_disp();
	gmo_disp_time = sceKernelGetSystemTimeLow() - t;
}
