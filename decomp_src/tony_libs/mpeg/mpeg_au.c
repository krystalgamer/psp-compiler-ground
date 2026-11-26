/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", sceMpegGetPcmAu);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", func_000041EC);

unsigned char *func_000044E0(unsigned char *p, int type)
{
	unsigned char *ret;

	switch (type) {
	case 1:
		ret = p + 0xE;
		break;
	case 2:
		if (p[0xD] & 2)
			ret = p + 0x12;
		else
			ret = NULL;
		break;
	case 0x1F40:
		ret = func_000044E0(p, 2);
		if (ret == NULL)
			ret = func_000044E0(p, 1);
		ret += 6;
		break;
	case 3:
		if (p[0xD] & 1)
			ret = func_000044E0(p, 0x1F40);
		else
			ret = NULL;
		break;
	case 4:
		ret = func_000044E0(p, 0x1F40);
		if (p[0xD] & 1)
			ret += 0x40;
		break;
	case 5:
		if (p[0xD] & 2) {
			ret = func_000044E0(p, 0x1F40);
			ret -= 2;
			ret = p + func_0000752C(ret);
		} else {
			ret = NULL;
		}
		break;
	default:
		ret = NULL;
		break;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", sceMpegGetAtracAu);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", func_000048BC);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", sceMpegGetAvcAu);

int func_00004CF0(AuNode *node, int addr, int unk4, AuNode *next, int size)
{
	node->addr = addr;
	node->unk4 = unk4;
	node->next = next;
	if ((unsigned int)size >= 0x1000) {
		node->size = 0;
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	node->size = size;
	return 0;
}

int func_00004D24(AuNode *node, AuNode *next)
{
	node->next = next;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", func_00004D30);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", func_00005148);

unsigned char *sceMpegMallocAvcEsBuf(SceMpeg *mp)
{
	MpegSys *sys = mp->sys;
	int h = 0;
	int i;

	if (func_00001100(mp) != 0)
		return NULL;
	func_00005AE0(sys->sema);
	for (i = 0; i < sys->unk67C; i++) {
		if (sys->flag[i] == 0) {
			sys->flag[i] = 1;
			h = i + 1;
			break;
		}
	}
	func_00005B7C(sys->sema);
	return (unsigned char *)h;
}

int sceMpegFreeAvcEsBuf(SceMpeg *mp, int h)
{
	MpegSys *sys = mp->sys;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005AE0(sys->sema);
	if (h > 0 && h <= sys->unk67C)
		sys->flag[h - 1] = 0;
	else
		ret = SCE_MPEG_ERROR_INVALID_VALUE;
	func_00005B7C(sys->sema);
	return ret;
}

int func_000052A8(SceMpeg *mp, int h)
{
	MpegSys *sys = mp->sys;

	if (h > 0 && h <= sys->unk67C && sys->flag[h - 1] == 1)
		return sys->val[h - 1];
	return h;
}

int sceMpegQueryAtracEsSize(SceMpeg *mp, int *esSize, int *outSize)
{
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	*esSize = 0x840;
	*outSize = 0x2000;
	return 0;
}

int sceMpegQueryPcmEsSize(SceMpeg *mp, int *esSize, int *outSize)
{
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	*esSize = 0x140;
	*outSize = 0x140;
	return 0;
}

int func_00005380(SceMpeg *mp, int *a, int *b)
{
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	*a = 0x19100;
	*b = 0x2A300;
	return 0;
}

int func_000053D8(unsigned char *p)
{
	return (func_0000752C(p + 2) & 0x3FF) * 8 + 8;
}

int func_00005400(unsigned char *p)
{
	return p[0] & 0xF;
}

unsigned int func_0000540C(unsigned char *p)
{
	return func_00007544(p + 1) >> 23;
}

void func_0000542C(unsigned char *p, int flag)
{
	if (!flag)
		p[1] &= 0x7F;
	else
		p[1] |= 0x80;
}

unsigned int func_00005450(unsigned char *p)
{
	return func_00007544(p + 1) & 0x1FFFFF;
}

int func_00005478(unsigned char *p)
{
	return p[3];
}

unsigned char *func_00005480(unsigned char *p, unsigned int i)
{
	unsigned char *r = NULL;

	if (i < p[3])
		r = p + 4 + i * 4;
	return r;
}

int func_000054A4(unsigned char *p)
{
	return p[1];
}

int func_000054AC(unsigned char *p, int i)
{
	if (i < 4)
		return func_0000752C(p + 2 + i * 2);
	return 0;
}

unsigned char *func_000054E8(unsigned char *p)
{
	return p + 0xE;
}

AuList *func_000054F0(SceMpeg *mp)
{
	MpegSys *sys = mp->sys;

	return &sys->lists[sys->curList];
}

int func_00005510(void)
{
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", D_000079CC);

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_au", D_00007A4C);
