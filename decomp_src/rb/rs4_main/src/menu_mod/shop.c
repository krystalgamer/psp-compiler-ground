/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern const float D_00104710;
void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmSetLoop(int, int);
void bxAnmSetPause(int, int);

void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmExec(int);

int cardlistGetSaveID(int);

void *memset(void *, int, unsigned int);
int _TtrFontPutSet_3F420();

typedef struct { unsigned char b[4]; } CardWork4;

typedef struct { unsigned char kind; char pad; unsigned short id; } SortCard;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", Sub_Shop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopAniSet);

void _AniInfoSet_3CB84(int anm)
{
	bxAnmSetFrame(anm, 0.0f);
	bxAnmSetSpeed(anm, D_00104710);
	bxAnmSetLoop(anm, 1);
	bxAnmSetPause(anm, 0);
}

void _AniFrameSet(int anm, int frame)
{
	bxAnmSetFrame(anm, (float)frame);
	bxAnmSetSpeed(anm, 0.0f);
	bxAnmExec(anm);
}

int _ShopCursorInitSet(void *shop, SortCard *list, int card)
{
	int i;
	int id;
	int ret = 0;
	if (card == 0) {
		return 0;
	}
	id = cardlistGetSaveID(card);
	for (i = 0; i < M2C_FIELD(shop, int *, 0x10); i++) {
		if (list[i].id == id) {
			ret = i;
			break;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopCursorSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopNowCardSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopSaruCardCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopSaruCardCheck2);

typedef struct { unsigned char kind; unsigned char pad; unsigned short id; } ShopCard;
int _ShopDeckCheck(char *w, ShopCard *c)
{
	int r = -1;
	int i, n;
	if (c != NULL) {
		n = *(int *)(w + 0x7FF4);
		for (i = 0; i < n; i++) {
			ShopCard *e = (ShopCard *)(i * 4 + (int)w + 0x5BE0);
			if (e[1].id == c->id && e[1].kind == c->kind)
				r = i;
		}
	}
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeckCheckSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeck2SaveSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopDeck2OmakaseSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _ShopPutSet);

void _CardListPutDel(int unused, char *p)
{
	char buf[0x18];
	memset(buf, 0, 0x18);
	_TtrFontPutSet_3F420(p + 0xC3, buf, 0, 0);
	_TtrFontPutSet_3F420(p + 0xCB, buf, 0, 0);
	_TtrFontPutSet_3F420(p + 0xD3, buf, 0, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardListPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _CardNowPutSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _DeckNowPutSet);

int _BarPutSet(void *arg0) {
    int temp_lo;

    if (M2C_FIELD(arg0, int *, 0x1C) != 0) {
        temp_lo = 0x3B8 / (int) (M2C_FIELD(arg0, int *, 0x10) - 1);
        M2C_FIELD(arg0, int *, 0x20) = temp_lo;
        if (temp_lo >= 0x88) {
            M2C_FIELD(arg0, int *, 0x20) = 0x88;
        }
        _AniFrameSet(M2C_FIELD(((M2C_FIELD(arg0, signed char *, 0x32) * 4) + arg0), int *, 0x8030), M2C_FIELD(arg0, int *, 0x20));
        _BarPutPosSet(arg0);
    }
    return 0;
}

int _BarPutPosSet(void *arg0) {
    if (M2C_FIELD(arg0, int *, 0x1C) != 0) {
        M2C_FIELD(arg0, int *, 0x24) = (int) ((int) ((0x88 - M2C_FIELD(arg0, int *, 0x20)) * M2C_FIELD(arg0, int *, 0x14)) / (int) (M2C_FIELD(arg0, int *, 0x10) - 7));
    }
    return 0;
}

int _WinPutSet(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSet2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSetWork);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _WinPutSetWorkCardPack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _TtrFontPutSet_3F420);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _Salbum2CardListSet);

void _SwapCardWorkSet(CardWork4 *a, CardWork4 *b)
{
	CardWork4 t;
	t = *a;
	*a = *b;
	*b = t;
}

void _SwapIntWorkSet(int *arg0, int *arg1) {
    int temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SortCardListSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _SortCardListSetInit);

int _SortCardListGet(SortCard *t, int n, SortCard *k)
{
	int r = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (t[i].id == k->id && t[i].kind == k->kind) {
			r = i;
			break;
		}
	}
	return r;
}

int _CardListDel(SortCard *t, int n, SortCard *k)
{
	int i = _SortCardListGet(t, n, k);
	n--;
	for (; i < n; i++) {
		t[i].id = t[i + 1].id;
		t[i].kind = t[i + 1].kind;
	}
	return n;
}

int Sub_ShopUnLock(void *arg0) {
    int var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, int *, 0x40) == 5) {
        M2C_FIELD(arg0, int *, 0x40) = 0;
        var_a1 = 1;
    }
    return var_a1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _FontNumSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", Sub_Shop_WindowPut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/shop", _GetCardPackID);

int _DeckCheck(int saveid, int kind)
{
	int sd = saveGetCurrentData();
	int r;
	int i, j;
	saveid = cardlistGetCardIDFromSaveID(saveid);
	r = saveid == *(unsigned short *)(sd + 0x228);
	for (i = 0; i < 5; i++)
		for (j = 0; j < 20; j++) {
			ShopCard *e = (ShopCard *)((i * 0x34 + j) * 4 + sd + 0x2D0);
			if (saveid == e[1].id && kind == e[1].kind)
				return 1;
		}
	return r;
}
