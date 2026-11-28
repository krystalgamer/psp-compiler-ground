/* cflags: -O3 */
#include "common.h"
/* SDK libgu font.c (6.6.0 source minus the init flag and debug-font callback; this revision keeps
   gu_debug_vramtop as an integer and gu_debug_wbp as a pointer), -O4 like libgu */
#define FONTCNT_MAX 1024
#define SCEGU_PF5650 0
#define SCEGU_PF5551 1
#define SCEGU_PF4444 2
#define SCEGU_PF8888 3

void *sceGeEdramGetAddr(void);
typedef union { unsigned int ui; void *p; } ScePspUnion32_;
static __inline__ unsigned int sceKernelMakeUncachedAddrUIntPtr(const void *v)
{
	return (__builtin_allegrex_ins(0x40000000U, (unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakeUncachedAddr(const void *_p)
{
	ScePspUnion32_ u;
	u.ui = sceKernelMakeUncachedAddrUIntPtr(_p);
	return u.p;
}

void _sceGuDebugFontInit(void);
void _sceGuDebugSwapBuffer(void);
void _sceGuDebugDispBuffer(int fpf, int width, int height);
void _sceGuDebugDrawBuffer(int fpf, void *fbp, int fbw);

typedef struct SceGuDebugFont {
	int x, y;
	unsigned int col;
	char c;
	unsigned char pad[3];
} SceGuDebugFont;

extern const unsigned int fonttex[];
extern SceGuDebugFont gu_fontbuf[2][FONTCNT_MAX];
extern int gu_fontcnt[2];
extern int gu_debug_frame;
extern unsigned int gu_debug_vramtop;
extern int   gu_debug_fpf;
extern unsigned char *gu_debug_wbp;
extern int   gu_debug_fbw;
extern int   gu_debug_sw;
extern int   gu_debug_sh;

void _sceGuDebugFontInit(void)
{
	gu_debug_vramtop = (unsigned int)sceGeEdramGetAddr();
	gu_debug_frame = 0;
}

void _sceGuDebugSwapBuffer(void)
{
	gu_debug_frame = !gu_debug_frame;
}

void _sceGuDebugDispBuffer(int fpf, int width, int height)
{
	gu_debug_fpf = fpf;
	gu_debug_sw = width;
	gu_debug_sh = height;
}

void _sceGuDebugDrawBuffer(int fpf, void *fbp, int fbw)
{
	gu_debug_wbp = (unsigned char *)fbp;
	gu_debug_fbw = fbw;
}

void sceGuDebugPrint(int x, int y, unsigned int col, const char *str)
{
	int				r, g, b, a;
	int				fx, fy;
	int				code;
	int				fontcnt;
	SceGuDebugFont	*fontbuf;

	fontbuf = gu_fontbuf[gu_debug_frame];
	fontcnt = gu_fontcnt[gu_debug_frame];
	if (fontcnt >= FONTCNT_MAX) {
		return;
	}
	fontbuf = &fontbuf[ fontcnt ];

	fx = x;
	fy = y;

	r = (col >>  0) & 0xff;
	g = (col >>  8) & 0xff;
	b = (col >> 16) & 0xff;
	a = (col >> 24) & 0xff;

	if (gu_debug_fpf == SCEGU_PF5650) {
		r = r >> 3;
		g = g >> 2;
		b = b >> 3;
		col = (b << 11) | (g << 5) | r;
	} else if (gu_debug_fpf == SCEGU_PF5551) {
		r = r >> 3;
		g = g >> 3;
		b = b >> 3;
		a = a >> 7;
		col = (a << 15) | (b << 10) | (g << 5) | r;
	} else if (gu_debug_fpf == SCEGU_PF4444) {
		r = r >> 4;
		g = g >> 4;
		b = b >> 4;
		a = a >> 4;
		col = (a << 12) | (b << 8) | (g << 4) | r;
	}

	while (*str) {
		if (*str == '\n') {
			fx = x;
			fy += 8;
			str++;
			continue;
		}
		code = *str - '!' + 1;

		fontbuf->x = fx;
		fontbuf->y = fy;
		fontbuf->col = col;
		fontbuf->c = code++;

		fx += 8;

		str++;
		fontcnt++;
		if (fontcnt >= FONTCNT_MAX) {
			break;
		}
		fontbuf++;
	}
	gu_fontcnt[gu_debug_frame] = fontcnt;
	return;
}

void sceGuDebugFlush(void)
{
	unsigned short	*fp;
	unsigned int	data;
	unsigned int	mask;
	int				code;
	int				u, v;
	int				col;
	int				fx, fy;
	int				fontcnt;
	SceGuDebugFont	*fontbuf;

	fontbuf = gu_fontbuf[gu_debug_frame];
	fontcnt = gu_fontcnt[gu_debug_frame];
	if (fontcnt == 0) {
		return;
	}

	data = 0;
	mask = 0;
	while (fontcnt) {
		fx = fontbuf->x;
		fy = fontbuf->y;
		if (((fy + 7) < gu_debug_sh) && ((fx + 7) < gu_debug_sw) && (fy >= 0) && (fx >= 0)) {
			code = fontbuf->c;
			col = fontbuf->col;
			for(v = 0; v < 8; v++) {
				if (v == 0) {
					data = fonttex[code * 2];
					mask = 1;
				} else if (v == 4) {
					data = fonttex[code * 2 + 1];
					mask = 1;
				}

				for(u = 0; u < 8; u++) {
					if (gu_debug_fpf == SCEGU_PF8888) {
						fp = (unsigned short *)sceKernelMakeUncachedAddr(gu_debug_vramtop + gu_debug_wbp + ((fy + v) * gu_debug_fbw + (fx + u)) * 4);
						if (data & mask) {
							fp[0] = col&0xffff;
							fp[1] = (col >> 16) & 0xffff;
						}
					} else {
						fp = (unsigned short *)sceKernelMakeUncachedAddr(gu_debug_vramtop + gu_debug_wbp + ((fy + v) * gu_debug_fbw + (fx + u)) * 2);
						if (data & mask) {
							*fp = (unsigned short)col;
						}
					}
					mask = mask << 1;
				}
			}
		}
		fontbuf++;
		fontcnt--;
	}
	gu_fontcnt[gu_debug_frame] = 0;
	return;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/font", fonttex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/font", __psp_libinfo___10BF8C);
