/* cflags: -Os -fno-strength-reduce */
#include "common.h"

typedef struct { unsigned char kind; unsigned char sub; unsigned short no; } CardId;
typedef struct { CardId id; int ref; } Card2Ref;
extern Card2Ref l_atCard2RefImg[364];
int cardanmGetCard2Ref(CardId *c)
{
	Card2Ref *e;
	int ret = -1;
	for (e = &l_atCard2RefImg[363]; e >= l_atCard2RefImg; e--) {
		if (c->no == e->id.no && c->kind == e->id.kind) {
			ret = e->ref;
			break;
		}
	}
	return ret;
}

void cardanmGetRef2Card(CardId *out, int ref)
{
	Card2Ref *e;
	for (e = &l_atCard2RefImg[363]; e >= l_atCard2RefImg; e--) {
		if (e->ref == ref) {
			*out = e->id;
			return;
		}
	}
	{
		CardId none = { 0xFF, 0, 0xFFFF };
		*out = none;
	}
}


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", cardanmTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101D1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101D3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101D5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101D78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101D88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardanm", D_00101DC0);
