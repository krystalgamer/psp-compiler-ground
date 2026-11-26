/* SDK 2.5.0 libgu debug font (font.o), built -O3 by 1.8.4.internal: the SDK 6.6.0
   src/gu/font.c without the libgu callback registration (2.5.0's libgu calls these
   functions directly) and the gu_debug_initialized check, gu_debug_vramtop an unsigned int
   and gu_debug_wbp a pointer; fonttex of the 2.5.0 font.h.
   Sony compiled it with -std=iso9899:1999, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O3 */
#include "font_sdk.h"

static const unsigned int fonttex[] =
{
	0x00000000, 0x00000000, 0x10101010, 0x00100000,
	0x00282828, 0x00000000, 0x287C2828, 0x0028287C,
	0x38147810, 0x00103C50, 0x10204C0C, 0x00606408,
	0x08141408, 0x00582454, 0x00102040, 0x00000000,
	0x10102040, 0x00402010, 0x10100804, 0x00040810,
	0x10385410, 0x00105438, 0x7C101000, 0x00001010,
	0x00000000, 0x08101000, 0x7C000000, 0x00000000,
	0x00000000, 0x00181800, 0x10204000, 0x00000408,
	0x54644438, 0x0038444C, 0x10141810, 0x007C1010,
	0x20404438, 0x007C0418, 0x30404438, 0x00384440,
	0x24283020, 0x0020207C, 0x403C047C, 0x00384440,
	0x3C040830, 0x00384444, 0x1020447C, 0x00101010,
	0x38444438, 0x00384444, 0x78444438, 0x00182040,
	0x00100000, 0x00001000, 0x00100000, 0x08101000,
	0x0C183060, 0x00603018, 0x007C0000, 0x0000007C,
	0x6030180C, 0x000C1830, 0x20404438, 0x00100010,
	0x54744438, 0x00380474, 0x44442810, 0x0044447C,
	0x3C48483C, 0x003C4848, 0x04044830, 0x00304804,
	0x4848281C, 0x001C2848, 0x3C04047C, 0x007C0404,
	0x3C04047C, 0x00040404, 0x74044438, 0x00384444,
	0x7C444444, 0x00444444, 0x10101038, 0x00381010,
	0x20202070, 0x00182420, 0x0C142444, 0x00442414,
	0x04040404, 0x007C0404, 0x54546C44, 0x00444444,
	0x544C4C44, 0x00446464, 0x44444438, 0x00384444,
	0x3C44443C, 0x00040404, 0x44444438, 0x00582454,
	0x3C44443C, 0x00442414, 0x38044438, 0x00384440,
	0x1010107C, 0x00101010, 0x44444444, 0x00384444,
	0x44444444, 0x00102828, 0x54444444, 0x00446C54,
	0x10284444, 0x00444428, 0x38444444, 0x00101010,
	0x1020407C, 0x007C0408, 0x10101070, 0x00701010,
	0x10080400, 0x00004020, 0x1010101C, 0x001C1010,
	0x00442810, 0x00000000, 0x00000000, 0x007C0000,
	0x00000000, 0x00000000, 0x40380000, 0x00784478,
	0x4C340404, 0x00344C44, 0x44380000, 0x00384404,
	0x64584040, 0x00586444, 0x44380000, 0x0038047C,
	0x7C105020, 0x00101010, 0x64580000, 0x38405864,
	0x4C340404, 0x00444444, 0x10180010, 0x00381010,
	0x10180010, 0x0C121010, 0x14240404, 0x0024140C,
	0x10101018, 0x00381010, 0x542C0000, 0x00545454,
	0x4C340000, 0x00444444, 0x44380000, 0x00384444,
	0x4C340000, 0x0404344C, 0x64580000, 0x40405864,
	0x4C340000, 0x00040404, 0x04780000, 0x003C403C,
	0x083C0808, 0x00304808, 0x24240000, 0x00582424,
	0x44440000, 0x00102844, 0x54440000, 0x00285454,
	0x28440000, 0x00442810, 0x44440000, 0x38405864,
	0x207C0000, 0x007C0810, 0x04080830, 0x00300808,
	0x10101010, 0x00101010, 0x2010100C, 0x000C1010,
	0x0000007C, 0x00000000, 0x00000000, 0x00000000,
};

#define FONTCNT_MAX		1024					// max font count


void _sceGuDebugFontInit(void);
void _sceGuDebugSwapBuffer(void);
void _sceGuDebugDispBuffer(int fpf, int width, int height);
void _sceGuDebugDrawBuffer(int fpf, void *fbp, int fbw);

extern void _sceGuSetDebugFontCallback(
				void (*psceGuDebugFlush)(void),
				void (*p_sceGuDebugSwapBuffer)(void),
				void (*p_sceGuDebugDispBuffer)(int fpf, int width, int height),
				void (*p_sceGuDebugDrawBuffer)(int fpf, void *fbp, int fbw));

//J デバック表示
typedef struct SceGuDebugFont {
	int x, y;
	unsigned int col;
	char c;
	unsigned char pad[3];
} SceGuDebugFont;


extern SceGuDebugFont gu_fontbuf[2][FONTCNT_MAX];
extern int gu_fontcnt[2];
extern int gu_debug_frame;


extern unsigned int gu_debug_vramtop;

extern int   gu_debug_fpf;
extern unsigned char *gu_debug_wbp;
extern int   gu_debug_fbw;
extern int   gu_debug_sw;
extern int   gu_debug_sh;



/*J デバッグ表示の初期化 */
/*E Initialize debug display  */
void _sceGuDebugFontInit(void)
{
	gu_debug_vramtop = (unsigned int)sceGeEdramGetAddr();
	gu_debug_frame = 0;
	return;
}


/*J デバッグフォント用バッファの交代 */
/*E Alternate debug font buffers  */
void _sceGuDebugSwapBuffer(void)
{
	gu_debug_frame = !gu_debug_frame;
	return;
}


/*J 表示フレームバッファのサイズを設定 */
/*E Set display frame buffer size  */
void _sceGuDebugDispBuffer(int fpf, int width, int height)
{
	gu_debug_fpf = fpf;
	gu_debug_sw = width;
	gu_debug_sh = height;
	return;
}


/*J 描画フレームバッファのサイズを設定 */
/*E Set drawing frame buffer size  */
void _sceGuDebugDrawBuffer(int fpf, void *fbp, int fbw)
{
	(void)fpf;
	gu_debug_wbp = (unsigned char *)fbp;
	gu_debug_fbw = fbw;
	return;
}


/*J デバッグ用の表示 */
/*E Draw debug string */
void sceGuDebugPrint(int x, int y, unsigned int col, const char *str)
{
	int				r, g, b, a;
	int				fx, fy;
	int				code;
	int				fontcnt;
	SceGuDebugFont	*fontbuf;

	fontbuf = gu_fontbuf[gu_debug_frame];
	fontcnt = gu_fontcnt[gu_debug_frame];
	{if (fontcnt >= FONTCNT_MAX) {{
		return;
	}}}
	fontbuf = &fontbuf[ fontcnt ];

	fx = x;
	fy = y;

	r = (col >>  0) & 0xff;
	g = (col >>  8) & 0xff;
	b = (col >> 16) & 0xff;
	a = (col >> 24) & 0xff;

	{if (gu_debug_fpf == SCEGU_PF5650) {{
		r = r >> 3;
		g = g >> 2;
		b = b >> 3;
		col = (b << 11) | (g << 5) | r;
	}} else {{if (gu_debug_fpf == SCEGU_PF5551) {{
		r = r >> 3;
		g = g >> 3;
		b = b >> 3;
		a = a >> 7;
		col = (a << 15) | (b << 10) | (g << 5) | r;
	}} else {{if (gu_debug_fpf == SCEGU_PF4444) {{
		r = r >> 4;
		g = g >> 4;
		b = b >> 4;
		a = a >> 4;
		col = (a << 12) | (b << 8) | (g << 4) | r;
	}}}}}}}

	{while (*str) {{
		{if (*str == '\n') {{
			fx = x;
			fy += 8;
			str++;
			continue;
		}}}
		code = *str - '!' + 1;

		fontbuf->x = fx;
		fontbuf->y = fy;
		fontbuf->col = col;
		fontbuf->c = code++;

		fx += 8;

		str++;
		fontcnt++;
		{if (fontcnt >= FONTCNT_MAX) {{
			break;
		}}}
		fontbuf++;
	}}}
	gu_fontcnt[gu_debug_frame] = fontcnt;
	return;
}


/*J デバッグ表示のフラッシュ */
/*E Flush debug string */
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
	{if (fontcnt == 0) {{
		return;
	}}}

	data = 0;
	mask = 0;
	{while (fontcnt) {{
		fx = fontbuf->x;
		fy = fontbuf->y;
		{if (((fy + 7) < gu_debug_sh) && ((fx + 7) < gu_debug_sw) && (fy >= 0) && (fx >= 0)) {{
			code = fontbuf->c;
			col = fontbuf->col;
			{for(v = 0; v < 8; v++) {{
				{if (v == 0) {{
					data = fonttex[code * 2];
					mask = 1;
				}} else {{if (v == 4) {{
					data = fonttex[code * 2 + 1];
					mask = 1;
				}}}}}

				{for(u = 0; u < 8; u++) {{
					{if (gu_debug_fpf == SCEGU_PF8888) {{
						fp = (unsigned short *)sceKernelMakeUncachedAddr(gu_debug_vramtop + gu_debug_wbp + ((fy + v) * gu_debug_fbw + (fx + u)) * 4);
						{if (data & mask) {{
							fp[0] = col&0xffff;
							fp[1] = (col >> 16) & 0xffff;
						}}}
					}} else {{
						fp = (unsigned short *)sceKernelMakeUncachedAddr(gu_debug_vramtop + gu_debug_wbp + ((fy + v) * gu_debug_fbw + (fx + u)) * 2);
						{if (data & mask) {{
							*fp = (unsigned short)col;
						}}}
					}}}
					mask = mask << 1;
				}}}
			}}}
		}}}
		fontbuf++;
		fontcnt--;
	}}}
	gu_fontcnt[gu_debug_frame] = 0;
	return;
}


