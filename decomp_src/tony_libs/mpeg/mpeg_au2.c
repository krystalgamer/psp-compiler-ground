/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"
/* --- end declarations --- */

int func_00005518(SceMpeg *mp, MpegStream *stream)
{
	MpegSys *sys = mp->sys;
	AuList2 *e;
	SceMpegAuInfo info;
	int n;
	int ret;
	int i;
	int cnt;
	unsigned char *x;
	int v;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	if (stream->pair == (StreamEntry *)-1)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	func_00005AE0(sys->sema);
	e = func_00001208(stream->id, mp->sys, 1);
	if (e == (AuList2 *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	func_000013AC((AuList2 *)stream->pair, 0, 1, &info, &n);
	if (n != 1) {
		ret = 0x80618004;
		x = (unsigned char *)0xFFFF0000;
	} else {
		x = (unsigned char *)info.unk[7];
	}
	cnt = e->num;
	for (i = 0; i < cnt; i++) {
		func_000013AC(e, 0, 1, &info, &n);
		if (x != (unsigned char *)0xFFFF0000 && func_000048BC(sys->rb, x, (unsigned char *)info.unk[7]) == 1)
			break;
		func_00001474(e, 1, &n);
	}
	stream->unk10 = 0x7FFF;
	stream->unk2C = 0;
	func_00005B7C(sys->sema);
	return ret;
}

int func_00005694(SceMpeg *mp, MpegStream *stream, int idx, int *out)
{
	MpegSys *sys = mp->sys;
	AuList2 *e;
	SceMpegAuInfo info;
	int n;
	int ret;
	unsigned char *dst;
	unsigned char *p;
	int cnt;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005AE0(sys->sema);
	e = func_00001208(stream->id, mp->sys, 1);
	if (e == (AuList2 *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	if (stream->pair == (StreamEntry *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	if (idx != 0) {
		func_000013AC((AuList2 *)stream->pair, idx, 1, &info, &n);
	} else if (stream->unk10 == 0x7FFF) {
		func_000013AC((AuList2 *)stream->pair, 0, 1, &info, &n);
	} else {
		out[0] = stream->unk10;
		dst = (unsigned char *)(out + 2);
		out[1] = stream->unk2C;
		__builtin_memcpy(dst, stream->unkC, 0x800);
		goto done;
	}
	if (n != 1) {
		func_00005B7C(sys->sema);
		return 0x80618004;
	}
	if ((unsigned int)info.unk[8] > 0x800) {
		func_00005B7C(sys->sema);
		return 0x80618007;
	}
	dst = (unsigned char *)(out + 2);
	memcpy(dst, (void *)info.unk[7], info.unk[8]);
	out[0] = 0;
	out[1] = 0;
done:
	if (sys->unkC == 0) {
		cnt = func_00005478(func_000054E8(dst));
		p = func_00005480(func_000054E8(dst), cnt - 1);
		func_0000542C(p, 0);
	}
	func_00005B7C(sys->sema);
	return ret;
}

int sceMpegChangeGetAvcAuMode(SceMpeg *mp, MpegStream *stream, int mode)
{
	MpegSys *sys = mp->sys;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005AE0(sys->sema);
	if (func_00001208(stream->id, mp->sys, 1) == (void *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	if (stream->pair == (StreamEntry *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	switch (mode) {
	case 0:
		stream->unk30 &= ~2;
		break;
	case 2:
		stream->unk30 |= 2;
		break;
	default:
		ret = SCE_MPEG_ERROR_INVALID_VALUE;
		break;
	}
	func_00005B7C(sys->sema);
	return ret;
}

int sceMpegChangeGetAuMode(SceMpeg *mp, MpegStream *stream, int mode)
{
	MpegSys *sys = mp->sys;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005AE0(sys->sema);
	if (func_00001208(stream->id, mp->sys, 1) == (void *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	switch (mode) {
	case 0:
		stream->unk30 &= ~1;
		break;
	case 1:
		stream->unk30 |= 1;
		break;
	default:
		ret = SCE_MPEG_ERROR_INVALID_VALUE;
		break;
	}
	func_00005B7C(sys->sema);
	return ret;
}
