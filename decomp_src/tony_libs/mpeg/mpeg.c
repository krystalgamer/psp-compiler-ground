/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegFlushStream);

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
	detail[1] = ((int *)sys->buf694)[8];
	detail[2] = sys->info->unk8;
	detail[3] = sys->info->unkC;
	detail[4] = sys->info->unk10;
	detail[5] = sys->info->unk14;
	detail[6] = sys->info->unk18;
	detail[7] = sys->info->unk1C;
	detail[8] = sys->info->unk20;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegAvcDecode);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegAvcDecodeStop);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", func_00000F40);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", sceMpegAtracDecode);

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", D_0000797C);

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg", D_00007984);
