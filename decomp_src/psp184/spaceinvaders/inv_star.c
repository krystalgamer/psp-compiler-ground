/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int inv_bg;


typedef struct { int disp, f4, no, fc, f10, f14, f18, f1c, f20; } INV_BG;
typedef struct __attribute__((packed)) { float f[10]; } P_BG;
extern P_BG p_bg;
void inv_star_init(void)
{
	INV_BG *b = (INV_BG *)&inv_bg;

	b->f4 = 0;
	b->disp = 0;
	b->fc = 0;
	b->f10 = 0;
	b->f14 = 0;
	b->f18 = 0;
	b->f1c = 0;
	b->f20 = 0;
	p_bg.f[0] = 0;
	b->no = -1;
	p_bg.f[1] = 0;
	p_bg.f[5] = 1.0f;
	p_bg.f[6] = 1.0f;
	p_bg.f[2] = -1.0f;
	p_bg.f[3] = -1.0f;
	p_bg.f[4] = 0;
	p_bg.f[7] = 1.0f;
	p_bg.f[8] = 1.0f;
	p_bg.f[9] = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_set);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_star_dispset(int arg0) {
    inv_bg = arg0;
}

typedef struct { float x, y, z; } SCV;
typedef struct { int mode; float fovy; SCV pos; SCV rot; SCV hist[8]; } SCAM;
extern SCAM camera_s __asm__("camera");
extern u8 p_buf[];
extern u8 p_2A3DC4[];
extern int inv_bg_disp_time;
unsigned int sceKernelGetSystemTimeLow(void);
void sceGuDisable(int);
void sceGuEnable(int);
void sceGuColor(unsigned int);
void set_texture(int);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumTranslate(const void *v);
void sceGumScale(const void *v);
void sceGumRotateX(float);
void sceGumRotateY(float);
void sceGumRotateZ(float);
int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void inv_star_disp(void)
{
	unsigned int t;
	int i;
	SCV *h;

	inv_bg_disp_time = 0;
	if (((INV_BG *)&inv_bg)->disp == 0)
		return;
	t = sceKernelGetSystemTimeLow();
	sceGuDisable(10);
	sceGuDisable(1);
	sceGuDisable(0);
	sceGuDisable(9);
	sceGuDisable(7);
	sceGuColor(0xFFFFFFFF);
	if (((INV_BG *)&inv_bg)->f4 == 1) {
		for (i = 7; i >= 0; i--) {
			if (camera_s.hist[i].z == camera_s.rot.z && camera_s.hist[i].y == camera_s.rot.y && camera_s.hist[i].x == camera_s.rot.x)
				continue;
			sceGumPushMatrix();
			sceGumRotateZ(-(camera_s.hist[i].z - camera_s.rot.z) * 3.1415927f / 180.0f);
			sceGumRotateX(-(camera_s.hist[i].x - camera_s.rot.x) * 3.1415927f / 180.0f);
			sceGumRotateY(-(camera_s.hist[i].y - camera_s.rot.y) * 3.1415927f / 180.0f);
			sceGumDrawArray(0, 0x19C, 4000, 0, &p_buf[i * 0xFA00]);
			sceGumPopMatrix();
		}
	}
	sceGumPushMatrix();
	sceKernelDcacheWritebackInvalidateRange(p_2A3DC4, 0xFA00);
	sceGumDrawArray(0, 0x19C, 4000, 0, p_2A3DC4);
	sceGumPopMatrix();
	if (((INV_BG *)&inv_bg)->no != -1) {
		set_texture(((INV_BG *)&inv_bg)->no);
		sceGumPushMatrix();
		sceGuEnable(9);
		sceGumTranslate(&((INV_BG *)&inv_bg)->fc);
		sceGumRotateZ(-camera_s.rot.z * 3.1415927f / 180.0f);
		sceGumRotateX(-camera_s.rot.x * 3.1415927f / 180.0f);
		sceGumRotateY(-camera_s.rot.y * 3.1415927f / 180.0f);
		sceGumScale(&((INV_BG *)&inv_bg)->f18);
		sceGuColor(0xFFFFFFFF);
		sceKernelDcacheWritebackInvalidateRange(&p_bg, 0x28);
		sceGumDrawArray(6, 0x183, 2, 0, &p_bg);
		sceGumPopMatrix();
	}
	sceGuEnable(0);
	sceGuEnable(1);
	sceGuEnable(10);
	sceGuEnable(7);
	inv_bg_disp_time = sceKernelGetSystemTimeLow() - t;
}
