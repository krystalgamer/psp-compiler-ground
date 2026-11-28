/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

static __inline__ int __strtok_find(const char *d, char c)
{
	int sc;

	while ((sc = *d++) != '\0') {
		if (sc == c)
			return sc;
	}
	return 0;
}
int __tolower_i(int c) __asm__("func_0000720C");
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

int sceMpegFlushStream(SceMpeg *mp, MpegStream *stream)
{
	MpegSys *sys = mp->sys;
	StreamEntry *e;
	StreamEntry *pair;
	int ret;
	int type;
	int ch;
	AuList2 *l;	/* stream->pair is an AU list: pointer-typed head/tail stores */
	int a, b;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005AE0(sys->sema);
	e = func_00001208(stream->id, mp->sys, 1);
	if (e == (StreamEntry *)-1) {
		func_00005B7C(sys->sema);
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	if (e->stream != (MpegStream *)-1) {
		e->unk0 = -1;
		e->unk4 = -1;
		e->unkC = 0;
		pair = stream->pair;
		if (pair != (StreamEntry *)-1) {
			l = (AuList2 *)pair;
			l->tail = (AuNode2 *)-1;
			l->head = (AuNode2 *)-1;
			l->num = 0;
		}
	}
	stream->unk10 = 0x7FFF;
	stream->unk2C = 0;
	func_000072EC(&type, &ch, stream->id);
	a = D_000078F4[type].unk0;
	b = D_000078F4[type].unk4;
	stream->unk28 = a;
	stream->unk14 = b;
	stream->unk18 = 1;
	stream->unk20 = 0;
	stream->unk34 = 0;
	stream->unk38 = 0;
	func_00005B7C(sys->sema);
	return ret;
}

int sceMpegFlushAllStream(SceMpeg *mp)
{
	MpegSys *sys = mp->sys;
	int ret;
	int i;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	for (i = 0; i < 0x70; i++) {
		if (sys->streams[i].stream != (MpegStream *)-1) {
			ret = sceMpegFlushStream(mp, sys->streams[i].stream);
			if (ret != 0)
				return ret;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegUnRegistStream);

MpegStream *sceMpegRegistStream(SceMpeg *mp, int type, int ch)
{
	MpegSys *sys = mp->sys;
	MpegStream *stream;
	int esBuf = -1;

	if (func_00001100(mp) != 0)
		return NULL;
	func_00005AE0(sys->sema);
	stream = func_00001208(func_00007258(type, ch), sys, 2);
	if (stream == (MpegStream *)-1)
		goto err;
	if (type == 0)
		esBuf = (int)sys->unk20 + (ch << 11);
	if (func_00000920(mp, type, ch, esBuf, stream) != 0)
		goto err;
	func_00005B7C(sys->sema);
	return stream;
err:
	func_00005B7C(sys->sema);
	return NULL;
}

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", D_000078F4);

int sceMpegInit(void)
{
	static const char libName[] = "SceMpegLibmpeg";
	static const char dmacName[] = "SceMpegDmacpDemuxCh";
	static const char avcName[] = "SceMpegAvc";
	static const char atracName[] = "SceMpegAtrac";

	if (func_00005A58(1, 1, libName, &D_00007D8C) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	if (func_00005A58(1, 1, avcName, &D_00007D84) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	if (func_00005A58(1, 1, atracName, &D_00007D88) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	return 0;
}

int sceMpegFinish(void)
{
	if (func_00005AB0(D_00007D8C) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	if (func_00005AB0(D_00007D84) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	if (func_00005AB0(D_00007D88) != 0)
		return SCE_MPEG_ERROR_INTERNAL;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegCreate);

int sceMpegDelete(SceMpeg *mp)
{
	MpegSys *sys = mp->sys;
	int ret;
	int i;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	func_00005FD4(sys->video);
	func_00005AE0(D_00007D8C);
	for (i = 0; i < 0x70; i++) {
		sys->streams[i].unk0 = -1;
		sys->streams[i].unk4 = -1;
		sys->streams[i].stream = (MpegStream *)-1;
		sys->streams[i].unkC = 0;
	}
	if (func_00005AB0(sys->sema) != 0) {
		func_00005B7C(D_00007D8C);
		return SCE_MPEG_ERROR_INTERNAL;
	}
	func_00005B7C(D_00007D8C);
	return ret;
}

int sceMpegInitAu(SceMpeg *mp, void *hEsBuf, SceMpegAu *au)
{
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	au->pEsBuf = hEsBuf;
	au->iEsSize = 0;
	return 0;
}

int sceMpegQueryMemSize(int mode)
{
	return 0xB3D7;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", func_00000920);

int sceMpegAvcDecodeMode(SceMpeg *mp, int *mode)
{
	VideoCtx *video = mp->sys->video;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	switch (mode[0]) {
	case -1:
		break;
	case 0:
	case 1:
	case 2:
		video->unk34 = mode[0];
		break;
	default:
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	switch (mode[1]) {
	case -1:
		break;
	case 0:
	case 1:
	case 2:
	case 3:
		sceMpegbase_0530BE4E(D_00007984[mode[1]]);
		break;
	default:
		return SCE_MPEG_ERROR_INVALID_VALUE;
	}
	return 0;
}

int sceMpegAvcDecodeDetail(SceMpeg *mp, int *detail)
{
	MpegSys *sys;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	sys = mp->sys;
	detail[0] = sys->video->unk8;
	detail[1] = sys->buf694->unk20;
	detail[2] = sys->info->unk8;
	detail[3] = sys->info->unkC;
	detail[4] = sys->info->unk10;
	detail[5] = sys->info->unk14;
	detail[6] = sys->info->unk18;
	detail[7] = sys->info->unk1C;
	detail[8] = sys->info->unk20;
	return 0;
}

int sceMpegAvcDecode(SceMpeg *mp, SceMpegAu *au, int width, void **pRGBA, int *num)
{
	MpegSys *sys;
	VideoCtx *video;
	Buf694 *buf;
	VideoInfo *info;
	int es;
	int pad;
	int ret;
	int i;
	CscAvcParam param;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	sys = mp->sys;
	video = sys->video;
	buf = sys->buf694;
	info = sys->info;
	es = func_000052A8(mp, (int)au->pEsBuf);
	if (sys->unk6A4 == 0) {
		pad = 16 - au->iEsSize % 16;
		if (pad == 16)
			pad = 0;
		func_00005ED8((unsigned char *)es, au->iEsSize + pad);
		au->iEsSize += pad;
	}
	video->unk24 = (void *)(es & 0x0FFFFFFF);
	video->unk28 = au->iEsSize;
	ret = func_00005F2C(video);
	au->iEsSize = 0;
	if (ret != 0)
		return ret;
	*num = info->unk20;
	if (sys->mode != 3) {
		for (i = 0; i < *num; i++) {
			if (pRGBA[i] == NULL)
				return SCE_MPEG_ERROR_INVALID_VALUE;
			param.width = (unsigned int)info->unkC >> 4;
			param.height = (unsigned int)info->unk8 >> 4;
			param.unk8 = 0;
			param.unkC = 0;
			param.buf[0] = (void *)buf->bufs.p[0];
			param.buf[2] = (void *)buf->bufs.p[2];
			param.buf[4] = (void *)buf->bufs.p[4];
			param.buf[6] = (void *)buf->bufs.p[6];
			param.buf[1] = (void *)buf->bufs.p[1];
			param.buf[3] = (void *)buf->bufs.p[3];
			param.buf[5] = (void *)buf->bufs.p[5];
			param.buf[7] = (void *)buf->bufs.p[7];
			ret = sceMpegBaseCscAvc(pRGBA[i], 0, width, &param);
			if (ret != 0)
				break;
		}
	}
	return ret;
}

int sceMpegAvcDecodeStop(SceMpeg *mp, int width, void **pRGBA, int *num)
{
	MpegSys *sys;
	Buf694 *buf;
	VideoInfo *info;
	int ret;
	int i;
	CscAvcParam param;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	sys = mp->sys;
	buf = sys->buf694;
	info = sys->info;
	ret = func_00005F80(sys->video);
	if (ret != 0)
		return ret;
	*num = info->unk20;
	if (sys->mode != 3) {
		for (i = 0; i < *num; i++) {
			if (pRGBA[i] == NULL)
				return SCE_MPEG_ERROR_INVALID_VALUE;
			param.width = (unsigned int)info->unkC >> 4;
			param.height = (unsigned int)info->unk8 >> 4;
			param.unk8 = 0;
			param.unkC = 0;
			param.buf[0] = (void *)buf->bufs.p[0];
			param.buf[2] = (void *)buf->bufs.p[2];
			param.buf[4] = (void *)buf->bufs.p[4];
			param.buf[6] = (void *)buf->bufs.p[6];
			param.buf[1] = (void *)buf->bufs.p[1];
			param.buf[3] = (void *)buf->bufs.p[3];
			param.buf[5] = (void *)buf->bufs.p[5];
			param.buf[7] = (void *)buf->bufs.p[7];
			ret = sceMpegBaseCscAvc(pRGBA[i], 0, width, &param);
			if (ret != 0)
				break;
		}
	}
	return ret;
}

int func_00000F40(SceMpeg *mp, VideoCtx **out)
{
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	*out = mp->sys->video;
	return 0;
}

int sceMpegAtracDecode(SceMpeg *mp, SceMpegAu *au, void *pcm, int init)
{
	AudioCtx *actx;
	int ret;

	ret = func_00001100(mp);
	if (ret != 0)
		return ret;
	actx = mp->sys->unk6C4;
	if (init == 1) {
		ret = func_00006208(actx, mp->sys->unk6BC, mp->sys->unk6C0, (AudioParam2 *)((char *)au->pEsBuf + 2), (AudioParam4 *)((char *)au->pEsBuf + 4));
		if (ret != 0)
			return ret;
	}
	actx->unk18 = (int)au->pEsBuf;
	actx->unk20 = (int)pcm;
	return func_000063B8(actx);
}

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", D_0000797C);

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", D_00007984);
