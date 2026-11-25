/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int func_000016E4(unsigned char *buf, unsigned int size, WaveFmt *fmt, unsigned int *a, unsigned int *c, unsigned int *d, int *e, int *f, int *g)
{
	unsigned int pos;
	unsigned int len;
	unsigned int id;
	int type = -1;
	unsigned short n;
	int i;

	*a = 0;
	*e = 0;
	*c = 0;
	pos = 0;
	*d = 0;
	do {
		if (func_00001DFC(buf, &pos, size) != 0x46464952)
			return -1;
		len = func_00001DFC(buf, &pos, size) - 4;
		if (len % 2 == 1)
			len++;
		if (func_00001DFC(buf, &pos, size) == 0x45564157)
			break;
		if (pos + len <= size)
			pos += len;
		else
			pos = size;
	} while (pos < size);
	while (pos < size) {
		id = func_00001DFC(buf, &pos, size);
		if (pos >= size)
			break;
		len = func_00001DFC(buf, &pos, size);
		if (len % 2 == 1)
			len++;
		switch (id) {
		case 0x20746D66:
			type = func_00001E8C(buf, &pos, size);
			switch (type) {
			case 1:
				fmt->tag = type;
				fmt->nChannels = func_00001E8C(buf, &pos, size);
				fmt->rate = func_00001DFC(buf, &pos, size);
				fmt->bytesPerSec = func_00001DFC(buf, &pos, size);
				fmt->nBlockAlign = func_00001E8C(buf, &pos, size);
				fmt->bits = func_00001E8C(buf, &pos, size);
				len -= 0x10;
				break;
			case 0x270:
				fmt->tag = type;
				fmt->nChannels = func_00001E8C(buf, &pos, size);
				fmt->rate = func_00001DFC(buf, &pos, size);
				fmt->bytesPerSec = func_00001DFC(buf, &pos, size);
				fmt->nBlockAlign = func_00001E8C(buf, &pos, size);
				fmt->bits = func_00001E8C(buf, &pos, size);
				fmt->cbSize = func_00001E8C(buf, &pos, size);
				if (func_00001E8C(buf, &pos, size) != 1)
					return -1;
				func_00001DFC(buf, &pos, size);
				fmt->unk14 = func_00001E8C(buf, &pos, size);
				if (fmt->unk14 != func_00001E8C(buf, &pos, size))
					return -1;
				if (func_00001E8C(buf, &pos, size) != 1)
					return -1;
				if (func_00001E8C(buf, &pos, size) != 0)
					return -1;
				len -= 0x20;
				type = 3;
				break;
			case 0xFFFE:
				fmt->tag = type;
				fmt->nChannels = func_00001E8C(buf, &pos, size);
				fmt->rate = func_00001DFC(buf, &pos, size);
				fmt->bytesPerSec = func_00001DFC(buf, &pos, size);
				fmt->nBlockAlign = func_00001E8C(buf, &pos, size);
				fmt->bits = func_00001E8C(buf, &pos, size);
				fmt->cbSize = func_00001E8C(buf, &pos, size);
				n = func_00001E8C(buf, &pos, size);
				fmt->unk14 = func_00001DFC(buf, &pos, size);
				fmt->guid1 = func_00001DFC(buf, &pos, size);
				fmt->guid2[0] = func_00001E8C(buf, &pos, size);
				fmt->guid2[1] = func_00001E8C(buf, &pos, size);
				for (i = 0; i < 8; i++) {
					if (pos < size)
						fmt->guid4[i] = buf[pos++];
					else
						fmt->guid4[i] = 0;
				}
				if (func_00001D94((Guid *)&fmt->guid1, &D_00003844)) {
					fmt->validBits = n;
					fmt->unk28 = func_00001E8C(buf, &pos, size);
					for (i = 0; i < 2; i++) {
					if (pos < size)
						fmt->unk2A[i] = buf[pos++];
					else
						fmt->unk2A[i] = 0;
				}
					for (i = 0; i < 8; i++) {
					if (pos < size)
						fmt->unk2C[i] = buf[pos++];
					else
						fmt->unk2C[i] = 0;
				}
					len -= 0x34;
				} else if (func_00001D94((Guid *)&fmt->guid1, &D_00003834)) {
					fmt->validBits = n;
					len -= 0x28;
				} else {
					return -1;
				}
				type = 5;
				break;
			default:
				return -1;
			}
			break;
		case 0x74636166:
			*c = func_00001DFC(buf, &pos, size);
			len -= 4;
			if (len >= 4) {
				*e = func_00001DFC(buf, &pos, size);
				len -= 4;
			}
			break;
		case 0x6C706D73:
			if (*f < 0) {
				if (pos + 0x1C > size)
					return -1;
				pos += 0x1C;
				if (func_00001DFC(buf, &pos, size) != 0) {
					if (pos + 0xC > size)
						return -1;
					pos += 0xC;
					*f = func_00001DFC(buf, &pos, size);
					len -= 0x14;
					*g = func_00001DFC(buf, &pos, size);
					if (*g < *f)
						return -1;
				}
				len -= 0x20;
			}
			break;
		case 0x61746164:
			*d = len;
			if (*a != 0)
				return -1;
			*a = pos;
			return type;
		}
		if (pos + len > size) {
			pos = size;
			return -1;
		}
		pos += len;
	}
	return type;
}

int func_00001D94(Guid *a, Guid *b)
{
	int ret = 0;

	if (a->d1 == b->d1 && a->d2 == b->d2 && func_00001F04(a->d4, b->d4, 8) == 0)
		ret = 1;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", func_00001DFC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", func_00001E8C);

int func_00001F04(const unsigned char *a, const unsigned char *b, unsigned int size)
{
	long long n = size;

	for (; n > 0; n--) {
		if (*a != *b)
			return *a < *b ? -1 : 1;
		a++;
		b++;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", D_00003834);

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", D_00003844);
