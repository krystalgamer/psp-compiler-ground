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

unsigned int func_0000725C(int type, int ch)
{
	int sh = 0;

	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	switch (D_00007AA0[type].mask) {
	case 0xFF000000:
		sh = 24;
		break;
	case 0xFFFF0000:
		sh = 16;
		break;
	case 0xFFFFFF00:
		sh = 8;
		break;
	case 0xFFFFFFFF:
		break;
	default:
		return 0;
	}
	return D_00007AA0[type].id | (ch << sh);
}

int func_000072F0(int *type, int *ch, unsigned int str_id)
{
	int ret = 0;
	unsigned int str_id_base = 0;
	unsigned int str_id_ref;
	unsigned int mask = 0;
	int i = 0;

	for (i = 0; i <= 16 && ret == 0; i++) {
		switch (D_00007AA0[i].mask) {
		case 0xFFFFFFFF:
			str_id_base = str_id & 0xFFFFFF00;
			if (str_id_base == D_00007AA0[i].id) {
				*type = i;
				ret = 1;
				*ch = str_id & 0xFFFF;
			}
			break;
		case 0xFFFFFF00:
			str_id_ref = D_00007AA0[i].id;
			if (str_id_ref == 0xBF01E000) {
				str_id_base = str_id & 0xFFFFE000;
				mask = 0x1F;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 8) & mask;
				ret = 1;
			}
			break;
		case 0xFFFF0000:
			str_id_ref = D_00007AA0[i].id;
			switch (str_id_ref) {
			case 0xBD800000:
				str_id_base = str_id & 0xFFE00000;
				mask = 0x1F;
				break;
			case 0xBD000000:
			case 0xBD100000:
			case 0xBD200000:
				str_id_base = str_id & 0xFFF00000;
				mask = 0xF;
				break;
			case 0xBD880000:
			case 0xBD900000:
			case 0xBDA00000:
				str_id_base = str_id & 0xFFF80000;
				mask = 0x7;
				break;
			default:
				str_id_base = str_id & 0xFFFF0000;
				mask = 0;
				break;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 16) & mask;
				ret = 1;
			}
			break;
		case 0xFF000000:
			str_id_ref = D_00007AA0[i].id;
			if (str_id_ref == 0xE0000000) {
				str_id_base = str_id & 0xF0000000;
				mask = 0xF;
			} else if (str_id_ref == 0xC0000000) {
				str_id_base = str_id & 0xE0000000;
				mask = 0x1F;
			} else {
				str_id_base = str_id & 0xFF000000;
				mask = 0;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 24) & mask;
				ret = 1;
			}
			break;
		}
	}
	return ret;
}

unsigned int func_00007504(int type)
{
	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return D_00007AA0[type].mask;
}

int func_00007530(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (unsigned short)((c[0] << 8) + c[1]);
}

unsigned int func_00007548(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 16) + (c[1] << 8) + c[2];
}

unsigned int func_00007568(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
}

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/libmpeg_util", D_00007AA0);
