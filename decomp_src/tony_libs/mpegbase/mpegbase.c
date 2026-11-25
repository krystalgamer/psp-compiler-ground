/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpegbase.h"

static inline int cscSetParam(int arg0)
{
	int ret = sceDmacplus_driver_B2EFA681(0, arg0, &D_00001740);
	D_00001740.unk18 = arg0;
	D_00001740.unk1C = 0;
	return ret;
}
/* --- end declarations --- */

int module_start(void)
{
	func_00000BA0();
	func_00000828();
	func_00001278();
	return 0;
}

int module_stop(void)
{
	func_000012B4();
	func_00000BE0();
	func_00000878();
	return 0;
}

int sceMpegbase_AC9E717E(int arg0, CscParam *param)
{
	register unsigned int k1 asm("$27");
	unsigned int oldk1;
	int ret;

	K1_SAVE(oldk1);
	ret = sceKernelWaitSema(D_00001740.sema, 1, 0);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	if ((k1 & 0x18) && (int)((unsigned int)param | ((unsigned int)param + sizeof(CscParam))) < 0) {
		ret = 0x80000023;
	} else {
		D_00001740.param = *param;
		ret = sceDmacplus_driver_B2EFA681(0, arg0, &D_00001740);
		D_00001740.unk18 = arg0;
		D_00001740.unk1C = 0;
	}
	sceKernelSignalSema(D_00001740.sema, 1);
	K1_RESTORE(oldk1);
	return ret;
}

int sceMpegBaseCscInit(int arg0)
{
	unsigned int oldk1;
	int ret;

	K1_SAVE(oldk1);
	ret = sceKernelWaitSema(D_00001740.sema, 1, 0);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	{
		D_00001740.param.c[0] = 0x95;
		D_00001740.param.c[1] = 0x0;
		D_00001740.param.c[2] = 0xCC;
		D_00001740.param.c[3] = 0x95;
		D_00001740.param.c[4] = 0x3CE;
		D_00001740.param.c[5] = 0x398;
		D_00001740.param.c[6] = 0x95;
		D_00001740.param.c[7] = 0x102;
		D_00001740.param.c[8] = 0x0;
		D_00001740.param.c[9] = 0x10;
		D_00001740.param.c[10] = 0x1;
		ret = cscSetParam(arg0);
		sceKernelSignalSema(D_00001740.sema, 1);
	}
	K1_RESTORE(oldk1);
	return ret;
}

int sceMpegBaseCscAvc(unsigned int dst, unsigned int dst2, int width, CscAvcParam *p)
{
	register unsigned int k1 asm("$27");
	unsigned int oldk1;
	int ret;
	unsigned int sz1, sz2, size;

	K1_SAVE(oldk1);
	ret = sceKernelWaitSema(D_00001740.sema, 1, 0);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	sz1 = (unsigned int)(p->width * p->height) / 4;
	sz2 = (unsigned int)(p->width * p->height) / 8;
	size = width ? width : D_00001740.unk18;
	size = size * p->height * 4;
	if (staBufBad((unsigned int)p, sizeof(CscAvcParam))
	    || dynBufBad(p->buf[0], sz1)
	    || dynBufBad(p->buf[2], sz1)
	    || dynBufBad(p->buf[4], sz2)
	    || dynBufBad(p->buf[6], sz2)
	    || dynBufBad(p->buf[1], sz1)
	    || dynBufBad(p->buf[3], sz1)
	    || dynBufBad(p->buf[5], sz2)
	    || dynBufBad(p->buf[7], sz2)
	    || dynBufBad(dst, size)
	    || (dst2 != 0 && K1_USER() && !dynBufOk(dst2, size))) {
		ret = 0x80000023;
	} else {
		if (width != 0) {
			ret = sceDmacplus_driver_B2EFA681(D_00001740.unk1C, width, &D_00001740);
			if (ret != 0)
				goto end;
		}
		ret = sceDmacplus_driver_1D73DDA8((void *)dst, (void *)dst2, p);
		if (ret == 0)
			ret = sceDmacplus_driver_3A98EE05(0, 0);
	}
end:
	sceKernelSignalSema(D_00001740.sema, 1);
	K1_RESTORE(oldk1);
	return ret;
}

int sceMpegBaseCscVme(unsigned int dst, unsigned int dst2, int width, CscVmeParam *p)
{
	register unsigned int k1 asm("$27");
	unsigned int oldk1;
	int ret;
	unsigned int sz1, sz2, size;

	K1_SAVE(oldk1);
	ret = sceKernelWaitSema(D_00001740.sema, 1, 0);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	sz1 = (unsigned int)(p->width * p->height) / 2;
	sz2 = (unsigned int)(p->width * p->height) / 8;
	size = width ? width : D_00001740.unk18;
	size = size * p->height * 4;
	if (staBufBad((unsigned int)p, sizeof(CscVmeParam))
	    || dynBufBad(p->buf[0], sz1)
	    || dynBufBad(p->buf[1], sz1)
	    || dynBufBad(p->buf[2], sz2)
	    || dynBufBad(p->buf[3], sz2)
	    || dynBufBad(p->buf[4], sz2)
	    || dynBufBad(p->buf[5], sz2)
	    || dynBufBad(dst, size)
	    || (dst2 != 0 && K1_USER() && !dynBufOk(dst2, size))) {
		ret = 0x80000023;
	} else {
		if (width != 0) {
			ret = sceDmacplus_driver_B2EFA681(D_00001740.unk1C, width, &D_00001740);
			if (ret != 0)
				goto end;
		}
		ret = sceDmacplus_driver_74323807((void *)dst, (void *)dst2, p);
		if (ret == 0)
			ret = sceDmacplus_driver_3A98EE05(0, 0);
	}
end:
	sceKernelSignalSema(D_00001740.sema, 1);
	K1_RESTORE(oldk1);
	return ret;
}

int func_00000828(void)
{
	D_00001740.sema = sceKernelCreateSema("SceMpegBaseCsc", 0, 1, 1, 0);
	D_00001740.unk18 = 0;
	D_00001740.unk1C = 0;
	return 0;
}

int func_00000878(void)
{
	sceKernelDeleteSema(D_00001740.sema);
	return 0;
}

int func_000008A0(void)
{
	return sceKernelWaitSema(D_00001740.sema, 1, 0);
}

int func_000008C8(void)
{
	return sceKernelSignalSema(D_00001740.sema, 1);
}

int func_000008EC(void)
{
	return sceKernelPollSema(D_00001740.sema, 1);
}

int sceMpegbase_0530BE4E(int arg0)
{
	unsigned int oldk1;
	int ret;

	K1_SAVE(oldk1);
	ret = sceKernelWaitSema(D_00001740.sema, 1, 0);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	D_00001740.unk1C = arg0;
	ret = sceDmacplus_driver_B2EFA681(arg0, D_00001740.unk18, &D_00001740);
	sceKernelSignalSema(D_00001740.sema, 1);
	K1_RESTORE(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpegbase/nonmatchings/mpegbase", sceMpegBasePESpacketCopy);

int func_00000BA0(void)
{
	D_00001780.sema = sceKernelCreateSema("SceMpegBasePESpacketCopy", 0, 1, 1, 0);
	return 0;
}

int func_00000BE0(void)
{
	sceKernelDeleteSema(D_00001780.sema);
	return 0;
}

int func_00000C08(void)
{
	return sceKernelWaitSema(D_00001780.sema, 1, 0);
}

int func_00000C30(void)
{
	return sceKernelSignalSema(D_00001780.sema, 1);
}

int func_00000C54(void)
{
	return sceKernelPollSema(D_00001780.sema, 1);
}

int sceMpegBaseYCrCbCopy(CscAvcParam *dst, CscAvcParam *src, int flags)
{
	unsigned int oldk1;
	int ret;
	unsigned int sz1, sz2, ysize, csize, ysize2, csize2;

	K1_SAVE(oldk1);
	ret = func_000008A0();
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	ret = func_00000C08();
	if (ret < 0)
		goto out1;
	ret = sceKernelWaitSema(D_00001E00, 1, 0);
	if (ret < 0)
		goto out2;
	sz2 = ((src->height >> 5) + ((src->height >> 4) & 1)) * src->width * 16;
	sz1 = (src->height >> 5) * src->width * 16;
	ysize2 = sz2 / 2;
	csize2 = sz2 / 4;
	ysize = sz1 / 2;
	csize = sz1 / 4;
	if (staBufBad((unsigned int)src, sizeof(CscAvcParam))
	    || staBufBad((unsigned int)dst, sizeof(CscAvcParam)))
		ret = 0x80000023;
	else if ((flags & 1)
		 && (dynBufBad(dst->buf[0], ysize2)
		    || dynBufBad(dst->buf[4], csize2)
		    || dynBufBad(dst->buf[1], ysize)
		    || dynBufBad(dst->buf[5], csize)))
		ret = 0x80000023;
	else if ((flags & 2)
		 && (dynBufBad(dst->buf[2], ysize2)
		    || dynBufBad(dst->buf[6], csize2)
		    || dynBufBad(dst->buf[3], ysize)
		    || dynBufBad(dst->buf[7], csize)))
		ret = 0x80000023;
	else {
		if (flags & 1) {
			func_0000134C(dst->buf[0], src->buf[0], ysize2);
			func_0000134C(dst->buf[1], src->buf[1], ysize);
			func_0000134C(dst->buf[4], src->buf[4], csize2);
			func_0000134C(dst->buf[5], src->buf[5], csize);
		}
		if (flags & 2) {
			func_0000134C(dst->buf[2], src->buf[2], ysize2);
			func_0000134C(dst->buf[3], src->buf[3], ysize);
			func_0000134C(dst->buf[6], src->buf[6], csize2);
			func_0000134C(dst->buf[7], src->buf[7], csize);
		}
	}
	sceKernelSignalSema(D_00001E00, 1);
out2:
	func_00000C30();
out1:
	func_000008C8();
	K1_RESTORE(oldk1);
	return ret;
}

int sceMpegBaseYCrCbCopyVme(CscVmeParam *dst, CscVmeParam *src, int flags)
{
	unsigned int oldk1;
	int ret;
	unsigned int sz, sz1, sz3;

	K1_SAVE(oldk1);
	ret = func_000008A0();
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	ret = func_00000C08();
	if (ret < 0)
		goto out1;
	ret = sceKernelWaitSema(D_00001E00, 1, 0);
	if (ret < 0)
		goto out2;
	sz = (((src->height >> 4) << 4) + 32) * src->width;
	sz1 = sz / 2;
	sz3 = sz / 8;
	if (staBufBad((unsigned int)src, sizeof(CscVmeParam))
	    || staBufBad((unsigned int)dst, sizeof(CscVmeParam)))
		ret = 0x80000023;
	else if ((flags & 1)
		 && (dynBufBad(src->buf[0], sz1)
		    || dynBufBad(src->buf[2], sz3)
		    || dynBufBad(src->buf[3], sz3)))
		ret = 0x80000023;
	else if ((flags & 2)
		 && (dynBufBad(src->buf[1], sz1)
		    || dynBufBad(src->buf[4], sz3)
		    || dynBufBad(src->buf[5], sz3)))
		ret = 0x80000023;
	else {
		if (flags & 1) {
			func_0000134C(dst->buf[0], src->buf[0], sz1);
			func_0000134C(dst->buf[2], src->buf[2], sz3);
			func_0000134C(dst->buf[3], src->buf[3], sz3);
		}
		if (flags & 2) {
			func_0000134C(dst->buf[1], src->buf[1], sz1);
			func_0000134C(dst->buf[4], src->buf[4], sz3);
			func_0000134C(dst->buf[5], src->buf[5], sz3);
		}
	}
	sceKernelSignalSema(D_00001E00, 1);
out2:
	func_00000C30();
out1:
	func_000008C8();
	K1_RESTORE(oldk1);
	return ret;
}

int func_00001278(void)
{
	D_00001E00 = sceKernelCreateSema("SceMpegBaseYCrCb", 0, 1, 1, 0);
	return 0;
}

int func_000012B4(void)
{
	sceKernelDeleteSema(D_00001E00);
	return 0;
}

int func_000012DC(void)
{
	return sceKernelWaitSema(D_00001E00, 1, 0);
}

int func_00001304(void)
{
	return sceKernelSignalSema(D_00001E00, 1);
}

int func_00001328(void)
{
	return sceKernelPollSema(D_00001E00, 1);
}

INCLUDE_ASM("tmp/asm/tony_libs/mpegbase/nonmatchings/mpegbase", func_0000134C);
