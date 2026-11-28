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
int __tolower_i(int c) __asm__("func_00007210");
extern const char D_000079A4[];

extern const StreamTypeInfo D_00007904[];
/* --- end declarations --- */

int sceMpegRingbufferPut(SceMpegRingbuffer *rb, int num, int avail)
{
	int ret, out, n;

	n = func_00003A8C(rb, num, avail);
	ret = n;
	if (ret < 0)
		return ret;
	ret = func_000014F8(rb->mp, rb, n, &out);
	if (ret < 0)
		return ret;
	if (n != out)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	ret = func_00003E94(rb, n);
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_ringbuf", func_00003A8C);

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_ringbuf", sceMpegRingbufferAvailableSize);

int sceMpegRingbufferQueryMemSize(int packNum)
{
	return (packNum << 11) + packNum * 0x68;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_ringbuf", sceMpegRingbufferConstruct);

int sceMpegRingbufferDestruct(SceMpegRingbuffer *rb)
{
	return 0;
}

int func_00003E2C(SceMpegRingbuffer *rb)
{
	MpegSys *sys = rb->mp->sys;
	int ret;
	int n;

	ret = func_00001104(rb->mp);
	if (ret != 0)
		return ret;
	func_00005AE4(sys->sema);
	n = rb->iDataPackNum;
	func_00005B80(sys->sema);
	return n;
}

int func_00003E94(SceMpegRingbuffer *rb, int num)
{
	MpegSys *sys = rb->mp->sys;
	int ret;
	int avail;
	int left;
	int chunk;
	int n;

	ret = func_00001104(rb->mp);
	if (ret != 0)
		return ret;
	func_00005AE4(sys->sema);
	avail = rb->iDataPackNum;
	n = (avail < num) ? avail : num;
	for (left = n; left > 0; left -= chunk) {
		chunk = left;
		if (rb->iPackNum < rb->iRead + left)
			chunk = rb->iPackNum - rb->iRead;
		rb->iRead += chunk;
		if (rb->iRead == rb->iPackNum)
			rb->iRead = 0;
	}
	rb->iDataPackNum = avail - n;
	func_00005B80(sys->sema);
	return n;
}

void func_00003F50(SceMpegRingbuffer *rb, int *pos, int addr)
{
	int d = addr - (int)rb->pBuf;
	int idx = d / rb->iPackSize;
	int w = rb->iWrite;

	if (idx == w && d > 0) {
		*pos = -1;
		return;
	}
	if (rb->iWrite < rb->iRead) {
		if (idx < *pos)
			*pos = idx;
	} else if (rb->iWrite < idx) {
		if (rb->iRead >= *pos || idx < *pos)
			*pos = idx;
	} else {
		if (rb->iRead >= *pos && idx < rb->iRead && idx < *pos)
			*pos = idx;
	}
}
