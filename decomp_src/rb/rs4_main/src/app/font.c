/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceFontClose(int);                              /* extern */
int sceFontDoneLib(int);                            /* extern */
extern unsigned char D_000FC438;
extern int FontID;
extern int LibID;

#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FC3F8;
extern unsigned char D_000FC41C;
extern unsigned char D_000FC4EC;
extern int pFontDat;
extern int pMarkFontDat;
extern int pMarkTextDat;
extern unsigned char D_000FC524;
M2C_UNK _memFree(int *, M2C_UNK *, M2C_UNK);        /* extern */
extern unsigned char D_000FC544;
extern unsigned char D_000FC62C;

void *_memAlloc();

int copAddVec();

extern int D_00119780;
extern const float D_000FC670;

int fontImgPut();

int fontStrPut();
extern const float D_000FC668;
extern const float D_000FC66C;
extern int MarkFontID;
typedef struct { int w[12]; int advance; int pad[3]; } FontCharInfo;
int sceFontGetCharInfo(int, unsigned int, FontCharInfo *);
int fontIsMarkFont(int c);
void *_memAllocZero(int, void *, int);
extern const float D_000FC674;
typedef struct { int pixelFormat; int xPos64; int yPos64; } FontGlyphHead;
typedef struct { float x, y, z, w; } FontVec;
typedef struct FontCache { struct FontCache *next; int code; int pad[2]; char buf[0x200]; } FontCache;
typedef struct FontChar { struct FontChar *next; FontCache *cache; int pad[2]; FontVec pos; char pad2[0x50 - 0x20]; } FontChar;
typedef struct { int busy; int pad1[3]; FontVec pos; char pad2[0x54 - 0x20]; FontGlyphHead img; char pad3[0x68 - 0x60]; void *buf; FontCache *cacheHead, *cacheTail; FontChar *charHead, *charTail; } FontStr;
extern const float D_000FC678;
int sceFontGetCharGlyphImage(int, unsigned int, void *);

int _fontAlloc(int a, int size)
{
	int r = -1;
	if (size)
		r = (int)_memAlloc(size, &D_000FC3F8, 0x41);
	return r;
}

void _fontFree(int heap, int *p) {
    if (p != (int *)-1) {
        _memFree(p, &D_000FC3F8, 0x4C);
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC3F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC41C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC450);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC470);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC480);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC494);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC498);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "fontTerm";
    consPrintf("%s\n", temp_v0);
    if (sceFontClose(FontID) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xC9, temp_v0, &D_000FC438);
    }
    FontID = 0;
    if (sceFontDoneLib(LibID) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xCE, temp_v0, &D_000FC438);
    }
    LibID = 0x8046FFFF;
    return 0;
}

int fontSetPgfResource(int arg0) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xDA, "fontSetPgfResource", &D_000FC4EC);
    }
    pFontDat = arg0;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC4EC);

int fontSetPgfResourceExtra(int arg0, int arg1) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE4, "fontSetPgfResourceExtra", &D_000FC4EC);
    }
    if (arg1 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE5, "fontSetPgfResourceExtra", "pTextDat");
    }
    pMarkFontDat = arg0;
    pMarkTextDat = arg1;
    return 1;
}

int fontGetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xF4, "fontGetPos", &D_000FC524);
    }
    M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x10);
    M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x14);
    M2C_FIELD(arg1, int *, 8) = (int) M2C_FIELD(arg0, int *, 0x18);
    M2C_FIELD(arg1, int *, 0xC) = (int) M2C_FIELD(arg0, int *, 0x1C);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC524);

int fontSetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x102, "fontSetPos", &D_000FC524);
    }
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(arg1, int *, 0);
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(arg1, int *, 4);
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(arg1, int *, 8);
    M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(arg1, int *, 0xC);
    return 1;
}

int fontOfsPos(int *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x110, "fontOfsPos", &D_000FC524);
    }
    if (*arg0 != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x111, "fontOfsPos", &D_000FC544);
    }
    copAddVec((char *)arg0 + 0x10, arg1, (char *)arg0 + 0x10);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC544);

int fontIsMarkFont(int c)
{
	int r, i, n;
	short *t;
	r = 0;
	t = *(short **)pMarkTextDat;
	n = (unsigned int)((int *)pMarkTextDat)[1] >> 1;
	for (i = 1; i < n; i++) {
		if (t[i] == c)
			r = 1;
	}
	if (r)
		consPrintf("%s : Found Mark Code = %x\n", "fontIsMarkFont", c);
	return r;
}

float fontGetCharWidth(void *f, int c)
{
	FontCharInfo info;
	int id;
	if (f == NULL)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x12E, "fontGetCharWidth", &D_000FC524);
	if (c != '\n') {
	if (fontIsMarkFont(c)) id = MarkFontID;
	else id = FontID;
	if (sceFontGetCharInfo(id, (unsigned short)c, &info) != 0)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x134, "fontGetCharWidth", &D_000FC438);
	return (float)info.advance * D_000FC668;
	}
	return D_000FC66C;
}

float fontGetCharHeight(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x145, "fontGetCharHeight", &D_000FC524);
    }
    return (float)((D_00119780 + 0x3F) & ~0x3F) * D_000FC670;
}

float fontGetStrWidth(void *f, int *s, int n)
{
	float max = 0.0f;
	float w = 0.0f;
	float cw;
	int c;
	for (; n && (c = *s) != 0; n--, s++) {
		cw = fontGetCharWidth(f, c);
		if (cw >= 0.0f) {
			w += cw;
			max = max < w ? w : max;
		} else {
			w = 0.0f;
		}
	}
	return max;
}

float fontGetStrHeight(void *f, int *s, int n)
{
	float ch = fontGetCharHeight(f);
	float h = 0.0f;
	int line = 0;
	int c;
	while (n && (c = *s) != 0) {
		n--;
		if (c == '\n') {
			h += ch;
			line = 0;
		} else
			line = 1;
		s++;
	}
	h += line == 1 ? ch : 0.0f;
	return h;
}

void fontImgInit(int a)
{
	fontImgInitEx(a, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontImgInitEx);

int fontImgTerm(int *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E2, "fontImgTerm", &D_000FC524);
    }
    if (*arg0 != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E3, "fontImgTerm", &D_000FC544);
    }
    _memFree(arg0, &D_000FC3F8, 0x1E5);
    return 1;
}

int fontImgPut(FontStr *p, int c)
{
	FontCharInfo info;
	int h;
	if (p == NULL)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x1F1, "fontImgPut", &D_000FC524);
	if (p->busy != 0)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x1F2, "fontImgPut", &D_000FC544);
	h = D_00119780;
	h += 0x3F;
	h &= ~0x3F;
	if (c != '\n') {
		if (sceFontGetCharInfo(fontIsMarkFont(c) ? MarkFontID : FontID, (unsigned short)c, &info) != 0)
			consPrintf(&D_000FC41C, &D_000FC3F8, 0x1FC, "fontImgPut", &D_000FC438);
		p->img.xPos64 = ((int)p->pos.x + info.w[2]) << 6;
		p->img.yPos64 = (((int)p->pos.y - info.w[3]) << 6) + h;
		if (sceFontGetCharGlyphImage(fontIsMarkFont(c) ? MarkFontID : FontID, (unsigned short)c, &p->img) != 0)
			consPrintf(&D_000FC41C, &D_000FC3F8, 0x202, "fontImgPut", &D_000FC438);
		p->pos.x += (float)info.advance * D_000FC674;
	} else {
		p->pos.x = 0;
		p->pos.y += (float)h * D_000FC674;
	}
	return 1;
}

int fontImgStr(int f, int *str, int n) {
    int c;
    while (n != 0 && (c = *str) != 0) {
        fontImgPut(f, c);
        n--;
        str++;
    }
    return 1;
}

int fontImgDat(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x224, "fontImgDat", &D_000FC524);
    }
    if (M2C_FIELD(arg0, int *, 0) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x225, "fontImgDat", &D_000FC544);
    }
    return M2C_FIELD(arg0, int *, 0x50);
}

void *fontStrInit(void)
{
	short *p = _memAllocZero(0x80, &D_000FC3F8, 0x231);
	if (p == NULL)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x232, "fontStrInit", &D_000FC524);
	*(int *)p = 1;
	*(int *)(p + 0x2A) = 0;
	p[0x33] = 0;
	*(int *)(p + 0x34) = 0;
	*(int *)(p + 8) = 0;
	*(int *)(p + 10) = 0;
	p[0x30] = 32;
	p[0x31] = 32;
	p[0x32] = 16;
	return p;
}

int fontStrTerm(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *temp_s0_2;
    M2C_UNK *var_a0;
    M2C_UNK *var_a0_2;

    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24D, "fontStrTerm", &D_000FC524);
    }
    if (M2C_FIELD(arg0, M2C_UNK **, 0) != (M2C_UNK *)1) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24E, "fontStrTerm", &D_000FC62C);
    }
    var_a0 = M2C_FIELD(arg0, M2C_UNK **, 0x6C);
    if (var_a0 != NULL) {
        do {
            temp_s0 = *var_a0;
            _memFree(var_a0, &D_000FC3F8, 0x254);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
    var_a0_2 = M2C_FIELD(arg0, M2C_UNK **, 0x74);
    if (var_a0_2 != NULL) {
        do {
            temp_s0_2 = *var_a0_2;
            _memFree(var_a0_2, &D_000FC3F8, 0x25D);
            var_a0_2 = temp_s0_2;
        } while (temp_s0_2 != NULL);
    }
    _memFree(arg0, &D_000FC3F8, 0x262);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC62C);

int fontStrPut(FontStr *p, int c)
{
	FontCharInfo info;
	FontCache *cache;
	FontChar *ch;
	int h;
	if (p == NULL)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x26E, "fontStrPut", &D_000FC524);
	if (p->busy != 1)
		consPrintf(&D_000FC41C, &D_000FC3F8, 0x26F, "fontStrPut", &D_000FC62C);
	h = D_00119780;
	h += 0x3F;
	h &= ~0x3F;
	if (c != '\n') {
		for (cache = p->cacheHead; cache != NULL; cache = cache->next)
			if (cache->code == c) break;
		if (cache != NULL) {
			if (sceFontGetCharInfo(FontID, (unsigned short)cache->code, &info) != 0)
				consPrintf(&D_000FC41C, &D_000FC3F8, 0x282, "fontStrPut", &D_000FC438);
		} else {
			cache = _memAllocZero(0x210, &D_000FC3F8, 0x285);
			if (cache == NULL)
				consPrintf(&D_000FC41C, &D_000FC3F8, 0x286, "fontStrPut", "pCache");
			if (p->cacheHead == NULL) p->cacheHead = cache;
			if (p->cacheTail != NULL) p->cacheTail->next = cache;
			p->cacheTail = cache;
			cache->next = NULL;
			cache->code = c;
			if (sceFontGetCharInfo(FontID, (unsigned short)c, &info) != 0)
				consPrintf(&D_000FC41C, &D_000FC3F8, 0x293, "fontStrPut", &D_000FC438);
			p->img.xPos64 = info.w[2] << 6;
			p->img.yPos64 = h - (info.w[3] << 6);
			p->buf = cache->buf;
			if (sceFontGetCharGlyphImage(FontID, (unsigned short)c, &p->img) != 0)
				consPrintf(&D_000FC41C, &D_000FC3F8, 0x29A, "fontStrPut", &D_000FC438);
		}
		ch = _memAllocZero(0x50, &D_000FC3F8, 0x29F);
		if (ch == NULL)
			consPrintf(&D_000FC41C, &D_000FC3F8, 0x2A0, "fontStrPut", "pChar");
		if (p->charHead == NULL) p->charHead = ch;
		if (p->charTail != NULL) p->charTail->next = ch;
		p->charTail = ch;
		ch->next = NULL;
		ch->cache = cache;
		ch->pos = p->pos;
		p->pos.x += (float)info.advance * D_000FC678;
	} else {
		p->pos.x = 0;
		p->pos.y += (float)h * D_000FC678;
	}
	return 1;
}

int fontStrStr(int f, int *str, int n) {
    int c;
    while (n != 0 && (c = *str) != 0) {
        fontStrPut(f, c);
        n--;
        str++;
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC668);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC66C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC670);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", D_000FC678);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/font", fontStrDraw);
