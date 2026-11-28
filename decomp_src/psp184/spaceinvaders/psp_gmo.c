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
	u8 b10, b11, b12, b13;
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_disp);
