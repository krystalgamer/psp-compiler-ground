/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "game.h"

typedef struct {
	unsigned short u, v;
	short x, y, z;
} SPRVTX;

typedef struct SPRITE {
	int type;
	int no;
	float z;
	float f[14];
	int flag;
	int color;
	void *next;
	SPRVTX v[4];
} SPRITE;

typedef struct {
	int u, v, w, h, no, flag;
} SPRDATA;

void *sceGimPictureCreate(int);
int sceGimPictureLoadFile(void *, void *, int, int);
void *sceGimPictureDuplicate(void *, int);
int sceGimPictureDelete(void *);
int sceGimPictureUnload(void *);
void free(void *);
int printf(const char *, ...);
int SpriteDraw(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);
int SpriteDrawZoom(int no, int color, float z, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10);
int SpriteDraw3D(int no, int color, int flag, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13);
int SpriteDrawEz(int no, float z, int color, float x, float y, float w, float h, float u, float v);
int draw_DrawSprite(SPRITE *sp);
int draw_DrawSpriteEx(SPRITE *sp);
int draw_DrawSpritePt4(SPRITE *sp);
void *malloc(unsigned int);
char *strncpy(char *, const char *, unsigned int);
int sceGimPictureActivate(void *);
int sceKernelDcacheWritebackAll(void);
void sceGuColor(unsigned int);
void sceGuDrawArray(int, int, int, const void *, const void *);

extern void *Gims[128];
extern unsigned char isSkip;
extern int global_color;
extern float global_fader;
extern int sprite_number;
extern int SkipFrameCount;
extern int D_000D6498;
extern SPRITE sprite_buf[4096];
extern SPRITE *spr_buf_now[16];
extern SPRITE *spr_buf_begin[16];

void init_gims(void)
{
	int i;

	for (i = 0; i < 128; i++)
		Gims[i] = 0;
}

void release_gims(int no)
{
	void **p = &Gims[no];

	if (*p != 0) {
		sceGimPictureUnload(*p);
		sceGimPictureDelete(*p);
		*p = 0;
	}
}

int load_gims(int no, const char *name)
{
	void *buf;
	int size;
	void *pic;

	if (no >= 128)
		return -1;
	release_gims(no);
	if (!load_file(name, &buf, &size))
		return -2;
	pic = sceGimPictureCreate(0);
	sceGimPictureLoadFile(pic, buf, size, 0);
	Gims[no] = sceGimPictureDuplicate(pic, 2);
	free(buf);
	return no;
}

int set_gim(int no, void *buf, int size)
{
	void *pic;

	if (no >= 128)
		return -1;
	release_gims(no);
	pic = sceGimPictureCreate(0);
	sceGimPictureLoadFile(pic, buf, size, 0);
	Gims[no] = sceGimPictureDuplicate(pic, 2);
	return no;
}

int LoadGimFile(int no, int file)
{
	char *addr;
	int size;
	char *buf;
	void *pic;

	if (no >= 128)
		return -1;
	release_gims(no);
	GetPakInfo(file, &addr, &size);
	pic = sceGimPictureCreate(0);
	if (sceGimPictureLoadFile(pic, addr, size, 0) == 0) {
		buf = malloc(size);
		if (buf == 0)
			return -1;
		strncpy(buf, addr, size);
		if (sceGimPictureLoadFile(pic, addr, size, 0) == 0)
			return -1;
		free(buf);
	}
	Gims[no] = sceGimPictureDuplicate(pic, 0);
	return no;
}

void SpriteAllFreeImage(void)
{
	int i;

	for (i = 0; i < 128; i++)
		release_gims(i);
}

int get_gims(int no)
{
	return (int)Gims[no];
}

void SpriteSetSkipFrame(unsigned char skip)
{
	isSkip = skip;
}

SPRITE *GetSpriteBuf(int pri)
{
	SPRITE *sp;

	if (spr_buf_begin[pri] == 0) {
		sp = &sprite_buf[sprite_number++];
		spr_buf_begin[pri] = sp;
		spr_buf_now[pri] = sp;
	} else {
		sp = &sprite_buf[sprite_number++];
		spr_buf_now[pri]->next = sp;
		spr_buf_now[pri] = sp;
	}
	return sp;
}

void SpriteInit(void) {
}

void SpriteKick(void) {
}

void SpriteInitExt(void)
{
	int i;

	global_color = -1;
	sprite_number = 0;
	for (i = 0; i < 4096; i++) {
		sprite_buf[i].type = 0;
		sprite_buf[i].next = 0;
	}
	for (i = 0; i < 16; i++) {
		spr_buf_now[i] = 0;
		spr_buf_begin[i] = 0;
	}
}

void SpriteKickExt(void)
{
	int i;
	SPRITE *sp;

	if (D_000D6498 < sprite_number) {
		D_000D6498 = sprite_number;
		printf("SPRITE MAX: %d\n", sprite_number);
	}
	if (isSkip) {
		isSkip = 0;
		SkipFrameCount++;
		if (SkipFrameCount < 3)
			return;
	} else {
		SkipFrameCount = 0;
	}
	for (i = 15; i >= 0; i--) {
		for (sp = spr_buf_begin[i]; sp != 0; sp = sp->next) {
			switch (sp->type) {
			case 1:
				draw_DrawSprite(sp);
				break;
			case 2:
				draw_DrawSpriteEx(sp);
				break;
			case 3:
				draw_DrawSpritePt4(sp);
				break;
			}
		}
	}
}

void SpriteSetColor(int arg0) {
    global_color = arg0;
}

void SpriteSetColorRGBA(int arg0, int arg1, int arg2, int arg3) {
    global_color = (arg0 & 0xFF) | ((arg1 & 0xFF) << 8) | ((arg2 & 0xFF) << 0x10) | (arg3 << 0x18);
}

int SpriteGetColor(void) {
    return global_color;
}

float SpriteGetFader(void) {
    return global_fader;
}

void SpriteSetFader(float fparg0) {
    global_fader = fparg0;
}

int getFader(int color)
{
	int i, c;
	int ret = color & 0xff000000;

	for (i = 0; i < 3; i++) {
		c = (color >> (i * 8)) & 0xff;
		c = c * global_fader;
		ret |= (c & 0xff) << (i * 8);
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", D_0002DC10);

int SpriteDraw(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3)
{
	SPRITE *sp = GetSpriteBuf((int)z);

	sp->type = 3;
	sp->no = no;
	sp->z = z;
	if (color == -1)
		sp->color = global_color;
	else
		sp->color = color;
	sp->v[0].x = x0;
	sp->v[0].y = y0;
	sp->v[0].z = 0;
	sp->v[0].u = u0;
	sp->v[0].v = v0;
	sp->v[1].x = x1;
	sp->v[1].y = y1;
	sp->v[1].z = 0;
	sp->v[1].u = u1;
	sp->v[1].v = v1;
	sp->v[2].x = x2;
	sp->v[2].y = y2;
	sp->v[2].z = 0;
	sp->v[2].u = u2;
	sp->v[2].v = v2;
	sp->v[3].x = x3;
	sp->v[3].y = y3;
	sp->v[3].z = 0;
	sp->v[3].u = u3;
	sp->v[3].v = v3;
	return 1;
}

int SpriteDrawEz(int no, float z, int color, float x, float y, float w, float h, float u, float v)
{
	return SpriteDraw(no, color, z, x, y, u, v, x + w, y, u + w, v, x, y + h, u, v + h, x + w, y + h, u + w, v + h);
}

#ifdef NON_MATCHING
/* diff 5 with every cc1: only no/color swap (the original keeps color in s8 and spills
 * no).  Like DrawSprite's f0/f1, an equal-priority tie between two parameters goes to
 * the later parameter in the original and to the earlier one in our compilers. */
double cos(double);
double sin(double);
int SpriteDrawZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot)
{
	float vx[4], vy[4], dx[4], dy[4];
	float px, py;
	int i;

	if (rot == 0.0f) {
		float qx = x + cx;
		float qy = y + cy;

		vx[0] = vx[2] = qx - cx * sx;
		vy[0] = vy[1] = qy - cy * sy;
		vx[1] = vx[3] = qx + (w - cx) * sx;
		vy[2] = vy[3] = qy + (h - cy) * sy;
	} else {
		px = x + cx;
		py = y + cy;
		dx[0] = dx[2] = (px - cx * sx) - px;
		dy[0] = dy[1] = (py - cy * sy) - py;
		dx[1] = dx[3] = (px + (w - cx) * sx) - px;
		dy[2] = dy[3] = (py + (h - cy) * sy) - py;
		for (i = 0; i < 4; i++) {
			vx[i] = cos(rot) * dx[i] + sin(rot) * dy[i];
			vy[i] = -sin(rot) * dx[i] + cos(rot) * dy[i];
			vy[i] += py;
			vx[i] += px;
		}
	}
	SpriteDraw(no, color, z, vx[0], vy[0], u, v, vx[1], vy[1], u + w, v, vx[2], vy[2], u, v + h, vx[3], vy[3], u + w, v + h);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDrawZoom);
#endif

#ifdef NON_MATCHING
/* Close: right register allocation, but f[0]/f[1] stores come out swapped. */
int SpriteDraw3D(int no, int color, int flag, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13)
{
	SPRITE *sp = GetSpriteBuf((int)z);

	sp->type = 2;
	sp->no = no;
	sp->z = z;
	if (color == -1) sp->color = global_color; else sp->color = color;
	sp->f[0] = f0;
	sp->f[2] = f2;
	sp->f[3] = f3;
	sp->f[4] = f4;
	sp->f[5] = f5;
	sp->f[6] = f6;
	sp->flag = flag;
	sp->f[7] = f7;
	sp->f[8] = f8;
	sp->f[9] = f9;
	sp->f[10] = f10;
	sp->f[11] = f11;
	sp->f[12] = f12;
	sp->f[13] = f13;
	sp->f[1] = f1;
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", SpriteDraw3D);
#endif

int SpriteDrawC(float z, int x, int y, SPRDATA *p)
{
	int w = p->w / 2;
	int h = p->h / 2;
	int u = p->u;
	int v = p->v;

	if (p->flag & 1)
		w = -w;
	else if (p->flag & 2)
		h = -h;
	return SpriteDraw(p->no, -1, z, x - w, y - h, u, v, x + w, y - h, u + p->w, v, x - w, y + h, u, v + p->h, x + w, y + h, u + p->w, v + p->h);
}

#ifdef NON_MATCHING
/* diff 4 (every store order): f0/f1 get $f27/$f26 the other way round; the
 * same tie as in SpriteDraw3D.  No callers in this module. */
int DrawSprite(int no, int flag, int n, float z, float f0, float f1, float f13, float f2, float f3, float f4, float f5, float f6, float f7)
{
	SPRITE *sp = GetSpriteBuf((int)z);

	sp->type = 1;
	sp->no = no;
	sp->z = z;
	sp->f[0] = f0;
	sp->f[1] = f1;
	sp->f[2] = f2;
	sp->f[3] = f3;
	sp->f[4] = f4;
	sp->f[5] = f5;
	sp->f[6] = f6;
	sp->f[7] = f7;
	sp->f[10] = n;
	sp->f[13] = f13;
	sp->flag = flag;
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", DrawSprite);
#endif

int DrawSpriteEz(float z, float x, float y, float w, float h, float u, float v, int no)
{
	return SpriteDrawEz(no, z, -1, x, y, w, h, u, v);
}

int DrawSpriteZoom(int no, int color, float z, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10)
{
	return SpriteDrawZoom(no, color, z, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag)
{
	return SpriteDraw3D(no, -1, flag, z, f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13);
}

int DrawSpritePt4(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3)
{
	return SpriteDraw(no, color, z, x0, y0, u0, v0, x1, y1, u1, v1, x2, y2, u2, v2, x3, y3, u3, v3);
}

int GetSpriteColor(void)
{
	return SpriteGetColor();
}

void SetSpriteColor(int arg0) {
    SpriteSetColor(arg0);
}

void SetSpriteColorRGBA(int arg0, int arg1, int arg2, int arg3) {
    SpriteSetColorRGBA(arg0, arg1, arg2, arg3);
}

int draw_DrawSpritePt4(SPRITE *sp)
{
	void *pic = Gims[sp->no];
	int ret = 0;

	if (pic != 0) {
		sceGimPictureActivate(pic);
		sceKernelDcacheWritebackAll();
		sceGuColor(getFader(sp->color));
		sceGuDrawArray(4, 0x800102, 4, 0, sp->v);
		ret = 1;
	}
	return ret;
}

int draw_DrawSprite(SPRITE *sp)
{
	void *pic = Gims[sp->no];
	int italic = sp->f[10];

	if (pic == 0)
		return 0;
	sceGimPictureActivate(pic);
	if (italic == 0) {
		sp->v[0].x = sp->f[0];
		sp->v[0].y = sp->f[1];
		sp->v[0].z = 0;
		sp->v[0].u = sp->f[4];
		sp->v[0].v = sp->f[5];
		sp->v[1].x = sp->f[0] + sp->f[2];
		sp->v[1].y = sp->f[1];
		sp->v[1].z = 0;
		sp->v[1].u = sp->f[4] + sp->f[6];
		sp->v[1].v = sp->f[5];
		sp->v[2].x = sp->f[0];
		sp->v[2].y = sp->f[1] + sp->f[3];
		sp->v[2].z = 0;
		sp->v[2].u = sp->f[4];
		sp->v[2].v = sp->f[5] + sp->f[7];
		sp->v[3].x = sp->f[0] + sp->f[2];
		sp->v[3].y = sp->f[1] + sp->f[3];
		sp->v[3].z = 0;
		sp->v[3].u = sp->f[4] + sp->f[6];
		sp->v[3].v = sp->f[5] + sp->f[7];
	} else {
		sp->v[0].x = sp->f[0];
		sp->v[0].y = sp->f[1] + 15.0f;
		sp->v[0].z = 0;
		sp->v[0].u = sp->f[4];
		sp->v[0].v = sp->f[5];
		sp->v[1].x = sp->f[0] + sp->f[2];
		sp->v[1].y = sp->f[1];
		sp->v[1].z = 0;
		sp->v[1].u = sp->f[4] + sp->f[6];
		sp->v[1].v = sp->f[5];
		sp->v[2].x = sp->f[0];
		sp->v[2].y = sp->f[1] + sp->f[3] + 15.0f;
		sp->v[2].z = 0;
		sp->v[2].u = sp->f[4];
		sp->v[2].v = sp->f[5] + sp->f[7];
		sp->v[3].x = sp->f[0] + sp->f[2];
		sp->v[3].y = sp->f[1] + sp->f[3];
		sp->v[3].z = 0;
		sp->v[3].u = sp->f[4] + sp->f[6];
		sp->v[3].v = sp->f[5] + sp->f[7];
	}
	sceGuColor(getFader(-1));
	sceGuDrawArray(4, 0x800102, 4, 0, sp->v);
	return 1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/wrap_sprite", draw_DrawSpriteEx);

int NullFunc(void) {
    return 1;
}
