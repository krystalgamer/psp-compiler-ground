#include "common.h"

typedef struct {
	unsigned int mbitbuf;
	int mbits;
	unsigned char *mbs_ptr;
	unsigned char *mbs_ptr0;
	unsigned char *mbs_ptr_end;
} BITWORK;

extern BITWORK gBitWork;

void bitget_init(unsigned char *buf)
{
	gBitWork.mbs_ptr = buf;
	gBitWork.mbs_ptr0 = buf;
	gBitWork.mbits = 0;
	gBitWork.mbitbuf = 0;
}

int bitget(int n)
{
	unsigned int x;

	if (gBitWork.mbits < n) {
		while (gBitWork.mbits <= 24) {
			gBitWork.mbitbuf = (gBitWork.mbitbuf << 8) | *gBitWork.mbs_ptr++;
			gBitWork.mbits += 8;
		}
	}
	gBitWork.mbits -= n;
	x = gBitWork.mbitbuf >> gBitWork.mbits;
	gBitWork.mbitbuf -= x << gBitWork.mbits;
	return x;
}

void bitget_skip(int n)
{
	unsigned int k;

	if (gBitWork.mbits < n) {
		n -= gBitWork.mbits;
		k = n >> 3;
		gBitWork.mbs_ptr += k;
		n -= k << 3;
		gBitWork.mbitbuf = *gBitWork.mbs_ptr++;
		gBitWork.mbits = 8;
	}
	gBitWork.mbits -= n;
	gBitWork.mbitbuf -= (gBitWork.mbitbuf >> gBitWork.mbits) << gBitWork.mbits;
}

void bitget_init_end(unsigned char *buf_end)
{
	gBitWork.mbs_ptr_end = buf_end;
}

int bitget_overrun()
{
	return gBitWork.mbs_ptr > gBitWork.mbs_ptr_end;
}

int bitget_bits_used()
{
	unsigned int n;

	n = ((gBitWork.mbs_ptr - gBitWork.mbs_ptr0) << 3) - gBitWork.mbits;
	return n;
}

void bitget_check(int n)
{
	if (gBitWork.mbits < n) {
		while (gBitWork.mbits <= 24) {
			gBitWork.mbitbuf = (gBitWork.mbitbuf << 8) | *gBitWork.mbs_ptr++;
			gBitWork.mbits += 8;
		}
	}
}

int bitget_lb(int n)
{
	unsigned int x;

	if (gBitWork.mbits < n + 2) {
		while (gBitWork.mbits <= 24) {
			gBitWork.mbitbuf = (gBitWork.mbitbuf << 8) | *gBitWork.mbs_ptr++;
			gBitWork.mbits += 8;
		}
	}
	gBitWork.mbits -= n;
	x = gBitWork.mbitbuf >> gBitWork.mbits;
	gBitWork.mbitbuf -= x << gBitWork.mbits;
	return x;
}

int bitget2(int n)
{
	unsigned int x;

	if (gBitWork.mbits < 11) {
		while (gBitWork.mbits <= 24) {
			gBitWork.mbitbuf = (gBitWork.mbitbuf << 8) | *gBitWork.mbs_ptr++;
			gBitWork.mbits += 8;
		}
	}
	x = gBitWork.mbitbuf >> (gBitWork.mbits - n);
	return x;
}

void bitget_purge(int n)
{
	gBitWork.mbits -= n;
	gBitWork.mbitbuf -= (gBitWork.mbitbuf >> gBitWork.mbits) << gBitWork.mbits;
}

void mac_bitget_check(int n)
{
	int rbits;
	unsigned int rbitbuf;
	unsigned char *rbs_ptr;

	rbits = gBitWork.mbits;
	if (rbits < n) {
		rbs_ptr = gBitWork.mbs_ptr;
		rbitbuf = gBitWork.mbitbuf;
		while (rbits <= 24) {
			rbitbuf = (rbitbuf << 8) | *rbs_ptr++;
			rbits += 8;
		}
		gBitWork.mbitbuf = rbitbuf;
		gBitWork.mbs_ptr = rbs_ptr;
		gBitWork.mbits = rbits;
	}
}

int mac_bitget(int n)
{
	unsigned int code;

	gBitWork.mbits -= n;
	code = gBitWork.mbitbuf >> gBitWork.mbits;
	gBitWork.mbitbuf -= code << gBitWork.mbits;
	return code;
}

int mac_bitget2(int n)
{
	return gBitWork.mbitbuf >> (gBitWork.mbits - n);
}

int mac_bitget_1bit()
{
	unsigned int code;

	gBitWork.mbits--;
	code = gBitWork.mbitbuf >> gBitWork.mbits;
	gBitWork.mbitbuf -= code << gBitWork.mbits;
	return code;
}

void mac_bitget_purge(int n)
{
	gBitWork.mbits -= n;
	gBitWork.mbitbuf -= (gBitWork.mbitbuf >> gBitWork.mbits) << gBitWork.mbits;
}
